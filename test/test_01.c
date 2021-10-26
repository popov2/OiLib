#include <stdio.h>
#include <stdlib.h>

#include "../src/oilist.h"

int main( int argc, char** argv )
{
    TList* pNewList = OiList_Create();


    OiList_Destroy( pNewList, NULL );

    return 0;
}