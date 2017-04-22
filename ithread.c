#include "ithread.h"
#include "types.h"
#include "user.h"
#include "mmu.h"

int ithread_create(ithread_t* t, void(*fcn)(void*), void *arg){
    void* stack = malloc(2 * PGSIZE);
    if ((uint)stack % PGSIZE){
        stack += PGSIZE - ((uint)stack % PGSIZE);
    }
    t = (ithread_t*)stack;
    return clone(fcn, arg, stack);
}

int ithread_join(ithread_t* t){
    return join((void*)t);
}