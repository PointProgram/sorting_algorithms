#include "../include/FillArr.h"
#include "../include/CommonVector.h"


void DynBeg(int P, int M, int N) {//allocate memory of array
    int k, i;
    Arr3D = (int***) malloc(P*sizeof(int**));
	for (k=0; k<P; k++){
		Arr3D[k] = (int**) malloc(M*sizeof(int*));
		for (i=0; i<M; i++)
			Arr3D[k][i] = (int*) malloc(N*sizeof(int));
	}
}
void DynEnd(int P, int M) {//release memory
    int k, i;
    for(k=0;k<P;k++){
		for(i=0;i<M;i++){
			free(Arr3D[k][i]);
		}
		free(Arr3D[k]);
	}
	free(Arr3D);
}
void FillUp(int P, int M, int N){//fill array with ordered numbers
	int i,j,k;
	int number = 0;
	for(k=0;k<P;k++){
		for(j=0;j<N;j++){
			for(i=0;i<M;i++){
			Arr3D[k][i][j]=number++;
			}
		}
	}
}
void FillRand(int P, int M, int N){//fill 3D array with random numbers
	int i,j,k;
	for(k=0;k<P;k++){
		for(j=0;j<N;j++){
			for(i=0;i<M;i++){
				Arr3D[k][i][j]=rand()%(P*M*N);
			}
		}
	}
}
void FillDown(int P, int M, int N){//fill 3D array with unordered numbers
int i,j,k;
int number = P*M*N;
	for(k=0;k<P;k++){
		for(j=0;j<N;j++){
			for(i=0;i<M;i++){
				Arr3D[k][i][j]=number--;
			}
		}
	}
}
void vectorDynBeg(int V) {//allocate memory for vector
	Vec = (int*) malloc(V*sizeof(int));
}
void vectorDynEnd() {//free memory
	free(Vec);
}
void vectorFillUp(int V){//fill vector with ordered numbers
    for(int v=0;v<V;v++){
        Vec[v]=v;
    }
}
void vectorFillRand(int V){//fill vector with random numbers
    for(int v=0;v<V;v++){
        Vec[v]=rand();
    }
}
void vectorFillDown(int V){//fill vector with unordered numbers
    for(int v=0;v<V;v++){
        Vec[v]=V-v;;
    }
}
