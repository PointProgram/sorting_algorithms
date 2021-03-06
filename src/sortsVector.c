#include "../include/sortsVector.h"
#include "../include/commonVector.h"

#include <math.h>
#include <stdlib.h>


clock_t vectorInsert1(int * A, int N) {
    int Elem, j;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int i = 1; i < N; i++) {
        Elem = A[i];
        j = 0;
        while (Elem > A[j]) j = j + 1;
        for (int k = i - 1; k >= j; k--)
            A[k + 1] = A[k];
        A[j] = Elem;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 1 of the direct insertion method (with a linear search for the place of insertion from the beginning of the sequence being sorted, or "from the left")

clock_t vectorInsert2(int * A, int N) {
    int Elem, j;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int i = 1; i < N; i++) {
        Elem = A[i];
        j = i;
        while (j > 0 && Elem < A[j - 1]) {
            A[j] = A[j - 1];
            j = j - 1;
        }
        A[j] = Elem;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 2 of the direct insertion method (from lines - by searching for the place of insertion from the inserted element, or "on the right", without a barrier).

// Vector alike implementation of expanding size for below method
//#define VectorLength 10
//int Vector[VectorLength+1];
//--------------------------------------
clock_t vectorInsert3(int * A, int N) {
    int j;
    clock_t time_start, time_stop;
    time_start = clock();

//to complete the sorting process, add operation  + 1 to the expression N; hence, memory should be increased as well for full completion of the sort
    //for (int i = 2; i < N + 1; i++) {
    for (int i = 2; i < N; i++) {
        A[0] = A[i];
        j = i;
        while (A[0] < A[j - 1]) {
            A[j] = A[j - 1];
            j = j - 1;
        }
        A[j] = A[0];
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 3 of the direct insertion method (from lines - by searching for the place of insertion from the inserted element, or "on the right", with a barrier).

clock_t vectorInsert4(int * A, int N) {
    int Elem, L, R, j;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int i = 1; i <= N - 1; i++) {
        Elem = A[i];
        L = 0;
        R = i;
        while (L < R) {
            j = (L + R) / 2;
            if (A[j] <= Elem) {
                L = j + 1;
            } else R = j;
        }
        for (int k = i - 1; k >= R; k--) {
            A[k + 1] = A[k];
        }
        A[R] = Elem;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 4 of the direct insertion method (with a binary search for the insertion site).

clock_t vectorSelect1(int * A, int N) {
    int Min, imin;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        Min = A[s];
        imin = s;
        for (int i = s + 1; i < N; i++)
            if (A[i] < Min) {
                Min = A[i];
                imin = i;
            }
        A[imin] = A[s];
        A[s] = Min;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 1 of the direct selection method.

clock_t vectorSelect2(int * A, int N) {
    int imin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        imin = s;
        for (int i = s + 1; i < N; i++)
            if (A[i] < A[imin]) imin = i;
        tmp = A[imin];
        A[imin] = A[s];
        A[s] = tmp;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 2 of the direct selection method.

clock_t vectorSelect3(int * A, int N) {
    int Min, Max;
    int L, R, imin, imax;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N - 1;
    while (L < R) {
        Min = A[L];
        imin = L;
        Max = A[L];
        imax = L;
        for (int i = L + 1; i < R + 1; i++) {
            if (A[i] < Min) {
                Min = A[i];
                imin = i;

            } else

            if (A[i] > Max) {
                Max = A[i];
                imax = i;

            }
        }
        A[imin] = A[L];
        A[L] = Min;
        if (imax == L) A[imin] = A[R];
        else A[imax] = A[R];
        A[R] = Max;

        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 3 of the direct selection method.

clock_t vectorSelect4(int * A, int N) {
    int L, R, imin, imax, tmp;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N - 1;
    while (L < R) {
        imin = L;
        imax = L;

        for (int i = L + 1; i < R + 1; i++)
            if (A[i] < A[imin]) imin = i;
            else
        if (A[i] > A[imax]) imax = i;

        tmp = A[imin];
        A[imin] = A[L];
        A[L] = tmp;
        if (imax == L) {
            tmp = A[imin];
            A[imin] = A[R];
            A[R] = tmp;
        } else {
            tmp = A[imax];
            A[imax] = A[R];
            A[R] = tmp;
        }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 4 of the direct selection method.

clock_t vectorSelect5(int * A, int N) {
    int Min, imin;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        Min = A[s];
        imin = s;
        for (int i = s + 1; i < N; i++)
            if (A[i] < Min) {
                Min = A[i];
                imin = i;
            }
        if (imin != s) {
            A[imin] = A[s];
            A[s] = Min;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 5 of the direct selection method.

clock_t vectorSelect6(int * A, int N) {
    int imin, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        imin = s;
        for (int i = s + 1; i < N; i++)
            if (A[i] < A[imin]) imin = i;
        if (imin != s) {
            tmp = A[imin];
            A[imin] = A[s];
            A[s] = tmp;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 6 of the direct selection method.

clock_t vectorSelect7(int * A, int N) {
    int Min, Max;
    int L, R, imin, imax;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N - 1;
    while (L < R) {
        Min = A[L];
        imin = L;
        Max = A[L];
        imax = L;
        for (int i = L + 1; i < R + 1; i++) {
            if (A[i] < Min) {
                Min = A[i];
                imin = i;

            } else

            if (A[i] > Max) {
                Max = A[i];
                imax = i;

            }
        }
        if (imin != L) {
            A[imin] = A[L];
            A[L] = Min;
        }
        if (imax != R) {
            if (imax == L) A[imin] = A[R];
            else A[imax] = A[R];
            A[R] = Max;
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

// Sorting algorithm No. 7 of the direct selection method.

clock_t vectorSelect8(int * A, int N) {
    int L, R, imin, imax, tmp;

    clock_t time_start, time_stop;
    time_start = clock();

    L = 0;
    R = N - 1;
    while (L < R) {
        imin = L;
        imax = L;

        for (int i = L + 1; i < R + 1; i++)
            if (A[i] < A[imin]) imin = i;
            else
                if (A[i] > A[imax]) imax = i;

        if (imin != L) {
            tmp = A[imin];
            A[imin] = A[L];
            A[L] = tmp;
        }
        if (imax != R)
            if (imax == L) {
                tmp = A[imin];
                A[imin] = A[R];
                A[R] = tmp;
            }
        else {
            tmp = A[imax];
            A[imax] = A[R];
            A[R] = tmp;
        }
        L = L + 1;
        R = R - 1;
    }
    time_stop = clock();
    return time_stop - time_start;
}

// Sorting algorithm No. 8 of the direct selection method.

clock_t vectorExchange1(int * A, int N) {
    int tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int R = N - 1; R > 0; R--) {
        for (int i = 0; i < R; i++)
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
            }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 1 of the direct exchange method (without modifications).

clock_t vectorExchange2(int * A, int N) {
    int R, flag, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    R = N - 1;
    flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < R; i++)
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                flag = 1;
            } R--;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 2 of the direct exchange method (using the flag).

clock_t vectorExchange3(int * A, int N) {
    int R, k, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    R = N - 1;
    while (R > 0) {
        k = 0;
        for (int i = 0; i < R; i++)
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                k = i;
            } R = k;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 3 of the direct exchange method (with memory of the place of the last permutation).

clock_t vectorExchange4(int * A, int N) {
    int L, R, k, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    L = 0;
    R = N - 1;
    k = 0;
    while (L < R) {
        for (int i = L; i < R; i++)
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                k = i;
            } R = k;
        for (int i = R - 1; i >= L; i--)
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                k = i;
            } L = k + 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Sorting algorithm No. 4 of the direct exchange method (Shaker sorting).

clock_t vectorInsertExchange(int * A, int N) {
    int j, tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int i = 1; i < N; i++) {
        j = i;
        while (j > 0 && A[j] < A[j - 1]) {
            tmp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = tmp;
            j = j - 1;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Hybrid "insertion-exchange" algorithm.

clock_t vectorSelect1Exchange(int * A, int N) {
    int Min;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        Min = A[s];
        for (int i = s + 1; i < N; i++)
            if (A[i] < Min) {
                Min = A[i];
                A[i] = A[s];
                A[s] = Min;
            }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Hybrid algorithm "choice #1 - exchange".

clock_t vectorSelect2Exchange(int * A, int N) {
    int tmp;
    clock_t time_start, time_stop;
    time_start = clock();
    for (int s = 0; s < N - 1; s++) {
        for (int i = s + 1; i < N; i++)
            if (A[i] < A[s]) {
                tmp = A[i];
                A[i] = A[s];
                A[s] = tmp;
            }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Hybrid algorithm "choice #2 - exchange".

clock_t vectorSelect3Exchange(int * A, int N) {
    int Min, Max, tmp;
    int L, R;

    clock_t time_start, time_stop;
    time_start = clock();
    L = 0;
    R = N - 1;
    while (L < R) {
        if (A[L] > A[R]) {
            tmp = A[L];
            A[L] = A[R];
            A[R] = tmp;
        }
        Min = A[L];
        Max = A[R];
        for (int i = L + 1; i < R + 1; i++) {
            if (A[i] < Min) {
                Min = A[i];
                A[i] = A[L];
                A[L] = Min;

            } else

            if (A[i] > Max) {
                Max = A[i];
                A[i] = A[R];
                A[R] = Max;

            }
        }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Hybrid algorithm "choice #3 - exchange".

clock_t vectorSelect4Exchange(int * A, int N) {
    int Min, Max;
    int L, R;

    clock_t time_start, time_stop;
    time_start = clock();
    L = 0;
    R = N - 1;
    while (L < R) {
        for (int i = L; i < R + 1; i++) {
            if (A[i] < A[L]) {
                Min = A[i];
                A[i] = A[L];
                A[L] = Min;

            } else

            if (A[i] > A[R]) {
                Max = A[i];
                A[i] = A[R];
                A[R] = Max;

            }
        }
        L = L + 1;
        R = R - 1;
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Hybrid algorithm "choice #4 - exchange".

clock_t vectorShell_1(int * A, int N) {
    int Elem, t, j, k;
    clock_t time_start, time_stop;
    time_start = clock();
    if (N < 4) t = 1;
    else t = (int) log2f((float) N) - 1;

    int *Stages = (int*) malloc(t*sizeof(int));


    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--) Stages[i] = 2 * Stages[i + 1] + 1;

    for (int p = 0; p < t; p++) {
        k = Stages[p];
        for (int i = k; i < N; i++) {
            Elem = A[i];
            j = i;
            while (j >= k && Elem < A[j - k]) {
                A[j] = A[j - k];
                j = j - k;
            }
            A[j] = Elem;
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Algorithm No. 1 of the Shell sorting method.

clock_t vectorShell_2(int * A, int N) {
    int tmp, t, j, k;
    clock_t time_start, time_stop;
    time_start = clock();
    if (N < 4) t = 1;
    else t = (int) log2f((float) N) - 1;

    int *Stages = (int*) malloc(t*sizeof(int));


    Stages[t - 1] = 1;
    for (int i = t - 2; i >= 0; i--) Stages[i] = 2 * Stages[i + 1] + 1;

    for (int p = 0; p < t; p++) {
        k = Stages[p];
        for (int i = k; i < N; i++) {
            j = i;
            while (j >= k && A[j] < A[j - k]) {
                tmp = A[j];
                A[j] = A[j - k];
                A[j - k] = tmp;
                j = j - k;
            }
        }
    }

    time_stop = clock();

    return time_stop - time_start;
}

// Algorithm No. 2 of the Shell sorting method.

void vectorQuickSort(int L, int R) {
    int B, tmp, i, j;

    B = Vec[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j) {
        while (Vec[i] < B) i = i + 1;
        while (Vec[j] > B) j = j - 1;
        if (i <= j) {
            tmp = Vec[i];
            Vec[i] = Vec[j];
            Vec[j] = tmp;
            i = i + 1;
            j = j - 1;
        }
    }
    if (L < j) vectorQuickSort(L, j);
    if (i < R) vectorQuickSort(i, R);
}

// Algorithm of the "quick sorting" method (Hoare sorting).
