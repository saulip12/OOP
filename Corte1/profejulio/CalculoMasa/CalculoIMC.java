public class CalculoIMC {
    
    public double calcularIMC(Persona persona) {
        double peso = persona.getPeso();
        double altura = persona.getAltura();
        
        if (altura > 0) {
            return peso / (altura * altura);
        } else {
            return 0;
        }
    }
    
    public String clasificarIMC(double imc) {
        if (imc < 18.5) {
            return "Bajo peso";
        } else if (imc >= 18.5 && imc < 25) {
            return "Peso normal";
        } else if (imc >= 25 && imc < 30) {
            return "Sobrepeso";
        } else {
            return "Obesidad";
        }
    }
}