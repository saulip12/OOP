import java.util.Scanner;
public class App {
    //logica del programa
    public static void main(String[] args)  
    {
        Numero numero1 = new Numero(5);
        Numero numero2 = new Numero(7);
        Numero suma = new Numero();
        Scanner teclado = new Scanner(System.in);
        Vista vista = new Vista();
        vista.mostrarTitulo();
        vista.mostrarNumero();

        int n1 = teclado.nextInt();//si es entero se pede guardar en n1, asegura
        numero1.setNumero(n1);
        vista.mostrarNumero();
        System.out.println("Digite numero 2");
        int n2 = teclado.nextInt();
        numero2.setNumero(n2);

        int s = numero1.getNumero() + numero2.getNumero(); 
        suma.setNumero(s);

        System.out.println(suma.getNumero());
        teclado.close();
    }
}
