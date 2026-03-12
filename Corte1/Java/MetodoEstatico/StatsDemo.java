public class StatsDemo {
static class Stats {// clase 
public static int sum(int[] a) {//metodo
int total = 0;
for (int x : a) total += x; // enhanced for-loop. 
return total;
}
public static double average(int[] a) {
return (double) sum(a) / a.length;// obtener el numero de elementos que tiene un arreglo
}
}
public static void main(String[] args) {
int[] grades = {80, 75, 90, 60, 95};
System.out.println("Sum: " + Stats.sum(grades));//llama al metodo estatico sum
System.out.println("Average: " + Stats.average(grades));// llama al metodo estatico average(promedio)
}
}

