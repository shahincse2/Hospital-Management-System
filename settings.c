#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void changeTitle();
void changePassword();
//int changeColour();

/* ************************************************* Title Screen ********************************************* */
/* ************************************************* Change Hospital Title ********************************************* */

void changeTitle(){
    clearWindow();

    ColorSet();
     char sentence[100];
    FILE *fptr;
    fptr = fopen("data/program.txt", "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    pointXY(22, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 <><><><><> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    pointXY(30, 11);
    printf("\n\n\t\t\tEnter The Hospital Name :");
    //scanf("%s", &sentence);
    gets(sentence);
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    SetColor(10);
    pointXY(30, 15);
    printf("Successfully Done");
    ColorSet();
    getch();
    settings();
    return 0;
}
void getTitle(){
    char name[100],  hospitalTItle[100] = "Hospital Management System";
    FILE *fptr;
    fptr = fopen("data/program.txt", "r");
    fscanf(fptr, "%[^\n]", name);
    if(strlen(name) != 0){
        for(size_t i = 0; i < sizeof hospitalTItle; ++i)
        hospitalTItle[i] = 0;
    }
    if(strlen(name) != 0){

        for (int i = 0; i < strlen(name); i++){
            hospitalTItle[i] = name[i];
        }
    }
    printf("%s", hospitalTItle);
}

/* ************************************************* Change Color ********************************************* */

int changeColour(){
    clearWindow();
    char colorCode[4];
    pointXY(22, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 <><><><><> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");

    pointXY(70, 13);
    printf("The Color Code List : ");
    pointXY(70, 14);
    printf("--------------------------------");

    pointXY(70, 15);
    printf("Black = 0 \tBlue = 1");

    pointXY(70, 16);
    printf("Green = 2 \t Red = 4");

    pointXY(70, 17);
    printf("Purple = 5\t Yellow = 6");

    pointXY(70, 18);
    printf("White = 7\t");

    pointXY(30, 11);
    printf("PLease Enter The Color Code From List :-- ");
    scanf("%s", &colorCode);
    colorCode[0] = toupper(colorCode[0]);
    printf("%s", colorCode);
    FILE *ek;
    ek = fopen("data/color.bat", "w");
    fprintf(ek, "%s",&colorCode);
    fclose(ek);
    SetColor(10);
    pointXY(30, 16);
    printf("Successfully Changed Colour");
    ColorSet();
    getch();
    settings();

}
void ColorSet(){
    int color;
    FILE *ft;
    ft = fopen("data/color.bat", "r");
    fscanf(ft, "%d", &color);
    fclose(ft);
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
       wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
       SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }
void Title(void){
    ColorSet();
    printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 <><><><><> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\n\t\t\t\t\t      ");
    getTitle();
    printf("       ");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 <><><><><> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    }
settings(){
    clearWindow();
    ColorSet();
    //Title();
    int choose;
    int start;
    pointXY(16,4);
    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Settings \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t\t\t\t1 .Change Hospital Name.");
	printf("\n\n\t\t\t\t\t\t2. Change Password \n");
	printf("\n\t\t\t\t\t\t3. Change Colour \n");
	printf("\n\t\t\t\t\t\t4. Admin Menu \n");
	printf("\n\t\t\t\t\t\tEnter a number 1-4 :");
    do{
    scanf("%d", &choose);

    if(choose == 1 || choose == 2 || choose == 3 || choose == 4){
        switch(choose){
        case 1:
            changeTitle();
            break;
        case 2:
            changePassword();
            break;
        case 3:
            changeColour();
            break;
        case 4:
            adminMenu();
            break;
        default:
            printf("Please choose 1-4");
        }
        break;
       }else{
            printf("Please Enter a number within 1-4 :");
       }
        start ++;
    }while(start <= 2);
    if(start == 3){homeScreen();}
    system("CLS");


}




