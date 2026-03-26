#include <iostream>
#include <string>
using namespace std;

// CLASE
class Persona {     
public:
    // ATRIBUTOS
    string nombre;   
    int edad;        

    // METODO (función miembro)
    void mostrar() {
        cout << "Nombre = " << nombre << "\n";
        cout << "Edad = " << edad << "\n";
    }
  
    // NO hay constructor explícito (usa constructor por defecto)
};  

int main() {
    // OBJETOS (instancias de la clase Persona)
    Persona p1;     
    Persona p2;     

    p1.nombre = "Ana";
    p1.edad = 20;

    p2.nombre = "Luis";
    p2.edad = 22;

    cout << "Objeto 1:\n";
    p1.mostrar();

    cout << "\nObjeto 2:\n";
    p2.mostrar();

    return 0;
}
