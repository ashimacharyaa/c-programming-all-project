#include <stdio.h>

// Input module
int getInput() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    while (num < 0) {
        printf("Please enter a non-negative integer: ");
        scanf("%d", &num);
    }
    return num;
}

// Calculation module
unsigned long long calculateFactorial(int n) {
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

// Output module
void displayResult(int n, unsigned long long result) {
    printf("Factorial of %d is %llu\n", n, result);
}

// Main function
int main() {
    int number = getInput();
    unsigned long long result = calculateFactorial(number);
    displayResult(number, result);
    return 0;
}
