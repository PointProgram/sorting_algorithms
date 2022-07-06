#ifndef  __COMMONVECTOR_H__
#define __COMMONVECTOR_H__

// enumeration structure for containing definitions for sort types used in the program
typedef enum sortAlg{INSERT1, INSERT2, INSERT3, INSERT4, \
                    SELECT1, SELECT2, SELECT3, SELECT4, \
                    SELECT5, SELECT6, SELECT7, SELECT8, \
                    EXCHANGE1, EXCHANGE2, EXCHANGE3, \
                    EXCHANGE4, INSERTEXCHANGE, \
                    SELECT1EXCHANGE, SELECT2EXCHANGE, \
                    SELECT3EXCHANGE, SELECT4EXCHANGE, \
                    SHELL_1, SHELL_2, QUICKSORT} sortAlg;

// enumeration structure for containing definitions for the array type in accordance to its dimensions
typedef enum arrType {TENSOR_,  VECTOR_} arrType;

// enumeration structure for containing definitions for the array type in accordance to its filler elements
typedef enum fillType {UP, RANDOM, DOWN} fillType;

// global pointer for the main 3D array manipulation
int ***Arr3D;
//global pointer for the content copying of the unsorted 3D array manipulation
int ***Arr3D_unsorted;
//global pointer for the content copying of the sorted 3D array manipulation
int ***Arr3D_sorted;

// global pointer for the main 1D array manipulation
int *Vec;
//global pointer for the content copying of the unsorted 1D array manipulation
int *Vec_unsorted;
//global pointer for the content copying of the sorted 1D array manipulation
int *Vec_sorted;

#endif
