class student:
    def __init__ (self):
        self.name=""
        self.roll=""

    def show_name(self):
        print(f"Students name is {self.name}")
    
    def show_roll(self):
        print(f"Students roll is {self.roll}")


if __name__ == "__main__":
    std1 = student()
    std1.name = "Sajid Hossain"
    std1.roll = 2024331528

    std2 = student()
    std2.name = "Raihanul Islam"
    std2.roll = 2024331514

    std1.show_name()
    std1.show_roll()

    std2.show_name()
    std2.show_roll()
