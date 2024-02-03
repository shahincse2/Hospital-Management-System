#define BKSP 8
#define ESC 27
aboutUs(){
    char back;
    clearWindow();
    ColorSet();
    pointXY(16,0);
	printf("\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 About US \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t\t\t      ");
    getTitle();
    printf("\n========================================================================================================================");
    printf("\t\t\tHospital Management System is a storage application,  developed to maintain the \n\t\tDetails of Doctor,  Patient  and  Employees  in  any  hospital.It maintains the\n\t\tinformation about the personal  details of their Doctor, Patient and Employees. \n\t\tThe application is actually a suite of applications  developed  using C. It is \n\t\tsimple to understand and can be used by anyone who is  not even  familiar with \n\t\tsimple Hospital Management System. It is user friendly and  just asks  the user\n\t\tto follow  step  by  step operations by giving him few options. It is fast and\n\t\tcan perform many operations of a company.");
    printf("\n========================================================================================================================");
	printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 <><><><><> \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t Press 'Bckspace'->Main Menu, System Exit 'ESC'");
    back = getch();
    if(back == BKSP){
        mainMenuItem();
    }else if(back != ESC){
        aboutUs();
    }
}
