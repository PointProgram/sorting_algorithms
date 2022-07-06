#include <time.h>//for delay()
#include <windows.h>//for HANDLE
#include <string.h>
#include <conio.h> // for window use
#include <stdio.h>

//#include "../include/conio.h" //for getch() and linux use

#include "../include/measurementResults.h"
#include "../include/measurementTime.h"
#include "../include/commonVector.h"
#include "../include/menuList.h"
#include "../include/globalVariables.h"
#include "../include/displayArray.h"
#include "../include/fillArray.h"
#include "../include/argStd.h"

#pragma warning (disable:4996)
#define MAX 11 //max number of menu items
#define MIN 1 //min number of menu items

arrType checkArrayType = TENSOR_;

// string array with sort algorithms names
const char *algNames[] = {"INSERT1", "INSERT2", "INSERT3", "INSERT4",
                    "SELECT1", "SELECT2", "SELECT3", "SELECT4",
                    "SELECT5", "SELECT6", "SELECT7", "SELECT8",
                    "EXCHANGE1", "EXCHANGE2", "EXCHANGE3",
                    "EXCHANGE4", "INSERTEXCHANGE",
                    "SELECT1EXCHANGE", "SELECT2EXCHANGE",
                    "SELECT3EXCHANGE", "SELECT4EXCHANGE",
                    "SHELL 1", "SHELL 2", "QUICKSORT"};

// set fixed coordinates
void gotoxy(int x, int y)
{
    COORD coord;
    coord.Y = y;
    coord.X = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// display information to the console
void screenSaver() {
    system("cls");
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
    // The average result of each of the three measurements will be output
    // to the screen in portable positions

    for(int i =0;i<97;i++) printf("-");//draw a frame
    printf("\n");
        printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
        printf("|%20s\t|\t%7.6f\t|\t%7.6f\t|\t%7.6f\t|\n", algNames[algType], ordered, random, backordered);//prints time for those ways
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

// change values of the global variables for 3D array
void setTensorValues() {
    int* ptr = &BLOCK, x;

    printf("Enter value of BLOCKS: ");
    scanf("%d", &x);
    *ptr = x;

    ptr = &ROW;
    printf("Enter value of ROWS: ");
    scanf("%d", &x);
    *ptr = x;

    ptr = &COLUMN;
    printf("Enter value of COLUMNS: ");
    scanf("%d", &x);
    *ptr = x;
}

// change values of the global variable for 1D array
void setVectorValue() {
    int* ptr = &VECTOR_LENGTH, x;

    printf("Enter value of VECTOR LENGTH: ");
    scanf("%d", &x);
    *ptr = x;
}

// display gained measurement to the console
void getTimeMeasurement(sortAlg algType, arrType typeArr) {
    float F1, F2, F3;
    int blocks = BLOCK, rows = ROW, cols = COLUMN;

    system("cls");
    if (typeArr == TENSOR_)
        printf("\t\t\t\tNumber of elements BLOCKSxROWSxCOLUMNS: %dx%dx%d\n\n", BLOCK, ROW, COLUMN);
    else {
        printf("\t\t\t\tNumber of elements LENGTH: %d\n\n", VECTOR_LENGTH);
        blocks = VECTOR_LENGTH;
    }

    srand(time(NULL));//restart time value
    printf("ORDERED --->>> LOADING...\n");
    arrayMeasurement(UP, blocks, rows, cols, algType, typeArr); //loads results of exchange sort measurement
    F1=MeasurementProcessing();//F1 has a value of time

    srand(time(NULL));
    printf("RANDOM --->>> LOADING...\n");
    arrayMeasurement(RANDOM, blocks, rows, cols, algType, typeArr);
    F2=MeasurementProcessing();

    srand(time(NULL));
    printf("UNORDERED  --->>> LOADING...\n");
    arrayMeasurement(DOWN, blocks, rows, cols, algType, typeArr);
    F3=MeasurementProcessing();

    Sleep(1000);
    printf("\t\t\tCOPMLETED: waiting \t");
    for (int i = 0; i < 10; i++) {
        printf("*");
        Sleep(100);
    }

    system("cls");

    if (typeArr == TENSOR_) {
        printf("\t\t\t\t\tThree-dimensional array\n");
        outTableWithSortingTime(algType, F1, F2, F3);
        printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", BLOCK, ROW, COLUMN);
    }
    else {

        printf("\t\t\t\t\tOnde-dimensional array\n");
        outTableWithSortingTime(algType, F1, F2, F3);
        printf("\t\t\t\tNumber of elements LENGTH: %d\n\n", VECTOR_LENGTH);
    }
    printf("---- Time for an ordered array: %f SEC\n\n", F1 / CLOCKS_PER_SEC);
    printf("---- Time for a random array: %f SEC\n\n", F2 / CLOCKS_PER_SEC);
    printf("---- Time for an unordered array: %f SEC\n\n", F3 / CLOCKS_PER_SEC);

    printf("Press the left arrow to come back to menu...");

    if(getch()==224){//check buttons, if user clicked left arrow you move to the menu, if right arrow you loads vector measurement
        char key= getch();//check keys
        if (key == 75) { system("cls"); tensorMainMenu();}
    }
 }

 // display the submenu for choosing the submethods of the Insert sort algorithm and select the desired model
 void getInsertMeasurement(arrType typeArr) {
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
            getTimeMeasurement(INSERT1, typeArr);
            break;
        }
        case 2: {
            getTimeMeasurement(INSERT2, typeArr);
            break;
        }
        case 3: {
            getTimeMeasurement(INSERT3, typeArr);
            break;
        }
        case 4: {
            getTimeMeasurement(INSERT4, typeArr);
            break;
        }
        case 5: {
            system("cls");
            tensorMainMenu();
        }
    }
 }


 // display the submenu for choosing the submethods of the Select sort algorithm and select the desired model
 void getSelectMeasurement(arrType typeArr) {
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
            getTimeMeasurement(SELECT1, typeArr);
            break;
        }
        case 2: {
            getTimeMeasurement(SELECT2, typeArr);
            break;
        }
        case 3: {
            getTimeMeasurement(SELECT3, typeArr);
            break;
        }
        case 4: {
            getTimeMeasurement(SELECT4, typeArr);
            break;
        }
        case 5: {
            getTimeMeasurement(SELECT5, typeArr);
            break;
        }
        case 6: {
            getTimeMeasurement(SELECT6, typeArr);
            break;
        }
        case 7: {
            getTimeMeasurement(SELECT7, typeArr);
            break;
        }
        case 8: {
            getTimeMeasurement(SELECT8, typeArr);
            break;
        }
        case 9: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

// display the submenu for choosing the submethods of the Exchange sort algorithm and select the desired model
void getExchangeMeasurement(arrType typeArr) {
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
            getTimeMeasurement(EXCHANGE1, typeArr);
            break;
        }
        case 2: {
            getTimeMeasurement(EXCHANGE2, typeArr);
            break;
        }
        case 3: {
            getTimeMeasurement(EXCHANGE3, typeArr);
            break;
        }
        case 4: {
            getTimeMeasurement(EXCHANGE4, typeArr);
            break;
        }
        case 5: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

// display the submenu for choosing the submethods of the Hybrid Select-Exchange sort algorithm and select the desired model
  void getSelectExchangeMeasurement(arrType typeArr) {
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
            getTimeMeasurement(SELECT1EXCHANGE, typeArr);
            break;
        }
        case 2: {
            getTimeMeasurement(SELECT2EXCHANGE, typeArr);
            break;
        }
        case 3: {
            getTimeMeasurement(SELECT3EXCHANGE, typeArr);
            break;
        }
        case 4: {
            getTimeMeasurement(SELECT4EXCHANGE, typeArr);
            break;
        }
        case 5: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

 // display the submenu for choosing the submethods of the Shell sort algorithm and select the desired model
void getShellMeasurement(arrType typeArr) {
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
            getTimeMeasurement(SHELL_1, typeArr);
            break;
        }
        case 2: {
            getTimeMeasurement(SHELL_2, typeArr);
            break;
        }
        case 3: {
            system("cls");
            tensorMainMenu();
        }
    }
 }

// general field for program management and central hub of execution
void tensorMainMenu(){//main menu in which user can choose type of sort algorithms
	unsigned short position = 1;//current position
	unsigned short tr = 1;
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
        arrow(8, position);printf("Setting parameter values for the array");
        gotoxy(30, 18);
        arrow(9, position);printf("Switch between 1D and 3D arrays");
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
            getInsertMeasurement(checkArrayType);
            break;
        }
		case 2 : {
            getSelectMeasurement(checkArrayType);
            break;
        }
		case 3 : {
            getExchangeMeasurement(checkArrayType);
            break;
        }
        case 4 : {
            getTimeMeasurement(INSERTEXCHANGE, checkArrayType);
            break;
        }
        case 5: {
            getSelectExchangeMeasurement(checkArrayType);
            break;
        }
        case 6: {
            getShellMeasurement(checkArrayType);
            break;
        }
        case 7: {
            getTimeMeasurement(QUICKSORT, checkArrayType);
            break;
        }
        case 8: {
            system("cls");

            if (checkArrayType == TENSOR_) {
                tensorReleasingMemory(BLOCK, ROW);
                setTensorValues();
                tensorAllocation(BLOCK, ROW, COLUMN);
            }
            else {
                vectorReleaseMemory();
                setVectorValue();
                vectorAllocation(VECTOR_LENGTH);
            }

            printf("Press the left arrow to come back to menu...");
            if (getch() == 224) {
                char key = getch();
                if (key == 75) { system("cls"); tensorMainMenu(); }
            }
            break;
        }
        case 9: {
            system("cls");
            if (checkArrayType == TENSOR_)
                printf("Currently 3D array version is used\n");
            else
                printf("Currently 1D array version is used\n");

            printf("Do you want to switch to different version:\n");
            printf("YES? - print Y, otherwise type any key and return to the menu\n");
            char ch;
            scanf("%c", &ch);

            if (ch == 'Y') {
                if(checkArrayType == TENSOR_)
                    checkArrayType = VECTOR_;
                else
                    checkArrayType = TENSOR_;
                system("cls");
                tensorMainMenu();
            }
            else {
                system("cls");
                tensorMainMenu();
            }

            break;
        }
        case 10: {
            system("cls");
            if  ( (checkArrayType == TENSOR_ && (Arr3D_sorted == NULL || Arr3D_unsorted == NULL)) || (checkArrayType == VECTOR_ && (Vec_sorted == NULL || Vec_unsorted == NULL))) {
                printf("\tSorry, but it looks that you haven't done any sorting.\n");
                Sleep(1500);
                system("cls");
                tensorMainMenu();
                break;
            }
            printf("UNSORTED_ARRAY");
            if (checkArrayType == TENSOR_)
                display3DArray(Arr3D_unsorted, BLOCK, ROW, COLUMN);
            else
                display1DArray(Vec_unsorted, VECTOR_LENGTH);
            printf("SORTED_ARRAY");
            if (checkArrayType == TENSOR_)
                display3DArray(Arr3D_sorted, BLOCK, ROW, COLUMN);
            else
                display1DArray(Vec_sorted, VECTOR_LENGTH);

            printf("Press the left arrow to come back to menu...");
            if (getch() == 224) {
                char key = getch();
                if (key == 75) { system("cls"); tensorMainMenu(); }
            }

            break;
        }
	}
}
