#ifndef __SORTSVECTOR_H__
#define __SORTSVECTOR_H__
#include <time.h>

clock_t vectorInsert1(int * A, int N);
clock_t vectorInsert2(int * A, int N);
clock_t vectorInsert3(int * A, int N);
clock_t vectorInsert4(int * A, int N);
clock_t vectorSelect1(int * A, int N);
clock_t vectorSelect2(int * A, int N);
clock_t vectorSelect3(int * A, int N);
clock_t vectorSelect4(int * A, int N);
clock_t vectorSelect5(int * A, int N);
clock_t vectorSelect6(int * A, int N);
clock_t vectorSelect7(int * A, int N);
clock_t vectorSelect8(int * A, int N);
clock_t vectorExchange1(int * A, int N);
clock_t vectorExchange2(int * A, int N);
clock_t vectorExchange3(int * A, int N);
clock_t vectorExchange4(int * A, int N);
clock_t vectorInsertExchange(int * A, int N);
clock_t vectorSelect1Exchange(int * A, int N);
clock_t vectorSelect2Exchange(int * A, int N);
clock_t vectorSelect3Exchange(int * A, int N);
clock_t vectorSelect4Exchange(int * A, int N);
clock_t vectorShell_1(int * A, int N);
clock_t vectorShell_2(int * A, int N);
void vectorQuickSort(int L, int R);

#endif // __SORTSVECTOR_H__
