/*
 * Replace the following string of 0s with your student number
 * 200408673
 */
#include <stdlib.h>
#include "job.h"
#include <string.h>
#include <stdio.h>
/*
 * DO NOT EDIT the job_new function.
 */
job_t* job_new(pid_t pid, unsigned int id, const char* label) {
    return job_set((job_t*) malloc(sizeof(job_t)), pid, id, label);
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look for other functions in this file that you can use to implement 
 *      this function
 */
job_t* job_copy(job_t* dst, job_t* src) {
    if (!src){
        return src;
    }else if (src == dst){
        return dst;
    }else if(!dst){
        dst = (job_t*) malloc(sizeof(job_t));
    }

    dst = job_set(dst, src->pid, src->id, src->label);

    return dst;
}

/* 
 * TODO: you must complete the implementation of this function, which 
 * currently only sets the pid and id fields of a job to zero.
 */
void job_init(job_t* job) {
    if (job) {
        job->pid = 0;
        job->id = 0;

        int i;
        for (i=0; i<MAX_NAME_SIZE; i++){
            job->label[i] = 0;
        }
    }
}

/* 
 * TODO: you must complete the implementation of this function, which 
 * currently only compares the pid and id fields of a job.
 */
bool job_is_equal(job_t* j1, job_t* j2) {
    if (!j1 && !j2) {
        return true;
    }else if(!j1 || !j2){
        return false;
    }else{
        return ((j1->pid == j2->pid && j1->id == j2->id && strcmp(j1->label, j2->label) == 0));
    }
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - read the information in job.h about padding and truncation of job labels
 */
job_t* job_set(job_t* job, pid_t pid, unsigned int id, const char* label) {
    if (job){

        if (!label){
            label = "";
        }

        char* padding ="********************************";
        job->pid = pid;
        job->id = id;

        int i = snprintf(job->label, MAX_NAME_SIZE, "%s%s", label, padding);
        return i < 0 ? NULL : job;
    }
    return job;
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
    free(job);
}