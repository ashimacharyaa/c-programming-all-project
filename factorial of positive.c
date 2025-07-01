#include<stdio.h>
int main()
{
int num,i=1, fact=1;
printf("Enter a positive Integer:");
scanf("%d",&num);
 if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
}
while (i <= num)
{
        fact *= i;
        i++;
    }
    printf("Factorial of %d = %d\n", num, fact);
return 0;
}
