#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define BKSP 8
#define ENTER 13
#define ESC 27

void mainMenuItem();// Menu list location main-menu.c
void welcomePage();
void userLogin(); // Admin loin function
void searchPatient();
void fileExit();
void infoSearch();
void aboutUs();
void adminMenu();
void drInfo();
void patientInfo();
void staffInfo();
void doctorFile();
void settings();
void SetColor(int ForgC){
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
       wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
       SetConsoleTextAttribute(hStdOut, wColor);
     }
     return 0;
 }
void main(void){
    welcomePage();
}




