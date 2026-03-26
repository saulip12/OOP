// CLASE
class Persona {     
    // ATRIBUTOS
    public String nombre;
    public int edad;

    // MÉTODO normal (de instancia)
    public void mostrar() {
        System.out.println("Nombre = " + nombre);
        System.out.println("Edad = " + edad);
    }
};  

// CLASE PRINCIPAL (contiene el método main)
public class MainPersona {
    public static void main(String[] args) {
        // OBJETOS (instancias de la clase Persona)
        Persona p1 = new Persona();
        Persona p2 = new Persona();

        p1.nombre = "Ana";
        p1.edad = 20;

        p2.nombre = "Luis";
        p2.edad = 22;

        System.out.println("Objeto 1:");
        p1.mostrar();

        System.out.println("\nObjeto 2:");
        p2.mostrar();
    }
}
