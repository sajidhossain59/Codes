#include <WiFi.h>
#include <WebServer.h>

// ========== WIFI ==========
const char* ssid = "SOCCER_BOT";
const char* password = "12345678";

WebServer server(80); // port 

// ========== L298N PINS ==========
#define IN1 12  // Left motor
#define IN2 14
#define IN3 27  // Right motor
#define IN4 26

// ========== SETTINGS ==========
#define MAX_SPEED 255
#define DEADZONE 15

#define FORWARD_TIME 700
#define BACKWARD_TIME 700

// ========== VARIABLES ==========
int leftPWM = 0;
int rightPWM = 0;

unsigned long lastCommandTime = 0;
unsigned long sequenceStart = 0;

bool autoActive = false;

// ========== WEBPAGE ==========

const char webpage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width,
initial-scale=1, maximum-scale=1, user-scalable=no">

<title>ROBO SOCCER CONTROLLER</title>

<style>
* { box-sizing: border-box; }

body {
    margin: 0;
    background: #101820;
    color: white;
    font-family: Arial;
    text-align: center;
    user-select: none;
    touch-action: none;
}

h2 {
    margin-top: 35px;
    font-size: 23px;
    color: #00e5ff;
}

#joystick {
    width: min(78vw, 340px);
    height: min(78vw, 340px);
    margin: 55px auto 35px;
    background: #263746;
    border: 4px solid #00e5ff;
    border-radius: 50%;
    position: relative;
    touch-action: none;
}

#stick {
    width: 85px;
    height: 85px;
    background: linear-gradient(145deg,#00e5ff,#007bff);
    border-radius: 50%;
    position: absolute;
    left: 50%;
    top: 50%;
    transform: translate(-50%,-50%);
}

#returnBtn {
    background: #00bcd4;
    color: #101820;
    border: none;
    padding: 16px 35px;
    border-radius: 12px;
    font-size: 17px;
    font-weight: bold;
}

#returnBtn:disabled {
    opacity: 0.5;
}
</style>
</head>

<body>

<h2>ROBO SOCCER CONTROLLER</h2>

<div id="joystick">
    <div id="stick"></div>
</div>

<button id="returnBtn">GO & RETURN</button>

<script>
const joystick = document.getElementById("joystick");
const stick = document.getElementById("stick");
const returnBtn = document.getElementById("returnBtn");

let active = false;
let x = 0, y = 0;
let lastSend = 0;

function sendCommand(force = false) {
    const now = Date.now();

    if (!force && now - lastSend < 40) return;

    lastSend = now;

    fetch(`/control?x=${x.toFixed(3)}&y=${y.toFixed(3)}`)
        .catch(() => {});
}

function moveJoystick(e) {
    if (!active) return;

    const rect = joystick.getBoundingClientRect();

    let dx = e.clientX - rect.left - rect.width / 2;
    let dy = rect.top + rect.height / 2 - e.clientY;

    const max = rect.width / 2 - 48;
    const distance = Math.hypot(dx, dy);

    if (distance > max) {
        dx *= max / distance;
        dy *= max / distance;
    }

    x = dx / max;
    y = dy / max;

    stick.style.left = (50 + dx / rect.width * 100) + "%";
    stick.style.top = (50 - dy / rect.height * 100) + "%";

    sendCommand();
}

function resetJoystick() {
    if (!active) return;

    active = false;
    x = 0;
    y = 0;

    stick.style.left = "50%";
    stick.style.top = "50%";

    sendCommand(true);
}

joystick.addEventListener("pointerdown", e => {
    active = true;
    joystick.setPointerCapture(e.pointerId);
    moveJoystick(e);
});

joystick.addEventListener("pointermove", moveJoystick);
joystick.addEventListener("pointerup", resetJoystick);
joystick.addEventListener("pointercancel", resetJoystick);

returnBtn.addEventListener("click", async () => {
    if (active) resetJoystick();

    returnBtn.disabled = true;

    try {
        await fetch("/sequence");
    } catch(e) {}

    setTimeout(() => {
        returnBtn.disabled = false;
    }, 1500);
});
</script>

</body>
</html>
)rawliteral";

// ========== MOTOR CONTROL ==========

void setMotor(int pin1, int pin2, int speed) {

    speed = constrain(speed, -MAX_SPEED, MAX_SPEED);  // keep var in a limit 

    if (speed > 0) {
        analogWrite(pin1, speed);
        analogWrite(pin2, 0);
    }
    else if (speed < 0) {
        analogWrite(pin1, 0);
        analogWrite(pin2, abs(speed));
    }
    else {
        analogWrite(pin1, 0);
        analogWrite(pin2, 0);
    }
}

void driveMotors(int left, int right) {

    leftPWM = constrain(left, -255, 255);
    rightPWM = constrain(right, -255, 255);

    setMotor(IN1, IN2, leftPWM);
    setMotor(IN3, IN4, rightPWM);
}

void stopMotors() {
    driveMotors(0, 0);
}

// ========== JOYSTICK CONTROL ==========

void handleControl() {

    if (autoActive) {
        server.send(200, "text/plain", "BUSY");
        return;
    }

    float x = constrain(server.arg("x").toFloat(), -1.0, 1.0);
    float y = constrain(server.arg("y").toFloat(), -1.0, 1.0);

    lastCommandTime = millis();

    float left = y + x;
    float right = y - x;

    float maxValue = max(abs(left), abs(right));

    if (maxValue > 1.0) {
        left /= maxValue;
        right /= maxValue;
    }

    int l = round(left * 255);
    int r = round(right * 255);

    if (abs(l) < DEADZONE) l = 0;
    if (abs(r) < DEADZONE) r = 0;

    driveMotors(l, r);

    server.send(200, "text/plain", "OK");
}

// ========== GO & RETURN ==========

void handleSequence() {

    if (!autoActive) {

        autoActive = true;
        sequenceStart = millis();
        lastCommandTime = millis();

        driveMotors(255, 255);

        Serial.println("Moving Forward");
    }

    server.send(200, "text/plain", "STARTED");
}

// ========== SETUP ==========

void setup() {

   // Serial.begin(115200);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopMotors();

    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);

    Serial.println("ROBO SOCCER CONTROLLER");
    Serial.print("IP: ");
    Serial.println(WiFi.softAPIP());

    server.on("/", []() {
        server.send_P(200, "text/html", webpage);
    });

    server.on("/control", handleControl);
    server.on("/sequence", handleSequence);

    server.begin();

    lastCommandTime = millis();
}

// ========== MAIN LOOP ==========

void loop() {

    server.handleClient();

    if (autoActive) {

        unsigned long elapsed = millis() - sequenceStart;

        if (elapsed >= FORWARD_TIME &&
            elapsed < FORWARD_TIME + BACKWARD_TIME) {

            driveMotors(-255, -255);

        }

        else if (elapsed >= FORWARD_TIME + BACKWARD_TIME) {

            stopMotors();
            autoActive = false;

            Serial.println("Returned and Stopped");
        }
    }

    else if (millis() - lastCommandTime > 350) {

        stopMotors();
    }

    /*/ Serial Monitor

    static unsigned long lastPrint = 0;

    if (millis() - lastPrint >= 100) {

        lastPrint = millis();

        Serial.print("Left PWM: ");
        Serial.print(leftPWM);

        Serial.print(" | Right PWM: ");
        Serial.println(rightPWM);
    } /*/
}