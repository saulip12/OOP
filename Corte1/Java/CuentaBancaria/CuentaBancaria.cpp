// CLASE
class CuentaBancaria {     
    // ATRIBUTOS privados
    private String titular;
    private double saldo;

    // CONSTRUCTOR (con parámetros)
    public CuentaBancaria(String titular, double saldoInicial) {
        this.titular = titular;
        this.saldo = saldoInicial;
    }

    // MÉTODOS GETTERS (de instancia)
    public String getTitular() { 
        return titular; 
    }

    public double getSaldo() { 
        return saldo; 
    }

    // MÉTODO normal (de instancia)
    public void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }

    // MÉTODO normal (de instancia)
    public void retirar(double monto) {
        if (monto > 0 && monto <= saldo) saldo -= monto;
    }

    // MÉTODO normal (de instancia)
    public void mostrar() {
        System.out.println("Titular = " + titular);
        System.out.println("Saldo = " + saldo);
    }

    // NO hay constructor por defecto
    // NO hay métodos estáticos
};  

// CLASE PRINCIPAL (contiene el método main)
public class MainCuenta {
    public static void main(String[] args) {
        // OBJETO (instancia de la clase CuentaBancaria)
        CuentaBancaria c1 = new CuentaBancaria("Maria", 100000.0);

        c1.mostrar();

        c1.depositar(25000.0);
        c1.retirar(10000.0);

        System.out.println("\nDespues de operaciones:");
        c1.mostrar();
    }
}
