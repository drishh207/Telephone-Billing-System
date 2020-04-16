#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
struct subscriber
{
char username[100];
char pass[100];
float amount;
char phonenumber[10];
}s;
struct admin
{
    char username[100];
    char pass[100];
}a;
struct plan
{
    char amount[10];
    char plan[10000];
}pa;
void choice();
void ulogin();
void alogin();
void addrecords();
void listrecords();
void deleterecords();
void payment();
void userlogin();
void disp();
void disp1();
void adminlogin();
void adminreg();
void searchrecords();
void modrecords();
void choiceplans();
void addplans();
void delplans();
void extractplan();
void extractplan1();
main()
{
	printf("\n\n\n\n\n\n\n**************************************************************");
	printf("\n\t\t------WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM-------");
	printf("\n\t\t****************************************************************");
    getch();
    system("cls");
    choice();
}
void choice()
{
	system("cls");
    int i;
    char ch;
    while(1)
    {
         printf("\n\n\t\t\t\t LOGIN PAGE\n");
     printf("    ");
    for(i=0;i<79;i++)
        printf("-");
          printf("\n\n");
        printf("\t\t\tEnter \n\t\t\t\tU: Login as User \n \t\t\t\tA: Login as Admin\n \t\t\t\tE: Exit\n");
        printf("\t\t\t");
        ch=getche();
        ch=toupper(ch);
		fflush(stdin);
        switch(ch)
        {
            case 'U': system("cls");ulogin();break;
            case 'A': system("cls");alogin();break;
            case 'E': system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\t\t\tFOR USING OUR SERVICE");
                exit(0);
				break;
            default:system("cls");
				printf("\n\n\t\t\t\tIncorrect Input");
				printf("\n\n\t\t\t\t\t\t\tAny key to continue");
				getch();
				break;
        }
    }
    getch();
    system("cls");
}
void alogin()
{
	char ch;
    int i;
    while(1)
    {
         printf("\n\n\t\t\t\t ADMIN LOGIN PAGE\n");
     printf("    ");
    for(i=0;i<79;i++)
        printf("-");
          printf("\n\n");
        printf("\t\t\tEnter \n\t\t\t  L: Administrator Login \n\t\t\t  R: New Administrator Registration \n\t\t\t  E: Exit\n");
        printf("\t\t\t");
        ch=getche();
        ch=toupper(ch);
        fflush(stdin);
        switch(ch)
        {
           case 'L': system("cls");adminlogin();break;
           case 'R': system("cls");adminreg();break;
           case 'E': system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\t\t\tFOR USING OUR SERVICE");
				exit(0);
				break;
            default:system("cls");
				printf("\n\n\t\t\t\t\tIncorrect Input");
				printf("\n\n\t\t\t\t\t\t\t\tAny key to continue");
				getch();
        }
    }
    getch();
    system("cls");
}
void ulogin()
{
	char ch;
    int i;
   while (1)
	{
	     printf("\n\n\t\t\t\t USER LOGIN PAGE\n");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
	    printf("\n\n");
	    printf("\t\t\tEnter\n\t\t\t  U: User login \n\t\t\t  R: Registration as new user\n\t\t\t  E: for Exit\n");
	    printf("\t\t\t");
	   ch=getche();
       ch=toupper(ch);
       fflush(stdin);
       switch(ch)
	    {
	        case 'U':system("cls");userlogin(); break;
	        case 'R':system("cls"); addrecords();break;
	        case 'E':
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\t\t\tFOR USING OUR SERVICE");
				exit(0);
				break;
	        default: system("cls");
				printf("\n\n\t\t\t\tIncorrect Input");
				printf("\n\n\t\t\t\t\t\tAny key to continue");
				getch();
	    }
	    system("cls");
    }
    getch();
    system("cls");
}
void userlogin()
{
	 int i;
    printf("\n\t\t\t\t    USER LOGIN\n\t");
    for(i=0;i<79;i++)
        printf("-");
   FILE *f;
    char name[100];
    char pass[100];
    printf("\n\n\t\t Enter username: ");
    scanf("%s",&name);
    printf("\n\t\tEnter Password: ");
    scanf("%s",&pass);
    long int recsize=sizeof(s);
    f=fopen("records.txt","rb+");
    if(f==NULL)
        exit(0);
    system("cls");
    while(fread(&s,recsize,1,f)==1)
    {
        if(strcmp(s.username,name)==0)
        {
            if(strcmp(s.pass,pass)==0)
            {
            fseek(f,recsize,SEEK_CUR);
             Sleep(2000);
            printf("\n\n\t\t\tSuccessfully signed in!!");
             Sleep(2000);
            system("cls");
            disp();
            break;
            }
        }
    }
     if (feof(f)) {
            printf("\n\n\n\t\t\tThe username or password entered is wrong. Please try again");
            system("cls");
            ulogin();
            system("cls");
        }
        system("cls");
}
void adminlogin()
{
	int i;
    printf("\n\t\t\t\t  ADMINISTRATOR LOGIN\n\t");
    for(i=0;i<79;i++)
        printf("-");
   FILE *f;
    char name[100];
    char pass[100];
    printf("\n\n\t\t Enter admin username: ");
    scanf("%s",&name);
    printf("\n\t\tEnter admin Password: ");
    scanf("%s",&pass);
    long int recsize=sizeof(a);
    f=fopen("admin.txt","rb+");
    if(f==NULL)
        exit(0);
    system("cls");
    while(fread(&a,recsize,1,f))
    {
        if(strcmp(a.username,name)==0)
        {
            if(strcmp(a.pass,pass)==0)
            {
            fseek(f,recsize,SEEK_CUR);
            printf("Successfully signed in!!");
            Sleep(2000);
            system("cls");
            disp1();
            break;
            }
        }
    }
     if (feof(f)) {
            printf("\n\n\n\t\t\tThe username or password entered is wrong. Please try again");
            Sleep(2000);
            system("cls");
            alogin();
            system("cls");
        }
 }
 void addrecords()
 {
 	int i;
    printf("\n\t\t\t\tREGISTER AS NEW USER\n");
    for(i=0;i<79;i++)
        printf("-");
   FILE *f;
	char test;
	f=fopen("records.txt","ab+");
	if(f==0)
	{   f=fopen("records.txt","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/n press any key to continue");
		getch();
	}
	     system("cls");
		printf("\n\t\t\t Enter phone number:");
		printf( "\t");
		scanf("%s",&s.phonenumber);
		printf("\n\t\t\t Enter username:");
		fflush(stdin);
		printf("\t");
		scanf("%s",&s.username);
		printf("\n\t\t\t Enter Password:");
		printf("\t");
		scanf("%s",&s.pass);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("\n\t\t1 record successfully added");
		fclose(f);
		system("cls");
		ulogin();
 }
 void adminreg()
 {
 	int j;
    printf("\n\t\t\t\tADMINISTRATOR REGISTRATION\n");
    for(j=0;j<79;j++)
        printf("-");
    FILE *f;
	f=fopen("admin.txt","ab+");
	if(f==0)
	{
	    f=fopen("admin.txt","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/n press any key to continue");
		getch();
	}
        printf("\n\t\t Enter username:  ");
		fflush(stdin);
		scanf("%s",&a.username);
		printf("\n\t\t Enter Password:  ");
		scanf("%s",&a.pass);
		fwrite(&a,sizeof(a),1,f);
		fflush(stdin);
		system("cls");
		printf("\n\n\nt\t\t\t1 record successfully added");
		fclose(f);
		system("cls");
		alogin();
 }
 void disp()
 {
 	  int j;
    printf("\n\t\t\t\tUSER ACCOUNT\n");
    for(j=0;j<79;j++)
        printf("-");
    char ch;
    printf("\n\t\t\tEnter \n\t\t\t D: Viewing your own data \n\t\t\t P: payment \n\t\t\t M: Modify Phone number on same username\n\t\t\t L: logout from account\n");
    fflush(stdin);
    printf("\n\t\t\t");
    ch=getche();
    ch=toupper(ch);
    switch(ch)
    {
        case 'D': system("cls"); listrecords();break;
        case 'P': system("cls"); payment();break;
        case 'M': system("cls"); modrecords(); break;
        case 'L': system("cls");
                       Sleep(2000);
				       choice();
        default: system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
				system("cls");
				disp();
    }
    system("cls");
 }
 void disp1()
 {
 	int j;
    printf("\n\t\t\t\tADMIN ACCOUNT\n");
    for(j=0;j<79;j++)
        printf("-");
     char ch;
    printf("\n\t\t\tEnter \n\t\t\t V: Viewing all Users \n\t\t\t D: Deleting records\n\t\t\t M: Modifying Plans \n\t\t\t L: Logout from account\n ");
    fflush(stdin);
    ch=getche();
    ch=toupper(ch);
    switch(ch)
    {
        case 'D': system("cls"); deleterecords(); break;
        case 'V': system("cls");searchrecords();break;
        case 'M':system("cls");choiceplans();break;
        case 'L':system("cls");
				choice();
        default:system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
				system("cls");
				disp1();
  }
  system("cls");
 }
 void listrecords()
 {
 	int j;
    printf("\n\t\t\t\tUSER INFORMATION\n");
    for(j=0;j<79;j++)
        printf("-");
	FILE *f;
	int i;
        char name[100];
        printf("\nEnter username\t");
        scanf("%s",&name);
        long int recsize=sizeof(s);
        f=fopen("records.txt","rb+");
        if(f==NULL)
		exit(0);
	   system("cls");
	   printf("Phone Number\t\tUser Name\t\t\tAmount\n");
	   for(i=0;i<79;i++)
		printf("-");
	   while(fread(&s,recsize,1,f)==1)
	   {
            if(strcmp(s.username,name)==0)
              {
                  fseek(f,sizeof(s),SEEK_CUR);
		          printf("\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.username,s.amount);
              }
	   }
    printf("\n");
	for(i=0;i<79;i++)
		printf("-");
fclose(f);
getch();
system("cls");
disp();
 }
 void modrecords()
 {
 	int i;
     char phone[11];
    printf("\t\t\t\t\tCHANGE PHONE NUMBER\n");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
    printf("\n\n\n");
    printf("\t\tEnter phone number to be modified:  ");
    gets(phone);
    FILE *f;
    long int recsize=sizeof(s);
    f=fopen("records.txt","rb+");
    if(f==NULL){
        system("cls");
		printf("please wait while we configure your computer");
		printf("/n press any key to continue");
		getch();
    }
    rewind(f);
    while(fread(&s,recsize,1,f)==1)
    {
        if(strcmp(s.phonenumber,phone)==0)
        {
            system("cls");
            printf("\n\n\tEnter new phonenumber:  ");
            s.amount=0;
            scanf("%s",&s.phonenumber);
            fseek(f,ftell(f)-recsize,0);
            fwrite(&s,recsize,1,f);
            break;
        }
    }
    system("cls");
    printf("\n\n\t\t The Record has been successfully modified.");
    fclose(f);
    system("cls");
    disp();
 }
 void deleterecords()
 {
 	FILE *f,*t;
 	int j;
    printf("\n\t\t\t\tDELETING A USER\n");
    for(j=0;j<79;j++)
        printf("-");
    int i,status;
	char ch[100];
	char phonenumber[20];
	t=fopen("delete.txt","w+");
	if(t==NULL)
	exit(0);
	f=fopen("records.txt","rb+");
	if(f==NULL)
	exit(0);
	long int recsize=sizeof(s);
	printf("\n\n\t\t Enter the phone number to be deleted from the Database: ");
    fflush(stdin);
	gets(phonenumber);
	rewind(f);
	while(fread(&s,recsize,1,f)==1)
         {
           if(strcmp(s.phonenumber,phonenumber)!=0)
            fwrite(&s,recsize,1,t);
        }
        fclose(f);
        fclose(t);
        remove("records.txt");
        rename("delete.txt","records.txt");
        printf("\n\n\t\t\tThe phonenumber %s is removed successfully\n",phonenumber);
        Sleep(2000);
        system("cls");
        disp1();
 }
 void searchrecords()
 {
 	int i;
    printf("\t\t\t\t\tLIST OF ALL USERS\n");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
    printf("\n\n");
    printf("\tPhone Number\t\tUser Name\t\t\tAmount\n");
	   for(i=0;i<79;i++)
		printf("-");
		printf("\t");
    FILE *f;
    long int recsize=sizeof(s);
    f=fopen("records.txt","rb+");
    if(f==NULL){
        system("cls");
		printf("please wait while we configure your computer");
		printf("/n press any key to continue");
		getch();
    }
    rewind(f);
    while(fread(&s,recsize,1,f)==1)
    {
        fseek(f,recsize,SEEK_CUR);
         printf("\n\t%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.username,s.amount);
    }
        printf("\n");
	for(i=0;i<79;i++)
		printf("-");
fclose(f);
getch();
system("cls");
disp1();
 }
 void choiceplans()
 {
 	 int i;
    char ch;
    printf("\n\t\t\t\tMODIFYING PLANS\n");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
    printf("\n\n");
     printf("\t\t\tEnter \n\t\t\t  A: Adding a new plan \n\t\t\t  D: Deleting a plan \n\t\t\t  L: List all plans \n\t\t\t  E: Exit\n");
        printf("\t\t\t");
        ch=getche();
        ch=toupper(ch);
        fflush(stdin);
        switch(ch)
        {
            case 'A': system("cls"); addplans();break;
            case 'D': system("cls"); delplans();break;
            case 'L': system("cls"); extractplan1();break;
            case 'E':
				system("cls");
				//printf("\n\n\t\t\t\tTHANK YOU");
				//printf("\n\n\t\t\tFOR USING OUR SERVICE");
				system("cls");
				disp1();
				break;
	        default: system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
        }
        system("cls");
 }
 void addplans()
 {
 	FILE *f;
    int i;
    printf("\n\t\t\t\tADD A NEW PLAN\n ");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
    printf("\n\n");
    f=fopen("plan.txt","ab+");
	if(f==0)
	{   f=fopen("plan.txt","wb+");
		system("cls");
		printf("\n\n\t\t\t\tplease wait while we configure your computer\n");
		printf("\n\n\n\t\t\t\t\t\t press any key to continue");
		getch();
	}
	     system("cls");
		printf("\n\t\tEnter amount:\t");
		printf( "\t");
		gets(pa.amount);
		printf("\n\t\tEnter plan:\t");
		fflush(stdin);
		printf("\t");
		gets(pa.plan);
		fwrite(&pa,sizeof(pa),1,f);
		fflush(stdin);
		system("cls");
		printf("\n\n\n\t\t\t1 record successfully added!!\n");
		Sleep(2000);
		fclose(f);
		system("cls");
		choiceplans();
 }
 void delplans()
 {
 	FILE *f,*t;
 	int j;
    printf("\n\t\t\t\tDELETING A PLAN\n");
    for(j=0;j<79;j++)
        printf("-");
    int i,status;
	char ch[100];
	char amt[7];
	t=fopen("deletep.txt","wb+");
	if(t==NULL)
	exit(0);
	f=fopen("plan.txt","rb+");
	if(f==NULL)
	exit(0);
	long int recsize=sizeof(pa);
	printf("\n\n\t\t Enter the amount of the plan to be deleted from the Database: ");
    fflush(stdin);
	gets(amt);
	rewind(f);
	while(fread(&pa,recsize,1,f)==1)
         {
           if(strcmp(pa.amount,amt)!=0)
            fwrite(&pa,recsize,1,t);
        }
        fclose(f);
        fclose(t);
        remove("plan.txt");
        rename("deletep.txt","plan.txt");
        printf("\n\n\t\t\tThe plan with amount %s is removed successfully\n",amt);
        Sleep(2000);
        system("cls");
        choiceplans();
 }
 void extractplan1()
 {
 	 FILE *f;
    long int recsize=sizeof(pa);
    f=fopen("plan.txt","rb+");
	if(f==NULL)
		exit(0);
	system("cls");
    int i;
    printf("\n\t\t\t\tPLANS AVAILABE\n");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
	    printf("\n\n");
	    printf("\t\t       AMOUNT \t\t\t PLAN");
     rewind(f);
	while(fread(&pa,recsize,1,f)==1)
    {
         //fseek(f,recsize,SEEK_CUR);
         printf("\n\t\t\t%-10s\t\t%-20s\t\t",pa.amount,pa.plan);
    }
    if(getch())
    {
    system("cls");
    choiceplans();
    }
 }
 void payment()
 {
 	 int j;
    printf("\n\t\t\t\t PAYMENT OF PRE-PAID PLAN\n\t\t\t");
    for(j=0;j<79;j++)
        printf("-");
	FILE *f;
	char phonenumber[20];
	long int recsize=sizeof(s); 
	float amt;
	int i;
	f=fopen("records.txt","rb+");
	if(f==NULL)
		exit(0);
	system("cls");
	printf("\n\t\t\t\tPAYMENT OF PRE-PAID PLAN\n\t");
    for(j=0;j<79;j++)
        printf("-");
	printf("\n\n\n\t\t\tEnter phone number of the subscriber for payment:  ");
	scanf("%s",phonenumber);
	fflush(stdin);
	while(fread(&s,recsize,1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
		    printf("\n\t\t\t\t\t\t\t\tPAYMENT OF PRE-PAID PLAN\n\t\t\t");
		    for(j=0;j<79;j++)
		    printf("\t\t");
            printf("-");
			system("cls");
			printf("\n\t\t\t Phone No.: %s",s.phonenumber);
		    printf("\n\t\t\t Name: %s",s.username);
			printf("\n\t\t\t Current amount: %f",s.amount);
			printf("\n\n");
			for(i=0;i<79;i++)
				printf("-");
            extractplan();
            printf("\n\n\t\t\tEnter amount of payment:  ");
			fflush(stdin);
			scanf(" %f",&s.amount);
			fseek(f,-recsize,SEEK_CUR);
			fwrite(&s,recsize,1,f);
			break;
		}
	}
	system("cls");
	printf("\n\n\n\t   THANK YOU %s FOR YOUR TIMELY PAYMENTS",s.username);
	getch();
	fclose(f);
	system("cls");
	disp();
 }
 void extractplan()
{
     FILE *t;
    long int recsize=sizeof(pa);
    t=fopen("plan.txt","rb+");
	if(t==NULL)
		exit(0);
     int i;
    printf("\n\t\t\t\tPLANS AVAILABE\n");
    printf("    ");
    for(i=0;i<79;i++)
        printf("-");
	    printf("\n\n");
	    printf("\t\t       AMOUNT \t\t\t PLAN");
     rewind(t);
	while(fread(&pa,recsize,1,t)==1)
    {
        //fseek(f,recsize,SEEK_CUR);
         printf("\n\t\t\t%-10s\t\t%-20s\t\t",pa.amount,pa.plan);
    }

}
