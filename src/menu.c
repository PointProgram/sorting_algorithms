#include <time.h>//for delay()
#include <windows.h>//for HANDLE
#include <string.h>
#include <conio.h> // for windows use
//#include "../include/conio.h" //for getch() and linux use
#include "../include/mesRes.h"
#include "../include/measurement.h"
#include "../include/commonVector.h"
#include "../include/menu.h"
#include "../include/globVar.h"
#include "../include/displayArray.h"

#include "../include/fillArr.h"

#pragma warning (disable:4996)
#define MAX 8 //max number of menu items
#define MIN 1 //min number of menu items

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

void screen_saver()//printf a information in console
{
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
void menut();//main menu
void menuv();//vector time measurement
void OutTable1(float ordered, float random, float backordered)//table for exchange3
{

for(int i =0;i<97;i++) printf("-");//draw a frame
printf("\n");
    printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
    printf("|\tExchange3\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", ordered, random, backordered);//prints time for those ways
    printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    for(int i =0;i<97;i++) printf("-");
    printf("\n\n");
}
void OutTable2(float ordered, float random, float backordered)//table for Select8
{
    for(int i =0;i<97;i++) printf("-");
printf("\n");
    printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
    //all tables have the same values
    printf("|\tSelect8\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", ordered, random, backordered);
    printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    for(int i =0;i<97;i++) printf("-");
    printf("\n\n");
}
void OutTable3(float ordered, float random, float backordered)//table for quicksort
{
 for(int i =0;i<97;i++) printf("-");
printf("\n");
    printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
    //all tables have the same values
    printf("|\tQuickSort\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", ordered, random, backordered);
    printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    for(int i =0;i<97;i++) printf("-");
    printf("\n\n");
}
void OutTable(float ordered1, float random2, float backordered3,float ordered4, float random5, float backordered6,float ordered7, float random8, float backordered9)
{
    //system("cls");
    //Average result of measurements that will be shown on the screen in specefic position
    for(int i =0;i<97;i++) printf("-");
    printf("\n|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
    //All columns print the same value
    printf("|\tExchange3\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", ordered1, random2, backordered3);
    printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    for(int i =0;i<97;i++) printf("-");
    printf("\n|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
    //All columns print the same value
    printf("|\tSelect8\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", ordered4, random5, backordered6);
    printf("|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    for(int i =0;i<97;i++) printf("-");
    printf("\n|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
    printf("|\t\t\t| \tOrdered \t| \tRandom \t\t| \tBackOrdered\t|\n");
    //All columns print the same value
    printf("|\tQuickSort\t|\t%7.2f\t\t|\t%7.2f\t\t|\t%7.2f\t\t|\n", ordered7, random8, backordered9);
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
void setV(int a, int b, int c) {
    int* ptr;
    ptr = &P;
    *ptr = a;
    ptr = &M;
    *ptr = b;
    ptr = &N;
    *ptr = c;

}
void menut(){//main menu in which user can choose type of sort algorithms
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
	arrow(1, position);printf("1.Exchange3");//check where to locate an arrow
	gotoxy(30,11);
	arrow(2, position);printf("2.Select8");
	gotoxy(30,12);
	arrow(3, position);printf("3.QuickSort");
	gotoxy(30,13);
	arrow(4, position);printf("4.All sort algorithms");
    gotoxy(30,14);
    arrow(5, position);printf("Set X Y Z values sorting array algorithm");
    gotoxy(30, 15);
    arrow(6, position);printf("Choosing 2d or 3d algorithm");
    gotoxy(30, 16);
    arrow(7, position);printf("Display");
    gotoxy(30, 17);
	arrow(8, position);printf("Exit\n");
	gotoxy(30,18);

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
	    float F1, F2, F3, F4 ,F5 , F6 ,F7 ,F8 ,F9;//variables for time measurements
		case 1: {
		    system("cls");
            printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", P, M, N);
		    srand(time(NULL));//restart time value
            ExchangeSortMeasurement(1, P, N, M);//loads results of exchange sort measurement
            F1=MeasurementProcessing();//F1 has a value of time
            srand(time(NULL));
            ExchangeSortMeasurement(2, P, N, M);
            F2=MeasurementProcessing();
            srand(time(NULL));
            ExchangeSortMeasurement(3, P, N, M);
            F3=MeasurementProcessing();
            printf("\t\t\t\t\tThree-dimensional array\n");
            OutTable1(F1, F2, F3);
            printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", P,M,N);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){//check buttons, if user clicked left arrow you move to the menu, if right arrow you loads vector measurement
                char key= getch();//check keys
                if (key == 75) { system("cls"); menut();}
            }
            break;
        }
		case 2 : {
		    system("cls");
            srand(time(NULL));
            SelectMeasurement(1, P, N, M);
            F1=MeasurementProcessing();
            srand(time(NULL));
            SelectMeasurement(2, P, N, M);
            F2=MeasurementProcessing();
            srand(time(NULL));
            SelectMeasurement(3, P, N, M);
            F3=MeasurementProcessing();
            printf("\t\t\t\t\tThree-dimensional array\n");
            OutTable2(F1, F2, F3);
            printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", P,M,N);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){
                char key= getch();
                if (key == 75) { system("cls"); menut();}
            }
            break;
        }
		case 3 : {
		    system("cls");
		    srand(time(NULL));
            QuickSortMeasurement(1, P, N, M);
            F1=MeasurementProcessing();
            srand(time(NULL));
            QuickSortMeasurement(2, P, N, M);
            F2=MeasurementProcessing();
            srand(time(NULL));
            QuickSortMeasurement(3, P, N, M);
            F3=MeasurementProcessing();
            printf("\t\t\t\t\tThree-dimensional array\n");
            OutTable3(F1, F2, F3);
            printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", P,M,N);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){
                char key= getch();
                if (key == 75) { system("cls"); menut();}
            }
            break;
        }
	case 4 : {
	    system("cls");
        srand(time(NULL));
        ExchangeSortMeasurement(1, P, N, M);
        F1=MeasurementProcessing();
        srand(time(NULL));
        ExchangeSortMeasurement(2, P, N, M);
        F2=MeasurementProcessing();
        srand(time(NULL));
        ExchangeSortMeasurement(3, P, N, M);
        F3=MeasurementProcessing();
        srand(time(NULL));
        SelectMeasurement(1, P, N, M);
        F4=MeasurementProcessing();
        srand(time(NULL));
        SelectMeasurement(2, P, N, M);
        F5=MeasurementProcessing();
        srand(time(NULL));
        SelectMeasurement(3, P, N, M);
        F6=MeasurementProcessing();
        srand(time(NULL));
        QuickSortMeasurement(1, P, N, M);
        F7=MeasurementProcessing();
        srand(time(NULL));
        QuickSortMeasurement(2, P, N, M);
        F8=MeasurementProcessing();
        srand(time(NULL));
        QuickSortMeasurement(3, P, N, M);
        F9=MeasurementProcessing();
        printf("\t\t\t\t\tThree-dimensional array\n");
        OutTable(F1, F2, F3, F4, F5, F6, F7, F8,F9);
        printf("\t\t\t\tNumber of elements PxMxN: %dx%dx%d\n\n", P,M,N);
            printf("Press the left arrow to come back to menu...");
            if(getch()==224){
                char key= getch();
                if (key == 75) { system("cls"); menut();}
            }
        break;
	}
    case 5: {
        system("cls");
        DynEnd(P, M);
        int* ptr = &P;
        int x, a, b, c;
        printf("Enter value of P: ");
        a = scanf("%d", &x);
        *ptr = x;
        ptr = &M;
        printf("Enter value of M: ");
        b = scanf("%d", &x);
        *ptr = x;
        ptr = &N;
        printf("Enter value of N: ");
        c = scanf("%d", &x);
        *ptr = x;
        DynBeg(P, M, N);
        printf("Press the left arrow to come back to menu...");
        if (getch() == 224) {
            char key = getch();
            if (key == 75) { system("cls"); menut(); }
        }
        break;
    }
    case 6: {
        system("cls");
        printf("Currently 3d array version is used\n");
        printf("Do you want to switch to version version:\n");
        printf("YES? - print Y, else type any key and return to the menu\n");
        char ch;
        scanf("%c", &ch);
        if (ch == 'Y')
            menuv();
        else {
            system("cls"); menut();
        }

        break;
    }
    case 7: {
        system("cls");
        printf("Your array is printed in console\n");

        display3DArray();

        printf("Press the left arrow to come back to menu...");
        if (getch() == 224) {
            char key = getch();
            if (key == 75) { system("cls"); menut(); }
        }

        break;
    }
	}
}
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
            menut();
        else
            system("cls"); menuv();
        break;
    }
	}
}
