#ifndef __commonVector_H__
#define __commonVector_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum sortAlg{INSERT1, INSERT2, INSERT3, INSERT4,
                    SELECT1, SELECT2, SELECT3, SELECT4,
                    SELECT5, SELECT6, SELECT7, SELECT8,
                    EXCHANGE1, EXCHANGE2, EXCHANGE3,
                    EXCHANGE4, INSERTEXCHANGE,
                    SELECT1EXCHANGE, SELECT2EXCHANGE,
                    SELECT3EXCHANGE, SELECT4EXCHANGE,
                    SHELL_1, SHELL_2, QUICKSORT};

int ***Arr3D;//global pointer on array
int ***Arr3D_random;

int *Vec;//global pointer on vector
int *Vec_random;

#endif
