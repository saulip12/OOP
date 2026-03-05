package arrays1;

import java.util.Scanner;

public class Arrays1 
{
    public int[] data;
    public int n;

    public Arrays1(int n) 
    {
        this.n = n;
        this.data = new int[n];   // Crear el arreglo
    }

    public void getvector(String name) 
    {
        System.out.print(name + " = [ ");
        for (int i = 0; i < n ; i++) 
        {
            System.out.print(data[i]);
            if (i < n - 1) 
            {
                System.out.print(" , ");
            }
        }
        System.out.println(" ]");
    }

    public void setvector(String name)
    {
        Scanner sc = new Scanner(System.in);
        
        for (int i = 0; i < n ; i++) 
        {
            System.out.print("v[" + i + "]: ");
            data[i] = sc.nextInt();
        }
    }
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Tamano n: ");
        int n = sc.nextInt();

        Arrays1 v = new Arrays1(n);
        v.setvector("myVector");
        v.getvector("myVector");

        sc.close();
    }
}