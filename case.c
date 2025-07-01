#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("record.txt", "w");
    if(fp==NULL)
    {
        printf("file cannnot be opened for write ops.\n");
        exit(0);
    }
    else
    {
        printf("file available for write operation");
    }
    return 0;
}
