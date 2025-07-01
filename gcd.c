
#include <stdio.h>
int calculateGCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return calculateGCD(b, a % b);
}
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0) {
        printf("GCD is not defined for both numbers being zero.\n");
    } else {
        int gcd = calculateGCD(a, b);
        printf("GCD of %d and %d is: %d\n", a, b, gcd);
    }
    return 0;
}
