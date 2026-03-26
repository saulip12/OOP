// CLASE
class Matriz2x2 {     
    // ATRIBUTO (matriz bidimensional)
    public int[][] data;

    // CONSTRUCTOR (sin parámetros)
    public Matriz2x2() {
        data = new int[2][2];
    }

    // MÉTODO normal (de instancia)
    public void cargarEjemplo() {
        data[0][0] = 1; data[0][1] = 2;
        data[1][0] = 3; data[1][1] = 4;
    }

    // MÉTODO normal (de instancia)
    public void imprimir() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }

    // MÉTODO normal (de instancia)
    public int sumaElementos() {
        int s = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                s += data[i][j];
            }
        }
        return s;
    }

};  
public class MainMatriz2x2 {
    public static void main(String[] args) {
        // OBJETO (instancia de la clase Matriz2x2)
        Matriz2x2 m = new Matriz2x2();

        m.cargarEjemplo();
        m.imprimir();
        System.out.println("Suma = " + m.sumaElementos());
    }
}
