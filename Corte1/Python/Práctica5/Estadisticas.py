# Define una clase llamada Estadisticas
class Estadisticas:

    @staticmethod
    # Método estático que calcula la suma de los elementos de un arreglo
    def sum(a):
        total = 0  # Variable donde se guardará la suma total

        # Recorre cada elemento del arreglo a
        for x in a:
            total += x  # En cada interaccion se suma el valor de x al total

        return total  # Devuelve la suma total

    @staticmethod
    # Método estático que calcula el promedio de los elementos
    def average(a):
        return Estadisticas.sum(a) / len(a)  # Llama al método sum y divide entre la cantidad de elementos


# Función principal main
def main():
    grades = [80, 75, 90, 60, 95]  # Arreglo que ya tiene los datos predefinidos

    # Imprime la suma de las notas usando el método sum
    print("Sum:", Estadisticas.sum(grades))

    # Imprime el promedio de las notas usando el método average
    print("Average:", Estadisticas.average(grades))


# Verifica si el archivo se está ejecutando directamente
if __name__ == "__main__":
    main()  # Llama a la función principal