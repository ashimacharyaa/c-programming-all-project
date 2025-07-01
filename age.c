#include<stdio.h>
int main()
{
int n;
printf("Enter Your Age:");
scanf("%d",&n);
if(n>=18){
printf("Since Your age is %d. You are elligible to vote",n);
}
else{
printf("Since your age is %d. You are not elligible to vote",n);
}
return 0;
}
