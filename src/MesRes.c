#include "../include/measurement.h"
#include "../include/fillArr.h"
#include "../include/sortsVector.h"
#include "../include/sortsTensor.h"
#include "../include/mesRes.h"
#include "../include/commonVector.h"

enum sortAlg{INSERT1, INSERT2, INSERT3, INSERT4,
                    SELECT1, SELECT2, SELECT3, SELECT4,
                    SELECT5, SELECT6, SELECT7, SELECT8,
                    EXCHANGE1, EXCHANGE2, EXCHANGE3,
                    EXCHANGE4, INSERTEXCHANGE,
                    SELECT1EXCHANGE, SELECT2EXCHANGE,
                    SELECT3EXCHANGE, SELECT4EXCHANGE,
                    SHELL_1, SHELL_2, QUICKSORT};

clock_t measurementSortAlgorithms(int p, int n, int m, enum sortAlg typeSort) {
    switch(typeSort) {

        case INSERT1:
            return tensorInsert1(Arr3D, p, m, n);
        case INSERT2:
            return tensorInsert2(Arr3D, p, m, n);
        case INSERT3:
            return tensorInsert3(Arr3D, p, m, n);
        case INSERT4:
            return tensorInsert4(Arr3D, p, m, n);
        case SELECT1:
            return tensorSelect1(Arr3D, p, m, n);
        case SELECT2:
            return tensorSelect2(Arr3D, p, m, n);
        case SELECT3:
            return tensorSelect3(Arr3D, p, m, n);
        case SELECT4:
            return tensorSelect4(Arr3D, p, m, n);
        case SELECT5:
            return tensorSelect5(Arr3D, p, m, n);
        case SELECT6:
            return tensorSelect6(Arr3D, p, m, n);
        case SELECT7:
            return tensorSelect7(Arr3D, p, m, n);
        case SELECT8:
            return tensorSelect8(Arr3D, p, m, n);
        case EXCHANGE1:
            return tensorExchange1(Arr3D, p, m, n);
        case EXCHANGE2:
            return tensorExchange2(Arr3D, p, m, n);
        case EXCHANGE3:
            return tensorExchange3(Arr3D, p, m, n);
        case EXCHANGE4:
            return tensorExchange4(Arr3D, p, m, n);
        case INSERTEXCHANGE:
            return tensorInsertExchange(Arr3D, p, m, n);
        case SELECT1EXCHANGE:
            return tensorSelect1Exchange(Arr3D, p, m, n);
        case SELECT2EXCHANGE:
            return tensorSelect2Exchange(Arr3D, p, m, n);
        case SELECT3EXCHANGE:
            return tensorSelect3Exchange(Arr3D, p, m, n);
        case SELECT4EXCHANGE:
            return tensorSelect4Exchange(Arr3D, p, m, n);
        case SHELL_1:
            return tensorShell_1(Arr3D, p, m, n);
        case SHELL_2:
            return tensorShell_2(Arr3D, p, m, n);
    }



}
void tensorMeasurement(int a, int p, int n, int m, clock_t (*sort_f)(int ***, int, int, int) )//measurement for select for 3D array
{
    switch(a) {
        case 1:{
        for (int i = 0; i < measurements_number; i++)
        {
            FillUp(p,m,n);
            //Res[i] = tensorSelect8(Arr3D, p,m,n);
            Res[i] = (*sort_f)(Arr3D, p, m, n);

        }
        break;
        }
        case 2: {
        for (int i = 0; i < measurements_number; i++)
        {
            FillRand(p, m, n);
            Res[i] = (*sort_f)(Arr3D, p, m, n);
        }
        break;
        }
        case 3:{
        for (int i = 0; i < measurements_number; i++)
        {
            FillDown(p, m, n);
            Res[i] = (*sort_f)(Arr3D, p, m, n);
        }
        break;
        }
    }

}


void QuickSortMeasurement(int a, int p, int n, int m)//measurement for quicksort for 3D array
{
    switch(a) {
        case 1:{
            clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++)
        {
            FillUp(p,m,n);
            time_start = clock();//beg of time mes
            tensorQuickSort(0, p-1, n, m);
            time_stop = clock();//end of time mes
            Res[i] = time_stop - time_start;//result
        }
        break;
        }
        case 2: {
            clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++)
        {
            FillRand(p, m, n);
            time_start = clock();
            tensorQuickSort(0, p-1, n, m);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        break;
        }
        case 3:{
            clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++)
        {
            FillDown(p, m, n);
            time_start = clock();
            tensorQuickSort(0, p-1, n, m);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        break;
        }
    }
}
void SelectMeasurement(int a, int p, int n, int m)//measurement for select for 3D array
{
    switch(a) {
        case 1:{
        for (int i = 0; i < measurements_number; i++)
        {
            FillUp(p,m,n);
            Res[i] = tensorSelect8(Arr3D, p,m,n);
        }
        break;
        }
        case 2: {
        for (int i = 0; i < measurements_number; i++)
        {
            FillRand(p, m, n);
            Res[i] = tensorSelect8(Arr3D, p,m,n);
        }
        break;
        }
        case 3:{
        for (int i = 0; i < measurements_number; i++)
        {
            FillDown(p, m, n);
            Res[i] = tensorSelect8(Arr3D, p,m,n);
        }
        break;
        }
    }

}

void ExchangeSortMeasurement(int a, int p, int n, int m)//measurement for exchange for 3D array
{
    switch(a) {
        case 1:{
        for (int i = 0; i < measurements_number; i++)
        {
            FillUp(p,m,n);
            Res[i] = tensorExchange3(Arr3D, p,m,n);
        }
        break;
        }
        case 2: {
        for (int i = 0; i < measurements_number; i++)
        {
            FillRand(p,m,n);
            Res[i] = tensorExchange3(Arr3D, p,m,n);
        }
        break;
        }
        case 3:{
        for (int i = 0; i < measurements_number; i++)
        {
            FillDown(p, m, n);
            Res[i] = tensorExchange3(Arr3D, p,m,n);
        }
        break;
        }
    }
}

void vectorQuickSortMeasurement(int a, int v)//measurement for quicksort for vector
{
    switch(a) {
        case 1:{
            clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillUp(v);
            time_start = clock();
            vectorQuickSort(0, v-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        break;
        }
        case 2: {
            clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillRand(v);
            time_start = clock();
            vectorQuickSort(0, v-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        break;
        }
        case 3:{
            clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillDown(v);
            time_start = clock();
            vectorQuickSort(0, v-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        break;
        }
    }
}
void vectorSelectMeasurement(int a, int v)//measurement for select for vector
{
    switch(a) {
        case 1:{
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillUp(v);
            Res[i] = vectorSelect8(Vec, v);
        }
        break;
        }
        case 2: {
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillRand(v);
            Res[i] = vectorSelect8(Vec, v);
        }
        break;
        }
        case 3:{
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillDown(v);
            Res[i] = vectorSelect8(Vec, v);
        }
        break;
        }
    }

}

void vectorExchangeSortMeasurement(int a, int v)//measurement for exchange for vector
{
    switch(a) {
        case 1:{
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillUp(v);
            Res[i] = vectorExchange3(Vec, v);
        }
        break;
        }
        case 2: {
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillRand(v);
            Res[i] = vectorExchange3(Vec, v);
        }
        break;
        }
        case 3:{
        for (int i = 0; i < measurements_number; i++)
        {
            vectorFillDown(v);
            Res[i] = vectorExchange3(Vec, v);
        }
        break;
        }
    }
}
