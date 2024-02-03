
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
Patient Information
=========================*/

char repeatReply = 0;
char answare=0;
char reply;

int x, y, validate=0;
//FUNCTION DECLERATION
void AddNewPatient(void);
void PatientList();
void SearchPatient(void);
void UpdatePatientInfo(void);
void DeletePatientInfo(void);


struct Patient{
    char PatientId[11];
	char First_Name[20];
	char Last_Name[20];
    char Gender[3];
	char Age[6];
	char Address[30];
	char Contact_no[15];
	char Email[30];
	char Problem[20];
	char DrName[20];
};

struct Patient  pt,temp_c;
/*Menu select---------------------*/
patientInfo(){
    clearWindow();
	int choose;
	ColorSet();
	pointXY(0,0);
    patientInformationTitle();
	printf("\n\n\t\t\t\t1. Add Patient List\n");
	printf("\n\t\t\t\t2. Check Patinet List\n");
	printf("\n\t\t\t\t3. Search Patient\n");
	printf("\n\t\t\t\t4. Edit Patient Information\n");
	printf("\n\t\t\t\t5. Delete Patient From List\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);

	switch(choose){

	case 1:
        AddNewPatient();
    	break;
    case 2:
    	PatientList();
    	break;
	case 3:
        SearchPatient();
    	break;
	case 4:
		UpdatePatientInfo();
		break;
	case 5:
		DeletePatientInfo();
		break;
	case 6:
		adminMenu();
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch

}



AddNewPatient(){
      int valid=0,b, okey, one = 0, on=0;
     clearWindow();
     ColorSet();
/* **************************************ADD RECORD*******************************************/
	char ans;
	FILE*ek;//file pointer
	ek=fopen("data/Patient-Information.csv","a");//open file in write mode
    pointXY(0,0);
	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Patient Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    char item;
     printf("\n\t\t\t Continue->'Enter', Back->'Backspace'..., 'ESC'->Main Menu");
	item = getche();
	if(item == BKSP){
        patientInfo();
	}else if(item == ESC){
        adminMenu();
	}
/* ******************************************* ID no. ***************************************** */

do{

	I:
    printf("\n\n\t\t\tID no: ");
    scanf("%s",pt.PatientId);
    if(strlen(pt.PatientId)>10||strlen(pt.PatientId)!=10){
        SetColor(12);
		printf("\t\t\t( Please Use 10 digit. Enter again :)");
        ColorSet();
		goto I;
	}
	else{
		for (int b=0;b<strlen(pt.PatientId);b++)
		{
			if (!isalpha(pt.PatientId[b]))
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
	scanf("%s",pt.First_Name);
	pt.First_Name[0]=toupper(pt.First_Name[0]);
	if(strlen(pt.First_Name)>20||strlen(pt.First_Name)<2){
		printf("\t\t\t Invalid :( \t Please Enter 2-20 Letter First Name :)");
		goto A;
	}
	else{
		for (b=0;b<strlen(pt.First_Name);b++){
			if (isalpha(pt.First_Name[b])){
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
    scanf("%s",pt.Last_Name);
    pt.Last_Name[0]=toupper(pt.Last_Name[0]);
    if(strlen(pt.Last_Name)>20||strlen(pt.Last_Name)<2){
		printf("\t\t\tInvalid :( \t The maximum lenght for last name is 20 and min range is 2 :)");
		goto B;
	}
	else{
		for (b=0;b<strlen(pt.Last_Name);b++)
		{
			if (isalpha(pt.Last_Name[b]))
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
    scanf("%s",&pt.Gender);
    pt.Gender[0] = toupper(pt.Gender[0]);
    switch(pt.Gender[0]){
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

/* ***************************************** Age ********************************************************************** */
    clearLine();
    pointXY(0,0);

    printf("\n\n\n\n\n\n\n\t\t\tAge: ");
    scanf("%s",&pt.Age);

/* **************************************** Address ******************************************************************* */
 clearLine();
pointXY(0,0);
    do
    {
    C:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tAddress: ");
    scanf("%s",&pt.Address);
    pt.Address[0]=toupper(pt.Address[0]);
    if(strlen(pt.Address)>20||strlen(pt.Address)<4)
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
    scanf("%s",pt.Contact_no);
    if(strlen(pt.Contact_no)>11||strlen(pt.Contact_no)!=11){
		printf("\t\t\tSorry :( Invalid. Contact no. must contain 11 numbers. Enter again :)");
		goto D;
	}
	else{
		for (b=0;b<strlen(pt.Contact_no);b++)
		{
			if (!isalpha(pt.Contact_no[b]))
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
    scanf("%s",pt.Email);


    if(valid_mail(pt.Email) == -1){
        SetColor(12);
       printf("\t\t\tIn valid emial");
       ColorSet();
       goto EM;
    }





/* ********************************************************* Problem *********************************************** */
 clearLine();
pointXY(0,0);
    E:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tProblem: ");
    scanf("%s",pt.Problem);
    pt.Problem[0]=toupper(pt.Problem[0]);
    if(strlen(pt.Problem)>15||strlen(pt.Problem)<3)
	{
	    SetColor();
		printf("\t\t\tInvalid :( \t The max range for first name is 15 and min range is 3 :)");
		ColorSet();
		goto E;
	}
	else{
		for (b=0;b<strlen(pt.Problem);b++){
			if (isalpha(pt.Problem[b])){
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
/* ********************************************** DR Name **************************************** */
clearLine();
pointXY(0,0);
	F:
    pointXY(0,0);
    printf("\n\n\n\n\n\n\n\t\t\tDR Name:");
    scanf("%s",pt.DrName);
    pt.DrName[0]=toupper(pt.DrName[0]);
    if( strlen(pt.DrName)>30||strlen(pt.DrName)<3){
        SetColor();
		printf("\t\t\tInvalid :( \t The max range for first name is 30 and min range is 3 :)");
        ColorSet();
		goto F;
	}
	else{
		for (b=0;b<strlen(pt.DrName);b++){
			if (isalpha(pt.DrName[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
            SetColor();
			printf("\t\t\tDR Name name contain Invalid character :(  Enter again :)");
            ColorSet();
			goto F;
		}
	}

    fprintf(ek," %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", pt.PatientId, pt.First_Name, pt.Last_Name, pt.Gender, pt.Age, pt.Address, pt.Contact_no, pt.Email, pt.Problem, pt.DrName);
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
    	AddNewPatient();
	}
    else if(toupper(ans)=='N'){
    	patientInfo();
	}
    else{
        printf("\t\t\tInvalid Input\n");
        goto sd;
    }
}

/* ********************************************** Patient List **************************************** */

/* ********************************************** Patient List **************************************** */

PatientList(){
     clearWindow();
    ColorSet();
    int row;
	FILE *ek;
	ek=fopen("data/Patient-information.csv","r");
    pointXY(0,0);
	 printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        getTitle();
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
            int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|PT ID NO");
        pointXY(11,drlistTitltRow);
		printf("|Full Name");
		pointXY(26,drlistTitltRow);
		printf("|Gender");
		pointXY(34,drlistTitltRow);
		printf("|Age");
		pointXY(40,drlistTitltRow);
		printf("|Address");
		pointXY(55,drlistTitltRow);
		printf("|Contact No.");
		pointXY(68,drlistTitltRow);
		printf("|Email");
		pointXY(92,drlistTitltRow);
		printf("|Problem");
		pointXY(106,drlistTitltRow);
		printf("|DR Name|\n");

		printf("=======================================================================================================================\n");
		row=9;
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &pt.PatientId, &pt.First_Name, &pt.Last_Name,
					&pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email,&pt.Problem, &pt.DrName)!=EOF){
		    pointXY(0,row);
			printf("|%s",pt.PatientId);
		    pointXY(11,row);
			printf("|%s %s",pt.First_Name, pt.Last_Name);
			pointXY(26,row);
			printf("|%s",pt.Gender);
			pointXY(34,row);
			printf("|%s",pt.Age);
			pointXY(40,row);
			printf("|%s",pt.Address);
			pointXY(55,row);
			printf("|%s",pt.Contact_no);
			pointXY(68,row);
			printf("|%s",pt.Email);
			pointXY(92,row);
			printf("|%s", pt.Problem );
            pointXY(106,row);
			printf("|%s", pt.DrName );

			row++;
		}
		fclose(ek);
        char item;
        printf("\n\n\t\t\t\t Back->'Backspace', Admin Menu->'ESC'...");
        item = getche();
        if(item == BKSP){
            patientInfo();
        }else if(item == ESC){
            adminMenu();
        }else{
            PatientList();
        }

}
/* ********************************************** Search **************************************** */
SearchPatient(void){
     clearWindow();
	char PatientIds[11];
	pointXY(0,0);
	patientSearchTitle();
	FILE *ek;
	ek=fopen("data/Patient-Information.csv","r");
	pointXY(0,0);
    printf("\n\n\n\n\n\t\t\tSearch with ID no: ");
    scanf("%s",PatientIds);
	fflush(stdin);
    int row= 13;
	while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s \n", &pt.PatientId, &pt.First_Name, &pt.Last_Name,
					&pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email, &pt.Problem, &pt.DrName)!=EOF){
        if(pt.PatientId[0] == PatientIds[0] && pt.PatientId[1] == PatientIds[1] && pt.PatientId[2] == PatientIds[2] && pt.PatientId[3] == PatientIds[3] &&pt.PatientId[4] == PatientIds[4] &&pt.PatientId[5] == PatientIds[5] &&  pt.PatientId[6] == PatientIds[6] && pt.PatientId[7] == PatientIds[7] && pt.PatientId[8] == PatientIds[8] &&pt.PatientId[9] == PatientIds[9]){
        clearWindow();
        pointXY(12,0);
        printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        getTitle();
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|PT ID NO");
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
		printf("|Problem");
		pointXY(106,drlistTitltRow);
		printf("|DR Name|\n");
		printf("=======================================================================================================================\n");
		row=9;

		    pointXY(0,row);
			printf("|%s",pt.PatientId);
		    pointXY(11,row);
			printf("|%s %s",pt.First_Name, pt.Last_Name);
			pointXY(26,row);
			printf("|%s",pt.Gender);
			pointXY(34,row);
			printf("|%s",pt.Age);
			pointXY(45,row);
			printf("|%s",pt.Address);
			pointXY(60,row);
			printf("|%s",pt.Contact_no);
			pointXY(77,row);
			printf("|%s",pt.Email);
			pointXY(92,row);
			printf("|%s", pt.Problem );
            pointXY(106,row);
			printf("|%s", pt.DrName );
            pointXY(112,row);
			break;
		}
	   }
	   if(pt.PatientId[0] != PatientIds[0] && pt.PatientId[1] != PatientIds[1] && pt.PatientId[2] != PatientIds[2] && pt.PatientId[3] != PatientIds[3] &&pt.PatientId[4] != PatientIds[4] &&pt.PatientId[5] != PatientIds[5] &&  pt.PatientId[6]!= PatientIds[6] && pt.PatientId[7] != PatientIds[7] && pt.PatientId[8] != PatientIds[8] &&pt.PatientId[9] != PatientIds[9]){
		pointXY(0,0);
        SetColor(12);
		printf("\n\n\n\n\n\n\n\n\t\t\t404 not found!");
		ColorSet();
	   }
	fclose(ek);
	Agin:
	printf("\n\n\t\t\tDo you want to search more[Y/N]??");
    scanf("%c",&reply);
    if (toupper(reply)=='Y'){
        SearchPatient();
    }else if(toupper(reply)=='N'){
		patientInfo();
    }else{

        SetColor(12);
    	printf("\n\tInvalid Input.\n");
    	ColorSet();
    	goto Agin;
    }
}
/* ********************************************** Update Information **************************************** */

/* ********************************************** Update Information **************************************** */
void UpdatePatientInfo(void){
    clearWindow();
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char PatientIds[11];
 		ft=fopen("data/updatePatient.csv","w+");
	   ek=fopen("data/Patient-Information.csv","r");
	   if(ek==NULL){
		printf("\n\t Can not open file!! ");
		getch();
		adminMenu();
	   }
        ColorSet();
        pointXY(0,0);
         printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        getTitle();
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

       	printf("\n\n\t\t\t************** Edit Patient Record **************\n");
	   	printf("\n\t\t\tEnter the Id of Patient : ");
	   	scanf(" %s",PatientIds);
	   	fflush(stdin);
	   //	name[0]=toupper(name[0]);
		pointXY(12,15);

		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			adminMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &pt.PatientId, &pt.First_Name, &pt.Last_Name,
					&pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email, &pt.Problem, &pt.DrName)!=EOF)
		{
			if(pt.PatientId[0] == PatientIds[0] && pt.PatientId[1] == PatientIds[1] && pt.PatientId[2] == PatientIds[2] && pt.PatientId[3] == PatientIds[3] &&pt.PatientId[4] == PatientIds[4] &&pt.PatientId[5] == PatientIds[5] &&  pt.PatientId[6] == PatientIds[6] && pt.PatientId[7] == PatientIds[7] && pt.PatientId[8] == PatientIds[8] &&pt.PatientId[9] == PatientIds[9]){
				valid=1;
				pointXY(25,17);
				printf("*** Existing Record ***");
				pointXY(10,19);



				clearWindow();
        pointXY(12,0);
        printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Hospital Management System \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        int drlistTitltRow =7;
        pointXY(0,6);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|PT ID NO");
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
		printf("|Problem");
		pointXY(106,drlistTitltRow);
		printf("|DR Name|\n");
		printf("=======================================================================================================================\n");
		int row=9;
		    pointXY(0,row);
			printf("|%s",pt.PatientId);
		    pointXY(11,row);
			printf("|%s %s",pt.First_Name, pt.Last_Name);
			pointXY(26,row);
			printf("|%s",pt.Gender);
			pointXY(34,row);
			printf("|%s",pt.Age);
			pointXY(45,row);
			printf("|%s",pt.Address);
			pointXY(60,row);
			printf("|%s",pt.Contact_no);
			pointXY(77,row);
			printf("|%s",pt.Email);
			pointXY(92,row);
			printf("|%s", pt.Problem );
            pointXY(106,row);
			printf("|%s", pt.DrName );
            pointXY(112,row);

            pointXY(12,12);
            printf("Enter New First Name: ");
            scanf("%s",pt.First_Name);
            pointXY(12,13);
            printf("Enter Last Name: ");
            scanf("%s",pt.Last_Name);
            pointXY(12,14);
            printf("Enter Gender: ");
            scanf("%s",&pt.Gender);
            pt.Gender[0] = toupper(pt.Gender[0]);
            pointXY(12,15);
            printf("Enter Join Date: ");
            scanf(" %s",&pt.Age);
            pointXY(12,16);
            printf("Enter Address: ");
            scanf("%s",pt.Address);
            pt.Address[0]=toupper(pt.Address[0]);
            pointXY(12,17);
            printf("Enter Contact no: ");
            scanf("%s",pt.Contact_no);
            pointXY(12,18);
            printf("Enter New email: ");
            scanf("%s",pt.Email);
            pointXY(12,19);
            printf("Enter Problem: ");
            scanf("%s",pt.Problem);
            pt.Problem[0]=toupper(pt.Problem[0]);
            pointXY(12,20);
            printf("Enter DR Name: ");
            scanf("%s",pt.DrName);
            pt.DrName[0]=toupper(pt.DrName[0]);
            printf("\nPress 'E' for the Updating operation : ");
            ch=getche();
            if(ch=='e' || ch=='E')
            {
            fprintf(ft,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &pt.PatientId, &pt.First_Name, &pt.Last_Name,
                &pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email, &pt.Problem, &pt.DrName);
            printf("\n\n\t\t\t Patient record updated successfully...");
            }
			}
			else
			{
			fprintf(ft,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &pt.PatientId, &pt.First_Name, &pt.Last_Name,
					&pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email, &pt.Problem, &pt.DrName);
			}
		 }
		 if(!valid){
            SetColor(12);
            pointXY(0, 9);
            printf("\n\t\t\t\t\tThis patient Not exists...");
            ColorSet();
            getch();
         }
	   fclose(ft);
	   fclose(ek);
	   remove("data/Patient-information.csv");
   	   rename("data/updatePatient.csv","data/Patient-information.csv");
		getch();
		patientInfo();
}
/* ********************************************** Delete Information **************************************** */


void DeletePatientInfo(){
    clearWindow();
    ColorSet();
	int PatientIds;
	int found=0;
	FILE *ek, *fileData;
	fileData=fopen("data/delete-Patient.csv","w+");
	ek=fopen("data/Patient-information.csv","r");
	pointXY(30, 0);
	singleLineDelete();
	printf("\n\n\t\t\t============== Delete Patient Record =============\n");
	printf("\n\t\t Enter Patient ID to Delete: ");
	fflush(stdin);
	scanf("%d", &PatientIds);

	while (fscanf(ek,"%s %s %s %s %s %s %s %s %s %s\n", &pt.PatientId, &pt.First_Name, &pt.Last_Name,
					&pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email, &pt.Problem, &pt.DrName)!=EOF){

        //if(pt.PatientId[0] != PatientIds[0] && pt.PatientId[1] != PatientIds[1] && pt.PatientId[2] != PatientIds[2] && pt.PatientId[3] != PatientIds[3] && pt.PatientId[4] != PatientIds[4] &&pt.PatientId[5] != PatientIds[5] &&  pt.PatientId[6]!= PatientIds[6] && pt.PatientId[7] != PatientIds[7] && pt.PatientId[8] != PatientIds[8] && pt.PatientId[9] != PatientIds[9])
        if(stringConverter(pt.PatientId) != PatientIds)
            fprintf(fileData,"%s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", &pt.PatientId, &pt.First_Name, &pt.Last_Name, &pt.Gender, &pt.Age, &pt.Address, &pt.Contact_no, &pt.Email, &pt.Problem, &pt.DrName);
		else{
        int row = 11;
		int drlistTitltRow =9;
        pointXY(0,8);
        printf("=======================================================================================================================\n");
        pointXY(0,drlistTitltRow);
        printf("|PT ID");
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
		printf("|Problem");
		printf("|DR Name|\n");
		pointXY(107,drlistTitltRow);
		printf("=======================================================================================================================\n");

            pointXY(0,row);
			printf("|%s",pt.PatientId);
		    pointXY(11,row);
			printf("|%s %s",pt.First_Name, pt.Last_Name);
			pointXY(26,row);
			printf("|%s",pt.Gender);
			pointXY(34,row);
			printf("|%s",pt.Age);
			pointXY(45,row);
			printf("|%s",pt.Address);
			pointXY(62,row);
			printf("|%s",pt.Contact_no);
			pointXY(79,row);
			printf("|%s",pt.Email);
			pointXY(94,row);
			printf("|%s", pt.DrName );
            pointXY(107,row);
			printf("|%s", pt.DrName );
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
		remove("data/Patient-Information.csv");
		rename("data/delete-Patient.csv","data/Patient-Information.csv");
		SetColor(10);
		printf("\n\n\t\t\t Record deleted successfully :) Enter to Continue ");
		ColorSet();
		getch();
		patientInfo();
    }else if(toupper(reply[0])=='N'){
		patientInfo();
    }else{
        pointXY(30, 15);
    	printf("Invalid Input.\n");
    	goto Agin;
    }

	}
}


