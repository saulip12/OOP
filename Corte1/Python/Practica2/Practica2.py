class Person:
    #Constructor en python
    def __init__(self):
        self.name = ""
        self.age = 0
    # Metodo
    def say_hello(self):
        print(f"Hi, I'm {self.name} and I'm {self.age} years old.")

def main():
    #Crear un objeto
    p1 = Person()
    #Asignar atrib
    p1.name = "Luna"
    p1.age = 18

    p1.say_hello()

if __name__ == "__main__":
     main()
