#include <stdio.h>
#include <stdlib.h>

#include "src/oilist.h"

int main( __attribute__((unused)) int argc, __attribute__((unused)) char** argv )
{
    printf( "OiList test app\n" );
    printf( "---\n" );

    TList* pNewList = OiList_Create();
    printf( "[ ] New list created\n" );

    int* a = malloc( sizeof( int ) );
    *a = 1;
    OiList_Append( pNewList, a );

    int b = 200;
    OiList_AppendCopy( pNewList, &b, sizeof( int ) );

    void* pValue = OiList_First( pNewList );
    while( pValue )
    {
        int* pIntValue = (int*)pValue;
        
        printf( "item: %d\n", *pIntValue );

        pValue = OiList_Next( pNewList ); 
    }

    
    
    OiList_Destroy( pNewList, NULL );
    printf( "[ ] New list destriyed\n" );

    return 0;
}
