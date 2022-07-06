#include "../include/fillArray.h"
#include "../include/commonVector.h"
#include <string.h>
#include <stdlib.h>

void tensorAllocation(int blocks, int rows, int cols) {//allocate memory of array
    Arr3D = (int***) malloc(blocks*sizeof(int**));
	for (int k=0; k<blocks; k++){
		Arr3D[k] = (int**) malloc(rows*sizeof(int*));
		for (int i=0; i<rows; i++)
			Arr3D[k][i] = (int*) malloc(cols*sizeof(int));
	}
}

void tensorReleasingMemory(int blocks, int rows) {//release memory
    for(int k=0;k<blocks;k++){
		for(int i=0;i<rows;i++){
			free(Arr3D[k][i]);
		}
		free(Arr3D[k]);
	}
	free(Arr3D);
}

int ***copyArray3D(int blocks, int rows, int cols) {
    int ***cpy;

    cpy = (int***) malloc(blocks*sizeof(int**));
	for (int k=0; k<blocks; k++){
		cpy[k] = (int**) malloc(rows*sizeof(int*));
		for (int i=0; i<rows; i++)
			cpy[k][i] = (int*) malloc(cols*sizeof(int));
	}

    for(int i = 0; i < blocks; i++) {
        for (int j = 0; j < rows; j++) {
            memcpy(cpy[i][j], Arr3D[i][j], cols*sizeof(int));
        }
    }

    return cpy;
}

int *copyVector(int length) {
    int *cpy;

    cpy = (int*) malloc(length*sizeof(int));
    memcpy(cpy, Vec, sizeof(int) * length);

    return cpy;
}

void tensorFillUp(int blocks, int rows, int cols){//fill array with ordered numbers
	int number = 0;
	for(int k=0;k<blocks;k++){
		for(int j=0;j<rows;j++){
			for(int i=0;i<cols;i++){
			Arr3D[k][j][i]=number++;
			}
		}
	}
}

void tensorFillRand(int blocks, int rows, int cols){//fill 3D array with random numbers
	for(int k=0;k<blocks;k++){
		for(int j=0;j<rows;j++){
			for(int i=0;i<cols;i++){
				Arr3D[k][j][i]=rand()%(blocks*rows*cols);
			}
		}
	}
}

void tensorFillDown(int blocks, int rows, int cols){//fill 3D array with unordered numbers
int number = blocks*rows*cols;
	for(int k=0;k<blocks;k++){
		for(int j=0;j<rows;j++){
			for(int i=0;i<cols;i++){
				Arr3D[k][j][i]=number--;
			}
		}
	}
}

void vectorAllocation(int length) {//allocate memory for vector
	Vec = (int*) malloc(length*sizeof(int));
}

void vectorReleaseMemory() {//free memory
	free(Vec);
}

void vectorFillUp(int length){//fill vector with ordered numbers
    for(int v=0;v<length;v++)
        Vec[v]=v;
}

void vectorFillRand(int length){//fill vector with random numbers
    for(int v=0;v<length;v++)
        Vec[v]=rand()%length;
}

void vectorFillDown(int length){//fill vector with unordered numbers
    for(int v=0;v<length;v++)
        Vec[v]=length-v;
}
