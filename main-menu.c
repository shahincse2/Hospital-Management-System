#define BKSP 8
#define ESC 27
#define ENTER 13
mainMenuItem(){
    clearWindow();
    int choose;
    int start;
    pointXY(20, 0);
    printf("\n\n\n\n\n\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    getTitle();
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    pointXY(16,5);
    printf("\n\n\t\t\t\t1. Search \n");
	printf("\n\t\t\t\t2. Login \n");
	printf("\n\t\t\t\t3. About us \n");
	printf("\n\t\t\t\t4. System Exit \n");
	printf("\n\t\t\t\tPress 'ESC'-> Exit, 'Enter'->Continue");
	char back = getch();
    if(back == ENTER){
	printf("\n\n\t\t\t\tEnter a number 1-4 :  ");
   scanf("%i", &choose);

        switch(choose){

        case 1:
        infoSearch();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            aboutUs();
            break;
        case 4:
            clearWindow();
            pointXY(0,0);
            Title();
            break;
        default:
            printf("\t\t\tInvalid entry. Please enter right option :)");
            getch();//holds screen
        }//end of switch
    }else if(back != ESC){
    mainMenuItem();
    }
}
