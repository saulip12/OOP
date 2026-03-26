// CLASE
class Producto {     
    // ATRIBUTOS
    public String nombre;
    public double precio;

    // CONSTRUCTOR por defecto (sin parámetros)
    public Producto() {
        nombre = "Sin nombre";
        precio = 0.0;
    }

    // CONSTRUCTOR con un parámetro
    public Producto(String nombre) {
        this.nombre = nombre;
        this.precio = 0.0;
    }

    // CONSTRUCTOR con dos parámetros (sobrecarga de constructores)
    public Producto(String nombre, double precio) {
        this.nombre = nombre;
        this.precio = precio;
    }

    // MÉTODO normal (de instancia)
    public void mostrar() {
        System.out.println("Nombre = " + nombre);
        System.out.println("Precio = " + precio);
    }
};  

public class MainProducto {
    public static void main(String[] args) {
        // OBJETOS (instancias de la clase Producto)
        // Cada uno usa un constructor diferente (sobrecarga)
        Producto p1 = new Producto();                    // Constructor por defecto
        Producto p2 = new Producto("Cuaderno");          // Constructor con 1 parámetro
        Producto p3 = new Producto("Lapiz", 2500.0);     // Constructor con 2 parámetros

        p1.mostrar();
        System.out.println();
        p2.mostrar();
        System.out.println();
        p3.mostrar();
    }
}
