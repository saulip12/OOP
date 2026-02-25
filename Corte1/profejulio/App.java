import java.util.Scanner;
public class App {
    //logica del programa
    public static void main(String[] args)  
    {
        Numero numero1 = new Numero(5);
        Numero numero2 = new Numero(7);
        Numero multiplicacion = new Numero();
        Scanner teclado = new Scanner(System.in);
        Vista vista = new Vista();
        vista.mostrarTitulo();
        vista.mostrarNumero();

        int n1 = teclado.nextInt();//si es entero se pede guardar en n1, asegura
        numero1.setNumero(n1);
        vista.mostrarNumero();
        int n2 = teclado.nextInt();
        numero2.setNumero(n2);
        vista.mostrarNumero2();


        numero2.getNumero(); 

        int m = numero1.getNumero() * numero2.getNumero(); 
        multiplicacion.setNumero(m);

        System.out.println(multiplicacion.getNumero());
        teclado.close();
    }
}
