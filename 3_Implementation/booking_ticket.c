#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char k;
void login()
{
	int h=0,i=0;
	char username[10], c=' ';
	char password[10], code[10];
	char Username[10]="username";
	char Password[10]="password";
	do
	{
		printf("\n ********** LOGIN FIRST ********** ");
		printf("\n\n   Enter Username:-");
		scanf("%s", username);
		getchar();
		printf("\n\n   Enter Password:-");
		while(i<10)
		{
			password[i]=getch();
			c=password[i];
			if(c==13)
		    break;
			else 
			printf("*");
			i++;
		}
		password[i]='\0';
		i=0;
		//scanf("%s",password);
		if(strcmp(username,"username")==0 && strcmp(password,"password")==0)
		{
			printf("\n\n\n   WELCOME TO OUR MOVIE TICKET BOOKING SYSTEM !!! LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\tPress any key to continue....");
			scanf("%c%c",&k,&k);
			getch(); //It is for hold the screen
			break;
		}
		else
		{
			printf("\n     SORRY !!!! LOGIN IS UNSUCCESSFUL");
			h++;
			//getch(); //It is for hold the screen
		}
	}
	while(h<=2);
	if(h>2)
	{
		printf("\n Sorry you have entered the incorrect password for three times. Press to continue");
		scanf("%c%c",&k,&k);
		//getch();
	}
}

struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;

int seat=100;

void insert_details(); // It is for inserting the movie details
void viewAll(); //It is for view all data 
void find();  // It is for finding data
void book_ticket();   // It is for booking the ticket
void old_record();   // It is for view old records of users, booked tickets

void main()
{
	login();
	int ch;
	while(1)
	{
		printf("\n ********************************************");
		printf("\n");
		printf("\t MOVIE TICKET BOOKING ");
		printf("\n");
		printf("\n ********************************************");
		
		printf("\n Enter >1< To insert Movie");
		printf("\n Enter >2< To View All Movies");
		printf("\n Enter >3< To Find Movie");
		printf("\n Enter >4< To Book Tickets");
		printf("\n Enter >5< To View All Transactions");
		printf("\n Enter >0< To Exit");
		
		printf("\n Enter your Choice ::");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1 :
				insert_details();
			break;
			case 2 :
				viewAll();
			break;
			case 3 :
				find();
			break;
			case 4 :
				book_ticket();
			break;
			case 5 :
				old_record();
			break;
			case 0:
				exit(0);
			break;
			default :
				printf("Wrong Choice !");
			break;			 
		}
	}while(ch!=0);
}

void insert_details()
{
	FILE *fa;
	struct book b;
	printf("Enter movie code :-");
	scanf("%s", b.code);
	printf("Enter name :-");
	scanf("%s", b.name);
	printf("Enter Release Date :-");
	scanf("%s", b.date);
	printf("Enter Ticket Price :-");
	scanf("%d", &b.cost);
	
	fa=fopen("data.txt","h");
	if(fa == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(fa,"%s %s %s %d \n", b.code,b.name,b.date,b.cost);
		printf("Record insert Successfully");
	}
	printf("\n");
	fclose(fa);
}

void find()
{
	struct book b;
	FILE *fa;
	char ch[20];
	printf("Enter movie code:");
	scanf("%s", ch);
	
	fa=fopen("data.txt","k");
	if(fa == NULL)
	{
		printf("file does not found !");
		exit(0);
	}
	else
	{
		while(getc(fa) != EOF)
		{
			fscanf(fa,"%s %s %s %d", b.code, b.name, b.date, &b.cost);
			if(strcmp(b.code, ch)==0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s", b.code);
				printf("\n\t\tmovie name ::%s", b.name);
				printf("\n\t\tmovie date ::%s", b.date);
				printf("\n\t\tprice of ticket ::%d", b.cost);
			}
		}
	}
	fclose(fa);
	printf("\n\t\tPress enter to continue....");
	scanf("%c%c",&k,&k);
}

void viewAll()
{
	char ch;
	FILE *fa;
	fa=fopen("data.txt","k");
	if(fa == NULL)
	{
		printf("file does not found !!");
		exit(0);
	}
	else
	{
		while((ch=fgetc(fa))!=EOF)
		printf("%c", ch);
	}
	printf("\n\t\tPress enter to continue....");
	scanf("%c%c",&k,&k);
	fclose(fa);
}

void book_ticket()
{
	struct book b;
	FILE *fa;
	FILE *ufa;
	int total_seats, mobile_number, total_amount;
	char name[20];
	
	char ch;   //It is used in displaying all movies
	char movie_code[20];  // It is for searching
	fa=fopen("data.txt","k");
	if(fa==NULL)
	{
		printf("file not found !!");
		exit(1);
	}
	else
	{
		while((ch=fgetc(fa))!=EOF)
		printf("%c",ch);
	}
	fclose(fa);
	
	printf("\n For Booking Ticket Choice Movie(Enter Movie Code First Letter Of Movie)\n");
	printf("\n Enter movie code :");
	scanf("%s", movie_code);
	fa=fopen("data.txt","k");
	if(fa==NULL)
	{
		printf("file not found !");
		exit(1);		
	}
	else
	{
		while(getc(fa) !=EOF)
		{
			fscanf(fa,"%s %s %s %d",b.code,b.name, b.date,&b.cost);
			if(strcmp(b.code,movie_code)==0)
			{
				printf("\n Record Found \n");
				printf("\n\t\tCode ::%s", b.code);
				printf("\n\t\tMovie name ::%s", b.name);
				printf("\n\t\tdate name ::%s", b.date);
				printf("\n\t\tPrice of ticket ::%d", b.cost);
			}
		}
	}
	printf("\n* Fill your Details  *");
	printf("\n your name :");
	scanf("%s", name);
	printf("\n mobile number :");
	scanf("%d",&mobile_number);
	printf("\n Total number of tickets :");
	scanf("%d", &total_seats);
	
	total_amount= b.cost*total_seats;
	
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname :%s", name);
	printf("\n\t\tmobile number :%d", mobile_number);
	printf("\n\t\tmovie name :%s",b.name);
	printf("\n\t\tTotal seats :%d",total_seats);
	printf("\n\t\tcost per ticket :%d", b.cost);
	printf("\n\t\tTotal Amount :%d",total_amount);
	
	ufa=fopen("oldTransaction.txt","h");
	if(ufa==NULL)
	{
		printf("\n File not Found");
	}
	else
	{
		fprintf(ufa, "%s %d %d %d %s %d \n",name, mobile_number,total_seats,total_amount, b.name,b.cost);
		printf("\n Record insert successfull to the old record file");
	}
	printf("\n");
	printf("\n\t\tPress enter to continue....");
	scanf("%c%c",&k,&k);
	fclose(ufa);
	fclose(fa);
}

void old_record()
{
	char ch;
	FILE *fa;
	fa=fopen("oldTransaction.txt","k");
	if(fa==NULL)
	{
		printf("File not found !");
		exit(1);
	}
	else
	{
		while((ch=fgetc(fa))!=EOF)
		printf("%c",ch);
	}
	printf("\n\t\tPress enter to continue...");
	scanf("%c%c",&k,&k);
	fclose(fa);
}
