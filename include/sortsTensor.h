#ifndef __SORTSTENSOR_H__
#define __SORTSTENSOR_H__
#include <time.h>

// Define the new variable type which is a struct.
// This definition must be visible to any function that is accessing the
// members of a variable of this type.
typedef struct tensorCoords {
    size_t cb; // current block
    size_t cr; // current row
    size_t cc; // current column

    size_t nb; // next item block
    size_t nr; // next item row
    size_t nc; // next item column

}tensorCoords;

//Declare prototypes of  the tensor sort functions which are defined in corresponding source file
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
