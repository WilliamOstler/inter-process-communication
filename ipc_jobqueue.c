/*
 * Replace the following string of 0s with your student number
 * 20040867
 */
#include "ipc_jobqueue.h"

/* 
 * DO NOT EDIT the ipc_jobqueue_new function.
 */
ipc_jobqueue_t* ipc_jobqueue_new(proc_t* proc) {
    ipc_jobqueue_t* ijq = ipc_new(proc, "ipc_jobq", sizeof(jobqueue_t));
    
    if (!ijq) 
        return NULL;
    
    if (proc->is_init)
        jobqueue_init((jobqueue_t*) ijq->addr);
    
    return ijq;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the shared jobqueue_t is accessed in ipc_jobqueue_new and 
 *      passed to jobqueue_init (ipc_jobqueue_new initialises the shared 
 *      jobqueue by passing it to a function defined in jobqueue.h)
 */
size_t ipc_jobqueue_capacity(ipc_jobqueue_t* ijq) {
    return (!ijq) ? 0 : jobqueue_capacity((jobqueue_t*) ijq);
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - this is a wrapper for jobqueue function jobqueue_dequeue
 * - and remember you must call do_critical_work after dequeuing the job
 */
job_t* ipc_jobqueue_dequeue(ipc_jobqueue_t* ijq, job_t* dst) {
    if (!ijq){
        return NULL;
    }
    job_t* dequeued_job = jobqueue_dequeue((jobqueue_t*) ijq->addr, dst);
    do_critical_work(ijq->proc);
    return (dequeued_job);
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
void ipc_jobqueue_enqueue(ipc_jobqueue_t* ijq, job_t* job) {
    if(!ijq || !job){
        return;
    }
    jobqueue_enqueue((jobqueue_t*) ijq->addr, job);
    do_critical_work(ijq->proc);
    return;
}
    
/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
bool ipc_jobqueue_is_empty(ipc_jobqueue_t* ijq) {
    if(!ijq || jobqueue_is_empty((jobqueue_t*) ijq->addr)){
        return true;
    }else{
        do_critical_work(ijq->proc);
        return false;
    }
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
bool ipc_jobqueue_is_full(ipc_jobqueue_t* ijq) {
    if(!ijq){
        return true;
    }
    do_critical_work(ijq->proc);
    return jobqueue_is_full((jobqueue_t*) ijq->addr);
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - see ipc_jobqueue_dequeue hint
 */
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

/* 
 * TODO: you must implement this function.
 * Hint:
 * - look at how the ipc_jobqueue is allocated in ipc_jobqueue_new
 */
void ipc_jobqueue_delete(ipc_jobqueue_t* ijq) {
    return ipc_delete(ijq);
}
