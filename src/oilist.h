#ifndef OILIST_H
#define OILIST_H

#include <stdint.h>

//
//
//
typedef struct _TListItem TListItem;

struct _TListItem
{
    void* pData;
    TListItem* pNext;
};

typedef struct _TList
{
    uint16_t nCount;
    TListItem* pFirstItem;

    TListItem* pIteratorItem;
} TList;


//
//
//
TList* OiList_Create();

void OiList_Destroy( TList* aList, void (*f)(void*) );

int32_t OiList_Count( TList* aList );

void* OiList_AtIndex( TList* aList, uint16_t aIndex );

void* OiList_First( TList* aList );
void* OiList_Next( TList* aList );

void* OiList_Last( TList* aList );

void OiList_Append( TList* aList, void* aData );
void OiList_AppendCopy( TList* aList, void* aData, uint32_t aSize );
void OiList_Prepend( TList* aList, void* aData );
void OiList_PrependCopy( TList* aList, void* aData, uint32_t aSize );

#endif // OILIST_H
