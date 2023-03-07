#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void viewtrain(void);
void book(void);
float fare(int,int);
void printticket(char name[],int,int,float);
void viewticket(void);
void searchtrain(int);

typedef struct{
    char name[20];
    int trainno;
    int seats; 
}td;
int main()
{

    int choice,s;
    start:
    printf("\n\t\t\t*********************************\n");
	printf(" \t\t\t    TRAIN BOOKING SYSTEM");
	printf("\n\t\t\t*********************************"); 
	printf("\n\n\t\t\t1. View Trains");
	printf("\n\t\t\t------------------------");
	printf("\n\t\t\t2. Book Ticket");
	printf("\n\t\t\t------------------------");
	printf("\n\t\t\t3. View Ticket");
	printf("\n\t\t\t------------------------");
	printf("\n\t\t\t4. Search Train");
	printf("\n\t\t\t------------------------");
	printf("\n\t\t\t5. Exit");

	printf("\n\n\t\t\tEnter your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			viewtrain();
			printf("\n\nPress any key to go on Main Menu..");
			getch();
			break;
			
		case 2:
			 book();
			break;
			
		case 3:
			viewticket();
            
            break;
        case 4:
            printf("Enter Train number you have to search::");
            scanf("%d",&s);
            searchtrain(s);
            break;
        case 5:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
	
}


void viewtrain(void)
{
	printf("----------------------------------------------------------------------------------------------------");
	printf("\nTrain.No\tName\t\t\tDestination  \t\tCharges  \t\tTime\n");
	printf("=====================================================================================================");
	printf("\n12114\tGaribrath Express        \tNagpur To Pune       \tRs.1000   \t18:00  PM-->9:05 AM");
	printf("\n11040\tMaharashtra Express         \tGondia To Kolhapur     Rs.600   \t8:15 AM-->12:25 AM");
	printf("\n12289\tDuranto Express         \tMumbai To Nagpur       Rs.1200   \t20:15 PM-->7:20 AM");
	printf("\n12301\tRajdhani Express         \tHowrah To Delhi     \tRs.1800   \t16:50 PM-->10:05 AM");
	printf("\n12055\tJanShatabdi Express      \tDelhi To Dehradun      \tRs.1300   \t15:20 PM-->21:10 PM");
	printf("\n12275\tHumsafar Express      \t\tPrayagraj To Delhi      Rs.850   \t22:30 PM-->6:10 AM");
    printf("\n22436\tVande Bharat Express        \tNewDelhi To Varanasi    Rs.2150   \t6:00 AM-->14:00 PM");
    printf("\n12127\tIntercity Express         \tMumbai To Pune         \tRs.500   \t6:40 AM-->10:57 AM");
    printf("\n12029\tShatabdi Express     \t\tDelhi To Amritsar     \tRs.1200   \t7:20 AM-->13:30 PM");
    printf("\n19709\tKavi Guru Express        \tJaipur To Kamakhya     \tRs.900   \t23:30 PM-->23:25 PM");
}

void book(void)
{
	char confirm;
	int i=0;
	float price;
	td ticketdetail;
	FILE *fp;
	fp=fopen("Ticket.txt","w");
	printf("\t\t-------------------\n");
	printf("\t\tTRAIN TICKET BOOKING\n");
	printf("\t\t-------------------\n\n");


    printf("\n\t\tEnter Your Name-> ");
	scanf("%s",ticketdetail.name);

	printf("\n\t\tEnter Number of Passengers-> ");
	scanf("%d",&ticketdetail.seats);

	viewtrain();
	printf("\n\n\t\tEnter Train number-> ");
	start1:
	scanf("%d",&ticketdetail.trainno);
	if(ticketdetail.trainno==12114 || ticketdetail.trainno==11040 || ticketdetail.trainno==12289 || ticketdetail.trainno==12301 || ticketdetail.trainno==12055 || ticketdetail.trainno==12275 || ticketdetail.trainno==22436 || ticketdetail.trainno==12127 || ticketdetail.trainno==12029 || ticketdetail.trainno==19709 )
	{
		price=fare(ticketdetail.trainno,ticketdetail.seats);
		printticket(ticketdetail.name,ticketdetail.seats,ticketdetail.trainno,price);
	}
	else
	{
		printf("\nInvalid Train Number! Enter again::");
		goto start1;
	}

	printf("\n\n\t\tConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
	        
		fprintf(fp,"\t\nPassenger Name::%s\t\n",&ticketdetail.name);
		fprintf(fp,"\t\nNumber of seats::%d\t\n",ticketdetail.seats);
		fprintf(fp,"\t\nTrain number::%d\t\n",ticketdetail.trainno);
		fprintf(fp,"\t\nTotal Amount::%.3f\t\n",price);
		printf("\t\t==================");
		printf("\n \t\tBooking Done\n");
		printf("\t\t==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\n\t\tBooking Not Done!\n");
		}
		else
		{
			printf("\n\t\tInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float fare(int trainno,int seats)
{
	if (trainno==12114)
	{
		return(1000*seats);
	}
	if (trainno==11040)
	{
		return(600*seats);
	}
	if (trainno==12289)
	{
		return(1200*seats);
	}
	if (trainno==12301)
	{
		return(1800*seats);
	}
	if (trainno==12055)
	{
		return(1300*seats);
	}
	if (trainno==12275)
	{
		return(850*seats);
	}
	if (trainno==22436)
	{
		return(2150*seats);
	}
	if (trainno==12127)
	{
		return(500*seats);
	}
	if (trainno==12029)
	{
		return(1200*seats);
	}
	if (trainno==19079)
	{
		return(900*seats);
	}
}

void printticket(char name[],int seats,int trainno,float fare)
{
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",seats);
	printf("\nTrain Number:\t\t%d",trainno);

	printf("\nAmount Paid:\t\t%.2f",fare);
}

void viewticket(void)
{
	char c;
	FILE *fp;
	fp=fopen("Ticket.txt","r");
	printf("\nYou can also view ticket by opening 'Ticket.txt' file in your system\n");
	if(fp==NULL)
	{
		printf("\nNo data available\n");
		exit(0);
	}
	else
	{
		do{
			c=fgetc(fp);
			printf("%c",c);
			
		}while(c!=EOF);
		printf("Happy Journey!!!");
		fclose(fp);
	}
}
void searchtrain(int num)
{
	if (num==12114)
	{
		printf("\nTrain:\t\t\tGaribrath Express");
		printf("\nDestination:\t\tNagpur To Pune");
		printf("\nDeparture:\t\t 18:00  PM-->9:05 AM \n\n\n");
	}
	else if (num==11040)
	{
		printf("\nTrain:\t\t\tMaharashtra Express");
		printf("\nDestination:\t\tGondia To Kolhapur");
		printf("\nDeparture:\t\t 8:15  AM-->12:25 AM \n\n\n");
	}
	else if (num==12289)
	{
		printf("\nTrain:\t\t\tDuranto Express");
		printf("\nDestination:\t\tMumbai To Nagpur");
		printf("\nDeparture:\t\t 20:15 PM-->7:20 AM \n\n\n");
	}
	else if (num==12301)
	{
		printf("\nTrain:\t\t\tRajdhani Express");
		printf("\nDestination:\t\tHowrah To Delhi");
		printf("\nDeparture:\t\t 16:50  PM-->10:05 AM \n\n\n");
	}
	else if (num==12055)
	{
		printf("\nTrain:\t\t\tJanShatabdi Express");
		printf("\nDestination:\t\tDelhi To Dehradun");
		printf("\nDeparture:\t\t 15:20  PM-->21:10 PM \n\n\n");
	}
	else if (num==12275)
	{
		printf("\nTrain:\t\t\tHumsafar Express");
		printf("\nDestination:\t\tPrayagraj To Delhi");
		printf("\nDeparture:\t\t 22:30  PM-->6:10 AM \n\n\n");
	}
	else if (num==22436)
	{
		printf("\nTrain:\t\t\tVamde Bharat Express");
		printf("\nDestination:\t\tNewDelhi To Varanasi");
		printf("\nDeparture:\t\t 6:00  AM-->14:00 PM \n\n\n");
	}
	else if (num==12127)
	{
		printf("\nTrain:\t\t\tIntercity Express");
		printf("\nDestination:\t\tMumbai To Pune");
		printf("\nDeparture:\t\t 6:40  AM-->10:57 AM \n\n\n");
	}
	else if (num==12029)
	{
		printf("\nTrain:\t\t\tShatabdi Express");
		printf("\nDestination:\t\tDelhi To Amritsar");
		printf("\nDeparture:\t\t 7:20  AM-->13:30 PM \n\n\n");
	}
	else if (num==19709)
	{
		printf("\nTrain:\t\t\tKavi Guru Express");
		printf("\nDestination:\t\tJaipur To Kamakhya");
		printf("\nDeparture:\t\t 23:30  PM-->23:25 PM \n\n\n");
	}
	else
	printf("Invalid number");
}

