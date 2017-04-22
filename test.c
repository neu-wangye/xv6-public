#include "types.h"
#include "user.h"
#include "ithread.h"

void child(void *arg){
    int r = *(int*)arg;
    int i;
    for (i = 0; i < 10000; i++){
        printf(1, "%d", r);
    }
    exit();
}

int main(int argc, char* argv[]){
    int i = 1;
    int j = 2;
    ithread_t p1;
    ithread_t p2;
    ithread_create(&p1, &child, &i);
    ithread_create(&p2, &child, &j);
    ithread_join(&p1);
    ithread_join(&p2);
    exit();
}