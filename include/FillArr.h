#ifndef __fillArr_H__
#define __fillArr_H__

void FillUp(int p, int n, int m);
void FillRand(int p, int n, int m);
void FillDown(int p, int n, int m);
void DynBeg(int P, int M, int N);
void DynEnd(int P, int M);
int ***copyArray3D(int P, int M, int N) ;


void vectorFillUp(int ve);
void vectorFillRand(int ve);
void vectorFillDown(int ve);
void vectorDynBeg(int V);
void vectorDynEnd();
int *copyVector(int V) ;

#endif // __FillArr_H__
