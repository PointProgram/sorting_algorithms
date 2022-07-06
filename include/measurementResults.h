#ifndef __MEASUREMENTRESULTS_H__
#define __MEASUREMENTRESULTS_H__

#include "commonVector.h"
#include <time.h>

// get the time measurement for the specific array sorting method
clock_t measurementSortAlgorithmX(sortAlg typeSort, arrType type, int blocks, int rows, int cols);
// arrange appropriate parameters assigned to the current options pattern and collect data for average time calculation
void arrayMeasurement(fillType typeFill, int blocks, int rows, int cols, sortAlg typeSort, arrType typeArray);


#endif
