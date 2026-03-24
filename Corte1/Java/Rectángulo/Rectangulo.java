package rectangulo;

public class Rectangulo 
{
   public double base;
   public double altura;

    //constructores
    public Rectangulo(double b, double h) 
    {
        base = b;
        altura = h;
    }

    // metodos para calcular el área
    public double area() 
    {
        return base * altura;
    }

    public static void main(String[] args) 
    {
        Rectangulo r1 = new Rectangulo(2.0, 3.0);

        System.out.println("Base: " + r1.base);
        System.out.println("Altura: " + r1.altura);
        System.out.println("Area: " + r1.area());
    }
}