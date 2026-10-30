class stack:
    def __init__(self):
        self.arr = [0]*5
        self.top = -1

    def push(self, x):
        if self.top == 4:
            print("Stack overflow")
            return
        else:
            self.top+=1
            self.arr[self.top] = x
    
    def pop(self):
        if self.top == -1:
            print("Stack Underflow")
            return
        else:
            self.top-=1
    
    def show(self):
        for i in range(self.top,-1,-1):
            print(self.arr[i],end=" ")
        print()


# driver code
if __name__ == "__main__":

    # Creating stack object
    s = stack()

    # Performing operations
    s.push(int(input("Enter a number")))
    s.push(20)
    s.push(30)

    print("Stack elements: ", end="")
    s.show()

    s.pop()

    print("After pop: ", end="")
    s.show()