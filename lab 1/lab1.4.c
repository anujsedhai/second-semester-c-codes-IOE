#include<stdio.h>
#include<string.h>
#include<windows.h>
#define NoOfStudents 3
typedef struct
{
    char name [20];
    int roll;
    char address[30];
    long int number;
} std;
void sort(std *temp);
int main ()
{
    std bct[NoOfStudents];
    FILE *f;
    f=fopen("data.txt","w");
    int i;
    for(i=0;i<NoOfStudents;i++)
    {
        printf("Enter your name:\t");
        scanf(" %[^\n]s",bct[i].name);
        printf("\nEnter your address:\t");
        scanf(" %[^\n]s",bct[i].address);
        printf("\nEnter your roll number:\t");
        scanf("%d",&bct[i].roll);
        printf("\nEnter your phone number:\t");
        scanf("%ld",&bct[i].number);
    }
        fwrite(bct,sizeof(bct),1,f);
    fclose(f);
    f=fopen("data.txt","r");
    fread(&bct,sizeof(bct),1,f);
    fclose(f);
    sort(bct);
    system("cls");
    for (i=0;i<NoOfStudents;i++)
    {
        printf("%s\n",bct[i].name);
        printf("%s\n",bct[i].address);
        printf("%d\n",bct[i].roll);
        printf("%ld\n\n",bct[i].number);

    }



}

void sort(std *temp)
{
    std t;

    for (int i=0;i<NoOfStudents-1;i++)
    {
        for (int j=i+1;j<NoOfStudents;j++)
        {
            if(strcmp(temp[i].name,temp[j].name)>0)
            {
                t=temp[i];
                temp[i]=temp[j];
                temp[j]=t;

            }
        }
    }
}
