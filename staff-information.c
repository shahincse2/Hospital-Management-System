
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
Employee Information
=========================*/
char replies = 0;
char answare1=0;
int ok, up=0;
int a, b, checkValid=0, ifDone =0, ifwork = 0;
//FUNCTION DECLERATION
void WelcomeScreen(void);
void Add_stf_rec(void);
void StaffList();
void searchStaff(void);
void updateStaffInfo(void);
void deleteSTFInfo(void);

struct Staff{
    char StfId[11];
	char First_Name[20];
	char Last_Name[20];
    char Gender[3];
	char JoinDate[11];
	char Address[30];
	char Contact_no[15];
	char Email[30];
	char designation[20];
	char Department[20];
};

struct Staff  stf,temp_c;

char ddd[3],mmm[3],yyy[4];

/*Menu select---------------------*/
staffInfo(){;
    clearWindow();
	int choose;
   ColorSet();
	pointXY(0,0);
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Employee Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	printf("\n\n\t\t\t\t1. Add Employee List\n");
	printf("\n\t\t\t\t2. Employee List\n");
	printf("\n\t\t\t\t3. Search Employee\n");
	printf("\n\t\t\t\t4. Edit Employee Information\n");
	printf("\n\t\t\t\t5. Delete Employee From List\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);

	switch(choose){

	case 1:
	addNewStf();
    	break;
    case 2:
    	StaffList();
    	break;
	case 3:
	searchStaff();
    	break;
	case 4:
		updateStaffInfo();
		break;
	case 5:
		deleteSTFInfo();
		break;
	case 6:
		adminMenu();
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch

}

addNewStf(){
    char seperator[3] = "/|";
    int valid=0,b, okey, one = 0, on=0;
     clearWindow();
     ColorSet();
/* **************************************ADD RECORD*******************************************/
	char ans;
	FILE*ek;//file pointer
	ek=fopen("data/Employee-Information.csv","a");//open file in write mode
    pointXY(0,0);
	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Employee Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    char item;
     printf("\n\t\t\t Continue->'Enter', Back->'Backspace'...");
	item = getche();
	if(item == BKSP){
        staffInfo();
	}else if(item == ESC){
        adminMenu();
	}
/* ******************************************* ID no. ***************************************** */
do{
	I:
    printf("\n\n\t\t\tID no: ");
    scanf("%s",stf.StfId);
    if(strlen(stf.StfId)>10||strlen(stf.StfId)!=10){
        SetColor(12);
		printf("\t\t\t( Please Use 10 digit. Enter again :)");
        ColorSet();
		goto I;
	}
	else{
		for (b=0;b<strlen(stf.StfId);b++)
		{
			if (!isalpha(stf.StfId[b]))
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
	scanf("%s",stf.First_Name);
	stf.First_Name[0]=toupper(stf.First_Name[0]);
	if(strlen(stf.First_Name)>20||strlen(stf.First_Name)<2){
		printf("\t\t\t Invalid :( \t Please Enter 2-20 Letter First Name :)");
		goto A;
	}
	else{
		for (b=0;b<strlen(stf.First_Name);b++){
			if (isalpha(stf.First_Name[b])){
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
    scanf("%s",stf.Last_Name);
    stf.Last_Name[0]=toupper(stf.Last_Name[0]);
    if(strlen(stf.Last_Name)>20||strlen(stf.Last_Name)<2){
		printf("\t\t\tInvalid :( \t The maximum lenght for last name is 20 and min range is 2 :)");
		goto B;
	}
	else{
		for (b=0;b<strlen(stf.Last_Name);b++)
		{
			if (isalpha(stf.Last_Name[b]))
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
    scanf("%s",&stf.Gender);
    stf.Gender[0] = toupper(stf.Gender[0]);
    switch(stf.Gender[0]){
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


       pointXY(0,0);

    do{
    G:
    pointXY(0,0);
    clearLine();
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEnter Join Date: ");
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t Day:");
    scanf("%s",ddd);
    pointXY(0,0);
    clearLine();
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEnter Join Date: ");
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\t\t\t Month:");
    scanf("%s", mmm);
    pointXY(0,0);
    clearLine();
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tEnter Join Date: ");
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\t\t\t Year:");
    scanf("%s", yyy);

    if(!dateValidation(ddd, mmm, yyy)){
        SetColor();
        getch();
		goto G;
	}else{
        valid = 1;
	}
	stf.JoinDate[0] = ddd[0];stf.JoinDate[1] = ddd[1];stf.JoinDate[2] = seperator[0];
	stf.JoinDate[3]=mmm[0]; stf.JoinDate[4]=mmm[1];	stf.JoinDate[5]=seperator[0]; stf.JoinDate[6]=yyy[0];
	stf.JoinDate[7]=yyy[1]; stf.JoinDate[8]=yyy[2]; stf.JoinDate[9]=yyy[3];



    }while(!valid);


/* **************************************** Address ******************************************************************* */
 clearLine();
pointXY(0,0);
    do
    {
    C:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tAddress: ");
    scanf("%s",&stf.Address);
    stf.Address[0]=toupper(stf.Address[0]);
    if(strlen(stf.Address)>20||strlen(stf.Address)<4)
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
    scanf("%s",stf.Contact_no);
    if(strlen(stf.Contact_no)>11||strlen(stf.Contact_no)!=11){
		printf("\t\t\tSorry :( Invalid. Contact no. must contain 11 numbers. Enter again :)");
		goto D;
	}
	else{
		for (b=0;b<strlen(stf.Contact_no);b++)
		{
			if (!isalpha(stf.Contact_no[b]))
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
    scanf("%s",stf.Email);


    if(valid_mail(stf.Email) == -1){
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
    scanf("%s",stf.designation);
    stf.designation[0]=toupper(stf.designation[0]);
    if(strlen(stf.designation)>15||strlen(stf.designation)<3)
	{
	    SetColor();
		printf("\t\t\tInvalid :( \t The max range for first name is 15 and min range is 3 :)");
		ColorSet();
		goto E;
	}
	else{
		for (b=0;b<strlen(stf.designation);b++){
			if (isalpha(stf.designation[b])){
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
    scanf("%s",stf.Department);
    stf.Department[0]=toupper(stf.Department[0]);
    if( strlen(stf.Department)>30||strlen(stf.Department)<3){
        SetColor();
		printf("\t\t\tInvalid :( \t The max range for first name is 30 and min range is 3 :)");
        ColorSet();
		goto F;
	}
	else{
		for (b=0;b<strlen(stf.Department);b++){
			if (isalpha(stf.Department[b])){
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

    fprintf(ek," %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", stf.StfId, stf.First_Name, stf.Last_Name, stf.Gender, stf.JoinDate, stf.Address, stf.Contact_no, stf.Email, stf.designation, stf.Department);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    printf("\n\t\t\t.... Press Enter to continue ...");
    fclose(ek);//ek file is closed
    sd:
    pointXY(0,0);
    getch();
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y'){
    	addNewStf();
	}
    else if(toupper(ans)=='N'){
    	staffInfo();
	}
    else{
        printf("\t\t\tInvalid Input\n");
        goto sd;
    }
}

/* ********************************************** Employee List **************************************** */

/* ********************************************** Employee List **************************************** */

StaffList(){
     clearWindow();
    ColorSet();
    int row;
	FILE *ek;
	ek=fopen("data/Employee-information.csv","r");
    pointXY(0,0);
	printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	getTitle();
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|EM ID NO");
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
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &stf.StfId, &stf.First_Name, &stf.Last_Name,
					&stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email,&stf.designation, &stf.Department)!=EOF){

		    pointXY(0,row);
			printf("|%s",stf.StfId);
		    pointXY(11,row);
			printf("|%s %s",stf.First_Name, stf.Last_Name);
			pointXY(26,row);
			printf("|%s",stf.Gender);
			pointXY(34,row);
			printf("|%s",stf.JoinDate);
			pointXY(45,row);
			printf("|%s",stf.Address);
			pointXY(60,row);
			printf("|%s",stf.Contact_no);
			pointXY(77,row);
			printf("|%s",stf.Email);
			pointXY(92,row);
			printf("|%s", stf.designation );
            pointXY(106,row);
			printf("|%s", stf.Department );

			row++;
		}
		fclose(ek);
        char item;
        printf("\n\n\t\t\t\t Back->'Backspace', Admin Menu->'ESC'...");
        item = getche();
        if(item == BKSP){
            staffInfo();
        }else if(item == ESC){
            adminMenu();
        }else{
            StaffList();
        }

}
/* ********************************************** Search **************************************** */
void searchStaff(void){
     clearWindow();
	char DrIds[11];
	pointXY(0,0);
	singleSearchDr();
	FILE *ek;
	ek=fopen("data/Employee-Information.csv","r");
    printf("\n\n\t\t\tSearch with ID no: ");
    scanf("%s",DrIds);
	fflush(stdin);
    int row= 13;
	while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s \n", &stf.StfId, &stf.First_Name, &stf.Last_Name,
					&stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email, &stf.designation, &stf.Department)!=EOF){
        if(stf.StfId[0] == DrIds[0] && stf.StfId[1] == DrIds[1] && stf.StfId[2] == DrIds[2] && stf.StfId[3] == DrIds[3] &&stf.StfId[4] == DrIds[4] &&stf.StfId[5] == DrIds[5] &&  stf.StfId[6] == DrIds[6] && stf.StfId[7] == DrIds[7] && stf.StfId[8] == DrIds[8] &&stf.StfId[9] == DrIds[9]){
        clearWindow();
        pointXY(0,0);
        printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        getTitle();
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|EM ID NO");
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
		    pointXY(0,row);
			printf("|%s",stf.StfId);
		    pointXY(11,row);
			printf("|%s %s",stf.First_Name, stf.Last_Name);
			pointXY(26,row);
			printf("|%s",stf.Gender);
			pointXY(34,row);
			printf("|%s",stf.JoinDate);
			pointXY(45,row);
			printf("|%s",stf.Address);
			pointXY(60,row);
			printf("|%s",stf.Contact_no);
			pointXY(77,row);
			printf("|%s",stf.Email);
			pointXY(92,row);
			printf("|%s", stf.designation );
            pointXY(106,row);
			printf("|%s", stf.Department );
            pointXY(112,row);
			break;
		}
	   }
	   if(stf.StfId[0] != DrIds[0] && stf.StfId[1] != DrIds[1] && stf.StfId[2] != DrIds[2] && stf.StfId[3] != DrIds[3] &&stf.StfId[4] != DrIds[4] &&stf.StfId[5] != DrIds[5] &&  stf.StfId[6]!= DrIds[6] && stf.StfId[7] != DrIds[7] && stf.StfId[8] != DrIds[8] &&stf.StfId[9] != DrIds[9]){
		pointXY(5,8);
        SetColor(12);
		printf("\t\t\tNot found!");
		ColorSet();
	   }
	fclose(ek);
	char reply;
	Agin:
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&reply);
    if (toupper(reply)=='Y'){
        searchStaff();
    }else if(toupper(reply)=='N'){
		staffInfo();
    }else{

        SetColor(12);
    	printf("\n\tInvalid Input.\n");
    	ColorSet();
    	goto Agin;
    }
}
/* ********************************************** Update Information **************************************** */

/* ********************************************** Update Information **************************************** */
void updateStaffInfo(void){
    clearWindow();
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char DrIds[11];
        Title();// call Title window
 		ft=fopen("data/updateEmployee.csv","w+");
	   ek=fopen("data/Employee-Information.csv","r");
	   if(ek==NULL){
		printf("\n\t Can not open file!! ");
		getch();
		adminMenu();
	   }
        ColorSet();
        pointXY(12,0);
        printf("\n\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Edit Employee Record \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	   	printf("\n\n\t\t\t\tEnter Dr's Id : ");
	   	scanf(" %s",DrIds);
	   	fflush(stdin);
	   //	name[0]=toupper(name[0]);
		pointXY(12,15);

		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			adminMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &stf.StfId, &stf.First_Name, &stf.Last_Name,
					&stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email, &stf.designation, &stf.Department)!=EOF)
		{
			if(stf.StfId[0] == DrIds[0] && stf.StfId[1] == DrIds[1] && stf.StfId[2] == DrIds[2] && stf.StfId[3] == DrIds[3] &&stf.StfId[4] == DrIds[4] &&stf.StfId[5] == DrIds[5] &&  stf.StfId[6] == DrIds[6] && stf.StfId[7] == DrIds[7] && stf.StfId[8] == DrIds[8] &&stf.StfId[9] == DrIds[9]){
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
        printf("|EM ID NO");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Join Date");
		pointXY(40,drlistTitltRow);
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
			printf("|%s",stf.StfId);
		    pointXY(11,row);
			printf("|%s %s",stf.First_Name, stf.Last_Name);
			pointXY(26,row);
			printf("|%s",stf.Gender);
			pointXY(34,row);
			printf("|%s",stf.JoinDate);
			pointXY(45,row);
			printf("|%s",stf.Address);
			pointXY(60,row);
			printf("|%s",stf.Contact_no);
			pointXY(77,row);
			printf("|%s",stf.Email);
			pointXY(92,row);
			printf("|%s", stf.designation );
            pointXY(106,row);
			printf("|%s", stf.Department );
            pointXY(112,row);

            pointXY(12,12);
            printf("Enter New First Name: ");
            scanf("%s",stf.First_Name);
            pointXY(12,13);
            printf("Enter Last Name: ");
            scanf("%s",stf.Last_Name);
            pointXY(12,14);
            printf("Enter Gender: ");
            scanf("%s",&stf.Gender);
            stf.Gender[0] = toupper(stf.Gender[0]);
            pointXY(12,15);
            printf("Enter Join Date: ");
            scanf(" %s",&stf.JoinDate);
            pointXY(12,16);
            printf("Enter Address: ");
            scanf("%s",stf.Address);
            stf.Address[0]=toupper(stf.Address[0]);
            pointXY(12,17);
            printf("Enter Contact no: ");
            scanf("%s",stf.Contact_no);
            pointXY(12,18);
            printf("Enter New email: ");
            scanf("%s",stf.Email);
            pointXY(12,19);
            printf("Enter Designation: ");
            scanf("%s",stf.designation);
            stf.designation[0]=toupper(stf.designation[0]);
            pointXY(12,20);
            printf("Enter Department: ");
            scanf("%s",stf.Department);
            stf.Department[0]=toupper(stf.Department[0]);
            printf("\nPress E charecter for the Updating operation : ");
            ch=getche();
            if(ch=='e' || ch=='E')
            {
            fprintf(ft,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &stf.StfId, &stf.First_Name, &stf.Last_Name,
                &stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email, &stf.designation, &stf.Department);
            printf("\n\n\t\t\tPatient record updated successfully...");
            }
			}
			else
			{
			fprintf(ft,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &stf.StfId, &stf.First_Name, &stf.Last_Name,
					&stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email, &stf.designation, &stf.Department);
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
	   remove("data/Employee-information.csv");
   	   rename("data/updateEmployee.csv","data/Employee-information.csv");
		getch();
		staffInfo();
}
/* ********************************************** Delete Information **************************************** */


void deleteSTFInfo(){
    clearWindow();
    ColorSet();
	int DrIds;
	int found=0;
	FILE *ek, *fileData;
	fileData=fopen("data/delete-Employee.csv","w+");
	ek=fopen("data/Employee-information.csv","r");
	pointXY(30, 0);
	singleLineDelete();
	printf("\n\n\t\t\t============== Delete Employee Record =============\n");
	printf("\n\t\t Enter Employee ID to Delete: ");
	fflush(stdin);
	scanf("%d", &DrIds);

	while (fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &stf.StfId, &stf.First_Name, &stf.Last_Name,
					&stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email, &stf.designation, &stf.Department)!=EOF){

        //if(stf.StfId[0] != DrIds[0] && stf.StfId[1] != DrIds[1] && stf.StfId[2] != DrIds[2] && stf.StfId[3] != DrIds[3] && stf.StfId[4] != DrIds[4] &&stf.StfId[5] != DrIds[5] &&  stf.StfId[6]!= DrIds[6] && stf.StfId[7] != DrIds[7] && stf.StfId[8] != DrIds[8] && stf.StfId[9] != DrIds[9])
        if(stringConverter(stf.StfId) != DrIds)
            fprintf(fileData,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &stf.StfId, &stf.First_Name, &stf.Last_Name, &stf.Gender, &stf.JoinDate, &stf.Address, &stf.Contact_no, &stf.Email, &stf.designation, &stf.Department);
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
			printf("|%s",stf.StfId);
		    pointXY(11,row);
			printf("|%s %s",stf.First_Name, stf.Last_Name);
			pointXY(26,row);
			printf("|%s",stf.Gender);
			pointXY(34,row);
			printf("|%s",stf.JoinDate);
			pointXY(45,row);
			printf("|%s",stf.Address);
			pointXY(62,row);
			printf("|%s",stf.Contact_no);
			pointXY(79,row);
			printf("|%s",stf.Email);
			pointXY(94,row);
			printf("|%s", stf.Department );
            pointXY(107,row);
			printf("|%s", stf.Department );
			printf("\n");
			found=1;
		}
	}
	if(found==0){
		printf("\n\n\t\t\t Record not found....Press Any Key");
		getch();
		staffInfo();
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
		remove("data/Employee-Information.csv");
		rename("data/delete-Employee.csv","data/Employee-Information.csv");
		SetColor(10);
		printf("\n\n\t\t\t Record deleted successfully :) Enter to Continue ");
		ColorSet();
		getch();
		staffInfo();
    }else if(toupper(reply[0])=='N'){
		staffInfo();
    }else{
        pointXY(30, 15);
    	printf("Invalid Input.\n");
    	goto Agin;
    }

	}
}


