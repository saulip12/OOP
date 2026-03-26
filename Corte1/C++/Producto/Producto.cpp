#include <iostream>
#include <string>
using namespace std;

// CLASE
class Producto {     
public:
    // ATRIBUTOS
    string nombre;
    double precio;

    // CONSTRUCTOR por defecto (sin parámetros)
    Producto() {
        nombre = "Sin nombre";
        precio = 0.0;
    }

    // CONSTRUCTOR con un parámetro
    Producto(string nombre) {
        this->nombre = nombre;
        this->precio = 0.0;
    }

    // CONSTRUCTOR con dos parámetros (sobrecarga de constructores)
    Producto(string nombre, double precio) {
        this->nombre = nombre;
        this->precio = precio;
    }

    // MÉTODO normal (de instancia)
    void mostrar() {
        cout << "Nombre = " << nombre << "\n";
        cout << "Precio = " << precio << "\n";
    }

    // NO hay métodos estáticos
};  

int main() {
    // OBJETOS (instancias de la clase Producto)
    Producto p1;                    // Usa constructor por defecto
    Producto p2("Cuaderno");        // Usa constructor con 1 parámetro
    Producto p3("Lapiz", 2500.0);   // Usa constructor con 2 parámetros

    p1.mostrar();
    cout << "\n";
    p2.mostrar();
    cout << "\n";
    p3.mostrar();

    return 0;
}
