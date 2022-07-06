You might have problems with the library <conio.h>
which is originally not present in linux distibrutions, so 
in order to launch the project on Linus you should download 
additional library called <ncurses.h> using following commands:

sudo apt-get install libncurses5-dev libncursesw5-dev

As well, you could launch the project on such platfomrs as Visual Studio 
that is going to take care of this, but, first of all, you should uncomment
that library in the menu.c file and probably comment the "conih.h" file that
is located in ../include/... folder.


Besides, to have access to the <windows.h> library features you could
download mingw-64 dependencies via the command:

sudo apt install mingw-w64

Steps to Use :
1. sudo apt-get install g++-mingw-w64 (for minGW)
2. Then copy libgcc_s_sjlj-1.dll (To the project Dir)
in my case : cp /usr/lib/gcc/i686-w64-mingw32/7.3-win32/libgcc_s_sjlj-1.dll .
-Then copy libstdc++-6.dll (To the project Dir)
in my case : cp /usr/lib/gcc/i686-w64-mingw32/7.3-win32/libstdc++-6.dll .
3.Download w32api zip from te web site then unzip it in the working Dir.
4. COMPILE!!!!
ex : /usr/bin/i686-w64-mingw32-g++ -I w32api/include/ -L w32api/lib/ main.cpp


To implement sorting algorithms on arrays with more than one dimensions
you need to cretae kinda sophisticated sort of iteration through the array.

Thus, let's look what you cand do with bubble sort for the matrix with only too loops:

for(i=0;i<rows;i++)
  for(j=i;j<cols;j++)
    if(x[i/cols][i%cols]>x[j/cols][j%cols])
    {
        int temp = x[i/cols][i%cols];
        x[i/cols][i%cols] = x[j/cols][j%cols];
        x[j/cols][j%cols] = temp;
    }  
Here you can see calculations are done to the array indexes in order to get the
proper position. We have expression i/cols which gets the value of the row and
i % cols which gets the value of the column.

If you insist on having individual loops of each dimension, then this is the right way:

for (int ia=0; ia <row; ia++)
  for (int ja=0; ja <col; ja++)
    for (int ib=0; ib <row; ib++)
      for (int jb=0; jb <col; jb++)
        if(x[ia][ib]<x[ja][jb])
        {
            int temp = x[ia][ib];
            x[ia][ib] = x[ja][jb];
            x[ja][jb] = temp;
        }  

Also, I stumple upon following implementation, where the same problem is solved:

#include <stdio.h>

#define COL 5
#define ROW 6

int main()
{
    int temp, t, i, j;
    int arr[ROW][COL]={30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    for(t=1; t<(ROW*COL); t++)
    {
        for(i=0; i<ROW; i++)
        {
            for(j=0; j<COL-1; j++)
            {
                if (arr[i][j]>arr[i][j+1])
                {
                    temp=arr[i][j];
                    arr[i][j]=arr[i][j+1];
                    arr[i][j+1]=temp;
                }
            }
        }
        for(i=0; i<ROW-1; i++)
        {
            if (arr[i][COL-1]>arr[i+1][0])
            {
                temp=arr[i][COL-1];
                arr[i][COL-1]=arr[i+1][0];
                arr[i+1][0]=temp;
            }
        }
    }
    for(i=0; i<ROW; i++)
    {
        printf("\n");
        for(j=0; j<COL; j++)
            printf("%3d", arr[i][j]);
    }
    return 0; 
}

//simple function with array traversal of the implicit 1D array
void twoDimBubbleSort(int** arr, int row, int col) {
    for (int i = 0; i < (row * col); ++i) {
        for (int j = 0; j < (row * col) - 1; ++j) {
            int cr = j / col; // current row
            int cc = j % col; // current column
            int nr = (j + 1) / col; // next item row
            int nc = (j + 1) % col; // next item column

            if (arr[cr][cc] > arr[nr][nc])
                swap(&arr[cr][cc], &arr[nr][nc]); // any way you want to swap variables
        }
    }
}


Plus to that, look on the quite tricky and long way of sorting with the function
for bubble sorting for 3D array in ascending order:

//If you want to change the size of array then you would change the loop size.

#include <iostream>
using namespace std;

int sorting(int array[2][2][5]){
     int temp;
     for (int i = 0 ; i < 2 ; i++ )
         for (int j = 0 ; j < 2; j++ )
             for (int k = 0 ; k < 5 ; k++ )
                for (int a = 0 ; a < 2 ; a++ )
                    for (int b = 0 ; b < 2 ; b++ )
                        for (int c = 0 ; c < 5 ; c++ )
                            if (array[i][j][k] < array[a][b][c]){
                                temp = array[i][j][k];
                                array[i][j][k] = array[a][b][c];
                                array[a][b][c] = temp;}
   for (int i = 0 ; i < 2 ; i++ )
       for (int j = 0 ; j < 2 ; j++ )
           for (int k = 0 ; k < 5 ; k++ ){
               cout << array[i][j][k] << endl;
           }
    return 0;
}
int main(){
    int array1[2][2][5] = {{{45,23,67,1,-12},{34,43,234,567,576}},
    {{345,345,76,87,2},{456,789,890,32,4}}};
     sorting(array1);
}
////This is example of bubble sorting of 3D array. 


Below, different methods were tested on how to get the sorted array on 1D, 2D and 3D arrys:

#include <stdio.h>

void bubble_sort1(int a[], int N) {
	int tmp;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);
		
	}
	printf("\n");
	

}

void bubble_sort2(int a[], int N) {
	int tmp;
	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);
		
	}
	printf("\n");
	

}

//sort values in an ascending order
void bubble_matrix1(int a[4][4], int row, int col) {
	int tmp;
	for(int i = 0; i < (row * col); i++) {
		for (int j = 0; j < (row*col) - 1; j++) {
			int cr = j / col; // current row
			int cc = j % col; // current column
			int nr = (j + 1) / col; // next item row
			int nc = (j + 1) % col; // next item column
			
			if (a[cr][cc] > a[nr][nc]) {
				
				tmp = a[cr][cc];
				a[cr][cc] = a[nr][nc];
				a[nr][nc] = tmp;
			}
		}
	}
	
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	

}

//sort only each row of the matrix
void bubble_matrix2(int (*a)[4], int row, int col) {
	int tmp;
	for(int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++){
			for(int k = j + 1; k < col; k++) {
				if (a[i][j] > a[i][k]) {
					
					tmp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = tmp;
				}
			}
		}
	}
	
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");

}

//sort tensor matrix using implicit array traversal to vector form
void bubble_tensor1(int array[2][4][4], int block, int row, int col) {
	int tmp;
	
	printf("Beginning\n");
	for (int p = 0; p < block; p++) {
		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j++)
				printf("%d ", array[p][i][j]);
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
	
	//for(int i = 0; i < (block*row*col); i ++)
		for (int j = 0; j < (block*row*col); j++) {
			for (int p = 0; p < (block*row*col) - 1; p++) {
				
				int cb = p / (col * row); // current block
				int cr = (p / col) % row; // current row
				int cc = p % col; // current column
				
				int nb = (p + 1) / (col * row); // next item block
				int nr = ((p + 1) / col) % row; // next item row
				int nc = (p + 1) % col; // next item column
				
				//printf("POS: [%d][%d][%d] next - [%d][%d][%d]\n", cb, cr, cc, nb, nr, nc);
				
				if (array[cb][cr][cc] > array[nb][nr][nc]) {
					
					tmp = array[cb][cr][cc];
					array[cb][cr][cc] = array[nb][nr][nc];
					array[nb][nr][nc] = tmp;
				}
			}
		}
	
	printf("Sorted\n");

	for (int p = 0; p < block; p++) {
		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j++)
				printf("%d ", array[p][i][j]);
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
	

}

//make sure that every item stoods on right places
void current_item(int a[2][4][4], int block, int row, int col) {
	int tmp_b = 0, tmp_r = 0, tmp_c = 0;
	
	for (int p = 0; p < (block*row*col); p++) {
		int cb = p / (col * row); // current block
		int cr = (p / col) % row; // current row
		int cc = p % col; // current column
		
		if (tmp_c != cc) {
			printf(" ");
			tmp_c = cc;
		}
		if (tmp_r != cr) {
			printf("\n");
			tmp_r = cr;
		}
		if (tmp_b != cb) {
			printf("\n");
			tmp_b = cb;
		}
		
		printf("%d", a[cb][cr][cc]);
		

		
	}
	printf("\n\n");

	
	for (int p = 0; p < block; p++) {
		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j++)
				printf("%d ", a[p][i][j]);
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
	

}

int main () {
	int a[4][4] = { {5, 3, 1, 0},
					{7, 9, 5, 8}, 
					{2, 2, 5, 10},
					{15, 6, 4, 14} };
	
	int arr[2][4][4] = {
					{ {5, 3, 1, 0},
					{7, 9, 5, 8}, 
					{2, 2, 5, 10},
					{15, 6, 4, 14} },
					
					{ {16, 3, 1, 5},
					{16, 11, 5, 8}, 
					{2, 22, 5, 0},
					{15, 17, 3, 27} },
					
					};
					
		int arrrr[2][4][4] = {
				{ {0, 1, 2, 3},
				{4, 5, 6, 7}, 
				{8, 9, 10, 11},
				{12, 13, 14, 15} },
				
				{ {16, 17, 18, 19},
				{20, 21, 22, 23}, 
				{24, 25, 26, 27},
				{28, 29, 30, 31} },
				
				};
				
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 4; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	printf("\n");
	
	
	bubble_matrix1(a, 4, 4);
	
	printf("\n\n");
	
	bubble_tensor1(arr, 2, 4, 4);
	
	

					
	//current_item(arrrr, 2, 4, 4);
	
	return 0;
}
