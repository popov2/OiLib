#ifndef OISTACK_H
#define OISTACK_H

#include <stdint.h>

//
//
//
typedef struct _TStackItem TStackItem;

struct _TStackItem
{
    void* pData;
    TStackItem* pNext;
};

typedef struct _TStack
{
    uint16_t nCount;
    TStackItem* pTopItem;
} TStack;


//
//
//
TStack* OiStack_Create();

void OiStack_Destroy( TStack* aStack, void (*f)(void*) );

int32_t OiStack_Count( TStack* aStack );

void OiStack_Push( TStack* aStack, void* aData );
void* OiStack_Pop( TStack* aStack );

#endif // OISTACK_H
