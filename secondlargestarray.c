#include<stdio.h>
#include<conio.h>
int main()
{
int arr[100];
int i,n,max,min;
printf("Enter number of elements");
scanf("%d",&n);
printf("Enter %d elements:",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
if(arr[i]>max){
        max=arr[i];
}
if (arr[i]<min){
    min=arr[i];
}
printf(Maximum number is: %d",max);
printf(Minimum number is: %d",min);
return 0;
}


