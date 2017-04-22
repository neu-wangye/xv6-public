#ifndef _ITHREAD_H_
#define _ITHREAD_H_

#include "types.h"

int ithread_create(ithread_t* t, void(*fcn)(void*), void *arg);
int ithread_join(ithread_t* t);

#endif