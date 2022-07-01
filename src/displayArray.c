#include <stdio.h>
#include "../include/commonVector.h"
#include "../include/globVar.h"


void display3DArray() {
    int i,j,k;

	for(k=0;k<P;k++){
		for(j=0;j<N;j++){
			for(i=0;i<M;i++){
                printf("%d ", i);
			}
			printf("\n");
		}
		printf("\n");
	}

}

