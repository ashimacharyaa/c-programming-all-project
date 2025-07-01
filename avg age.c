#include<stdio.h>
int main()
{
  int num[5],i,ocount=0,ecount=0;
  printf("enter5 number to get even and odd");
  for(i=0;i<5;i++)
  {
      scanf("%d",&num[i]);
  }
  for(i=0;i<5;i++)
  {
  if(num[i]%2==0){
        printf("%d is even number\n",num[i]);
    ecount++;
  }
  else{
      printf("% is odd number\n",num[i]);
        ocount++;
  }
  }
  printf("Total Even number =%d\n",ecount);
  printf("Total odd number=%d",ocount);
  return 0;

}
