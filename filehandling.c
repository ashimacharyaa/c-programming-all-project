#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int age,num=2,i;
    char name[100], address[10];

    fp = fopen("person.txt", "w");
    if(fp==NULL)
    {
        printf("File cannot be opened for writing\n");
        exit(0);
    }
    for (i = 0; i < 2;i++)
    {
        printf("Enter name age and address:");
        scanf("%s%d%s", name, &age, address);

        fprintf(fp,"%s %d %s\n", name, age, address);
    }
    return 0;
}
