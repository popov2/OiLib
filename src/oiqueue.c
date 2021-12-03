#include <stdlib.h>
#include <string.h>

#include "oiqueue.h"

TQueue* OiQueue_Create()
{
    TQueue* pQueue = malloc( sizeof( TQueue ) );
    pQueue->nCount = 0;
    pQueue->pFirstItem = 0;

    return pQueue;
}

void OiQueue_Destroy( TQueue* aQueue, void (*f)(void*) )
{
    TQueueItem* pCurrentItem = 0;

    while( NULL != aQueue->pFirstItem )
    {
        pCurrentItem = aQueue->pFirstItem;
        aQueue->pFirstItem = aQueue->pFirstItem->pNext;

        if( f )
        {
            (*f)( pCurrentItem->pData );
        }
        else
        {
            free( pCurrentItem->pData );
        }

        free( pCurrentItem );
    }

    free( aQueue );

    return;
}

int32_t OiQueue_Count( TQueue* aQueue )
{
    if( NULL == aQueue )
    {
        return -1;
    }

    return aQueue->nCount;
}

void OiQueue_Enqueue( TQueue* aQueue, void* aData )
{
    if( NULL == aQueue )
    {
        return;
    }

    if( NULL == aData )
    {
        return;
    }

    TQueueItem* pNewItem = malloc( sizeof( TQueueItem ) );
    pNewItem->pData = aData;
    pNewItem->pNext = NULL;

    aQueue->nCount++;

    if( aQueue->pFirstItem == NULL )
    {
        aQueue->pFirstItem = pNewItem;
        return;
    }

    TQueueItem* pCurrentItem = aQueue->pFirstItem;
    while( pCurrentItem->pNext != NULL )
    {
        pCurrentItem = pCurrentItem->pNext;
    }
    pCurrentItem->pNext = pNewItem;

    return;
}

void* OiQueue_Dequeue( TQueue* aQueue )
{
    if( NULL == aQueue )
    {
        return NULL;
    }
    
    if( NULL == aQueue->pFirstItem )
    {
        return NULL;
    }

    TQueueItem* pItem = aQueue->pFirstItem;
    void* pData = pItem->pData;
    aQueue->pFirstItem = aQueue->pFirstItem->pNext;

    free( pItem );

    aQueue->nCount--;
    
    return pData;
}