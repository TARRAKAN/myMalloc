#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H
#include <stdbool.h>
#include <stdlib.h>

typedef char limiter[16];    //16 bytes data type for the next union

typedef union Data{
    struct{
        size_t sizeOfData;   // size of a memory block
        union header *pNext; // pointer to a next memory block's data union
        bool isFree;         // flag of a memory block (1 = a data is free) 
    }infStruct;
    limiter justLimiter;     // now size of the union is 16 bytes
}infData;

infData *pHead, pTail;
pthread_mutex_t mallocLocker;

void* my_malloc(size_t);

#endif
