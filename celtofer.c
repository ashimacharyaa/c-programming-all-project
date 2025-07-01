// Write a C program that prompts the user for a positive integer and calculates the factorial of that number using a while loop
#include<stdio.h>
int main()
{

    int num,i=1,fact=1;
    printf("Enter a number for which you want to find factorial");
    scanf("%d",&num);
    while(i<=num){
    fact=fact*i;
    }
        i++;
    printf("Factoril=%d",fact);
    return 0;
}
