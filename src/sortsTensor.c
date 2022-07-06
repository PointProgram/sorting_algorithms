#include "../include/sortsTensor.h"
#include "../include/commonVector.h"

#include <math.h>
#include <stdlib.h>

/*
 * Modifies the struct that exists in the calling function.
 *   Function get3DCoordinates() takes a pointer to a struct someStruct variable
 *   so that any modifications to the variable made in the function get3DCoordinates()
 *   will be to the variable pointed to.
 *   A pointer contains the address of a variable and is not the variable iteself.
 *   This allows the function get3DCoordinates() to modify the variable provided by the
 *   caller of get3DCoordinates() rather than a local copy.
 */
void modify3DCoordinates(tensorCoords *coord, const int current, const int next, const int rows, const int clmns) {
    coord->cb = current / (clmns * rows),
    coord->cr = (current / clmns) % rows,
    coord->cc =  current % clmns;

    if(next >= 0) {
        coord->nb = next / (clmns * rows),
        coord->nr = (next / clmns) % rows,
        coord->nc =  next % clmns;
    }
}

/*
 * Modifies the local copy of the struct, the original
 * in the calling function is not modified.
 * The C compiler will make a copy of the variable provided by the
 * caller of function get3DCoordinates() and so any changes that get3DCoordinates() makes
 * to the argument will be discarded since get3DCoordinates() is working with a
 * copy of the caller's variable and not the actual variable.
 */
tensorCoords get3DCoordinates(const int current, const int next, const int rows, const int clmns) {
    tensorCoords coord;

    coord.cb = current / (clmns * rows),
    coord.cr = (current / clmns) % rows,
    coord.cc =  current % clmns;

    if(next >= 0) {
        coord.nb = next / (clmns * rows),
        coord.nr = (next / clmns) % rows,
        coord.nc =  next % clmns;
    }
    return coord;
}

clock_t tensorInsert1(int ***A, int N, int rows, int clmns) {
    int Elem, j;
    clock_t time_start, time_stop;
    time_start = clock();

    for (int i = 1; i < N * rows * clmns; i++) {
         tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);

        Elem = A[indices_i.cb][indices_i.cr][indices_i.cc];
        j = 0;

        tensorCoords indices_j = get3DCoordinates(j, -1, rows, clmns);

        while (Elem > A[indices_j.cb][indices_j.cr][indices_j.cc]) {
            j = j + 1;
            modify3DCoordinates(&indices_j, j, -1, rows, clmns);
        }

        for (int k = i - 1; k >= j; k--) {
            tensorCoords indices_k = get3DCoordinates(k, k + 1, rows, clmns);

            A[indices_k.nb][indices_k.nr][indices_k.nc] = A[indices_k.cb][indices_k.cr][indices_k.cc];
        }

        A[indices_j.cb][indices_j.cr][indices_j.cc] = Elem;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 1 of the direct insertion method (with a linear search for the place of insertion from the beginning of the sequence being sorted, or "from the left")

clock_t tensorInsert2(int ***A, int N, int rows, int clmns) {
    int Elem, j;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int i = 1; i < N * rows * clmns; i++) {
        tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
        Elem = A[indices_i.cb][indices_i.cr][indices_i.cc];
        j = i;
        tensorCoords indices_j = get3DCoordinates(j, j -1, rows, clmns);

        while (j > 0 && Elem < A[indices_j.nb][indices_j.nr][indices_j.nc]) {
            A[indices_j.cb][indices_j.cr][indices_j.cc] = A[indices_j.nb][indices_j.nr][indices_j.nc];
            j = j - 1;
            modify3DCoordinates(&indices_j, j, j -1, rows, clmns);
        }

        A[indices_j.cb][indices_j.cr][indices_j.cc] = Elem;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 2 of the direct insertion method (from lines - by searching for the place of insertion from the inserted element, or "on the right", without a barrier).

// Vector alike implementation of expanding size for below method
//#define VectorLength 10
//int Vector[VectorLength+1];
//--------------------------------------
clock_t tensorInsert3(int ***A, int N, int rows, int clmns) {
    int j;
    clock_t time_start, time_stop;

    time_start = clock();

//to complete the sorting process, add operation  + 1 to the expression N * rows * sum; hence, memory should be increased as well for full completion of the sort
    for (int i = 2; i < N * rows * clmns ; i++)  {
        tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
        A[0][0][0] = A[indices_i.cb][indices_i.cr][indices_i.cc];
        j = i;
        tensorCoords indices_j = get3DCoordinates(j, j - 1, rows, clmns);

        while (A[0] [0][0] < A[indices_j.nb][indices_j.nr][indices_j.nc]) {
            A[indices_j.cb][indices_j.cr][indices_j.cc] = A[indices_j.nb][indices_j.nr][indices_j.nc];
            j = j - 1;
            modify3DCoordinates(&indices_j, j , j - 1, rows, clmns);
        }
         A[indices_j.cb][indices_j.cr][indices_j.cc] = A[0][0][0];
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 3 of the direct insertion method (from lines - by searching for the place of insertion from the inserted element, or "on the right", with a barrier).

clock_t tensorInsert4(int ***A, int N, int rows, int clmns) {
    int Elem, L, R, j;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int i = 1; i <= N * rows * clmns  - 1; i++) {
        tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
        Elem = A[indices_i.cb][indices_i.cr][indices_i.cc];
        L = 0;
        R = i;

        while (L < R) {
            j = (L + R) / 2;
            tensorCoords indices_j = get3DCoordinates(j, -1, rows, clmns);

            if (A[indices_j.cb][indices_j.cr][indices_j.cc] <= Elem)
                L = j + 1;
            else
                R = j;
        }

        for (int k = i - 1; k >= R; k--) {
            tensorCoords indices_k = get3DCoordinates(k, k+1, rows, clmns);
            A[indices_k.nb][indices_k.nr][indices_k.nc] = A[indices_k.cb][indices_k.cr][indices_k.cc];
        }
        tensorCoords indices_R = get3DCoordinates(R, -1, rows, clmns);
        A[indices_R.cb][indices_R.cr][indices_R.cc] = Elem;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 4 of the direct insertion method (with a binary search for the insertion site).

clock_t tensorSelect1(int ***A, int N, int rows, int clmns) {
    int Min, imin;
    clock_t time_start, time_stop;

    time_start = clock();
    for (int s = 0; s < N * rows * clmns - 1; s++) {
        tensorCoords indices_s = get3DCoordinates(s, -1, rows, clmns);
        Min = A[indices_s.cb][indices_s.cr][indices_s.cc];
        imin = s;

        for (int i = s + 1; i < N * rows * clmns; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < Min) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                imin = i;
            }
        }
        tensorCoords indices_imin = get3DCoordinates(imin, -1, rows, clmns);
        A[indices_imin.cb][indices_imin.cr][indices_imin.cc] = A[indices_s.cb][indices_s.cr][indices_s.cc];
        A[indices_s.cb][indices_s.cr][indices_s.cc] = Min;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 2 of the direct selection method.

clock_t tensorSelect2(int ***A, int N, int rows, int clmns) {
    int imin, tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int s = 0; s < N * rows * clmns - 1; s++) {
        imin = s;

        for (int i = s + 1; i < N * rows * clmns; i++) {
            tensorCoords indices_i_imin = get3DCoordinates(i, imin, rows, clmns);
            if (A[indices_i_imin.cb][indices_i_imin.cr][indices_i_imin.cc] < A[indices_i_imin.nb][indices_i_imin.nr][indices_i_imin.nc])  {
                imin = i;
                modify3DCoordinates(&indices_i_imin, i, imin, rows, clmns);
            }
        }
        tensorCoords indices_s_imin = get3DCoordinates(s, imin, rows, clmns);
        tmp = A[indices_s_imin.nb][indices_s_imin.nr][indices_s_imin.nc];
        A[indices_s_imin.nb][indices_s_imin.nr][indices_s_imin.nc] = A[indices_s_imin.cb][indices_s_imin.cr][indices_s_imin.cc];
        A[indices_s_imin.cb][indices_s_imin.cr][indices_s_imin.cc] = tmp;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 3 of the direct selection method.

clock_t tensorSelect3(int ***A, int N, int rows, int clmns) {
    int Min, Max;
    int L, R, imin, imax;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N * rows * clmns - 1;

    while (L < R) {
        tensorCoords indices_L = get3DCoordinates(L, -1, rows, clmns);
        Min = A[indices_L.cb][indices_L.cr][indices_L.cc];
        imin = L;
        Max = A[indices_L.cb][indices_L.cr][indices_L.cc];
        imax = L;

        for (int i = L + 1; i < R + 1; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < Min) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                imin = i;
            }
            else {
                if (A[indices_i.cb][indices_i.cr][indices_i.cc] > Max) {
                    Max = A[indices_i.cb][indices_i.cr][indices_i.cc];
                    imax = i;
                }
            }
        }

        tensorCoords indices_iminL = get3DCoordinates(imin, L, rows, clmns);
        A[indices_iminL.cb][indices_iminL.cr][indices_iminL.cc] = A[indices_iminL.nb][indices_iminL.nr][indices_iminL.nc];
        A[indices_iminL.nb][indices_iminL.nr][indices_iminL.nc] = Min;

        tensorCoords indices_imaxR = get3DCoordinates(imax, R, rows, clmns);
        if (imax == L)
           A[indices_iminL.cb][indices_iminL.cr][indices_iminL.cc] = A[indices_imaxR.nb][indices_imaxR.nr][indices_imaxR.nc];
        else
            A[indices_imaxR.cb][indices_imaxR.cr][indices_imaxR.cc] = A[indices_imaxR.nb][indices_imaxR.nr][indices_imaxR.nc];

       A[indices_imaxR.nb][indices_imaxR.nr][indices_imaxR.nc] = Max;

        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 3 of the direct selection method.

clock_t tensorSelect4(int ***A, int N, int rows, int clmns) {
    int L, R, imin, imax, tmp;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N * rows * clmns - 1;

    while (L < R) {
        imin = L;
        imax = L;

        for (int i = L + 1; i < R + 1; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
            tensorCoords indices_imax_min = get3DCoordinates(imax, imin, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < A[indices_imax_min.nb][indices_imax_min.nr][indices_imax_min.nc])
                imin = i;
            else
                if (A[indices_i.cb][indices_i.cr][indices_i.cc] > A[indices_imax_min.cb][indices_imax_min.cr][indices_imax_min.cc]);
                    imax = i;
        }

        tensorCoords indices_L_R = get3DCoordinates(L, R, rows, clmns);
        tensorCoords indices_imax_min = get3DCoordinates(imax, imin, rows, clmns);

        tmp = A[indices_imax_min.nb][indices_imax_min.nr][indices_imax_min.nc];
        A[indices_imax_min.nb][indices_imax_min.nr][indices_imax_min.nc] = A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc];
        A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc] = tmp;

        if (imax == L) {
            tmp = A[indices_imax_min.nb][indices_imax_min.nr][indices_imax_min.nc];
            A[indices_imax_min.nb][indices_imax_min.nr][indices_imax_min.nc] =  A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
            A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = tmp;
        }
        else {
            tmp = A[indices_imax_min.cb][indices_imax_min.cr][indices_imax_min.cc];
            A[indices_imax_min.cb][indices_imax_min.cr][indices_imax_min.cc] = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
            A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = tmp;
        }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 4 of the direct selection method.

clock_t tensorSelect5(int ***A, int N, int rows, int clmns) {
    int Min, imin;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int s = 0; s < N * rows * clmns - 1; s++) {
        tensorCoords indices_s = get3DCoordinates(s, -1, rows, clmns);
        Min = A[indices_s.cb][indices_s.cr][indices_s.cc];
        imin = s;

        for (int i = s + 1; i < N * rows * clmns; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < Min) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                imin = i;
            }
        }

        tensorCoords indices_imin = get3DCoordinates(imin, -1, rows, clmns);
        if (imin != s) {
            A[indices_imin.cb][indices_imin.cr][indices_imin.cc] = A[indices_s.cb][indices_s.cr][indices_s.cc];
            A[indices_s.cb][indices_s.cr][indices_s.cc] = Min;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 5 of the direct selection method.

clock_t tensorSelect6(int ***A, int N, int rows, int clmns) {
    int imin, tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int s = 0; s < N * rows * clmns - 1; s++) {
        imin = s;

        for (int i = s + 1; i < N * rows * clmns; i++) {
            tensorCoords indices_i_imin = get3DCoordinates(i, imin, rows, clmns);
            if (A[indices_i_imin.cb][indices_i_imin.cr][indices_i_imin.cc] < A[indices_i_imin.nb][indices_i_imin.nr][indices_i_imin.nc])
                imin = i;
        }

        if (imin != s) {
            tensorCoords indices_imin_s = get3DCoordinates(imin, s, rows, clmns);
            tmp = A[indices_imin_s.cb][indices_imin_s.cr][indices_imin_s.cc];
            A[indices_imin_s.cb][indices_imin_s.cr][indices_imin_s.cc] = A[indices_imin_s.nb][indices_imin_s.nr][indices_imin_s.nc];
            A[indices_imin_s.nb][indices_imin_s.nr][indices_imin_s.nc] = tmp;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 6 of the direct selection method.

clock_t tensorSelect7(int ***A, int N, int rows, int clmns) {
    int Min, Max;
    int L, R, imin, imax;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N * rows * clmns - 1;
    while (L < R) {
        tensorCoords indices_L = get3DCoordinates(L, -1, rows, clmns);
        Min = A[indices_L.cb][indices_L.cr][indices_L.cc];
        imin = L;
        Max =A[indices_L.cb][indices_L.cr][indices_L.cc];
        imax = L;

        for (int i = L + 1; i < R + 1; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < Min) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                imin = i;
            }
            else {
                if (A[indices_i.cb][indices_i.cr][indices_i.cc]  > Max) {
                    Max = A[indices_i.cb][indices_i.cr][indices_i.cc];
                    imax = i;
                }
            }
        }

        tensorCoords indices_imin_imax = get3DCoordinates(imin, imax, rows, clmns);
        tensorCoords indices_R = get3DCoordinates(R, -1, rows, clmns);

        if (imin != L) {
            A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc] = A[indices_L.cb][indices_L.cr][indices_L.cc];
            A[indices_L.cb][indices_L.cr][indices_L.cc] = Min;
        }

        if (imax != R) {
            if (imax == L)
                A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc] = A[indices_R.cb][indices_R.cr][indices_R.cc];
            else
                A[indices_imin_imax.nb][indices_imin_imax.nr][indices_imin_imax.nc] = A[indices_R.cb][indices_R.cr][indices_R.cc];
            A[indices_R.cb][indices_R.cr][indices_R.cc] = Max;
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}
// Sorting algorithm No. 7 of the direct selection method.

clock_t tensorSelect8(int ***A, int N, int rows, int clmns) {
    int L, R, imin, imax, tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    L = 0;
    R = N * rows * clmns  - 1;
    while (L < R) {
        imin = L;
        imax = L;

        for (int i = L + 1; i < R + 1; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
            tensorCoords indices_imin_imax = get3DCoordinates(imin, imax, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc]< A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc])
                imin = i;
            else
                if (A[indices_i.cb][indices_i.cr][indices_i.cc] > A[indices_imin_imax.nb][indices_imin_imax.nr][indices_imin_imax.nc])
                    imax = i;
        }

        tensorCoords indices_imin_imax = get3DCoordinates(imin, imax, rows, clmns);
        tensorCoords indices_L_R = get3DCoordinates(L, R, rows, clmns);

        if (imin != L) {
            tmp = A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc];
            A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc] = A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc];
            A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc] = tmp;
        }
        if (imax != R) {
            if (imax == L) {
                tmp = A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc];
                A[indices_imin_imax.cb][indices_imin_imax.cr][indices_imin_imax.cc] = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
                A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = tmp;
            }
            else {
                        tmp = A[indices_imin_imax.nb][indices_imin_imax.nr][indices_imin_imax.nc];
                        A[indices_imin_imax.nb][indices_imin_imax.nr][indices_imin_imax.nc] = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
                        A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = tmp;
            }
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}
// Sorting algorithm No. 8 of the direct selection method.

clock_t tensorExchange1(int ***A, int N, int rows, int clmns) {
    int tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int R = N * rows * clmns - 1; R > 0; R--) {
        for (int i = 0; i < R; i++) {

            tensorCoords indices = get3DCoordinates(i, i + 1, rows, clmns);

            if (A[indices.cb][indices.cr][indices.cc] > A[indices.nb][indices.nr][indices.nc]) {
                tmp = A[indices.cb][indices.cr][indices.cc];
                A[indices.cb][indices.cr][indices.cc]  = A[indices.nb][indices.nr][indices.nc];
                A[indices.nb][indices.nr][indices.nc] = tmp;
            }
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 1 of the direct exchange method (without modifications).

clock_t tensorExchange2(int ***A, int N, int rows, int clmns) {
    int R, flag, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    R = N * rows * clmns - 1;
    flag = 1;

    while (flag == 1) {
        flag = 0;

        for (int i = 0; i < R; i++) {

                tensorCoords indices = get3DCoordinates(i, i + 1, rows, clmns);

             if (A[indices.cb][indices.cr][indices.cc] > A[indices.nb][indices.nr][indices.nc]) {
                tmp = A[indices.cb][indices.cr][indices.cc];
                A[indices.cb][indices.cr][indices.cc]  = A[indices.nb][indices.nr][indices.nc];
                A[indices.nb][indices.nr][indices.nc] = tmp;
                flag = 1;
            }
        }
        R--;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 2 of the direct exchange method (using the flag).

clock_t tensorExchange3(int ***A, int N, int rows, int clmns) {
    int R, k, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    R = N*rows*clmns - 1;
    while (R > 0) {
        k = 0;
        for (int i = 0; i < R; i++) {

            tensorCoords indices = get3DCoordinates(i, i + 1, rows, clmns);

            if (A[indices.cb][indices.cr][indices.cc] > A[indices.nb][indices.nr][indices.nc]) {
                tmp = A[indices.cb][indices.cr][indices.cc];
                A[indices.cb][indices.cr][indices.cc]  = A[indices.nb][indices.nr][indices.nc];
                A[indices.nb][indices.nr][indices.nc] = tmp;
                k = i;
            }
        }

        R = k;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Sorting algorithm No. 3 of the direct exchange method (with memory of the place of the last permutation).

clock_t tensorExchange4(int ***A, int N, int rows, int clmns) {
    int L, R, k, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    L = 0;
    R = N * rows * clmns - 1;
    k = 0;

    while (L < R) {
        for (int i = L; i < R; i++) {

                tensorCoords indices = get3DCoordinates(i, i + 1, rows, clmns);

             if (A[indices.cb][indices.cr][indices.cc] > A[indices.nb][indices.nr][indices.nc]) {
                tmp = A[indices.cb][indices.cr][indices.cc];
                A[indices.cb][indices.cr][indices.cc]  = A[indices.nb][indices.nr][indices.nc];
                A[indices.nb][indices.nr][indices.nc] = tmp;
                k = i;
            }
        }

        R = k;
        for (int i = R - 1; i >= L; i--) {

            tensorCoords indices = get3DCoordinates(i, i + 1, rows, clmns);

             if (A[indices.cb][indices.cr][indices.cc] > A[indices.nb][indices.nr][indices.nc]) {
                tmp = A[indices.cb][indices.cr][indices.cc];
                A[indices.cb][indices.cr][indices.cc]  = A[indices.nb][indices.nr][indices.nc];
                A[indices.nb][indices.nr][indices.nc] = tmp;
                k = i;
            }
        }
        L = k + 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 4 of the direct exchange method (Shaker sorting).

clock_t tensorInsertExchange(int ***A, int N, int rows, int clmns) {
    int j, tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int i = 1; i < N * rows * clmns; i++) {
        j = i;

        tensorCoords indices = get3DCoordinates(j, j - 1, rows, clmns);

        while (j > 0 && (A[indices.cb][indices.cr][indices.cc] < A[indices.nb][indices.nr][indices.nc])) {
            tmp = A[indices.cb][indices.cr][indices.cc];
            A[indices.cb][indices.cr][indices.cc] = A[indices.nb][indices.nr][indices.nc];
            A[indices.nb][indices.nr][indices.nc] = tmp;
            j = j - 1;
            modify3DCoordinates(&indices, j, j - 1, rows, clmns);
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Hybrid "insertion-exchange" algorithm.

clock_t tensorSelect1Exchange(int ***A, int N, int rows, int clmns) {
    int Min;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int s = 0; s < N * rows * clmns - 1; s++) {
        tensorCoords indices_s = get3DCoordinates(s, -1, rows, clmns);
        Min = A[indices_s.cb][indices_s.cr][indices_s.cc];

        for (int i = s + 1; i < N * rows * clmns; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < Min) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                A[indices_i.cb][indices_i.cr][indices_i.cc] = A[indices_s.cb][indices_s.cr][indices_s.cc];
                A[indices_s.cb][indices_s.cr][indices_s.cc] = Min;
            }
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Hybrid algorithm "choice #1 - exchange".

clock_t tensorSelect2Exchange(int ***A, int N, int rows, int clmns) {
    int tmp;
    clock_t time_start, time_stop;

    time_start = clock();

    for (int s = 0; s < N * rows * clmns - 1; s++) {
        tensorCoords indices_s = get3DCoordinates(s, -1, rows, clmns);

        for (int i = s + 1; i < N * rows * clmns; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < A[indices_s.cb][indices_s.cr][indices_s.cc]) {
                tmp = A[indices_i.cb][indices_i.cr][indices_i.cc];
                A[indices_i.cb][indices_i.cr][indices_i.cc] = A[indices_s.cb][indices_s.cr][indices_s.cc];
                A[indices_s.cb][indices_s.cr][indices_s.cc] = tmp;
            }
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Hybrid algorithm "choice #2 - exchange".

clock_t tensorSelect3Exchange(int ***A, int N, int rows, int clmns) {
    int Min, Max, tmp;
    int L, R;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N * rows * clmns - 1;
    while (L < R) {
        tensorCoords indices_L_R = get3DCoordinates(L, R, rows, clmns);

        if (A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc] > A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc]) {
            tmp = A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc];
            A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc] = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
            A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = tmp;
        }
        Min = A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc];
        Max = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];

        for (int i = L + 1; i < R + 1; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < Min) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                A[indices_i.cb][indices_i.cr][indices_i.cc] = A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc];
                A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc] = Min;

            }
            else {
                if (A[indices_i.cb][indices_i.cr][indices_i.cc] > Max) {
                    Max = A[indices_i.cb][indices_i.cr][indices_i.cc];
                    A[indices_i.cb][indices_i.cr][indices_i.cc] = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
                    A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = Max;
                }
            }
        }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Hybrid algorithm "choice #3 - exchange".

clock_t tensorSelect4Exchange(int ***A, int N, int rows, int clmns) {
    int Min, Max;
    int L, R;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N * rows * clmns - 1;

    while (L < R) {
        tensorCoords indices_L_R = get3DCoordinates(L, R, rows, clmns);

        for (int i = L; i < R + 1; i++) {
             tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
            if (A[indices_i.cb][indices_i.cr][indices_i.cc] < A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc]) {
                Min = A[indices_i.cb][indices_i.cr][indices_i.cc];
                A[indices_i.cb][indices_i.cr][indices_i.cc] = A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc];
                A[indices_L_R.cb][indices_L_R.cr][indices_L_R.cc] = Min;

            } else

            if (A[indices_i.cb][indices_i.cr][indices_i.cc] > A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc]) {
                Max = A[indices_i.cb][indices_i.cr][indices_i.cc];
                A[indices_i.cb][indices_i.cr][indices_i.cc] = A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc];
                A[indices_L_R.nb][indices_L_R.nr][indices_L_R.nc] = Max;

            }
        }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Hybrid algorithm "choice #4 - exchange".

clock_t tensorShell_1(int ***A, int N, int rows, int clmns) {
    int Elem, t, j, k;
    clock_t time_start, time_stop;

    time_start = clock();

    if (N*rows * clmns < 4) t = 1;
    else t = (int) log2f((float) N * rows * clmns) - 1;

    int *Stages = (int*) malloc(t*sizeof(int));

    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--) Stages[i] = 2 * Stages[i + 1] + 1;

    for (int p = 0; p < t; p++) {
        k = Stages[p];

        for (int i = k; i < N * rows * clmns; i++) {
            tensorCoords indices_i = get3DCoordinates(i, -1, rows, clmns);
            Elem = A[indices_i.cb][indices_i.cr][indices_i.cc];
            j = i;
            tensorCoords indices_jk = get3DCoordinates(j , j - k, rows, clmns);

            while (j >= k && Elem < A[indices_jk.nb][indices_jk.nr][indices_jk.nc]) {
                A[indices_jk.cb][indices_jk.cr][indices_jk.cc] = A[indices_jk.nb][indices_jk.nr][indices_jk.nc];
                j = j - k;
                modify3DCoordinates(&indices_jk, j, j - k, rows, clmns);
            }
            modify3DCoordinates(&indices_jk, j, j - k, rows, clmns);
            A[indices_jk.cb][indices_jk.cr][indices_jk.cc] = Elem;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Algorithm No. 1 of the Shell sorting method.

clock_t tensorShell_2(int ***A, int N, int rows, int clmns) {
    int tmp, t, j, k;
    clock_t time_start, time_stop;
    time_start = clock();

    if (N * rows * clmns < 4) t = 1;
    else t = (int) log2f((float) N * rows * clmns) - 1;

    int *Stages = (int*) malloc(t*sizeof(int));

    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--) Stages[i] = 2 * Stages[i + 1] + 1;

    for (int p = 0; p < t; p++) {
        k = Stages[p];

        for (int i = k; i < N * rows * clmns; i++) {
            j = i;
            tensorCoords indices_jk = get3DCoordinates(j , j - k, rows, clmns);

            while (j >= k && A[indices_jk.cb][indices_jk.cr][indices_jk.cc] < A[indices_jk.nb][indices_jk.nr][indices_jk.nc]) {
                tmp = A[indices_jk.cb][indices_jk.cr][indices_jk.cc];
                A[indices_jk.cb][indices_jk.cr][indices_jk.cc] = A[indices_jk.nb][indices_jk.nr][indices_jk.nc];
                A[indices_jk.nb][indices_jk.nr][indices_jk.nc] = tmp;
                j = j - k;
                modify3DCoordinates(&indices_jk, j , j - k, rows, clmns);
            }
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}
// Algorithm No. 2 of the Shell sorting method.

void tensorQuickSort(int L, int R, int rows, int cols) {
    int B, tmp, i, j;

    tensorCoords indices_b = get3DCoordinates((L + R) / 2 , -1 , rows, cols);

    B = Arr3D[indices_b.cb][indices_b.cr][indices_b.cc];
    i = L;
    j = R;

    while (i <= j) {
        tensorCoords indices_ij = get3DCoordinates(i , j , rows, cols);
        while (Arr3D[indices_ij.cb] [indices_ij.cr][indices_ij.cc]< B)  {
            i = i + 1;
            modify3DCoordinates(&indices_ij, i , j , rows, cols);
        }
        while (Arr3D[indices_ij.nb] [indices_ij.nr][indices_ij.nc]> B) {
            j = j - 1;
            modify3DCoordinates(&indices_ij, i , j , rows, cols);
        }

        if (i <= j) {
            tmp = Arr3D[indices_ij.cb] [indices_ij.cr][indices_ij.cc];
            Arr3D[indices_ij.cb] [indices_ij.cr][indices_ij.cc] = Arr3D[indices_ij.nb] [indices_ij.nr][indices_ij.nc];
            Arr3D[indices_ij.nb] [indices_ij.nr][indices_ij.nc] = tmp;
            i = i + 1;
            j = j - 1;
        }
    }
    if (L < j) tensorQuickSort(L, j, rows, cols);
    if (i < R) tensorQuickSort(i, R, rows, cols);
}
// Algorithm of the "quick sorting" method (Hoare sorting).
