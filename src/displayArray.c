#include "../include/displayArray.h"
#include <stdio.h>

void display3DArray(int ***A, int blocks, int rows, int cols) {

    printf("<______B________E_______G_____>\n");
	for(int k=0;k<blocks;k++){
		for(int j=0;j<rows;j++){
            printf("%3s", "|");
			for(int i=0;i<cols;i++){
                printf("%d ", A[k][j][i]);
                if (i == cols - 1) {
                    printf("\n");
                }
			}
		}
		printf("(%d)", k + 1);
		printf("\n");
	}
	printf("<______E________N_______D_____>\n\n");

}

void display1DArray(int *A, int length) {

    printf("<______B________E_______G_____>\n");

	for (int i=0; i < length; i++) {
        printf("[%d] ", A[i]);
	}

	printf("\n");
	printf("<______E________N_______D_____>\n\n");

}

