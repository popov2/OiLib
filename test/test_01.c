#include <stdio.h>
#include <stdlib.h>

#include "src/oilist.h"
#include "src/oistack.h"
#include "src/oiqueue.h"

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

    //
    //
    //
    TStack* pStack = OiStack_Create();
    printf( "[ ] New stack created\n" );

    int* a1 = malloc( sizeof( int ) );
    *a1 = 1;
    
    int* a2 = malloc( sizeof( int ) );
    *a2 = 2;
    
    int* a3 = malloc( sizeof( int ) );
    *a3 = 3;
    
    int* a4 = malloc( sizeof( int ) );
    *a4 = 4;

    OiStack_Push( pStack, a1 );
    OiStack_Push( pStack, a2 );
    OiStack_Push( pStack, a3 );
    OiStack_Push( pStack, a4 );

    int* z = (int*)OiStack_Pop( pStack );
    while( z )
    {
        printf( "Pop stack item: %d. Count: %d \n", *z, OiStack_Count( pStack ) );
        free( z );
        z = OiStack_Pop( pStack );
    }

    OiStack_Destroy( pStack, NULL );
    printf( "[ ] Stack destroyed\n" );

    //
    //
    //
    TQueue* pQueue = OiQueue_Create();
    printf( "[ ] New queue created\n" );

    int* b1 = malloc( sizeof( int ) );
    *b1 = 100;
    
    int* b2 = malloc( sizeof( int ) );
    *b2 = 200;
    
    int* b3 = malloc( sizeof( int ) );
    *b3 = 300;
    
    int* b4 = malloc( sizeof( int ) );
    *b4 = 400;

    OiQueue_Enqueue( pQueue, b1 );
    OiQueue_Enqueue( pQueue, b2 );
    OiQueue_Enqueue( pQueue, b3 );
    OiQueue_Enqueue( pQueue, b4 );

    int* z1 = (int*)OiQueue_Dequeue( pQueue );
    while( z1 )
    {
        printf( "dequeue item: %d. Count: %d \n", *z1, OiQueue_Count( pQueue ) );
        free( z1 );
        z1 = OiQueue_Dequeue( pQueue );
    }


    OiQueue_Destroy( pQueue, NULL );
    printf( "[ ] Queue destroyed\n" );

    return 0;
}
