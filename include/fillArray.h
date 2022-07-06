#ifndef __FILLARRAY_H__
#define __FILLARRAY_H__

// allocate memory to the 3D array
void tensorAllocation(int blocks, int rows, int cols);
// release allocated memory from the 3D array
void tensorReleasingMemory(int blocks, int rows);
// fill the 3D array with increasing numbers
void tensorFillUp(int blocks, int rows, int cols);
// fill the 3D array with random numbers
void tensorFillRand(int blocks, int rows, int cols);
// fill the 3D array with decreasing numbers
void tensorFillDown(int blocks, int rows, int cols);
// copy the content from the global 3D array to the local copy
int ***copyArray3D(int blocks, int rows, int cols);

// allocate memory to the 1D array
void vectorAllocation(int length);
// release allocated memory from the 1D array
void vectorReleaseMemory();
// fill the 1D array with increasing numbers
void vectorFillUp(int length);
// fill the 1D array with random numbers
void vectorFillRand(int length);
// fill the 1D array with decreasing numbers
void vectorFillDown(int length);
// copy the content from the global 1D array to the local copy
int *copyVector(int length);

#endif
