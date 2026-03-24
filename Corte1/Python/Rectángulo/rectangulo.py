
class Rectangle:
    # Constructor in Python
    def __init__(self, b, h):
        self.base = b
        self.height = h

    def area(self):
        return self.base * self.height


def main():
    r1 = Rectangle(3.0, 2.0)
    print("Base:", r1.base)
    print("Height:", r1.height)
    print("Area:", r1.area())


if __name__ == "__main__":
    main()