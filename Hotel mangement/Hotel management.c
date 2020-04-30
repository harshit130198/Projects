#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
FILE *r1,*r2,*r3,*r4,*r5;
char name[20],mobile[12],room_no[5],people[5],check_in[10],check_in_time[10],id_proof[20];
int room_file,room_info,room_del;
int choice,j;
char *s;
char ch;
char username[20];
char password[10];
time_t mytime;
char check_out[5];
int arr[5]={0,0,0,0,0},i;
int typ;
COORD coord={0,0};
int n1,k1;
int i1,j1;
int i,j;

void bill()


{
    char name[25];
    char di[25];
    char du[25];
    int td;
    int pcharges,tcharges;

printf("Enter the Name of customer:");
gets(name);
printf("Enter the Date of Check In:");
gets(di);
printf("Enter the Date of Check Out:");
gets(du);
printf("Per day Charges:");
scanf("%d",&pcharges);
printf("Total days:");
scanf("%d",&td);

tcharges=pcharges*td;

printf("--------------------------------------------------------------------------------\n");
printf("|Name Of Customer | Date Of | Date of | Per Day | Total Day | Total Day charges| ");
printf("\n|                 | check in|check out| charges |                              |\n");
printf("--------------------------------------------------------------------------------\n");
printf("|                 |         |                   |           |        |         |\n");
printf("|     %s            |%s|         %s     |  %d    |   %d   | %d  |\n",name,di,du,pcharges,td,tcharges);
printf("|                 |         |                   |           |        |         |\n");

getch();




}


 void loading()
{

        gotoxy(30,30);printf("----------------");
        gotoxy(30,31);printf("\t!  Loading !");
        gotoxy(30,32);printf("----------------");
        gotoxy(30,35);printf("   Please Wait");

     for(i=38;i<39;i++)
    {
        for(j=0;j<79;j++)
        {
            gotoxy(j,i);printf("|");//bottom
            delay(10000000);
        }
    }

    getch();
   return 0;
  }

void welcome()

{
     system("color a");

    for(i1=90;i1<91;i1++)
    {
        for(j1=0;j1<79;j1++)
        {
            gotoxy(i1,j1);printf("*");//top
            delay(10000000);
        }
    }
    for(i1=78;i1<79;i1++)
    {
        for(j1=0;j1<25;j1++)
        {
            gotoxy(i1,j1);printf("*");//right
            delay(10000000);
        }
    }


    for(i1=0;i1<1;i1++)
    {
        for(j1=0;j1<25;j1++)
        {
            gotoxy(i1,j1);printf("*");//left
            delay(10000000);
        }
    }
    for(i1=200;i1<201;i1++)
    {
        for(j1=0;j1<78;j1++)
        {
            gotoxy(i1,j1);printf("*");//bottom
            delay(10000000);
        }
    }
    gotoxy(29,3);printf("Welcome to Magic World");
    gotoxy(29,19);printf("Made By-");
    gotoxy(29,20);printf("Harshit Patel and Ketul Patel");
    getch();
   return 0;
  }

void delay(int x1)
{

    for(n1=0;n1<x1;n1++)
    {
        k1=n1;
    }
}
 void gotoxy(int x2,int y2)
 {
    coord.X=x2;
    coord.Y=y2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void login()
{

    printf("Enter username: ");
    scanf("%s",name);
    printf("Enter password: ");
    scanf("%s",password);

     /*   for(j=0;j<5;j++)
    {
        password[j]=getch();
        printf("*");


    }*/


        if (strcmp(name, "admin") == 0 && strcmp(password, "*****") == 0)
        {
            printf("Access granted\n");
        }
        else
        {
            printf("Access denied\n");
        }



}


void del_file()
{
    printf("Enter the room number to delete data ::");
    scanf("%d",&room_del);

    switch(room_del)
    {
    case 1:

            remove("customer1.txt");
            break;
    case 2:

            remove("customer2.txt");
            break;
    case 3:

            remove("customer3.txt");
            break;
    case 4:

            remove("customer4.txt");
            break;
    case 5:

            remove("customer5.txt");
            break;

    }
}

/*typedef struct _sysmin {
        WORD wMinute;
	} sysmin;

	void checkout_min()
	{
	    sysmin str_t;
	GetSystemTime(&str_t);

	printf("Min:%d\n",str_t.wMinute);

	}*/

void time_system()
{

		time_t mytime;
		mytime = time(NULL);
		s=ctime(&mytime);
}

void customer_details()
{

    again:
        printf("Enter the room Number ::");
    scanf("%d",&room_file);
    for(i=0;i<=4;i++)
    {
        if(room_file==arr[i])
             {
                 printf("Room is booked\nPlease try for other room\n\n");
                    goto again;
             }
    }
switch (room_file)
{


    case 1:
    r1=fopen("customer1.txt","w");

        printf("\nName of Costumer ::");
        getchar();
        gets(name);

        printf("\nMobile Number ::");
        scanf("%s",mobile);

        printf("\nTotal Number of people ::");
        scanf("%s",people);


        printf("\nEnter the ID Proof ::");
        scanf("%s",id_proof);

          fprintf(r1,"%s%s","Name of Customer ::",name);

          fprintf(r1,"%s%s","\nMobile No of Customer ::",mobile);
          fputs("\n",r1);

           fprintf(r1,"%s%s","Total People Staying ::",people);
           fputs("\n",r1);


            time_system();
            fprintf(r1,"%s%s","Check-in date and time of customer ::",s);
          //fputs("\n",r1);

            fprintf(r1,"%s%s","ID-proof Given ::",id_proof);
            fputs("\n",r1);
            fputs("\n",r1);

          fclose(r1);
          arr[0]=room_file;
          break;

    case 2:
        r2=fopen("customer2.txt","a+");

        printf("\nName of Costumer ::");
        getchar();
        gets(name);


        printf("\nMobile Number ::");
        scanf("%s",mobile);

        printf("\nTotal Number of people ::");
        scanf("%s",people);


        printf("\nEnter the ID Proof ::");
        scanf("%s",id_proof);

        fprintf(r2,"%s%s","Name of Customer ::",name);

        fprintf(r2,"%s%s","\nMobile No of Customer ::",mobile);
        fputs("\n",r2);

        fprintf(r2,"%s%s","Total People Staying ::",people);
        fputs("\n",r2);


        time_system();
        fprintf(r2,"%s%s","Check-in date and time of customer ::",s);
         // fputs("\n",r2);

        fprintf(r2,"%s%s","ID-proof Given ::",id_proof);
        fputs("\n",r2);
        fputs("\n",r2);

          arr[1]=room_file;
          fclose(r2);
          break;
    case 3 :
        r3=fopen("customer3.txt","a+");

        printf("\nName of Costumer ::");
        getchar();
        gets(name);


        printf("\nMobile Number ::");
        scanf("%s",mobile);

        printf("\nTotal Number of people ::");
        scanf("%s",people);


        printf("\nEnter the ID Proof ::");
        scanf("%s",id_proof);

          fprintf(r3,"%s%s","Name of Customer ::",name);

          fprintf(r3,"%s%s","\nMobile No of Customer ::",mobile);
          fputs("\n",r3);

           fprintf(r3,"%s%s","Total People Staying ::",people);
           fputs("\n",r3);


            time_system();
            fprintf(r3,"%s%s","Check-in date and time of customer ::",s);
          //fputs("\n",r3);

           fprintf(r3,"%s%s","ID-proof Given ::",id_proof);
           fputs("\n",r3);
           fputs("\n",r3);

          arr[2]=room_file;
          fclose(r3);
          break;
    case 4:
        r4=fopen("customer4.txt","a+");

        printf("\nName of Costumer ::");
        getchar();
        gets(name);


        printf("\nMobile Number ::");
        scanf("%s",mobile);

        printf("\nTotal Number of people ::");
        scanf("%s",people);



        printf("\nEnter the ID Proof ::");
        scanf("%s",id_proof);

          fprintf(r4,"%s%s","Name of Customer ::",name);

          fprintf(r4,"%s%s","\nMobile No of Customer ::",mobile);
          fputs("\n",r4);

           fprintf(r4,"%s%s","Total People Staying ::",people);
          fputs("\n",r4);


            time_system();
           fprintf(r4,"%s%s","Check-in date and time of customer ::",s);
          //fputs("\n",r4);


           fprintf(r4,"%s%s","ID-proof Given ::",id_proof);
           fputs("\n",r4);
          fputs("\n",r4);

          arr[3]=room_file;
          fclose(r4);
          break;
    case 5 :
        r5=fopen("customer5.txt","a+");

        printf("\nName of Costumer ::");
        getchar();
        gets(name);


        printf("\nMobile Number ::");
        scanf("%s",mobile);

        printf("\nTotal Number of people ::");
        scanf("%s",people);

        printf("\nEnter the ID Proof ::");
        scanf("%s",id_proof);

          fprintf(r5,"%s%s","Name of Customer ::",name);

          fprintf(r5,"%s%s","\nMobile No of Customer ::",mobile);
          fputs("\n",r5);

           fprintf(r5,"%s%s","Total People Staying ::",people);
          fputs("\n",r5);



            time_system();
           fprintf(r5,"%s%s","Check-in date and time of customer ::",s);
          //fputs("\n",r5);


           fprintf(r5,"%s%s","ID-proof Given ::",id_proof);
           fputs("\n",r5);
          fputs("\n",r5);

          arr[4]=room_file;
          fclose(r5);
          break;
}


}



void customer_information()
{
    printf("Enter the room no. to see Details :: ");
    scanf("%d",&room_info);
    switch(room_info)
    {
        case 1:
            {
                    r1=fopen("customer1.txt","r");
                    while((ch=getc(r1))!=EOF)
                    printf("%c",ch);
                    fclose(r1);
                    break;
            }
        case 2:
            {
                    r2=fopen("customer2.txt","r");
                    while((ch=getc(r2))!=EOF)
                    printf("%c",ch);
                    fclose(r2);
                    break;
            }
        case 3:
            {
                    r3=fopen("customer3.txt","r");
                    while((ch=getc(r3))!=EOF)
                    printf("%c",ch);
                    fclose(r3);
                    break;
            }
        case 4:
            {
                    r4=fopen("customer4.txt","r");
                    while((ch=getc(r4))!=EOF)
                    printf("%c",ch);
                    fclose(r4);
                    break;
            }
        case 5:
            {
                    r5=fopen("customer5.txt","r");
                    while((ch=getc(r5))!=EOF)
                    printf("%c",ch);
                    fclose(r5);
                    break;
            }
    }
}


void features()
 {

   printf("\nChoose the room type:\n1. Single Room\n2. Double Room");
   printf("\n3. Superior Suite\n4. Executive Room\n5. Family Suite\n");
   scanf("%d",&typ);
   if(typ>5)
     {
       printf("\nWrong choice!! Choose a number between 1-5:");
       features();
     }
   switch(typ)
     {
       case 1:
       printf("\n Room number            >>>1");
       printf("\n Advance                >>>7500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n******************************************************************");
       printf("\n\nSingle Room");
       printf("\nRs.15000 per day");
       printf("\nDouble Bed");
       printf("\nSitting corner with Sofa or Armchairs");
       printf("\nBathroom with Shower");
       printf("\nBranded bath amenities");
       printf("\nHairdryer");
       printf("\nBathrobes and Slippers");
       printf("\nSafe Deposit Box");
       printf("\nLED TV with satellite channels");
       printf("\nMini-Bar");
       printf("\nAir conditioning");
       printf("\nSteamer & amenities for making Coffee & Tea");
       printf("\nBalcony or Terrace");
       break;

       case 2:
       printf("\n Room number            >>>2");
       printf("\n Advance                >>>15000\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n******************************************************************");
       printf("\nDouble Room");
       printf("\nRs.22500 per day");
       printf("\nDouble Bed");
       printf("\nSitting corner with Sofa or Armchairs");
       printf("\nBathroom with Shower");
       printf("\nBranded bath amenities");
       printf("\nHairdryer");
       printf("\nBathrobes and Slippers");
       printf("\nSafe Deposit Box");
       printf("\nLED TV with satellite channels");
       printf("\nMini-Bar");
       printf("\nAir conditioning");
       printf("\nSteamer & amenities for making Coffee & Tea");
       printf("\nBalcony or Terrace");
       break;

       case 3:
       printf("\n Room number            >>>3");
       printf("\n Advance                >>>22500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n******************************************************************");
       printf("\nSuperior Suite");
       printf("\nRs.30000 per day");
       printf("\n2 Separate Bedrooms (upper floor, lower floor)");
       printf("\nSitting corner with Sofa or Armchairs");
       printf("\nBathroom with Shower");
       printf("\nBranded bath amenities");
       printf("\nHairdryer");
       printf("\nBathrobes and Slippers");
       printf("\nSafe Deposit Box");
       printf("\n2 LED TV with satellite channels");
       printf("\nMini-Bar");
       printf("\nAir conditioning");
       printf("\nSteamer & amenities for making Coffee & Tea");
       printf("\nBalcony or Terrace");
       break;

       case 4:
       printf("\n Room number            >>>4");
       printf("\n Advance                >>>30000\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n******************************************************************");
       printf("\nExecutive Suite");
       printf("\nRs.37500 per day");
       printf("\n2 Separate Bedrooms (upper floor, lower floor)");
       printf("\nSitting corner with Sofa or Armchairs");
       printf("\n1 or 2 Bathrooms with Bathtub and/or Shower");
       printf("\nBranded bath amenities");
       printf("\nHairdryer");
       printf("\nBathrobes and Slippers");
       printf("\nSafe Deposit Box");
       printf("\n2 LED TV with satellite channels");
       printf("\nMini-Bar");
       printf("\nAir conditioning");
       printf("\nSteamer & amenities for making Coffee & Tea");
       printf("\nBalcony or Terrace");
       break;

       case 5:
       printf("\n Room number            >>>5");
       printf("\n Advance                >>>37500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n******************************************************************");
       printf("\nGrand Suite");
       printf("\nRs.45000 per day");
       printf("\n3 Separate Bedrooms (upper floor)");
       printf("\nSitting corner with Sofa or Armchairs");
       printf("\n2 Bathrooms with Bathtub and/or Shower");
       printf("\nBranded bath amenities");
       printf("\nHairdryer");
       printf("\nBathrobes and Slippers");
       printf("\nSafe Deposit Box");
       printf("\n3 LED TV with satellite channels");
       printf("\nMini-Bar");
       printf("\nAir conditioning");
       printf("\nSteamer & amenities for making Coffee & Tea");
       printf("\nBalcony or Terrace");
       break;
     }
 }



void main()
{

                 welcome();
                 printf("\n\n\n\n\n");
                 login();
                 loading();

    while(1)
    {
            printf("\n\n\n\n\n\n\t\t\t --------------------------\n ");
            printf("\t\t\t|Welcome to Ganesh Meridian|\n");
            printf("\t\t\t --------------------------\n");
            printf("1. Press 1 for Booking\n\a");
            printf("2. Press 2 for Room's & Rate's information\n");
            printf("3. Press 3 for Getting Customer's Information\n");
            printf("4. Press 4 for deleting the Customer's Booking\n");
            printf("5. Press 5 for billing\n");
            printf("6. Press 6 to Exit\n\n\n");

            printf("Enter Your Choice :: ");
            scanf ("%d",&choice);

            switch(choice)
            {
            case 1:
                        customer_details();
                        break;
            case 2:

                        features();
                        break;
            case 3:

                        customer_information();
                        break;
            case 4:
                        del_file();
                        break;
            case 5:
                        customer_information();
                        bill();
                        break;
            case 6:
                        exit(0);
                        break;



            default:
                printf("No task like it Sorry try again");
                exit(0);


            }
    }
}

