#include <oilist.h>

#include <stdlib.h>

#include "oilist.h"

// 
// 
//
void* OiList_LastItem( TList* aList );


//
// 
// 
TList* OiList_Create()
{
    TList* pList = malloc( sizeof( TList ) );
    pList->nCount = 0;
    pList->pFirstItem = 0;
    pList->pIteratorItem = 0;

    return pList;
}

void OiList_Destroy( TList* aList, void (*f)(void*) )
{
    TListItem* pCurrentItem = 0;

    while( NULL != aList->pFirstItem )
    {
        pCurrentItem = aList->pFirstItem;
        aList->pFirstItem = aList->pFirstItem->pNext;

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

    free( aList );

    return;
}

uint16_t OiList_Count( TList* aList )
{
    return aList->nCount;
}

void* OiList_AtIndex( TList* aList, uint16_t aIndex )
{
    if( NULL == aList )
    {
        return 0;
    }

    if( NULL == aList->pFirstItem )
    {
        return 0;
    }

    TListItem* pCurrentItem = aList->pFirstItem;

    uint16_t nIndex = 0;

    while( NULL != pCurrentItem && nIndex < aIndex )
    {
        pCurrentItem = pCurrentItem->pNext;
        nIndex++;
    }

    if( NULL == pCurrentItem )
    {
        return 0;
    }

    return pCurrentItem->pData;
}

void* OiList_First( TList* aList )
{
    if( NULL == aList )
    {
        return 0;
    }

    aList->pIteratorItem = aList->pFirstItem;

    if( NULL == aList->pIteratorItem )
    {
        return 0;
    }

    return aList->pIteratorItem->pData;
}

void* OiList_Next( TList* aList )
{
    if( NULL == aList )
    {
        return 0;
    }

    if( NULL == aList->pIteratorItem )
    {
        return 0;
    }

    aList->pIteratorItem = aList->pIteratorItem->pNext;

    if( NULL == aList->pIteratorItem )
    {
        return 0;
    }

    return aList->pIteratorItem->pData;
}

void* OiList_LastItem( TList* aList )
{
    if( NULL == aList )
    {
        return 0;
    }

    if( NULL == aList->pFirstItem )
    {
        return 0;
    }

    TListItem* pCurrentItem = aList->pFirstItem;

    while( NULL != pCurrentItem->pNext )
    {
        pCurrentItem = pCurrentItem->pNext;
    }

    return pCurrentItem;
}

void* OiList_Last( TList* aList )
{
    TListItem* pLastItem = (TListItem*)OiList_LastItem( aList );
    if( NULL == pLastItem )
    {
        return 0;
    }

    return pLastItem->pData;
}

void OiList_Append( TList* aList, void* aData )
{
    if( NULL == aList )
    {
        return;
    }

    if( NULL == aData )
    {
        return;
    }

    TListItem* pNewItem = malloc( sizeof( TListItem ) );
    pNewItem->pData = aData;
    pNewItem->pNext = 0;

    if( aList->pFirstItem == 0 )
    {
        aList->pFirstItem = pNewItem;
    }
    else
    {
        TListItem* pLastItem = (TListItem*)OiList_LastItem( aList );
        if( NULL == pLastItem )
        {
            return;
        }

        pLastItem->pNext = pNewItem;
    }

    aList->nCount++;

    return;
}

void OiList_Prepend( TList* aList, void* aData )
{
    if( NULL == aList )
    {
        return;
    }

    if( NULL == aData )
    {
        return;
    }

    TListItem* pNewItem = malloc( sizeof( TListItem ) );
    pNewItem->pData = aData;
    pNewItem->pNext = aList->pFirstItem;

    aList->pFirstItem = pNewItem;

    aList->nCount++;

    return;
}


