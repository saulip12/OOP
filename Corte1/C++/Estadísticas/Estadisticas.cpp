#include <iostream>   // Librería que permite usar entrada y salida de datos como cout y cin
using namespace std;  // Permite usar cout y otras funciones sin escribir std:: antes

// Define la clase llamada Estadisticas
class Estadisticas 
{
public: // Indica que los elementos dentro pueden usarse fuera de la clase

    // Función estática que calcula la suma de los elementos de un arreglo
    static int sum(const int a[], int n) 
    {
        int total = 0;// Variable donde se guardará la suma total

        // Bucle que recorre el arreglo desde la posición 0 hasta n-1
        for (int i = 0; i < n; i++) 
            total += a[i];// En cada vuelta se suma el elemento del arreglo al total

        return total;// Devuelve la suma total de los elementos
    }

    // Función estática que calcula el promedio de los elementos del arreglo
    static double average(const int a[], int n) 
    {
        // Llama a la función sum para obtener la suma y la divide entre n
        return (double)sum(a, n) / n; // Se convierte a double para obtener decimales
    }
};

// Función principal main
int main() 
{
    // Declaración de un arreglo llamado grades que ya estan dados los datos
    int grados[] = {80, 75, 90, 60, 95};

    // Calcula el número de elementos del arreglo
    int n = sizeof(grados) / sizeof(grados[0]);
    /*sizeof(grados) da el tamaño total del arreglo en bytes
      sizeof(grados[0]) da el tamaño de un elemento
      al dividirlos obtenemos la cantidad de elementos*/

    // Imprime en pantalla la suma de los elementos usando la función sum
    cout << "Sum: " << Estadisticas::sum(grados, n) << "\n";

    // Imprime en pantalla el promedio usando la función average
    cout << "Average: " << Estadisticas::average(grados, n) << "\n";

    return 0; // Indica que el programa terminó correctamente
}