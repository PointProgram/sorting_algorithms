#ifndef __Sorts_H__
#define __Sorts_H__
#include <time.h>

clock_t Select8(int ***A, int p, int m, int n);
clock_t Exchange3(int ***A, int p, int m, int n);
void QuickSort(int L, int R, int n, int m);
clock_t VectorSelect8(int *Ve, int ve);
clock_t VectorExchange3(int *Ve, int ve);
void VectorQuickSort(int Lv, int Rv);

#endif // __Sorts_H__
