#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 500 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
void clearWindow(){
    int i,j;
    pointXY(2,0);
    for(i = 0; i < 120; i++){
        for(j = 0; j < 28; j++){
            pointXY(i,j);printf(" ");
        }
    }
    return;
}
//===================Date Validation=================


void dateValidation(char day[], char mon[], char year[]){

    int valid = 0, index =0, date=0, sign=1, mCon=1, month=0,ind = 0, number = 0, yearDate=0, i=0, yearCon = 1;
//================Day=======
    while(day[index] != '\0'){
        if(day[index] >= '0' && day[index] <= '9'){
            number = number*10 + day[index] - '0';
        } else {
            break;
        }
        index++;
    }
    number = number * sign;
//=============Month======
    while(mon[ind] != '\0'){
        if(mon[ind] >= '0' && mon[ind] <= '9'){
            month = month*10 + mon[ind] - '0';
        } else {
            break;
        }
        ind++;
    }
    month = month * mCon;
//============Year===========

    while(year[i] != '\0'){
        if(year[i] >= '0' && year[i] <= '9'){
            yearDate = yearDate*10 + year[i] - '0';
        } else {
            break;
        }
        i++;
    }
    yearDate = yearDate * yearCon;
//============Date Validation=================
    if (yearDate >= 2000 && yearDate <= 2021) {
    //check month
        if (month >= 1 && month <= 12) {
            //check days
            if ((number >= 1 && number <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
                //printf("Date is valid.\n");
                return 1;
            else if ((number >= 1 && number <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
               // printf("\t\t\tDate is valid.\n");
               return 1;
            else if ((number >= 1 && number <= 28) && (month == 2))
                //printf("Date is valid.\n");
                return 1;
            else if (number == 29 && month == 2 && (yearDate % 400 == 0 || (yearDate % 4 == 0 && yearDate % 100 != 0)))
                //printf("Date is valid.\n");
                return 1;
            else
                SetColor(12);
                printf("\t\t\tDay is invalid.\n");
                valid =1;

        } else {
            SetColor(12);
            printf("\t\t\tMonth is not valid.\n");
            valid =1;

        }
    } else {
        SetColor(12);
        printf("\t\t\tYear is not valid.\n");
        valid =1;


    }

    return valid;


}

void clearLine(){
    int i,j;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    for(i = 0; i < 100; i++){
        for(j = 5; j < 20; j++){
            pointXY(i,j);printf(" ");
        }
    }
    return;
}
void clearLineLogIn(){
    int i,j;
    printf("\n\n\n\n\n\n\n\n\n\n");
    for(i = 0; i < 100; i++){
        for(j = 16; j < 20; j++){
            pointXY(i,j);printf(" ");
        }
    }
    return;
}
void singleLineTitle(){
    	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Doctor Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

}


void singleSearchDr(){
    	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search Dr Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

}

void singleLineDelete(){
    	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Delete Doctor \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

}

void patientInformationTitle(){
    	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Patient Information \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

}

void patientSearchTitle(){
    	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search Patient Information \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

}

void stringConverter(char string[]){

    int valid = 0, index =0, date=0, sign=1, number = 0;
//================Day=======
    while(string[index] != '\0'){
        if(string[index] >= '0' && string[index] <= '9'){
            number = number*10 + string[index] - '0';
        } else {
            break;
        }
        index++;
    }
    number = number * sign;
    return number;
}
void singleTitle(){

}
