#include "../include/menu.h"
#include "../include/FillArr.h"
#include "../include/globVar.h"
int P = 20;
int M = 20;
int N = 14;
int V = 200;

int main()
{
    DynBeg(P, M, N);//allocate memory for 3D array
    vectorDynBeg(V);//allocate memory for vector
    screen_saver();//main info title
    menut();//menu for sort algorithms
    DynEnd(P, M);//free 3D array
    vectorDynEnd();//free vector
    return 0;
}
