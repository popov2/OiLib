#include <stdio.h>
#include <stdlib.h>

#include "src/oilist.h"

int main( int argc, char** argv )
{
    printf( "OiList test app\n" );
    printf( "---\n" );

    TList* pNewList = OiList_Create();
    printf( "[ ] New list created\n" );

    int* a = malloc( sizeof( int ) );
    OiList_Append( pNewList, a );

    
    OiList_Destroy( pNewList, NULL );
    printf( "[ ] New list destriyed\n" );

    return 0;
}
