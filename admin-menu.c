#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

adminMenu(){
    clearWindow();
    int choose;
    int start;
    ColorSet();
    pointXY(0,0);
    printf("\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	getTitle();
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t\t1. Doctor Information.");
	printf("\n\n\t\t\t\t\t\t2. Patient Information \n");
	printf("\n\t\t\t\t\t\t3. Employee Information \n");
	printf("\n\t\t\t\t\t\t4. Settings \n");
	printf("\n\t\t\t\t\t\t5. Logout \n");
	printf("\n\t\t\t\t\t\tEnter a number 1-4 :");



    do{
    scanf("%d", &choose);
    if(choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose ==5){
        switch(choose){
        case 1:
            drInfo();
            break;
        case 2:
            patientInfo();
            break;
        case 3:
            staffInfo();
            break;
        case 4:
            settings();
            break;
        case 5:
            mainMenuItem();
            break;
        default:
            printf("Please choose 1-3");
        }
        break;
       }else{
            printf("Please Enter a number within 1-5 :");
       }

        start ++;
    }while(start <= 2);
    if(start == 3){homeScreen();}
    system("CLS");
}
