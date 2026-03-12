#include <iostream>
using namespace std;

class Stats {
public:
static int sum(const int a[], int n) {
int total = 0;
for (int i = 0; i < n; i++) total += a[i];
return total;
}
static double average(const int a[], int n) {
return (double)sum(a, n) / n;
}
};
int main() {
// Array with fixed size (Unit 1: simple)
int grades[] = {80, 75, 90, 60, 95};
int n = sizeof(grades) / sizeof(grades[0]);
cout << "Sum: " << Stats::sum(grades, n) << "\n";
cout << "Average: " << Stats::average(grades, n) << "\n";
return 0;
}
