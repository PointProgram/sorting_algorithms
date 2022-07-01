#include "../include/measurement.h"
#include "../include/fillArr.h"
#include "../include/sortsVector.h"
#include "../include/sortsTensor.h"
#include "../include/mesRes.h"
#include "../include/commonVector.h"

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
