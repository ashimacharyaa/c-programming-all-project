#include <stdio.h>
int CalculatePower(int x, int y);
int main()
{
    int a,b,res,i;
    printf("Enter Base and Exponential:");
    scanf("%d%d",&a,&b);
    res= CalculatePower(a,b);
    printf("%d to the power of %d= %d\n",a,b,res);
    return 0;
}
CalculatePower(int x,int y)
{
    int i,res=1;
    for (i=1; i<=y; i++)
    {
        res=res * x;
    }
    return res;
}
