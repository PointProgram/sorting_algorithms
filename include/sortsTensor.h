#ifndef __SORTSTENSOR_H__
#define __SORTSTENSOR_H__
#include <time.h>

clock_t tensorInsert1(int ***A, int blocks, int rows, int clmns);
clock_t tensorInsert2(int ***A, int blocks, int rows, int clmns);
clock_t tensorInsert3(int ***A, int blocks, int rows, int clmns);
clock_t tensorInsert4(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect1(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect2(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect3(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect4(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect5(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect6(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect7(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect8(int ***A, int blocks, int rows, int clmns);
clock_t tensorExchange1(int ***A, int blocks, int rows, int clmns);
clock_t tensorExchange2(int ***A, int blocks, int rows, int clmns);
clock_t tensorExchange3(int ***A, int blocks, int rows, int clmns);
clock_t tensorExchange4(int ***A, int blocks, int rows, int clmns);
clock_t tensorInsertExchange(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect1Exchange(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect2Exchange(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect3Exchange(int ***A, int blocks, int rows, int clmns);
clock_t tensorSelect4Exchange(int ***A, int blocks, int rows, int clmns);
clock_t tensorShell_1(int ***A, int blocks, int rows, int clmns);
clock_t tensorShell_2(int ***A, int blocks, int rows, int clmns);
void tensorQuickSort(int L, int R,  int rows, int cols);

#endif // __SORTSTENSOR_H__
