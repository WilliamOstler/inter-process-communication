/*
 * Replace the following string of 0s with your student number
 * 20040867
 */
#include "ipc_jobqueue.h"

ipc_jobqueue_t* ipc_jobqueue_new(proc_t* proc) {
    ipc_jobqueue_t* ijq = ipc_new(proc, "ipc_jobq", sizeof(jobqueue_t));
    
    if (!ijq) 
        return NULL;
    
    if (proc->is_init)
        jobqueue_init((jobqueue_t*) ijq->addr);
    
    return ijq;
}

size_t ipc_jobqueue_capacity(ipc_jobqueue_t* ijq) {
    return (!ijq) ? 0 : jobqueue_capacity((jobqueue_t*) ijq);
}

job_t* ipc_jobqueue_dequeue(ipc_jobqueue_t* ijq, job_t* dst) {
    if (!ijq){
        return NULL;
    }
    job_t* dequeued_job = jobqueue_dequeue((jobqueue_t*) ijq->addr, dst);
    do_critical_work(ijq->proc);
    return (dequeued_job);
}

void ipc_jobqueue_enqueue(ipc_jobqueue_t* ijq, job_t* job) {
    if(!ijq || !job){
        return;
    }
    jobqueue_enqueue((jobqueue_t*) ijq->addr, job);
    do_critical_work(ijq->proc);
    return;
}

bool ipc_jobqueue_is_empty(ipc_jobqueue_t* ijq) {
    if(!ijq || jobqueue_is_empty((jobqueue_t*) ijq->addr)){
        return true;
    }else{
        do_critical_work(ijq->proc);
        return false;
    }
}

bool ipc_jobqueue_is_full(ipc_jobqueue_t* ijq) {
    if(!ijq){
        return true;
    }
    do_critical_work(ijq->proc);
    return jobqueue_is_full((jobqueue_t*) ijq->addr);
}

job_t* ipc_jobqueue_peekhead(ipc_jobqueue_t* ijq, job_t* dst) {
    if(!ijq){
        return NULL;
    }
    dst = jobqueue_peekhead((jobqueue_t*) ijq->addr, dst);
    if (dst){
        do_critical_work(ijq->proc);
    }
    return dst;
}

job_t* ipc_jobqueue_peektail(ipc_jobqueue_t* ijq, job_t* dst) {
    if(!ijq){
        return NULL;
    }
    dst = jobqueue_peektail((jobqueue_t*) ijq->addr, dst);
    if (dst){
        do_critical_work(ijq->proc);
    }
    return dst;
}

void ipc_jobqueue_delete(ipc_jobqueue_t* ijq) {
    return ipc_delete(ijq);
}
