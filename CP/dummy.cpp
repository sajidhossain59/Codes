#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    for (long long a = sqrt(n); a >= 1; --a) {
        if (n % a == 0) {
            long long b = n / a;
            cout << 2 * (a + b) << "\n";
            break;
        }
    }

    return 0;
}