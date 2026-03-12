public class StatsDemo {
static class Stats {
public static int sum(int[] a) {
int total = 0;
for (int x : a) total += x; // enhanced for-loop
return total;
}
public static double average(int[] a) {
return (double) sum(a) / a.length;
}
}
public static void main(String[] args) {
int[] grades = {80, 75, 90, 60, 95};
System.out.println("Sum: " + Stats.sum(grades));
System.out.println("Average: " + Stats.average(grades));
}
}
