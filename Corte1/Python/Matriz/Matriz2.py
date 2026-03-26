class Matriz2x2:
 def __init__(self):
  self.data = [[0, 0], [0, 0]]

 def cargar_ejemplo(self):
  self.data[0][0] = 1
  self.data[0][1] = 2
  self.data[1][0] = 3
  self.data[1][1] = 4

 def imprimir(self):
  for fila in self.data:
   print(fila)

 def suma_elementos(self):
  s = 0
  for fila in self.data:
   for x in fila:
    s += x
  return s


m = Matriz2x2()
m.cargar_ejemplo()
m.imprimir()
print("Suma =", m.suma_elementos())
