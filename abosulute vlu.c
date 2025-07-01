#include <stdio.h>

int main() {
    int num, abvalue;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num < 0) {
        abvalue = -num;
    } else {
        abvalue = num;
    }
    printf("Absolute value: %d\n", abvalue);
    return 0;
}
