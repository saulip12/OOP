#include <iostream>
using namespace std;

// CLASE
class VectorInt {     
public:
    // ATRIBUTO ESTÁTICO (constante)
    static const int N = 5;

    // ATRIBUTO (array de enteros)
    int data[N];

    // MÉTODO normal (de instancia)
    void cargarEjemplo() {
        data[0] = 10;
        data[1] = 20;
        data[2] = 30;
        data[3] = 40;
        data[4] = 50;
    }

    // MÉTODO normal (de instancia)
    int suma() {
        int s = 0;
        for (int i = 0; i < N; i++) s += data[i];
        return s;
    }

    // MÉTODO normal (de instancia)
    double promedio() {
        return (double) suma() / N;
    }

    // MÉTODO normal (de instancia)
    void imprimir() {
        for (int i = 0; i < N; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};  

int main() {
    // OBJETO (instancia de la clase VectorInt)
    VectorInt v;

    v.cargarEjemplo();

    return 0;
}
