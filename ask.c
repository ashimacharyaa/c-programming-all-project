
#include <stdio.h>
int main() {
int num,i,j,arr[100],temp;
printf("Enter How Many Integer: ");
scanf("%d", &num);

printf("Enter %d integer",num);
for(i=0;i<num;i++){
    scanf("%d",&arr[i]);
}
 for(i=0;i<num-1;i++){
    for(j=0;j<num-i-1;j++){
        if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
    }
 }
 }
 printf("Values after sorted");
for(i=0;i<num;i++){
    printf("%d",arr[i]);
}
return 0;
}
