public class Main {
    
    public static void main(String[] args) {
        Persona persona = new Persona();
        CalculoIMC calculo = new CalculoIMC();
        Impresion impresion = new Impresion();
        ValidadorDatos validador = new ValidadorDatos();
        
        int opcion;
        
        do {
            impresion.imprimirMenu();
            opcion = validador.validarOpcionMenu();
            
            switch (opcion) {
                case 1:
                    // Ingresar y validar peso
                    double peso = validador.validarPeso();
                    persona.setPeso(peso);
                    
                    // Ingresar y validar altura
                    double altura = validador.validarAltura();
                    persona.setAltura(altura);
                    
                    // Calcular IMC
                    double imc = calculo.calcularIMC(persona);
                    String clasificacion = calculo.clasificarIMC(imc);
                    
                    // Mostrar resultados
                    impresion.imprimirResultado(persona, imc, clasificacion);
                    break;
                    
                    
                default:
                    impresion.imprimirError("Opción no válida");
            }
            
        } while (opcion != 2);//Si la opcion es 1 no se cumple
        
        
    }
}