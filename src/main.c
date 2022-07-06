#include "../include/menuList.h"
#include "../include/fillArray.h"
#include "../include/globalVariables.h"

int BLOCK = 10;
int ROW = 10;
int COLUMN = 10;
int VECTOR_LENGTH = 20;

int main()
{
    tensorAllocation(BLOCK, ROW, COLUMN);//allocate memory for 3D array
    vectorAllocation(VECTOR_LENGTH);//allocate memory for vector

    screenSaver();//main info title

    tensorMainMenu();//menu for selecting sort algorithms

    tensorReleasingMemory(BLOCK, ROW);//free 3D array
    vectorReleaseMemory();//free vector

    return 0;
}
