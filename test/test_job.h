/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_job.h - structures and function declarations for unit tests
 * of job functions.
 * 
 */  
#ifndef _TEST_JOB_H
#define _TEST_JOB_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit/munit.h"

MunitResult test_job_new(const MunitParameter params[], void* fixture);
MunitResult test_job_new_null(const MunitParameter params[], void* fixture);

MunitResult test_job_copy_stack(const MunitParameter params[], void* fixture);
MunitResult test_job_copy_heap(const MunitParameter params[], void* fixture);
MunitResult test_job_copy_identity(const MunitParameter params[], 
    void* fixture);
MunitResult test_job_copy_null(const MunitParameter params[], void* fixture);

MunitResult test_job_init_stack(const MunitParameter params[], void* fixture);
MunitResult test_job_init_heap(const MunitParameter params[], void* fixture);
MunitResult test_job_init_null(const MunitParameter params[], void* fixture);

MunitResult test_job_is_equal(const MunitParameter params[], void* fixture);
MunitResult test_job_is_equal_init(const MunitParameter params[], 
    void* fixture);
MunitResult test_job_is_equal_null(const MunitParameter params[], 
    void* fixture);

MunitResult test_job_set_stack(const MunitParameter params[], void* fixture);
MunitResult test_job_set_heap(const MunitParameter params[], void* fixture);
MunitResult test_job_set_null(const MunitParameter params[], void* fixture);

static MunitTest tests[] = {
    { "/test_job_new", test_job_new, NULL, NULL, 
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_new_null", test_job_new_null, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
        
    { "/test_job_copy_stack", test_job_copy_stack, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_copy_heap", test_job_copy_heap, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_copy_identity", test_job_copy_identity, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_copy_null", test_job_copy_null, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
        
    { "/test_job_init_stack", test_job_init_stack, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_init_heap", test_job_init_heap, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_init_null", test_job_init_null, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
        
    { "/test_job_is_equal", test_job_is_equal, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_is_equal_init", test_job_is_equal_init, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_is_equal_null", test_job_is_equal_null, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
        
    { "/test_job_set_stack", test_job_set_stack, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_set_heap", test_job_set_heap, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_job_set_null", test_job_set_null, NULL, NULL,
        MUNIT_TEST_OPTION_NONE, NULL },
        
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
};

const MunitSuite suite = {
    "/test_job", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE 
};    


#endif