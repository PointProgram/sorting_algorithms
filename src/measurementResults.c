#include "../include/measurementTime.h"
#include "../include/fillArray.h"
#include "../include/sortsVector.h"
#include "../include/sortsTensor.h"
#include "../include/measurementResults.h"
#include "../include/commonVector.h"
#include "../include/argStd.h"

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
void arrayMeasurement(fillType typeFill, int blocks, int rows, int cols, sortAlg typeSort,  arrType typeArr)//measurement for select for 3D array
{
    for (int i = 0; i < measurements_number; i++) {
        if (typeFill == UP) {
            if (typeArr == TENSOR_)
                tensorFillUp(blocks,rows,cols);
            else
                vectorFillUp(blocks);
        }
        else if (typeFill == RANDOM) {
             if (typeArr == TENSOR_) {
                tensorFillRand(blocks,rows,cols);

                if (i == measurements_number - 1)
                    Arr3D_unsorted = copyArray3D(blocks, rows, cols);
             }
             else {
                vectorFillRand(blocks);

                if (i == measurements_number - 1)
                    Vec_unsorted = copyVector(blocks);
             }
        }
        else if (typeFill = DOWN) {
            if (typeArr == TENSOR_)
                tensorFillDown(blocks, rows, cols);
            else
                vectorFillDown(blocks);
        }

        if (typeSort == QUICKSORT) {
            clock_t time_start, time_stop;
            time_start = clock();//beg of time mes
            if (typeArr == TENSOR_)
                tensorQuickSort(0, blocks * rows * cols - 1, rows, cols);
            else
                vectorQuickSort(0, blocks - 1);
            time_stop = clock();//end of time mes
            Res[i] = time_stop - time_start;//result
        }
        else {
            if (typeArr == TENSOR_)
                Res[i] = measurementSortAlgorithm(typeSort, typeArr, blocks, rows, cols);
            else
                Res[i] = measurementSortAlgorithm(typeSort, typeArr, blocks);
        }

        if (i == measurements_number - 1 && typeFill == RANDOM)  {
            if (typeArr == TENSOR_)
                Arr3D_sorted = copyArray3D(blocks, rows, cols);
            else
                Vec_sorted = copyVector(blocks);
        }
    }
}
