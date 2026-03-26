# CLASE
class Persona:
    
    # CONSTRUCTOR (__init__)
    def __init__(self):
        self.nombre = ""
        self.edad = 0

    # MÉTODO normal (de instancia)
    def mostrar(self):
        print("Nombre =", self.nombre)
        print("Edad =", self.edad)

# Código principal
# OBJETOS (instancias de la clase Persona)
p1 = Persona()
p2 = Persona()

p1.nombre = "Ana"
p1.edad = 20

p2.nombre = "Luis"
p2.edad = 22

print("Objeto 1:")
p1.mostrar()

print("\nObjeto 2:")
p2.mostrar()
