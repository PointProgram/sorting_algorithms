#include "../include/Sorts.h"
#include "../include/CommonVector.h"
#include <time.h>


clock_t Select8(int ***A, int p, int m, int n)//sorting method Select8 for 3D array
{
	int L, R, imin, imax, tmp;

	clock_t time_start, time_stop;
	time_start = clock();

	L=0; R=p-1;
	while (L<R){
		imin=L; imax=L;
		for(int ii=L+1; ii<R+1; ii++)
			if (A[ii][0][0]<A[imin][0][0])
				imin=ii;
			else
				if (A[ii][0][0]>A[imax][0][0])
					imax=ii;
		if (imin!=L) {
    for(int j=0;j<n;j++)
    	for(int i=0;i<m;i++) {
            tmp=A[imin][i][j];
    		A[imin][i][j]=A[L][i][j];
    		A[L][i][j]=tmp;
		}}
		if (imax!=R)
			if (imax==L) {
                for(int j=0;j<n;j++)
                    for(int i=0;i<m;i++) {
                        tmp=A[imin][i][j];
                        A[imin][i][j]=A[R][i][j];
                        A[R][i][j]=tmp;
                    }
            }
			else {
                for(int j=0;j<n;j++)
                    for(int i=0;i<m;i++) {
                        tmp=A[imax][i][j];
                        A[imax][i][j]=A[R][i][j];
                        A[R][i][j]=tmp;
                    }
			}
        L=L+1; R=R-1;
	}
	time_stop = clock();
	return time_stop - time_start;
}
clock_t Exchange3(int ***A, int p, int m, int n)//sorting method Exchange3 for 3D array
{
   	int tmp, R, k;
	clock_t time_start, time_stop;

	time_start = clock();

	R=p-1;
	while(R>0) {
    k=0;
    for(int l=0;l<R;l++){
        if(A[l][0][0]>A[l+1][0][0]) {
            for(int j=0;j<n;j++)
                for(int i=0;i<m;i++) {
                    tmp=A[l][i][j];
                    A[l][i][j]=A[l+1][i][j];
                    A[l+1][i][j]=tmp;
                    k=l;
                }
            }
        }
    R=k;
	}

	time_stop = clock();
	return time_stop - time_start;
}

void QuickSort(int L, int R, int n, int m)//sorting method QuickSort for 3D array
{
	int B, tmp, ii, jj;

	B = Arr3D[(L+R)/2][0][0];
	ii=L; jj=R;
	while(ii<=jj) {
        while (Arr3D[ii][0][0]<B) ii = ii+1;
        while (Arr3D[jj][0][0]>B) jj = jj-1;
        if (ii<=jj) {
            for(int j=0;j<n;j++)
                for(int i=0;i<m;i++) {
                    tmp=Arr3D[ii][i][j];
                    Arr3D[ii][i][j]=Arr3D[jj][i][j];
                    Arr3D[jj][i][j]=tmp;
            }
            ii=ii+1;
            jj=jj-1;
        }
	}
	if (L<jj) QuickSort(L, jj, n, m);
	if (ii<R) QuickSort(ii, R, n, m);
}
clock_t VectorSelect8(int *Ve, int ve)//sorting method Select8 for Vector
{
	int L, R, imin, imax, tmp;

	clock_t time_start, time_stop;
	time_start = clock();

	L=0; R=ve-1;
	while (L<R){
		imin=L; imax=L;
		for(int i=L+1; i<R+1; i++)
			if (Ve[i]<Ve[imin])
				imin=i;
			else
				if (Ve[i]>Ve[imax])
					imax=i;
		if (imin!=L) {
            tmp=Ve[imin];
    		Ve[imin]=Ve[L];
    		Ve[L]=tmp;
		}
		if (imax!=R)
			if (imax==L) {
                        tmp=Ve[imin];
                        Ve[imin]=Ve[R];
                        Ve[R]=tmp;
            }
			else {
                        tmp=Ve[imax];
                        Ve[imax]=Ve[R];
                        Ve[R]=tmp;
			}
        L=L+1; R=R-1;
	}
	time_stop = clock();
	return time_stop - time_start;
}
clock_t VectorExchange3(int *Ve, int ve)//sorting method Select8 for Vector
{
   	int tmp, R, k;
	clock_t time_start, time_stop;

	time_start = clock();

	R=ve-1;
	while(R>0) {
        k=0;
        for(int i=0;i<R;i++)
            if(Ve[i]>Ve[i+1]) {
                tmp=Ve[i];
                Ve[i]=Ve[i+1];
                Ve[i+1]=tmp;
                k=i;
            }
        R=k;
	}

	time_stop = clock();

	return time_stop - time_start;
}

void VectorQuickSort(int Lv, int Rv)//sorting method Select8 for Vector
{
	int B, tmp, i, j;

	B = Vec[(Lv+Rv)/2];
	i=Lv; j=Rv;
	while(i<=j) {
        while (Vec[i]<B) i = i+1;
        while (Vec[j]>B) j = j-1;
        if (i<=j){
                    tmp=Vec[i];
                    Vec[i]=Vec[j];
                    Vec[j]=tmp;
            i=i+1;
            j=j-1;
        }
	}
	if (Lv<j) VectorQuickSort(Lv, j);
	if (i<Rv) VectorQuickSort(i, Rv);
}