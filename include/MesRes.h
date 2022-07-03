#ifndef __mesRes_H__
#define __mesRes_H__

#include "commonVector.h"

/*void QuickSortMeasurement(int a, int p, int n, int m);
void SelectMeasurement(int a, int p, int n, int m);
void ExchangeSortMeasurement(int a, int p, int n, int m);
void vectorQuickSortMeasurement(int a, int V);
void vectorSelectMeasurement(int a, int V);
void vectorExchangeSortMeasurement(int a, int v);
*/

clock_t measurementSortAlgorithmX(sortAlg typeSort, arrType type, int blocks, int rows, int cols);
void tensorMeasurement(fillType typeFill, int blocks, int rows, int cols, sortAlg typeSort,  arrType typeArray);
void vectorMeasurement(fillType typeFill, int length, sortAlg typeSort,  arrType typeArray);
void tensorQuickSortMeasurement(fillType typeFill, int blocks, int rows, int cols);
void vectorQuickSortMeasurement(fillType typeFill, int length);


#endif // __MesRes_H__
