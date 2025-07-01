#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[50];
    int roll;
    float marks;
};
int main(){
struct student s[5];
FILE*fp;
int i;
for(i=0;i<5;i++){
printf("Enter Name:");
scanf("%s",s[i].name);
printf("Enter Roll Number:");
scanf("%d",&s[i].roll);
printf("Enter Marks:");
scanf("%d",&s[i].marks);
}

fp=fopen("student.txt","w");
if(fp==NULL){
    printf("Invalid Input. Please enter valid output:");
    return 1;
}

fprintf(fp,"Displaying Name\t Roll Number\t Marks\t");
fprintf(fp,"===========================");
for (i=0;i<5;i++){
    fprintf(fp,"%s\t %d\t %f\t",s[i].name,s[i].roll,s[i].marks);
}
fclose(fp);

fp=fopen("student.txt","r");
if(fp==NULL){
    printf("Invalid Input. Please enter valid output:");
    return 1;
}
char ch;
printf("\n Content of student.txt: \n");
while(( ch=fgetc (fp)) !=EOF ){
    putchar (ch);
}
fclose(fp);
return 0;
}



