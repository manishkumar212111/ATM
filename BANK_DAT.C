#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

long int  n,atm_pin,bal,allowed_balance;
 long int num,no,c,no1,n1,nu;
 int n2,n3;
char name[20];

void random1()
{
FILE *fp1;
//int c;
int res,found=0;
fp1=fopen("bank_database.txt","r");

  for (c = 1; c <=1; c++)
  {
    n2 = rand() % 10000 + 1;
    }
    n1=n2;
    while(fscanf(fp1,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
    {

     if((n1+10000)==n)
     {
     found=1;

    fclose(fp1);
   random1();
     break;
     }
     }
     if(found!=1)
     {
     n=n1+10000;
   }

    fclose(fp1);
 //   return n1;
}

void main()
{
FILE *fp;
clrscr();
random1();
fp=fopen("bank_database.txt","a");

printf("Enter customer name::");
scanf("%s",name);
printf("\nEnter Balance::");
scanf("%ld",&bal);
printf("\nEnter max allowed balance::");
scanf("%ld",&allowed_balance);

printf("\nAccout Opened Successfully");

//n=n+10000;
 for (c = 1; c <=1; c++)
  {
    n3 = rand() % 1000 + 1;
    }
    n3=n3+1000;
    nu=n3;
printf("\nAccount NO:: %ld",n);
printf("\nATM pin:: %ld",nu);

fprintf(fp,"%ld %s %ld %ld %ld\n",n,name,nu,bal,allowed_balance);

fclose(fp);
getch();
}
/*int main()
{
open();
getch();
return 0;
} */
