/*
 * Replace the following string of 0s with your student number
 * 200408673
 */
#include "mutex_peterson.h"
#include <errno.h>

mutex_t* mutex_new(proc_t* proc) {

    if(!proc){
        errno = EINVAL;
        return NULL;
    }
    return ipc_new(proc, "mux_peters", sizeof(mutex_t));
}

void mutex_enter(mutex_t* mux) {
    if(mux){
        mutex_peterson_t* mp = (mutex_peterson_t*) mux->addr;

        int other_id = 1 - mux->proc->id;
        mp->interested[mux->proc->id % 2] = 1;
        mp->turn = mux->proc->id;

        while(mp->turn == mux->proc->id && mp->interested[other_id] == 1){
        }
    }
    return;
}

void mutex_leave(mutex_t* mux) {
    if(mux){
        mutex_peterson_t* mp = (mutex_peterson_t*) mux->addr;
        mp->interested[mux->proc->id % 2] = 0;
    }
    return;
}

void mutex_delete(mutex_t* mux) {
    if(mux){
        ipc_delete(mux);
    }
    return;
}
