#include <time.h>//for delay()
#include <windows.h>//for HANDLE
#include <string.h>
#include <conio.h> // for windows use
#include <stdio.h>

//#include "../include/conio.h" //for getch() and linux use
#include "../include/mesRes.h"
#include "../include/measurement.h"
#include "../include/commonVector.h"
#include "../include/menu.h"
#include "../include/globVar.h"
#include "../include/displayArray.h"
#include "../include/fillArr.h"
#include "../include/argStd.h"

#pragma warning (disable:4996)
#define MAX 11 //max number of menu items
#define MIN 1 //min number of menu items


const char *algNames[] = {"INSERT1", "INSERT2", "INSERT3", "INSERT4",
                    "SELECT1", "SELECT2", "SELECT3", "SELECT4",
                    "SELECT5", "SELECT6", "SELECT7", "SELECT8",
                    "EXCHANGE1", "EXCHANGE2", "EXCHANGE3",
                    "EXCHANGE4", "INSERTEXCHANGE",
                    "SELECT1EXCHANGE", "SELECT2EXCHANGE",
                    "SELECT3EXCHANGE", "SELECT4EXCHANGE",
                    "SHELL 1", "SHELL 2", "QUICKSORT"};


/*int P = 200;
int M = 20;
int N = 149;
int V = 200;*/




void gotoxy(int x, int y) //set coordinates
{
    COORD coord;
    coord.Y = y;
    coord.X = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void screenSaver() { //printf a information in console
    gotoxy(48,10);
      printf("SORT ANALYSIS WORK");
      gotoxy(38,12);
      printf("ON STRUCTURE DATA AND ALGORITHMS");
      gotoxy(59,16);
      printf("Prepared by Vasyl Meliukh");
      gotoxy(76,26);
      printf("Press the right arrow to continue...");
      while (1) //loop for checking a button
    {
        if (getch() == 224 && getch() == 77) break;// check if user pressed right arrow
    }

  }


void outTableWithSortingTime(sortAlg algType, float ordered, float random, float backordered)//table for exchange3
{
    for(int i =0;i<97;i++) printf("-");//draw a frame
    printf("\n");
        printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
        printf("|%20s\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", algNames[algType], ordered, random, backordered);//prints time for those ways
        printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
        for(int i =0;i<97;i++) printf("-");
        printf("\n\n");
}

void arrow(int r_pos, int a_pos)//locate arrow near active menu item
{
    if(r_pos == a_pos){
		printf("---->> - ");//prints thjs arrow to the menu item you choose
	} else{
		printf("         ");//locates near all other items
	}
}

void setValues(int a, int b, int c) {
    int* ptr;
    ptr = &BLOCK;
    *ptr = a;
    ptr = &ROW;
    *ptr = b;
    ptr = &COLUMN;
    *ptr = c;

}

void getTensorTimeMeasurement(sortAlg algType) {
    float F1, F2, F3;

    system("cls");
    printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", BLOCK, ROW, COLUMN);

    srand(time(NULL));//restart time value
    printf("ORDERED --->>> LOADING...\n");
    if(algType == QUICKSORT)
        tensorQuickSortMeasurement(UP, BLOCK, ROW, COLUMN);
    else
        tensorMeasurement(UP, BLOCK, ROW, COLUMN, algType, TENSOR_); //loads results of exchange sort measurement
    F1=MeasurementProcessing();//F1 has a value of time

    srand(time(NULL));
    printf("RANDOM --->>> LOADING...\n");
    if(algType == QUICKSORT)
        tensorQuickSortMeasurement(RANDOM, BLOCK, ROW, COLUMN);
    else
        tensorMeasurement(RANDOM, BLOCK, ROW, COLUMN, algType, TENSOR_);
    F2=MeasurementProcessing();

    srand(time(NULL));
    printf("UNORDERED  --->>> LOADING...\n");
    if(algType == QUICKSORT)
        tensorQuickSortMeasurement(DOWN, BLOCK, ROW, COLUMN);
    else
        tensorMeasurement(DOWN, BLOCK, ROW, COLUMN, algType, TENSOR_);
    F3=MeasurementProcessing();

    Sleep(1000);
    printf("\t\t\tCOPMLETED: waiting \t");
    for (int i = 0; i < 10; i++) {
        printf("*");
        Sleep(100);
    }

    system("cls");
    printf("\t\t\t\t\tThree-dimensional array\n");
    outTableWithSortingTime(algType, F1, F2, F3);
    printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", BLOCK, ROW, COLUMN);
    printf("Press the left arrow to come back to menu...");

    if(getch()==224){//check buttons, if user clicked left arrow you move to the menu, if right arrow you loads vector measurement
        char key= getch();//check keys
        if (key == 75) { system("cls"); tensorMainMenu();}
    }
 }

 void getInsertMeasurement() {
    int position = 1;//current position
	int keyActive = 0;

    system("cls");

     while(keyActive != 13)
	 {
        gotoxy(10,2);//
        printf("Sort algorithm choices:");
        gotoxy(10,3);
        printf("Variants of algorithm:");
        gotoxy(5,5);
        arrow(1, position);printf("1. Insert1");//check where to locate an arrow
        gotoxy(5,6);
        arrow(2, position);printf("2. Insert2");//check where to locate an arrow
        gotoxy(5,7);
        arrow(3, position);printf("3. Insert3");//check where to locate an arrow
        gotoxy(5,8);
        arrow(4, position);printf("4. Insert4");//check where to locate an arrow
        gotoxy(5, 9);
        arrow(5, position);printf("Back to the main menu\n");
        gotoxy(5, 11);

        printf("Press enter to continue...\n");

        keyActive = getch();
        //check the up and down keys
        if((keyActive == 80 )&& (position != 5)) {//move arrow till max number
            position++;
        } else if((keyActive==72)&& (position != 1)){//move arrow till min number
            position--;
        } else {
            position = position;//do nothing, but saves a position of arrow
        }
	}


	switch(position)//link user to the chosen item
	{
        case 1: {
            getTensorTimeMeasurement(INSERT1);
            break;
        }
        case 2: {
            getTensorTimeMeasurement(INSERT2);
            break;
        }
        case 3: {
            getTensorTimeMeasurement(INSERT3);
            break;
        }
        case 4: {
            getTensorTimeMeasurement(INSERT4);
            break;
        }
        case 5: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

void getSelectMeasurement() {
    int position = 1;//current position
	int keyActive = 0;

    system("cls");

     while(keyActive != 13)
	 {
        gotoxy(10,2);//
        printf("Sort algorithm choices:");
        gotoxy(10,3);
        printf("Variants of algorithm:");
        gotoxy(5,5);
        arrow(1, position);printf("1. Select1");//check where to locate an arrow
        gotoxy(5,6);
        arrow(2, position);printf("2. Select2");//check where to locate an arrow
        gotoxy(5,7);
        arrow(3, position);printf("3. Select3");//check where to locate an arrow
        gotoxy(5,8);
        arrow(4, position);printf("4. Select4");//check where to locate an arrow
        gotoxy(5, 9);
        arrow(5, position);printf("5. Select5");//check where to locate an arrow
        gotoxy(5, 10);
        arrow(6, position);printf("6. Select6");//check where to locate an arrow
        gotoxy(5, 11);
        arrow(7, position);printf("7. Select7");//check where to locate an arrow
        gotoxy(5, 12);
        arrow(8, position);printf("8. Select8");//check where to locate an arrow
        gotoxy(5, 13);
        arrow(9, position);printf("Back to the main menu\n");
        gotoxy(5, 14);

        printf("Press enter to continue...\n");

        keyActive = getch();
        //check the up and down keys
        if((keyActive == 80 )&& (position != 9)) {//move arrow till max number
            position++;
        } else if((keyActive==72)&& (position != 1)){//move arrow till min number
            position--;
        } else {
            position = position;//do nothing, but saves a position of arrow
        }
	}


	switch(position)//link user to the chosen item
	{
        case 1: {
            getTensorTimeMeasurement(SELECT1);
            break;
        }
        case 2: {
            getTensorTimeMeasurement(SELECT2);
            break;
        }
        case 3: {
            getTensorTimeMeasurement(SELECT3);
            break;
        }
        case 4: {
            getTensorTimeMeasurement(SELECT4);
            break;
        }
        case 5: {
            getTensorTimeMeasurement(SELECT5);
            break;
        }
        case 6: {
            getTensorTimeMeasurement(SELECT6);
            break;
        }
        case 7: {
            getTensorTimeMeasurement(SELECT7);
            break;
        }
        case 8: {
            getTensorTimeMeasurement(SELECT8);
            break;
        }
        case 9: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

void getExchangeMeasurement() {
    int position = 1;//current position
	int keyActive = 0;

    system("cls");

     while(keyActive != 13)
	 {
        gotoxy(10,2);//
        printf("Sort algorithm choices:");
        gotoxy(10,3);
        printf("Variants of algorithm:");
        gotoxy(5,5);
        arrow(1, position);printf("1. Exchange1");//check where to locate an arrow
        gotoxy(5,6);
        arrow(2, position);printf("2. Exchange2");//check where to locate an arrow
        gotoxy(5,7);
        arrow(3, position);printf("3. Exchange3");//check where to locate an arrow
        gotoxy(5,8);
        arrow(4, position);printf("4. Exchange4");//check where to locate an arrow
        gotoxy(5, 9);
        arrow(5, position);printf("Back to the main menu\n");
        gotoxy(5, 10);

        printf("Press enter to continue...\n");

        keyActive = getch();
        //check the up and down keys
        if((keyActive == 80 )&& (position != 5)) {//move arrow till max number
            position++;
        } else if((keyActive==72)&& (position != 1)){//move arrow till min number
            position--;
        } else {
            position = position;//do nothing, but saves a position of arrow
        }
	}


	switch(position)//link user to the chosen item
	{
        case 1: {
            getTensorTimeMeasurement(EXCHANGE1);
            break;
        }
        case 2: {
            getTensorTimeMeasurement(EXCHANGE2);
            break;
        }
        case 3: {
            getTensorTimeMeasurement(EXCHANGE3);
            break;
        }
        case 4: {
            getTensorTimeMeasurement(EXCHANGE4);
            break;
        }
        case 5: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

  void getSelectExchangeMeasurement() {
    int position = 1;//current position
	int keyActive = 0;

    system("cls");

     while(keyActive != 13)
	 {
        gotoxy(10,2);//
        printf("Sort algorithm choices:");
        gotoxy(10,3);
        printf("Variants of algorithm:");
        gotoxy(5,5);
        arrow(1, position);printf("1. Select1Exchange");//check where to locate an arrow
        gotoxy(5,6);
        arrow(2, position);printf("2. Select2Exchange");//check where to locate an arrow
        gotoxy(5,7);
        arrow(3, position);printf("3. Select3Exchange");//check where to locate an arrow
        gotoxy(5,8);
        arrow(4, position);printf("4. Select4Exchange");//check where to locate an arrow
        gotoxy(5, 9);
        arrow(5, position);printf("Back to the main menu\n");
        gotoxy(5, 10);

        printf("Press enter to continue...\n");

        keyActive = getch();
        //check the up and down keys
        if((keyActive == 80 )&& (position != 5)) {//move arrow till max number
            position++;
        } else if((keyActive==72)&& (position != 1)){//move arrow till min number
            position--;
        } else {
            position = position;//do nothing, but saves a position of arrow
        }
	}


	switch(position)//link user to the chosen item
	{
        case 1: {
            getTensorTimeMeasurement(SELECT1EXCHANGE);
            break;
        }
        case 2: {
            getTensorTimeMeasurement(SELECT2EXCHANGE);
            break;
        }
        case 3: {
            getTensorTimeMeasurement(SELECT3EXCHANGE);
            break;
        }
        case 4: {
            getTensorTimeMeasurement(SELECT4EXCHANGE);
            break;
        }
        case 5: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

void getShellMeasurement() {
        int position = 1;//current position
	int keyActive = 0;

    system("cls");

     while(keyActive != 13)
	 {
        gotoxy(10,2);//
        printf("Sort algorithm choices:");
        gotoxy(10,3);
        printf("Variants of algorithm:");
        gotoxy(5,5);
        arrow(1, position);printf("1. Shell_1");//check where to locate an arrow
        gotoxy(5,6);
        arrow(2, position);printf("2. Shell_2");//check where to locate an arrow
        gotoxy(5, 7);
        arrow(3, position);printf("Back to the main menu\n");
        gotoxy(5, 8);

        printf("Press enter to continue...\n");

        keyActive = getch();
        //check the up and down keys
        if((keyActive == 80 )&& (position != 3)) {//move arrow till max number
            position++;
        } else if((keyActive==72)&& (position != 1)){//move arrow till min number
            position--;
        } else {
            position = position;//do nothing, but saves a position of arrow
        }
	}


	switch(position)//link user to the chosen item
	{
        case 1: {
            getTensorTimeMeasurement(SHELL_1);
            break;
        }
        case 2: {
            getTensorTimeMeasurement(SHELL_2);
            break;
        }
        case 3: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

void tensorMainMenu(){//main menu in which user can choose type of sort algorithms
	int position = 1;//current position
	int tr = 1;
	int keyActive = 0;
	 while(keyActive != 13)
	 {
        if(tr == 1) {//if user clicked right arrow to screen_saver, so the page is deleted and menu is loaded
            tr = 0;
            system("cls");
        }

        gotoxy(35,8);//
        printf("MENU MANAGMENT");
        gotoxy(35,8);
        printf("Variants of testing:");
        gotoxy(30,10);
        arrow(1, position);printf("1. Insert");//check where to locate an arrow
        gotoxy(30,11);
        arrow(2, position);printf("2. Select");//check where to locate an arrow
        gotoxy(30,12);
        arrow(3, position);printf("3. Exchange");//check where to locate an arrow
        gotoxy(30,13);
        arrow(4, position);printf("4. InsertExchange");//check where to locate an arrow
        gotoxy(30,14);
        arrow(5, position);printf("5. SelectExchange");//check where to locate an arrow
        gotoxy(30,15);
        arrow(6, position);printf("6. Shell");
        gotoxy(30,16);
        arrow(7, position);printf("7. QuickSort");
        gotoxy(30,17);
        arrow(8, position);printf("Setting X Y Z values for the array");
        gotoxy(30, 18);
        arrow(9, position);printf("Switch between 1D and 3D algorithms");
        gotoxy(30, 19);
        arrow(10, position);printf("Displaying array soring results");
        gotoxy(30, 20);
        arrow(11, position);printf("Exit\n");
        gotoxy(30, 21);

        printf("Press enter to continue...");


        keyActive = getch();
        //check the up and down keys
        if((keyActive == 80 )&& (position != MAX)) {//move arrow till max number
            position++;
        } else if((keyActive==72)&& (position != MIN)){//move arrow till min number
            position--;
        } else {
            position = position;//do nothing, but saves a position of arrow
        }

	}

	switch(position)//link user to the chosen item
	{
		case 1: {
            getInsertMeasurement();
            break;
        }
		case 2 : {
            getSelectMeasurement();
            break;
        }
		case 3 : {
            getExchangeMeasurement();
            break;
        }
        case 4 : {
            getTensorTimeMeasurement(INSERTEXCHANGE);
            break;
        }
        case 5: {
            getSelectExchangeMeasurement();
            break;
        }
        case 6: {
            getShellMeasurement();
            break;
        }
        case 7: {
            getTensorTimeMeasurement(QUICKSORT);
            break;
        }
        case 8: {
            system("cls");
            tensorReleasingMemory(BLOCK, ROW);
            int* ptr = &BLOCK;
            int x, a, b, c;

            printf("Enter value of P: ");
            a = scanf("%d", &x);
            *ptr = x;
            ptr = &ROW;

            printf("Enter value of M: ");
            b = scanf("%d", &x);
            *ptr = x;
            ptr = &COLUMN;

            printf("Enter value of N: ");
            c = scanf("%d", &x);
            *ptr = x;

            tensorAllocation(BLOCK, ROW, COLUMN);
            printf("Press the left arrow to come back to menu...");
            if (getch() == 224) {
                char key = getch();
                if (key == 75) { system("cls"); tensorMainMenu(); }
            }
            break;
        }
        case 9: {
            system("cls");
            printf("Currently 3d array version is used\n");
            printf("Do you want to switch to version version:\n");
            printf("YES? - print Y, else type any key and return to the menu\n");
            char ch;
            scanf("%c", &ch);
            if (ch == 'Y')
                //menuv();
                tensorMainMenu();
            else {
                system("cls"); tensorMainMenu();
            }

            break;
        }
        case 10: {
            system("cls");
            printf("Your array is printed in console\n");

            display3DArray(BLOCK, ROW, COLUMN);

            printf("Press the left arrow to come back to menu...");
            if (getch() == 224) {
                char key = getch();
                if (key == 75) { system("cls"); tensorMainMenu(); }
            }

            break;
        }
	}
}

/*
void menuv() {//menu for vector measurements
    int position = 1;//current position
    int tr = 1;
    int keyActive = 0;
    while (keyActive != 13)
    {
        if (tr == 1) {//if user clicked right arrow to screen_saver, so the page is deleted and menu is loaded
            tr = 0;
            system("cls");
        }
        gotoxy(35, 8);//
        printf("MENU MANAGMENT");
        gotoxy(35, 8);
        printf("Variants of testing:");
        gotoxy(30, 10);
        arrow(1, position);printf("1.Exchange3");//check where to locate an arrow
        gotoxy(30, 11);
        arrow(2, position);printf("2.Select8");
        gotoxy(30, 12);
        arrow(3, position);printf("3.QuickSort");
        gotoxy(30, 13);
        arrow(4, position);printf("4.All sort algorithms");
        gotoxy(30, 14);
        arrow(5, position);printf("Set V value for length of vector");
        gotoxy(30, 15);
        arrow(6, position);printf("Choosing 2d or 3d algorithm");
        gotoxy(30, 16);
        arrow(7, position);printf("Exit\n");
        gotoxy(30, 17);

        printf("Press enter to continue...");

        keyActive = getch();
        //check the up and down keys
        if ((keyActive == 80) && (position != MAX)) {//move arrow till max number
            position++;
        }
        else if ((keyActive == 72) && (position != MIN)) {//move arrow till min number
            position--;
        }
        else {
            position = position;//do nothing, but saves a position of arrow
        }

    }
    switch(position)//link user to the choosed item
	{
	    float Fl1, Fl2, Fl3, Fl4 ,Fl5 , Fl6 ,Fl7 ,Fl8 ,Fl9;
		case 1: {
		    system("cls");
		    printf("\n\n");
		    srand(time(NULL));
            vectorExchangeSortMeasurement(1, V);
            Fl1=MeasurementProcessing();
            srand(time(NULL));
            vectorExchangeSortMeasurement(2, V);
            Fl2=MeasurementProcessing();
            srand(time(NULL));
            vectorExchangeSortMeasurement(3, V);
            Fl3=MeasurementProcessing();
            printf("\t\t\t\t\t\tVector\n");
            OutTable1(Fl1, Fl2, Fl3);
            printf("\n\t\t\t\tNumber of elements: %d\n\n", V);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){
    		char key= getch();
            if (key == 75) { system("cls"); menuv();}
            }
            break;
        }
		case 2 : {
		    system("cls");
            printf("\n\n");
            srand(time(NULL));
            vectorSelectMeasurement(1, V);
            Fl1=MeasurementProcessing();
            srand(time(NULL));
            vectorSelectMeasurement(2, V);
            Fl2=MeasurementProcessing();
            srand(time(NULL));
            vectorSelectMeasurement(3, V);
            Fl3=MeasurementProcessing();
            printf("\t\t\t\t\t\tVector\n");
            OutTable2(Fl1, Fl2, Fl3);
            printf("\n\t\t\t\tNumber of elements: %d\n\n", V);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){
    		char key= getch();
            if (key == 75) { system("cls"); menuv();}
            }
            break;
        }
		case 3 : {
		    system("cls");
            printf("\n\n");
		    srand(time(NULL));
            vectorQuickSortMeasurement(1, V);
            Fl1=MeasurementProcessing();
            srand(time(NULL));
            vectorQuickSortMeasurement(2, V);
            Fl2=MeasurementProcessing();
            srand(time(NULL));
            vectorQuickSortMeasurement(3, V);
            Fl3=MeasurementProcessing();
            printf("\t\t\t\t\t\tVector\n");
            OutTable3(Fl1, Fl2, Fl3);
            printf("\n\t\t\t\tNumber of elements: %d\n\n", V);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){
    		char key= getch();
            if (key == 75) { system("cls"); menuv();}
            }
            break;
        }
	case 4 : {
	    system("cls");
        printf("\n\n");
        srand(time(NULL));
        vectorExchangeSortMeasurement(1, V);
        Fl1=MeasurementProcessing();
        srand(time(NULL));
        vectorExchangeSortMeasurement(2, V);
        Fl2=MeasurementProcessing();
        srand(time(NULL));
        vectorExchangeSortMeasurement(3, V);
        Fl3=MeasurementProcessing();
        srand(time(NULL));
        vectorSelectMeasurement(1, V);
        Fl4=MeasurementProcessing();
        srand(time(NULL));
        vectorSelectMeasurement(2, V);
        Fl5=MeasurementProcessing();
        srand(time(NULL));
        vectorSelectMeasurement(3, V);
        Fl6=MeasurementProcessing();
        srand(time(NULL));
        vectorQuickSortMeasurement(1, V);
        Fl7=MeasurementProcessing();
        srand(time(NULL));
        vectorQuickSortMeasurement(2, V);
        Fl8=MeasurementProcessing();
        srand(time(NULL));
        vectorQuickSortMeasurement(3, V);
        Fl9=MeasurementProcessing();
        printf("\t\t\t\t\t\tVector\n");
        OutTable(Fl1, Fl2, Fl3, Fl4, Fl5, Fl6, Fl7, Fl8,Fl9);
        printf("\n\t\t\t\tNumber of elements: %d\n\n", V);
        printf("Press the left arrow to come back to menu...");
        if(getch()==224){
            char key= getch();
            if (key == 75) { system("cls"); menuv();}
        }
        break;
	}
    case 5: {
        system("cls");
        vectorDynEnd(P, M);
        int* ptr = &V;
        int x, a;
        printf("Enter value of V: ");
        a = scanf("%d", &x);
        *ptr = x;
        vectorDynBeg(V);
        printf("Press the left arrow to come back to menu...");
        if (getch() == 224) {
            char key = getch();
            if (key == 75) { system("cls"); menuv(); }
        }
        break;
    }
    case 6: {
        system("cls");
        printf("Currently vector version is used\n");
        printf("Do you want to switch to 3d version version:\n");
        printf("YES? - print Y, else type any key and return to the menu\n");
        char ch, v;
        v = scanf("%c", &ch);
        if (ch == 'Y')
            tensorMainMenu();
        else
            system("cls"); menuv();
        break;
    }
	}
}
*/
