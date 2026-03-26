public class Persona {
    public String nombre;
    public int edad;
    
    public void saludar() {
        System.out.println("Hola, soy " + nombre + " y tengo " + edad + " años.");
    }
    
    public static void main(String[] args) {
        Persona p1 = new Persona();
        p1.nombre = "Maria Paula";
        p1.edad = 18;
        p1.saludar();
        
        Persona p2 = new Persona();
        p2.nombre = "Lina";
        p2.edad = 30;
        p2.saludar();
        
        Persona p3 = new Persona();
        p3.nombre = "Camilo";
        p3.edad = 19;
        p3.saludar();
    }
}
