#include <stdlib.h>
#include <string.h>

#include "oistack.h"


TStack* OiStack_Create()
{
    TStack* pStack = malloc( sizeof( TStack ) );
    pStack->nCount = 0;
    pStack->pTopItem = 0;

    return pStack;
}

void OiStack_Destroy( TStack* aStack, void (*f)(void*) )
{
    TStackItem* pCurrentItem = 0;

    while( NULL != aStack->pTopItem )
    {
        pCurrentItem = aStack->pTopItem;
        aStack->pTopItem = aStack->pTopItem->pNext;

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

    free( aStack );

    return;
}

int32_t OiStack_Count( TStack* aStack )
{
    if( NULL == aStack )
    {
        return -1;
    }

    return aStack->nCount;
}

void OiStack_Push( TStack* aStack, void* aData )
{
    if( NULL == aStack )
    {
        return;
    }

    if( NULL == aData )
    {
        return;
    }

    TStackItem* pNewItem = malloc( sizeof( TStackItem ) );
    pNewItem->pData = aData;
    pNewItem->pNext = aStack->pTopItem;

    aStack->pTopItem = pNewItem;

    aStack->nCount++;

    return;
}

void* OiStack_Pop( TStack* aStack )
{
    if( NULL == aStack )
    {
        return NULL;
    }
    
    if( NULL == aStack->pTopItem )
    {
        return NULL;
    }

    TStackItem* pItem = aStack->pTopItem;
    void* pData = pItem->pData;
    aStack->pTopItem = aStack->pTopItem->pNext;

    free( pItem );

    aStack->nCount--;
    
    return pData;
}
