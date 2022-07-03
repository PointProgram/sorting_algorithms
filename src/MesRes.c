#include "../include/measurement.h"
#include "../include/fillArr.h"
#include "../include/sortsVector.h"
#include "../include/sortsTensor.h"
#include "../include/mesRes.h"
#include "../include/commonVector.h"
#include "../include/argStd.h"
#include "../include/displayArray.h"

clock_t measurementSortAlgorithmX(sortAlg typeSort, arrType type, int blocks, int rows, int cols) {

    switch(typeSort) {
        case INSERT1:
            if (type == TENSOR_)
                return tensorInsert1(Arr3D, blocks, rows, cols);
            else
                return vectorInsert1(Vec, blocks);
        case INSERT2:
            if (type == TENSOR_)
                return tensorInsert2(Arr3D, blocks, rows, cols);
            else
                return vectorInsert2(Vec, blocks);
        case INSERT3:
            if (type == TENSOR_)
                return tensorInsert3(Arr3D, blocks, rows, cols);
            else
                return vectorInsert3(Vec, blocks);
        case INSERT4:
            if (type == TENSOR_)
                return tensorInsert4(Arr3D, blocks, rows, cols);
            else
                return vectorInsert4(Vec, blocks);
        case SELECT1:
            if (type == TENSOR_)
                return tensorSelect1(Arr3D, blocks, rows, cols);
            else
                return vectorSelect1(Vec, blocks);
        case SELECT2:
            if (type == TENSOR_)
                return tensorSelect2(Arr3D, blocks, rows, cols);
            else
                return vectorSelect2(Vec, blocks);
        case SELECT3:
            if (type == TENSOR_)
                return tensorSelect3(Arr3D, blocks, rows, cols);
            else
                return vectorSelect3(Vec, blocks);
        case SELECT4:
            if (type == TENSOR_)
                return tensorSelect4(Arr3D, blocks, rows, cols);
            else
                return vectorSelect4(Vec, blocks);
        case SELECT5:
            if (type == TENSOR_)
                return tensorSelect5(Arr3D, blocks, rows, cols);
            else
                return vectorSelect5(Vec, blocks);
        case SELECT6:
            if (type == TENSOR_)
                return tensorSelect6(Arr3D, blocks, rows, cols);
            else
                return vectorSelect6(Vec, blocks);
        case SELECT7:
            if (type == TENSOR_)
                return tensorSelect7(Arr3D, blocks, rows, cols);
            else
                return vectorSelect7(Vec, blocks);
        case SELECT8:
            if (type == TENSOR_)
                return tensorSelect8(Arr3D, blocks, rows, cols);
            else
                return vectorSelect8(Vec, blocks);
        case EXCHANGE1:
            if (type == TENSOR_)
                return tensorExchange1(Arr3D, blocks, rows, cols);
            else
                return vectorExchange1(Vec, blocks);
        case EXCHANGE2:
            if (type == TENSOR_)
                return tensorExchange2(Arr3D, blocks, rows, cols);
            else
                return vectorExchange2(Vec, blocks);
        case EXCHANGE3:
            if (type == TENSOR_)
                return tensorExchange3(Arr3D, blocks, rows, cols);
            else
                return vectorExchange3(Vec, blocks);
        case EXCHANGE4:
            if (type == TENSOR_)
                return tensorExchange4(Arr3D, blocks, rows, cols);
            else
                return vectorExchange4(Vec, blocks);
        case INSERTEXCHANGE:
            if (type == TENSOR_)
                return tensorInsertExchange(Arr3D, blocks, rows, cols);
            else
                return vectorInsertExchange(Vec, blocks);
        case SELECT1EXCHANGE:
            if (type == TENSOR_)
                return tensorSelect1Exchange(Arr3D, blocks, rows, cols);
            else
                return vectorSelect1Exchange(Vec, blocks);
        case SELECT2EXCHANGE:
            if (type == TENSOR_)
                return tensorSelect2Exchange(Arr3D, blocks, rows, cols);
            else
                return vectorSelect2Exchange(Vec, blocks);
        case SELECT3EXCHANGE:
            if (type == TENSOR_)
                return tensorSelect3Exchange(Arr3D, blocks, rows, cols);
            else
                return vectorSelect3Exchange(Vec, blocks);
        case SELECT4EXCHANGE:
            if (type == TENSOR_)
                return tensorSelect4Exchange(Arr3D, blocks, rows, cols);
            else
                return vectorSelect4Exchange(Vec, blocks);
        case SHELL_1:
            if (type == TENSOR_)
                return tensorShell_1(Arr3D, blocks, rows, cols);
            else
                return vectorShell_1(Vec, blocks);
        case SHELL_2:
            if (type == TENSOR_)
                return tensorShell_2(Arr3D, blocks, rows, cols);
            else
                return vectorShell_2(Vec, blocks);
    }
}

//passing a function as a parameter argument
//void tensorMeasurement(int a, int p, int n, int m, clock_t (*sort_f)(int ***, int, int, int) )//measurement for select for 3D array
void tensorMeasurement(fillType typeFill, int blocks, int rows, int cols, sortAlg typeSort,  arrType typeArray)//measurement for select for 3D array
{
    for (int i = 0; i < measurements_number; i++) {
        if (typeFill == UP) {
            tensorFillUp(blocks,rows,cols);
        }
        else if (typeFill == RANDOM) {
            tensorFillRand(blocks,rows,cols);
        }
        else if (typeFill = DOWN) {
            tensorFillDown(blocks, rows, cols);
        }
        Res[i] = measurementSortAlgorithm(typeSort, typeArray, blocks, rows, cols) ;
    }
}


void vectorMeasurement(fillType typeFill, int length, sortAlg typeSort,  arrType typeArray) {
    for (int i = 0; i < measurements_number; i++) {
        if (typeFill == UP) {
            vectorFillUp(length);
        }
        else if (typeFill == RANDOM) {
            vectorFillRand(length);
        }
        else if (typeFill = DOWN) {
            vectorFillDown(length);
        }

        Res[i] = measurementSortAlgorithm(typeSort, typeArray, length);
    }
}

void tensorQuickSortMeasurement(fillType typeFill, int blocks, int rows, int cols)//measurement for quicksort for 3D array
{
        clock_t time_start, time_stop;
        for (int i = 0; i < measurements_number; i++) {
             if (typeFill == UP) {
                tensorFillUp(blocks,rows,cols);
            }
            else if (typeFill == RANDOM) {
                tensorFillRand(blocks,rows,cols);
            }
            else if (typeFill = DOWN) {
                tensorFillDown(blocks, rows, cols);
            }

            time_start = clock();//beg of time mes
            tensorQuickSort(0, blocks-1, rows, cols);
            time_stop = clock();//end of time mes
            Res[i] = time_stop - time_start;//result
        }
}


void vectorQuickSortMeasurement(fillType typeFill, int length)//measurement for quicksort vector
{
    clock_t time_start, time_stop;
    for (int i = 0; i < measurements_number; i++) {
         if (typeFill == UP) {
            vectorFillUp(length);
        }
        else if (typeFill == RANDOM) {
            vectorFillRand(length);
        }
        else if (typeFill = DOWN) {
            vectorFillDown(length);
        }

        time_start = clock();//beg of time mes
        vectorQuickSort(0, length-1);
        time_stop = clock();//end of time mes
        Res[i] = time_stop - time_start;//result
    }
}
