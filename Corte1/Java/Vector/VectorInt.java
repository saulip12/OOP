// CLASE
class VectorInt {     
    // ATRIBUTOS
    public int[] data;
    public int n;

    // CONSTRUCTOR (con parámetro)
    public VectorInt(int n) {
        this.n = n;
        this.data = new int[n];
    }

    // MÉTODO normal (de instancia)
    public int suma() {
        int s = 0;
        for (int i = 0; i < n; i++) s += data[i];
        return s;
    }

    // MÉTODO normal (de instancia)
    public double promedio() {
        if (n == 0) return 0.0;
        return (double) suma() / n;
    }

    // MÉTODO normal (de instancia)
    public void imprimir() {
        for (int i = 0; i < n; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }
};  

// CLASE PRINCIPAL (contiene el método main)
public class MainVectorInt {
    public static void main(String[] args) {
        // OBJETO (instancia de la clase VectorInt)
        VectorInt v = new VectorInt(5);

        v.data[0] = 10;
        v.data[1] = 20;
        v.data[2] = 30;
        v.data[3] = 40;
        v.data[4] = 50;

        v.imprimir();
        System.out.println("Suma = " + v.suma());
        System.out.println("Promedio = " + v.promedio());
    }
}
