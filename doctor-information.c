//HEADER FILES
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
#define ESC 27
/* ========================
Doctor Information
=========================*/
char reply = 0;
char ans=0;
int ok, on=0;
int a, b, valid=0, done =0, work = 0,sign =1;
char seperator[3] = "/|";
//FUNCTION DECLERATION
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void doctorList();
void searchDoctor(void);
void updateDoctorInfo(void);
void deleteInfo(void);
void ex_it(void);
//Defines pointXY() for ANSI C compilers.
void pointXY(short x, short y) {
COORD pos = {x, y};//sets co-ordinates in (x,y).
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct doctor{
    char DrId[11];
	char First_Name[20];
	char Last_Name[20];
    char Gender[3];
	char JoinDate[11];
	char Address[30];
	char Contact_no[15];
	char Email[30];
	char RoomNo[5];
	char designation[20];
	char Department[20];
};
char dd[3],mm[3],yy[4];
int date, index =0;
struct doctor  dr,temp_c;
/* ************************************************* Exit Screen ********************************************* */
void ex_it(void){
    clearWindow();
    pointXY(0,0);
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();//holds screen

}

/*Menu select---------------------*/
drInfo(){
    clearWindow();
	int choose;
	char item;
    pointXY(12,0);
    printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    getTitle();
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");printf("\n\n\t\t\t\t1. Add Doctor List\n");
	printf("\n\t\t\t\t2. Doctor List\n");
	printf("\n\t\t\t\t3. Search Doctor\n");
	printf("\n\t\t\t\t4. Edit Doctor Information\n");
	printf("\n\t\t\t\t5. Delete Doctor From List\n");
	printf("\n\t\t\t\t6. Exit from System\n");
	printf("\n\t\t\t Continue->'Enter', Back->'Backspace'...");
	item = getche();
	if(item == BKSP){
        adminMenu();
	}else if(item == ESC){
        drInfo();
	}
	printf("\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	switch(choose){

	case 1:
	addNewDoctor();
    	break;
    case 2:
    	doctorList();
    	break;
	case 3:
	searchDoctor();
    	break;
	case 4:
		updateDoctorInfo();
		break;
	case 5:
		deleteInfo();
		break;
	case 6:
		ex_it();
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch

}

addNewDoctor(){
     clearWindow();
     ColorSet();
/* **************************************ADD RECORD*******************************************/
	char ans;
	FILE*ek;//file pointer
	ek=fopen("data/Doctor-Information.csv","a");//open file in write mode
    pointXY(0,0);
	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Doctor Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    char item;
     printf("\n\t\t\t Continue->'Enter', Back->'Backspace'...");
	item = getche();
	if(item == BKSP){
        adminMenu();
	}else if(item == ESC){
        drInfo();
	}
/* ******************************************* ID no. ***************************************** */
do{
	I:
    printf("\n\n\t\t\tID no: ");
    scanf("%s",dr.DrId);
    if(strlen(dr.DrId)>10||strlen(dr.DrId)!=10){
        SetColor(12);
		printf("\t\t\t( Please Use 10 digit. Enter again :)");
        ColorSet();
		goto I;
	}
	else{
		for (b=0;b<strlen(dr.DrId);b++)
		{
			if (!isalpha(dr.DrId[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid){
		    SetColor(12);
			printf("\n\t\t\t Invalid character(  Enter again :)");
			ColorSet();
			goto I;
		}
	}
}
while(!valid);
clearLine();
pointXY(0,0);
	/* **************************First Name*********************************** */
	A:
    pointXY(0,0);
	printf("\n\n\n\n\n\n\n\t\t\tFirst Name: ");
	scanf("%s",dr.First_Name);
	dr.First_Name[0]=toupper(dr.First_Name[0]);
	if(strlen(dr.First_Name)>20||strlen(dr.First_Name)<2){
		printf("\t\t\t Invalid :( \t Please Enter 2-20 Letter First Name :)");
		goto A;
	}
	else{
		for (b=0;b<strlen(dr.First_Name);b++){
			if (isalpha(dr.First_Name[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
			printf("\n\t\t First name contain Invalid, Please enter valid character :(  Enter again :)");
			goto A;
		}
	}

	/* ********************************************** Last name ************************************************ */
clearLine();
pointXY(0,0);
	B:
    pointXY(0,0);
	printf("\n\n\n\n\n\n\n\t\t\tLast Name: ");
    scanf("%s",dr.Last_Name);
    dr.Last_Name[0]=toupper(dr.Last_Name[0]);
    if(strlen(dr.Last_Name)>20||strlen(dr.Last_Name)<2){
		printf("\t\t\tInvalid :( \t The maximum lenght for last name is 20 and min range is 2 :)");
		goto B;
	}
	else{
		for (b=0;b<strlen(dr.Last_Name);b++)
		{
			if (isalpha(dr.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\t\t\tInvalid, Please enter valid character : :(  Enter again :)");
			goto B;
		}
	}
/* ******************************************* Gender ************************************************************** */
clearLine();
pointXY(0,0);
 do{
    pointXY(0,0);
    Gender:
    printf("\n\n\n\n\n\n\n\t\t\tGender[F/M]: ");
    scanf("%s",&dr.Gender);
    dr.Gender[0] = toupper(dr.Gender[0]);
    switch(dr.Gender[0]){
        case 'M':
        case 'm':
            on =1;
            break;
        case 'F':
        case 'f':
            on =1;
            break;
        default:
            on = 0;
            printf("\t\t\tPlease Enter Valid Input \n");
    }

    }while(!on);

/* ***************************************** JoinDate ********************************************************************** */
//clearLine();
    pointXY(0,0);

    do{
    G:
    pointXY(0,0);
    clearLine();
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEnter Join Date: ");
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t Day:");
    scanf("%s",dd);
    pointXY(0,0);
    clearLine();
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEnter Join Date: ");
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\t\t\t Month:");
    scanf("%s", mm);
    pointXY(0,0);
    clearLine();
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEnter Join Date: ");
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\t\t\t Year:");
    scanf("%s", yy);

    if(!dateValidation(dd, mm, yy)){
        SetColor();
        getch();
		goto G;
	}else{
        valid = 1;
	}
	dr.JoinDate[0] = dd[0];dr.JoinDate[1] = dd[1];dr.JoinDate[2] = seperator[0];
	dr.JoinDate[3]=mm[0]; dr.JoinDate[4]=mm[1];	dr.JoinDate[5]=seperator[0]; dr.JoinDate[6]=yy[0];
	dr.JoinDate[7]=yy[1]; dr.JoinDate[8]=yy[2]; dr.JoinDate[9]=yy[3];
    }while(!valid);

/* **************************************** Address ******************************************************************* */
 clearLine();
pointXY(0,0);
    do
    {
    C:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tAddress: ");
    scanf("%s",&dr.Address);
    dr.Address[0]=toupper(dr.Address[0]);
    if(strlen(dr.Address)>20||strlen(dr.Address)<4)
	{
		printf("\t\t\tInvalid :( \t MAX Length 20 MIN Length 4 :)");
		goto C;
	}

}while(!valid);
/* ******************************************* Contact no. ***************************************** */
clearLine();
pointXY(0,0);
do
{
	D:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tContact no: ");
    scanf("%s",dr.Contact_no);
    if(strlen(dr.Contact_no)>11||strlen(dr.Contact_no)!=11){
		printf("\t\t\tSorry :( Invalid. Contact no. must contain 11 numbers. Enter again :)");
		goto D;
	}
	else{
		for (b=0;b<strlen(dr.Contact_no);b++)
		{
			if (!isalpha(dr.Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\t\t\tInvalid character, Please enter valid character : :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);


/* ************************************************** Email ******************************************** */
clearLine();
pointXY(0,0);
EM:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEmail: ");
    scanf("%s",dr.Email);


    if(valid_mail(dr.Email) == -1){
        SetColor(12);
       printf("\t\t\tIn valid emial");
       ColorSet();
       goto EM;
    }





/* ********************************************************* Designation *********************************************** */
 clearLine();
pointXY(0,0);
    E:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tDesignation: ");
    scanf("%s",dr.designation);
    dr.designation[0]=toupper(dr.designation[0]);
    if(strlen(dr.designation)>15||strlen(dr.designation)<3)
	{
	    SetColor();
		printf("\t\t\tInvalid :( \t The max range for first name is 15 and min range is 3 :)");
		ColorSet();
		goto E;
	}
	else{
		for (b=0;b<strlen(dr.designation);b++){
			if (isalpha(dr.designation[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
            SetColor(12);
			printf("\t\t\tInvalid character :(  Enter again :)");
            ColorSet();
			goto E;
		}
	}
/* ********************************************** Department **************************************** */
clearLine();
pointXY(0,0);
	F:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tDepartment:");
    scanf("%s",dr.Department);
    dr.Department[0]=toupper(dr.Department[0]);
    if( strlen(dr.Department)>30||strlen(dr.Department)<3){
        SetColor();
		printf("\t\t\tInvalid :( \t The max range for first name is 30 and min range is 3 :)");
        ColorSet();
		goto F;
	}
	else{
		for (b=0;b<strlen(dr.Department);b++){
			if (isalpha(dr.Department[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
            SetColor();
			printf("\t\t\tDepartment name contain Invalid character :(  Enter again :)");
            ColorSet();
			goto F;
		}
	}

    fprintf(ek," %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", dr.DrId, dr.First_Name, dr.Last_Name, dr.Gender, dr.JoinDate, dr.Address, dr.Contact_no, dr.Email, dr.designation, dr.Department);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    printf("\n\t\t\t.... Press Enter to continue ...");
    fclose(ek);//ek file is closed
    sd:
    pointXY(0,0);
    getch();
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	addNewDoctor();
	}
    else if(toupper(ans)=='N'){
    	drInfo();
	}
    else{
        printf("\t\t\tInvalid Input\n");
        goto sd;
    }
}

/* ********************************************** Doctor List **************************************** */

/* ********************************************** Doctor List **************************************** */

doctorList(){
     clearWindow();
    ColorSet();
    int row;
	FILE *ek;
	ek=fopen("data/Doctor-information.csv","r");
    pointXY(0,0);
    printf("\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	getTitle();
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|DR ID NO");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Join Date");
		pointXY(45,drlistTitltRow);
		printf("|Address");
		pointXY(60,drlistTitltRow);
		printf("|Contact No.");
		pointXY(77,drlistTitltRow);
		printf("|Email");
		pointXY(92,drlistTitltRow);
		printf("|Designation");
		pointXY(106,drlistTitltRow);
		printf("|Department|\n");

		printf("=======================================================================================================================\n");
		row=9;
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
					&dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email,&dr.designation, &dr.Department)!=EOF){


		    pointXY(0,row);
			printf("|%s",dr.DrId);
		    pointXY(11,row);
			printf("|%s %s",dr.First_Name, dr.Last_Name);
			pointXY(26,row);
			printf("|%s",dr.Gender);
			pointXY(34,row);
			printf("|%s",dr.JoinDate);
			pointXY(45,row);
			printf("|%s",dr.Address);
			pointXY(60,row);
			printf("|%s",dr.Contact_no);
			pointXY(77,row);
			printf("|%s",dr.Email);
			pointXY(92,row);
			printf("|%s", dr.designation );
            pointXY(106,row);
			printf("|%s", dr.Department );

			row++;
		}
		fclose(ek);
        char item;
        printf("\n\n\t\t\t\t Back->'Backspace', Admin Menu->'ESC'...");
        item = getche();
        if(item == BKSP){
            drInfo();
        }else if(item == ESC){
            adminMenu();
        }else{
            doctorList();
        }

}
/* ********************************************** Search **************************************** */
void searchDoctor(void){
     clearWindow();
	char DrIds[11];
	pointXY(0,0);
	singleSearchDr();
	FILE *ek;
	ek=fopen("data/Doctor-Information.csv","r");
    printf("\n\n\t\t\tSearch with ID no: ");
    scanf("%s",DrIds);
	fflush(stdin);
    int row= 13;
	while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s \n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
					&dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department)!=EOF){
        if(dr.DrId[0] == DrIds[0] && dr.DrId[1] == DrIds[1] && dr.DrId[2] == DrIds[2] && dr.DrId[3] == DrIds[3] &&dr.DrId[4] == DrIds[4] &&dr.DrId[5] == DrIds[5] &&  dr.DrId[6] == DrIds[6] && dr.DrId[7] == DrIds[7] && dr.DrId[8] == DrIds[8] &&dr.DrId[9] == DrIds[9]){
        clearWindow();
        pointXY(12,0);

	printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	getTitle();
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");
        int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|DR ID NO");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Join Date");
		pointXY(45,drlistTitltRow);
		printf("|Address");
		pointXY(60,drlistTitltRow);
		printf("|Contact No.");
		pointXY(77,drlistTitltRow);
		printf("|Email");
		pointXY(92,drlistTitltRow);
		printf("|Designation");
		pointXY(106,drlistTitltRow);
		printf("|Department|\n");
		printf("=======================================================================================================================\n");
		row=9;

//            dr.Last_Name[strlen(dr.Last_Name)-1] = '\0';
//            dr.Address[strlen(dr.Address)-1] = '\0';
//            dr.Email[strlen(dr.Email)-1] = '\0';
//            dr.designation[strlen(dr.designation)-1] = '\0';
//            dr.DrId[strlen(dr.DrId)-1] = '\0';
//            dr.Gender[strlen(dr.Gender)-1] = '\0';
//            dr.Contact_no[strlen(dr.Contact_no)-1] = '\0';
//            dr.Department[strlen(dr.Department)-1] = '\0';



		    pointXY(0,row);
			printf("|%s",dr.DrId);
		    pointXY(11,row);
			printf("|%s %s",dr.First_Name, dr.Last_Name);
			pointXY(26,row);
			printf("|%s",dr.Gender);
			pointXY(34,row);
			printf("|%s",dr.JoinDate);
			pointXY(45,row);
			printf("|%s",dr.Address);
			pointXY(60,row);
			printf("|%s",dr.Contact_no);
			pointXY(77,row);
			printf("|%s",dr.Email);
			pointXY(92,row);
			printf("|%s", dr.designation );
            pointXY(106,row);
			printf("|%s", dr.Department );
            pointXY(112,row);
			break;
		}
	   }
	   if(dr.DrId[0] != DrIds[0] && dr.DrId[1] != DrIds[1] && dr.DrId[2] != DrIds[2] && dr.DrId[3] != DrIds[3] &&dr.DrId[4] != DrIds[4] &&dr.DrId[5] != DrIds[5] &&  dr.DrId[6]!= DrIds[6] && dr.DrId[7] != DrIds[7] && dr.DrId[8] != DrIds[8] &&dr.DrId[9] != DrIds[9]){
		pointXY(5,8);
        SetColor(12);
		printf("\t\t\tNot found!");
		ColorSet();
	   }
	fclose(ek);
	Agin:
	printf("\n\n\t\t\tDo you want to search more[Y/N]??");
    scanf("%c",&reply);
    if (toupper(reply)=='Y'){
        searchDoctor();
    }else if(toupper(reply)=='N'){
		drInfo();
    }else{

        SetColor(12);
    	printf("\n\tInvalid Input.\n");
    	ColorSet();
    	goto Agin;
    }
}
/* ********************************************** Update Information **************************************** */

/* ********************************************** Update Information **************************************** */
void updateDoctorInfo(void){
    clearWindow();
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    int DrIds;
        Title();// call Title window
 		ft=fopen("data/updateDoctor.csv","w+");
	   ek=fopen("data/Doctor-Information.csv","r");
	   if(ek==NULL){
		printf("\n\t Can not open file!! ");
		getch();
		adminMenu();
	   }
        ColorSet();
        pointXY(12,0);
        printf("\n\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Edit Doctor Record \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	   	printf("\n\n\t\t\t\tEnter Dr's Id : ");
	   	scanf("%d",&DrIds);
	   	fflush(stdin);
	   //	name[0]=toupper(name[0]);
		pointXY(12,15);

		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			adminMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
					&dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department)!=EOF)
		{
        if(stringConverter(dr.DrId) == DrIds){
            valid=1;
            pointXY(25,17);
            printf("*** Existing Record ***");
            pointXY(10,19);



            clearWindow();
               pointXY(0,0);
        printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        getTitle();
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|DR ID NO");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Join Date");
		pointXY(45,drlistTitltRow);
		printf("|Address");
		pointXY(60,drlistTitltRow);
		printf("|Contact No.");
		pointXY(77,drlistTitltRow);
		printf("|Email");
		pointXY(92,drlistTitltRow);
		printf("|Designation");
		pointXY(106,drlistTitltRow);
		printf("|Department|\n");
		printf("=======================================================================================================================\n");
		int row=9;
		    pointXY(0,row);
			printf("|%s",dr.DrId);
		    pointXY(11,row);
			printf("|%s %s",dr.First_Name, dr.Last_Name);
			pointXY(26,row);
			printf("|%s",dr.Gender);
			pointXY(34,row);
			printf("|%s",dr.JoinDate);
			pointXY(45,row);
			printf("|%s",dr.Address);
			pointXY(60,row);
			printf("|%s",dr.Contact_no);
			pointXY(77,row);
			printf("|%s",dr.Email);
			pointXY(92,row);
			printf("|%s", dr.designation );
            pointXY(106,row);
			printf("|%s", dr.Department );
            pointXY(112,row);

            pointXY(12,12);
            printf("Enter New First Name: ");
            scanf("%s",dr.First_Name);
            pointXY(12,13);
            printf("Enter Last Name: ");
            scanf("%s",dr.Last_Name);
            pointXY(12,14);
            printf("Enter Gender: ");
            scanf("%s",&dr.Gender);
            dr.Gender[0] = toupper(dr.Gender[0]);
            pointXY(12,15);
            printf("Enter Join Date: ");
            scanf(" %s",&dr.JoinDate);
            pointXY(12,16);
            printf("Enter Address: ");
            scanf("%s",dr.Address);
            dr.Address[0]=toupper(dr.Address[0]);
            pointXY(12,17);
            printf("Enter Contact no: ");
            scanf("%s",dr.Contact_no);
            pointXY(12,18);
            printf("Enter email: ");
            scanf("%s",dr.Email);
            pointXY(12,19);
            printf("Enter Designation: ");
            scanf("%s",dr.designation);
            dr.designation[0]=toupper(dr.designation[0]);
            pointXY(12,20);
            printf("Enter Department: ");
            scanf("%s",dr.Department);
            dr.Department[0]=toupper(dr.Department[0]);
            printf("\nPress 'E' for the Updating operation : ");
            ch=getche();
            if(ch=='e' || ch=='E')
            {
            fprintf(ft,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
                &dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department);
            printf("\n\n\t\t\tDoctor record updated successfully...");
            }
			}
			else
			{
			fprintf(ft,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
					&dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department);
			}
		 }
		 if(!valid){
                SetColor(12);
                pointXY(0,0);
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNO RECORD FOUND...");
                ColorSet();

         getch();}

	   fclose(ft);
	   fclose(ek);
	   remove("data/Doctor-information.csv");
   	   rename("data/updateDoctor.csv","data/Doctor-information.csv");
		getch();
		drInfo();
}
/* ********************************************** Delete Information **************************************** */


void deleteInfo(){
    clearWindow();
    ColorSet();
	int DrIds;
	int found=0;
	FILE *ek, *fileData;
	fileData=fopen("data/delete-doctor.csv","w+");
	ek=fopen("data/Doctor-information.csv","r");
	pointXY(30, 0);
	singleLineDelete();
	printf("\n\n\t\t\t\t============== Delete Doctor Record =============\n");
	printf("\n\t\t Enter Doctor ID to Delete: ");
	fflush(stdin);
	scanf("%d", &DrIds);

	while (fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name,
					&dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department)!=EOF){

        //if(dr.DrId[0] != DrIds[0] && dr.DrId[1] != DrIds[1] && dr.DrId[2] != DrIds[2] && dr.DrId[3] != DrIds[3] && dr.DrId[4] != DrIds[4] &&dr.DrId[5] != DrIds[5] &&  dr.DrId[6]!= DrIds[6] && dr.DrId[7] != DrIds[7] && dr.DrId[8] != DrIds[8] && dr.DrId[9] != DrIds[9])
        if(stringConverter(dr.DrId) != DrIds)
            fprintf(fileData,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &dr.DrId, &dr.First_Name, &dr.Last_Name, &dr.Gender, &dr.JoinDate, &dr.Address, &dr.Contact_no, &dr.Email, &dr.designation, &dr.Department);
		else{
        int row = 11;
		int drlistTitltRow =9;
        pointXY(0,8);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|DR ID");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Join Date");
		pointXY(45,drlistTitltRow);
		printf("|Address");
		pointXY(62,drlistTitltRow);
		printf("|Contact No.");
		pointXY(79,drlistTitltRow);
		printf("|Email");
		pointXY(94,drlistTitltRow);
		printf("|Designation");
		pointXY(107,drlistTitltRow);
		printf("|Department|\n");
		printf("=======================================================================================================================\n");

            pointXY(0,row);
			printf("|%s",dr.DrId);
		    pointXY(11,row);
			printf("|%s %s",dr.First_Name, dr.Last_Name);
			pointXY(26,row);
			printf("|%s",dr.Gender);
			pointXY(34,row);
			printf("|%s",dr.JoinDate);
			pointXY(45,row);
			printf("|%s",dr.Address);
			pointXY(62,row);
			printf("|%s",dr.Contact_no);
			pointXY(79,row);
			printf("|%s",dr.Email);
			pointXY(94,row);
			printf("|%s", dr.designation );
            pointXY(107,row);
			printf("|%s", dr.Department );
			printf("\n");
			found=1;
		}
	}
	if(found==0){
		printf("\n\n\t\t\t Record not found....Press Any Key");
		getch();
		drInfo();
	}
	else{
    Agin:
	ColorSet();
	char reply[2];
	pointXY(30, 13);
	SetColor(12);
    printf("Are you sure to delete this record ? Y/N : ");
    ColorSet();
    scanf("%s",&reply);
    if (reply[0]=='Y' || reply[0] == 'y'){
        fclose(ek);
		fclose(fileData);
		remove("data/Doctor-Information.csv");
		rename("data/delete-doctor.csv","data/Doctor-Information.csv");
		SetColor(10);
		printf("\n\n\t\t\t Record deleted successfully :) Enter to Continue ");
		ColorSet();
		getch();
		drInfo();
    }else if(toupper(reply[0])=='N'){
		drInfo();
    }else{
        pointXY(30, 15);
    	printf("Invalid Input.\n");
    	goto Agin;
    }

	}
}


