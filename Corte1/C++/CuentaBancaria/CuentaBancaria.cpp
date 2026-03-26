#include <iostream>
#include <string>
using namespace std;

// CLASE
class CuentaBancaria {     
private:
    // ATRIBUTOS privados
    string titular;
    double saldo;

public:
    // CONSTRUCTOR (con parámetros)
    CuentaBancaria(string titular, double saldoInicial) {
        this->titular = titular;
        this->saldo = saldoInicial;
    }

    // MÉTODOS GETTERS (de instancia)
    string getTitular() { return titular; }
    double getSaldo() { return saldo; }

    // MÉTODO normal (de instancia)
    void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }

    // MÉTODO normal (de instancia)
    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) saldo -= monto;
    }

    // MÉTODO normal (de instancia)
    void mostrar() {
        cout << "Titular = " << titular << "\n";
        cout << "Saldo = " << saldo << "\n";
    }


};  

int main() {
    // OBJETO (instancia de la clase CuentaBancaria)
    CuentaBancaria c1("Maria", 100000.0);

    c1.mostrar();

    c1.depositar(25000.0);
    c1.retirar(10000.0);

    cout << "\nDespues de operaciones:\n";
    c1.mostrar();

    return 0;
}
