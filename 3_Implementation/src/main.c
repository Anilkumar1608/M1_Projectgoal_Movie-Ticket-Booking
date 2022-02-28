/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"booking_ticket.h"
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