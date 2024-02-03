#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <dos.h>
#include <dir.h>
#define BKSP 8
#define ENTER 13
struct doctor{
    char DrId[11];
	char First_Name[20];
	char Last_Name[20];
    char Gender[3];
	char RoomNo[4];
	char Address[30];
	char Contact_no[15];
	char Email[30];
	char designation[20];
	char Department[20];
};
struct doctor dr;
void infoSearch(void){
    clearWindow();
    ColorSet();
	char name[20];
	char back;
	system("cls");
	//Title();// call Title function
	FILE *ek;
	ek=fopen("data/Doctor-Information.csv","r");
	pointXY(0,0);
	printf("\n\n\n\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    getTitle();
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    ColorSet();
    printf("\n\n\t\t\t Press 'Backspace' to Home Screen or 'Enter' to continue");
    back = getch();
    if(back == BKSP){
        mainMenuItem();
    }
	printf("\n\n\t\t\t Enter Department Name:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
					&dr.Gender, &dr.RoomNo, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department)!=EOF)
	{
		if(strcmp(dr.Department,name)==0)
		{
		    int row=18;
        int drlistTitltRow = 16;
        pointXY(0,15);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|DR ID");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Room No");
		pointXY(45,drlistTitltRow);
		printf("|Address");
		pointXY(62,drlistTitltRow);
		printf("|Contact No.");
		pointXY(75,drlistTitltRow);
		printf("|Email");
		pointXY(94,drlistTitltRow);
		printf("|Designation");
		pointXY(107,drlistTitltRow);
		printf("|Department|\n");
		printf("=======================================================================================================================\n");


//
//            dr.Last_Name[strlen(dr.Last_Name)-1] = '\0';
//            dr.RoomNo[strlen(dr.RoomNo)-1] = '\0';
//            dr.Address[strlen(dr.Address)-1] = '\0';
//            dr.Email[strlen(dr.Email)-1] = '\0';
//            dr.designation[strlen(dr.designation)-1] = '\0';
//            dr.DrId[strlen(dr.DrId)-1] = '\0';
//            dr.Gender[strlen(dr.Gender)-1] = '\0';
//            dr.Contact_no[strlen(dr.Contact_no)-1] = '\0';
            pointXY(0,row);
			printf("|%s",dr.DrId);
		    pointXY(11,row);
		    dr.First_Name[strlen(dr.First_Name)-1] = '\0';
			printf("|%s %s",dr.First_Name, dr.Last_Name);
			pointXY(26,row);
			printf("|%s",dr.Gender);
			pointXY(34,row);
			//printf("|%s",dr.RoomNo);
			printf("|A-202");
			pointXY(45,row);
			printf("|%s",dr.Address);
			pointXY(62,row);
			printf("|%s",dr.Contact_no);
			pointXY(75,row);
			printf("|%s",dr.Email);
			pointXY(94,row);
			printf("|%s", dr.designation );
            pointXY(107,row);
			printf("|%s", dr.Department );
			printf("\n");
			row++;
		}
	   }
	   if(strcmp(dr.Department,name)!=0)
	   {
		pointXY(47,18);
		SetColor(12);
		printf("Record not found!");
		ColorSet();
		pointXY(47,19);
		//getch();
	   }
	fclose(ek);
	L:
	getch();
	char reply;
    pointXY(40,20);
	printf("Press 'Enter' search again or exit 'Backspace'");
    reply = getch();
    if (reply == ENTER){
        infoSearch();
    }
	else if(reply==BKSP){
		mainMenuItem();
    }
	else
    {
    	printf("\n\t\t\tInvalid Input.\n");
    	goto L;
    }
}
