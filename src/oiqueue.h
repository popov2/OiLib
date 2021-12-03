#ifndef OIQUEUE_H
#define OIQUEUE_H

#include <stdint.h>

//
//
//
typedef struct _TQueueItem TQueueItem;

struct _TQueueItem
{
    void* pData;
    TQueueItem* pNext;
};

typedef struct _TQueue
{
    uint16_t nCount;
    TQueueItem* pFirstItem;
} TQueue;


//
//
//
TQueue* OiQueue_Create();

void OiQueue_Destroy( TQueue* aQueue, void (*f)(void*) );

int32_t OiQueue_Count( TQueue* aQueue );

void OiQueue_Enqueue( TQueue* aQueue, void* aData );
void* OiQueue_Dequeue( TQueue* aQueue );

#endif // OIQUEUE_H
