#include <stdio.h>
#include <stdlib.h>
#include "dbl_vector.h"

#define DV_INITIAL_CAPACITY 4
#define DV_GROWTH_FACTOR 1.25

void dv_init( dbl_vector_t* vec ) 
{
    size_t NEW_MEM_Size = sizeof(double)*DV_INITIAL_CAPACITY;
    
    //Set that there is no data
    vec->size = 0;
    //Set the capacity to initial value
    vec->capacity = DV_INITIAL_CAPACITY;
    //Allocate Apporporate Memory
    vec->data = malloc(NEW_MEM_Size);
}

void dv_ensure_capacity( dbl_vector_t* vec, size_t new_size ) 
{
    //Initilise Apporporate Variables
    size_t old_capacity = vec->capacity;
    size_t old_size = vec->size;
    double* old_data = vec->data;
    
/**
 * WHERE old_capacity is the previous value of vec->capacity
 * AND old_size == previous value of vec->size
 * AND old_data == previous value of vec->data
 * AND new_capacity == max(old_capacity * DV_GROWTH_FACTOR, new_size)
 * AND new_mem_size == the number of bytes required to store new_capacity instances
 * of type double.
**/

}

void dv_destroy( dbl_vector_t* vec ) 
{
    // INSERT SOLUTION HERE
}

void dv_copy( dbl_vector_t* vec, dbl_vector_t* dest ) 
{
    // INSERT SOLUTION HERE
}

void dv_clear( dbl_vector_t* vec ) 
{
    // INSERT SOLUTION HERE
}

void dv_push( dbl_vector_t* vec, double new_item ) 
{
    size_t OLD_Size = vec->size;
    double* OLD_Data = vec->data;

    vec->size = OLD_Size+1;
    dv_ensure_capacity(vec,OLD_Size+1);
    

}

void dv_pop( dbl_vector_t* vec ) 
{
    // INSERT SOLUTION HERE
}

double dv_last( dbl_vector_t* vec ) 
{
    double result = NAN;
    // INSERT SOLUTION HERE
    return result;
}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) 
{
    // INSERT SOLUTION HERE
}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) 
{
    // INSERT SOLUTION HERE
}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) 
{
    // INSERT SOLUTION HERE
}