// square root of sum of two numbers
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    result = round(sqrt(a + b));
    printf("The rounded square root of the sum is: %.0f\n", result);
    return 0;
}
