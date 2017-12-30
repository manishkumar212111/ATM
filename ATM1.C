#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<dos.h>
void atm_database_update();
void update_bank_database();
void atm_database_update1();
long int account_no,password,new_pin;
long int bal1,n,nu,bal,allowed_balance,new_balance,bal2,n1,bal3,account_no2;
long int transaction_id,transaction;
int tm_mgsec,tm_sec,tm_min,tm_hour;
long int account_no1,money;
char datestr[9];
char name[20],status[20];
void login();
//Fund Transfer
void fund_transfer()
{
	FILE *p;
	int res=0;
	long int new_balance1;
	//strcpy(status,"transfer");
	printf("Enter Account No of reciever::");
	scanf("%ld",&account_no1);
	printf("\nEnter Amount::");
	scanf("%ld",&money);
	new_balance=bal-money;
	//new_balance1=bal+money;
	if(bal<money)
		{
			printf("\nYou don't have sufficient ballnce to transfer\n");
		}
		else
		{
	p=fopen("bank_database.txt","r");
	while(fscanf(p,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
	{
		if(account_no1==n)
		{
		new_balance1=bal+money;
		bal3=money;
		atm_database_update1();
		fclose(p);
		update_bank_database();
		new_balance=new_balance1;
		account_no=account_no1;
		update_bank_database();
		printf("\nmoney transferred");
		res=1;
		break;
		//getch();
	      }
	}
	if(res!=1)
	{
	printf("account not found\n");
	}
	}

	fclose(p);
	getch();
}
//pin change
void pin_change()
{
	FILE *fp,*fp1,*fp2;
	fp2=fopen("temp.txt","a");
	fp=fopen("bank_database.txt","r");
	printf("Enter new pin no\n");
	scanf("%ld",&new_pin);
	while(fscanf(fp,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
	{
		if(account_no==n && password==nu)
		{
			fprintf(fp2,"%ld %s %ld %ld %ld\n",n,name,new_pin,bal,allowed_balance);
		}
		else
		{
			fprintf(fp2,"%ld %s %ld %ld %ld\n",n,name,nu,bal,allowed_balance);
		}
	}
	fclose(fp);
	fclose(fp2);
	fp=fopen("bank_database.txt","w");
	fclose(fp);

	fp=fopen("bank_database.txt","a");
	fp2=fopen("temp.txt","r");
	while(fscanf(fp2,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
	{
//fscanf(fp1,"%s %s\n",name,roll);
		fprintf(fp,"%ld %s %ld %ld %ld\n",n,name,nu,bal,allowed_balance);
	}
	fclose(fp);
	fclose(fp2);
	fp2=fopen("temp.txt","w");
	fclose(fp2);
	printf("\nPin Changed");
	getch();

}
// Mini Statement
void mini_statement()
{
	FILE *fp;
	fp=fopen("atm_database.txt","r");
	printf("transaction_id\tRupees\tTime\tDate\tStatus\n");
	while(fscanf(fp,"%ld %ld %ld %d:%d:%d %s %s\n",&n1,&account_no2,&bal2,&tm_hour,&tm_min,&tm_sec,datestr,status)!=EOF)
	{

		 if(account_no==account_no2)
	{
		 printf("%ld\t\t%ld\t%d:%d\t%s\t%s",n1,bal2,tm_hour,tm_min,datestr,status);
		  printf("\n");
	}
	}
	fclose(fp);
	getch();
}

void random1()
{
	FILE *fp1;
	//int c; int n2;
	int res,c,n2,found=0;
	/*	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	 */
	fp1=fopen("atm_database.txt","r");

	for (c = 1; c <=1; c++)
	 {
	n2 = rand() % 10000 + 1;
	 }
	 n1=n2;
	  while(fscanf(fp1,"%ld %ld %ld %d:%d:%d %s %s\n",&n1,&account_no2,&bal2,&tm_hour,&tm_min,&tm_sec,datestr,status)!=EOF)
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
     transaction_id=n1+10000;
   }

    fclose(fp1);
 //   return n1;
}
// to update fund transfer
void atm_database_update1()
{
	FILE *fp;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
    char datestr[9];
    random1();

    _strdate(datestr);
	//struct date d;

	  strcpy(status,"transfer");
	fp=fopen("atm_database.txt","a");

	fprintf(fp,"%ld %ld %ld %d:%d:%d %s %s\n",transaction_id,account_no,bal3,tm.tm_hour,tm.tm_min,tm.tm_sec,datestr,status);
	fclose(fp);

}
void atm_database_update()
{
	FILE *fp;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
    char datestr[9];
    random1();

    _strdate(datestr);
	//struct date d;


	fp=fopen("atm_database.txt","a");

	fprintf(fp,"%ld %ld %ld %d:%d:%d %s %s\n",transaction_id,account_no,bal3,tm.tm_hour,tm.tm_min,tm.tm_sec,datestr,status);
	fclose(fp);

}
//Update bank database
void update_bank_database()
{
	FILE *fp,*fp1,*fp2;
	fp2=fopen("temp.txt","a");
	fp=fopen("bank_database.txt","r");
	while(fscanf(fp,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
	{
		if(account_no==n)
		{
		fprintf(fp2,"%ld %s %ld %ld %ld\n",n,name,nu,new_balance,allowed_balance);
		}
		else
		{
			fprintf(fp2,"%ld %s %ld %ld %ld\n",n,name,nu,bal,allowed_balance);
		}
	}
	fclose(fp);
	fclose(fp2);
	fp=fopen("bank_database.txt","w");
	fclose(fp);

	fp=fopen("bank_database.txt","a");
	fp2=fopen("temp.txt","r");
	while(fscanf(fp2,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
	{
		//fscanf(fp1,"%s %s\n",name,roll);
		fprintf(fp,"%ld %s %ld %ld %ld\n",n,name,nu,bal,allowed_balance);
	}
	fclose(fp);
	fclose(fp2);
	fp2=fopen("temp.txt","w");
	fclose(fp2);
	}

void cash_withdraw()
{
	long int sum=0,c=0;
	long int account_no1;
	int res;

	FILE *fp3;
	char str[9];
	strcpy(status,"cash");
	_strdate(str);
	fp3=fopen("atm_database.txt","r");
	printf("Enter Amount :: ");
	scanf("%ld",&bal3);
	while(fscanf(fp3,"%ld %ld %ld %d:%d:%d %s %s\n",&n1,&account_no1,&bal2,&tm_hour,&tm_min,&tm_sec,datestr,status)!=EOF)
	{
	 res=strcmp(str,datestr);

	 if(res==0 && account_no==account_no1)
	 {
	 c=1;
	 sum=sum+bal2;

	 }
	}
	sum=allowed_balance-sum;
	fclose(fp3);
	if(bal3>bal)
	{
		printf("\nYou have insufficient balance in your account");
	}
	else if(bal3>allowed_balance)
	{
		printf("\nYou are not allowed to take this amount");
	}
	else if(bal3>sum && c==1)
	{
	printf("you have crossed daily limit\n");
	}
	else
	{

		new_balance=bal-bal3;
		printf("\nPlease collect your cash\n");
		printf("Available balance is Rs %ld",bal-bal3);
		printf("\n\t\tTHANK YOU");
		update_bank_database();
		atm_database_update();
	}
	getch();

}
//get balance
void get_balance()
{
	printf("Current Balance is RS %ld.%d",bal1,000);
	printf("\n\n\t\tThank You\n");
	getch();
}
// login success
void login_success()
{
	int n;
	char ch;
	//system("cls");
	printf("\n\n\t\t\tWelcome %s\n\n",name);
	printf("\n\t\tSelect operation\n");
	printf("\t\tPress<1> Get Balance\n");
	printf("\t\tPress<2> Mini Statement\n");
	printf("\t\tPress<3> withdraw cash\n");
	printf("\t\tPress<4> Pin change \n");
	printf("\t\tPress<5>To fund transfer\n");
	printf("\t\tPress<6> Cancel\n");
	printf("\t\tPress<7> To Exit\n");
	printf("\t\tYour Choice:: ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			get_balance();
			break;
		case 2:
			mini_statement();
			break;
		case 3:
			cash_withdraw();
			break;
		case 4:
			pin_change();
			break;
		case 5:
			fund_transfer();
			break;
		case 6:
			login();
			break;
		case 7:
			exit (0);
		default:
			printf("Please choose correct option");
		}


	login();

}
//login
void login()
{
	int res=0;

	FILE *fp1;
	system("cls");
		 printf("\n\n\n\n\n\n\t\t\t\n");
	 printf("\t\t\t\tWELCOME TO\n\n");

	printf("\t\t\t    SATE BANK OF INDIA  \n");
	printf("\n\n\n");

	printf("\n\n\n\n\t\t\t\t\t\tCreated By MANISH KUMAR");
	printf("\nPress Enter to continue");
	getch();
	clrscr();
		A:
	fp1=fopen("bank_database.txt","r");

	clrscr();
	printf("\t\tEnter Account no:: ");
	scanf("%ld",&account_no);
	printf("\n\t\tEnter password::");
	scanf("%ld",&password);
	 while(fscanf(fp1,"%ld %s %ld %ld %ld\n",&n,name,&nu,&bal,&allowed_balance)!=EOF)
    {

     if(account_no==n && password==nu)
     {
	res=1;

	bal1=bal;
	fclose(fp1);
	login_success();

	break;
	 }
	}
	if(res!=1)
	{
		printf("\nAccount does not match\n\n");

		printf("\nPress ENTER to continue");
		 getch();
		fclose(fp1);
		goto A;
	       //	login();

	}


}
int main()
{
printf("hiii");
textcolor(6);
textbackground(10);

    login();
	getch();
	return 0;
}

