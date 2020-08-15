#include <stdio.h>
#include <unistd.h>

void *my_malloc(size_t size){
    void *block;
    block = sbrk(size);
    if (block == (void*) -1)
        return NULL;
    return block;
}
