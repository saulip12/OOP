class Producto:
 def __init__(self, nombre="Sin nombre", precio=0.0):
  self.nombre = nombre
  self.precio = precio

 def mostrar(self):
  print("Nombre =", self.nombre)
  print("Precio =", self.precio)


p1 = Producto()
p2 = Producto("Cuaderno")
p3 = Producto("Lapiz", 2500.0)

p1.mostrar()
print()
p2.mostrar()
print()
p3.mostrar()
