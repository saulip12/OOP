public class Impresion {
    
    public void imprimirMenu() {
        System.out.println("Calculadora de masa muscular");
        System.out.println("1. Calcular IMC");
        System.out.println("2. Salir");
        System.out.print("Seleccione una opción: ");
    }
    
    public void imprimirResultado(Persona persona, double imc, String clasificacion) {
        System.out.println("Tu indice de masa es: ");
        System.out.printf("Peso: %.2f kg%n", persona.getPeso());
        System.out.printf("Altura: %.2f m%n", persona.getAltura());
        System.out.printf("IMC: %.2f%n", imc);
        System.out.println("Clasificación: " + clasificacion);
    }
    
    public void imprimirError(String mensaje) {
        System.out.println("Error " + mensaje);
    }
    
    public void imprimirMensaje(String mensaje) {
        System.out.println(mensaje);
    }
    
}