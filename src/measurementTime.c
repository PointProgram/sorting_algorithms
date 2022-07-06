#include "../include/measurementTime.h"
//#include <stdio.h>

// an array of time measurements
clock_t Res[measurements_number];

float MeasurementProcessing()
{
    long int Sum;
    float AverageValue;

    ////////////////////////////////////////////////// ///////////
    // With these output statements, you can see why
    // the following calculation of measurement results is required
    //printf("Initial Measurement Results:\n");
    //for (int i = 0; i< measurements_number; i++)
    //printf(" %ld",Res[i]);
    //printf("\n\n");
    ////////////////////////////////////////////////// ///////////


    //------------------------------------------------ -----------
    /* Techniques for averaging measurement results:
    Step 1. The rejected_number of the first dimensions with indices is rejected
    from 0 to rejected_number-1.
    Step 2. Among other elements, we find the min_max_number variable
    riv with minimum values ​​and min_max_number of measurements with max-
    symbolic values, and also discard them.
    Step 3. We find the average value of the remaining measurements.
    */
    //------------------------------------------------ -----------
    /* Step 1. To perform Step 1, we simply start the algorithm with
    rejected_number index.
    */
    /* Step 2.
    To find min_max_number minimum and maximum
    of measurement values, we perform min_max_number iterations of the main one
    cycle of the shaker sorting algorithm in the index range from
    rejected_number to measurements_number-1.
    As a result, the min_max_number of minimum values ​​of measurements was
    must be in positions in the index range from
    rejected_number to rejected_number+min_max_number-1, and
    min_max_number of maximum values ​​of measurements - at positions in
    index range from measurements_number-min_max_number to
    measurements_number-1.
    */

    clock_t buf;
	int L = rejected_number, R = measurements_number - 1;
	int k = rejected_number;
	for (int j=0; j < min_max_number; j++) {
		for (int i = L; i < R; i++)	{
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
		R = k;
		for (int i = R - 1; i >= L; i--) {
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
		L = k + 1;
	}

	////////////////////////////////////////////////// ///////////
    // With these output statements, you can see why
    // the following calculation of measurement results is required
    // printf("Measurement Results after sorting:\n");
    // for (int i = 0; i< measurements_number; i++)
    // printf(" %ld",Res[i]);
    // printf("\n\n");
    ////////////////////////////////////////////////// ///////////


    // Step 3.
    /* Find the average value of measurements after discarding
    rejected_number of first measurements and min_max_number of measurements from
    minimum values and min_max_number of measurements from the maximum
    final values, that is, the average value of the measurements in the range
    indexes from rejected_number + min_max_number to
    measurements_number - min_max_number - 1.
    */

    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
       Sum = Sum + Res[i];

    /* The number of measurements left to calculate the average
    value is equal to
    measurements_number – 2 * min_max_number - rejected_number
    */

    AverageValue = (float)Sum/(float)(measurements_number - 2*min_max_number - rejected_number);

    ////////////////////////////////////////////////// ///////////
    // With these output statements, you can see why
    // the following calculation of measurement results is required
    /*
    printf("Initial rejected values: ");
    for (int i = 0; i < rejected_number; i++)
        printf("%ld ", Res[i]);
    printf("\n");
    printf("Rejected minimum values: ");
    for (int i = rejected_number; i < rejected_number + min_max_number; i++)
        printf("%ld ", Res[i]);
    printf("\n");
    printf("Rejected maximum values: ");
    for (int i = measurements_number - min_max_number; i < measurements_number; i++)
        printf("%ld ", Res[i]);
    printf("\n\n\n");
    printf("Sum of the remaining values, Sum = %ld;\n", Sum);
    printf("AverageValue = %11.2f\n\n\n", AverageValue);
    */

    return AverageValue;

}

