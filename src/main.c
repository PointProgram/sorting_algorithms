#include "../include/menu.h"
#include "../include/fillArr.h"
#include "../include/globVar.h"

int BLOCK = 3;//20;
int ROW = 3;//20;
int COLUMN = 3;//14;
int VECTOR_LENGTH = 200;

int main()
{
    tensorAllocation(BLOCK, ROW, COLUMN);//allocate memory for 3D array
    vectorAllocation(VECTOR_LENGTH);//allocate memory for vector

    screenSaver();//main info title

    tensorMainMenu();//menu for sort algorithms

    tensorReleasingMemory(BLOCK, ROW);//free 3D array
    vectorReleaseMemory();//free vector

    return 0;
}
