#include <stdint.h>


typedef struct _TList TList;

typedef struct _TListItem TListItem;



TList* OiList_Create();

void OiList_Destroy( TList* aList, void (*f)(void*) );

uint16_t OiList_Count( TList* aList );

void* OiList_AtIndex( TList* aList, uint16_t aIndex );

void* OiList_First( TList* aList );
void* OiList_Next( TList* aList );

void* OiList_Last( TList* aList );

void OiList_Append( TList* aList, void* aData );
void OiList_Prepend( TList* aList, void* aData );