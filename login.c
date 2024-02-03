#include <stdio.h>
#define ENTER 13
#define TAB 9
#define BKSP 8

char pwd[100];


userLogin(){
    clearWindow();
    ColorSet();
    char inputUsername[30];
    char inputPassword[30];
    char username[30] = "admin";
    char password[30] = "hms";
    int tried = 0;

    int userRow = 14;
    int pwsRow;
    do{
        system("cls");
        pointXY(26,3);
        printf("\n\n\n\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Admin Login \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
        pointXY(26,userRow++);
        clearLineLogIn();
        pointXY(26,15);
        printf("\n\t\t\t\t\t  Username : ");
        scanf("%s", &inputUsername);
        if(strcmp(username, inputUsername) == 0){
            pwsRow = userRow+1;
            PS:
            clearLineLogIn();
            pointXY(26,16);
            printf("\t\t\  Password : ");
            // Hide Password
            int i = 0;
            char ch;
            while(1){

                ch = getch();	//get key

                if(ch == ENTER || ch == TAB){
                    inputPassword[i] = '\0';
                    break;
                }else if(ch == BKSP){
                    if(i > 0){
                        i--;
                        printf("\b \b");		//for backspace
                    }
                }else{
                    inputPassword[i++] = ch;
                    printf("* \b");				//to replace password character with *
                }
            }//while ends here



            char fPass[30];
            FILE *fptr;
            if ((fptr = fopen("data/pws.bat", "r")) == NULL) {
                printf("Error! opening file");
                // Program exits if file pointer returns NULL.
                exit(1);
            }
            fscanf(fptr, "%[^\n]", fPass);
            fclose(fptr);

            if(strlen(fPass) != 0){
                for(int x; x < strlen(fPass); x++){
                    password[x] = fPass[x];
                }
            }
             // End file read

            if(strcmp(password, inputPassword) == 0){
                pointXY(26,pwsRow+2);
                printf("Pleas wait for few moment");
                    int a;
                    for (a = 0; a < 10; a++) {
                        delay(1);
                        printf("..");
                    }
                delay(1,7);
                pointXY(26,pwsRow++);
                printf("\t\t  Successfully logged in");
                adminMenu();
                break;
            }else{
                pointXY(26,12);
                SetColor(12);
                printf("\n\n\t\t\t\t\tPassword incorrect Please try again");
                ColorSet();
                  goto PS;
                   }
        }else{printf("User is incorrect try again \n");}
    }while(-1);
}


changePassword(){
    clearWindow();
    char cPassword[30], newPassword[30], againPassword[30];
    char password[30] = "hms";
    char fPass[30];
            FILE *fptr;
            if ((fptr = fopen("data/pws.bat", "r")) == NULL) {
                printf("Error! opening file");
                // Program exits if file pointer returns NULL.
                exit(1);
            }
            fscanf(fptr, "%[^\n]", fPass);
            fclose(fptr);

            if(strlen(fPass) != 0){
                for(int x; x < strlen(fPass); x++){
                    password[x] = fPass[x];
                }
            }
    pointXY(22, 8);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 <><><><><> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    pointXY(30, 13);
    printf("Enter your Current Password : ");
    scanf("%s", &cPassword);
    if(strcmp(password,cPassword) == 0){
        PASS:
        pointXY(30, 15);
        printf("Enter New Password : ");
        scanf("%s", &newPassword);
        if(strlen(newPassword) > 5 ){
            pointXY(30, 17);
            printf("Enter Confirm Password : ");
            scanf("%s", &againPassword);
           if(strcmp(newPassword, againPassword) == 0){
            FILE *fptr;
            fptr = fopen("data/pws.bat", "w");
            fprintf(fptr, "%s", againPassword);
            fclose(fptr);
                SetColor(10);
                printf("\n\t\t\tPassword Save Done :)");
                ColorSet();
                getch();
                settings();
            }else{
                pointXY(30, 19);
                SetColor(12);
                printf("Password Does not match");
                ColorSet();
                getch();
                settings();
            }
        }else{
            pointXY(30, 25);
            SetColor(12);
            printf("Enter min 6 char password\n");
            ColorSet();
            goto PASS;
        }
    }else{
        changePassword();
    }



}

