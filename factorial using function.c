#include <stdio.h>
void calculateFactorialSeries(int n) {
    long long factorial = 1;
    printf("Factorial series up to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%d! = %lld\n", i, factorial);
    }
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Please enter a number greater than 0.\n");
    } else {
        calculateFactorialSeries(n);
    }
    return 0;
}
