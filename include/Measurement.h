#ifndef __Measurement_H__
#define __Measurement_H__

#include <time.h>

//General number of time measurements of the algorithm 
#define measurements_number 28

//Number of rejected initial measurements
#define rejected_number 2

//Amount of rejected dimensions with minimal values
//It also equels the amount of rejectem measurements with maximum values
#define min_max_number 3

//Array of time values 
extern clock_t  Res[measurements_number];

//Function of processing and averaging of time measurement values of work algorithm.
//Returns the average time of the algorithm.
float MeasurementProcessing();

#endif
