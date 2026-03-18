import java.util.InputMismatchException;
import java.util.Scanner;

public class ValidadorDatos {
    private Scanner scanner;
    private Impresion impresion;
    
    public ValidadorDatos() {
        this.scanner = new Scanner(System.in);
        this.impresion = new Impresion();
    }
    
    public double validarPeso() {
        double peso = 0;
        boolean datoValido = false;
        
        do {
            try {
                System.out.print("Ingrese el peso en kg ");
                String entrada = scanner.nextLine().trim();
                
                // Validar que no esté vacío
                if (entrada.isEmpty()) {
                    impresion.imprimirError("No ingresó ningún valor");
                    continue;
                }
                
                // Validar que solo contenga números, punto y opcionalmente signo negativo
                if (!entrada.matches("^-?\\d*\\.?\\d+$")) {
                    impresion.imprimirError("Debe ingresar solo números con punto");
                    continue;
                }
                
                peso = Double.parseDouble(entrada);
                
                if (peso < 15) {
                    impresion.imprimirError("El peso no puede ser menor a 15 kg");
                } else if (peso > 500) {
                    impresion.imprimirError("El peso no puede exceder los 500 kg");
                } else {
                    datoValido = true;
                }
                
            } catch (NumberFormatException e) {
                impresion.imprimirError("Formato de número inválido");
            }
            
        } while (!datoValido);
        
        return peso;
    }
    
    public double validarAltura() {
        double altura = 0;
        boolean datoValido = false;
        
        do {
            try {
                System.out.print("Ingrese la altura en metros (use . como decimal): ");
                String entrada = scanner.nextLine().trim();
                
                // Validar que no esté vacío
                if (entrada.isEmpty()) {
                    impresion.imprimirError("No ingresó ningún valor");
                    continue;
                }
                
                // Validar que solo contenga números, punto y opcionalmente signo negativo
                if (!entrada.matches("^-?\\d*\\.?\\d+$")) {
                    impresion.imprimirError("Debe ingresar solo números ");
                    continue;
                }
                
                altura = Double.parseDouble(entrada);
                
                if (altura <= 0) {
                    impresion.imprimirError("La altura debe ser mayor a 0 metros");
                } else if (altura > 3) {
                    impresion.imprimirError("La altura no puede ser mayor a 3 metros");
                } else {
                    datoValido = true;
                }
                
            } catch (NumberFormatException e) {
                impresion.imprimirError("Formato de número inválido (ej: 1.75)");
            }
            
        } while (!datoValido);
        
        return altura;
    }
    
    public int validarOpcionMenu() {
        int opcion = 0;
        boolean opcionValida = false;
        
        do {
            try {
                System.out.print("Seleccione una opción: ");
                String entrada = scanner.nextLine().trim();
                
                // Validar que solo contenga números
                if (!entrada.matches("\\d+")) {
                    impresion.imprimirError("Debe ingresar solo números (1 o 2)");
                    continue;
                }
                
                opcion = Integer.parseInt(entrada);
                
                if (opcion < 1 || opcion > 2) {
                    impresion.imprimirError("Opción no válida. Debe ser 1 o 2");
                } else {
                    opcionValida = true;
                }
                
            } catch (NumberFormatException e) {
                impresion.imprimirError("Debe ingresar un número válido (1 o 2)");
            }
            
        } while (!opcionValida);
        
        return opcion;
    }
}