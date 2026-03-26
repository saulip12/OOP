# CLASE
class VectorInt:
    
    # CONSTRUCTOR (__init__)
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    # MÉTODO normal (de instancia)
    def suma(self):
        s = 0
        for x in self.data:
            s += x
        return s

    # MÉTODO normal (de instancia)
    def promedio(self):
        if self.n == 0:
            return 0.0
        return self.suma() / self.n

    # MÉTODO normal (de instancia)
    def imprimir(self):
        print(self.data)

    # NO hay métodos estáticos


# Código principal (fuera de cualquier clase)
# OBJETO (instancia de la clase VectorInt)
v = VectorInt(5)

v.data[0] = 10
v.data[1] = 20
v.data[2] = 30
v.data[3] = 40
v.data[4] = 50

v.imprimir()
print("Suma =", v.suma())
print("Promedio =", v.promedio())
