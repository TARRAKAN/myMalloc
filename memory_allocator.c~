#include <stdio.h>//del
#include <unistd.h>
#include "memory_allocator.h"

infData *pHead = NULL;
infData *pTail = NULL;

void* my_malloc(size_t size){
    size_t sizeOfBlocks;
    void *pBlock;
    infData *pHeader;
    if(!size)
        return NULL;
    pthread_mutex_lock(&mallocLocker);
    pHeader = get_free_block(size);
    if(pHeader){
        pHeader->infStruct.isFree = 0;
        pthread_mutex_unlock(&mallocLocker);
        return (void*)(pHeader + 1);
    }
    sizeOfBlocks = sizeof(infData) + size;
    pBlock = sbrk(sizeOfBlocks);
    if(pBlock == (void*) -1){
        pthread_mutex_unlock(&mallocLocker);
        return NULL;
    }
    pHeader = pBlock;
    pHeader->infStruct.sizeOfData = size;
    pHeader->infStruct.isFree = 0;
    pHeader->infStruct.pNext = NULL;
    if(!pHead)
        pHead = pHeader;
    if(pTail)
        pTail->infStruct.next = pHeader;
    pTail = pHeader;
    pthread_mutex_unlock(&mallocLocker);
    return (void*)(pHeader + 1);
}
