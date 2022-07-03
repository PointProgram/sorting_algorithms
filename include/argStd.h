#ifndef __ARGSTD_H__
#define __ARGSTD_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defining macros to enable default parameters usage
#define arguments_cnt(vrg1,vrg2,vrg3,vrg4,vrg5,vrgN, ...) vrgN
#define arguments_argn(...)  arguments_cnt(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define arguments_cat0(x,y)  x ## y
#define arguments_cat(x,y)   arguments_cat0(x,y)

#define arguments(arguments_f,...) arguments_cat(arguments_f, arguments_argn(__VA_ARGS__))(__VA_ARGS__)


#define measurementSortAlgorithm(...)   arguments(measurementSortAlgorithm, __VA_ARGS__)
#define measurementSortAlgorithm1(s)    measurementSortAlgorithmX(s, 0, 0, 0, 0)
#define measurementSortAlgorithm2(s, t)    measurementSortAlgorithmX(s, t, 0, 0, 0)
#define measurementSortAlgorithm3(s, t, p)    measurementSortAlgorithmX(s, t, p, 0, 0)
#define measurementSortAlgorithm4(s, t, p, n)  measurementSortAlgorithmX(s, t, p, n, 0)
#define measurementSortAlgorithm5(s, t, p, n, m) measurementSortAlgorithmX(s, t, p, n, m)




#endif
