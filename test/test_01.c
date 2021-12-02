#include <stdio.h>
#include <stdlib.h>

#include "src/oilist.h"

int main( int argc, char** argv )
{
    printf( "OiList test app\n" );
    printf( "---\n" );

    int a = 0;
    a++;
    a = 100;

    int b = a;

    TList* pNewList = OiList_Create();


    OiList_Destroy( pNewList, NULL );

    return 0;
}
