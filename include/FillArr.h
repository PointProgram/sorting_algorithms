#ifndef __fillArr_H__
#define __fillArr_H__

void tensorAllocation(int blocks, int rows, int cols);
void tensorReleasingMemory(int blocks, int rows);
void tensorFillUp(int blocks, int rows, int cols);
void tensorFillRand(int blocks, int rows, int cols);
void tensorFillDown(int blocks, int rows, int cols);
int ***copyArray3D(int blocks, int rows, int cols);

void vectorAllocation(int length);
void vectorReleaseMemory();
void vectorFillUp(int length);
void vectorFillRand(int length);
void vectorFillDown(int length);
int *copyVector(int length);

#endif // __FillArr_H__
