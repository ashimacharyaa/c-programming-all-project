#include<stdio.h>
//function defination
void multiply(int a,int b)
{
    int product;
    product=a*b;
    printf("\nresult=%d\n",product);
}
int main()
{
    int num1,num2,product;
    printf("enter two number");
    scanf("%d%d",&num1,&num2);

    multiply(num1,num2);//function call
    return 0;
}
