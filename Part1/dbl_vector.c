#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    size_t new_mem_size = sizeof(double) * new_size;
    
    //This doesn't seem right
    size_t new_cap = fmax(old_capacity*DV_GROWTH_FACTOR,new_size);
    printf("TING 1: %fd \n", old_capacity*DV_GROWTH_FACTOR);
    printf("TING 2: %ld \n",new_size);
    vec->size = old_size;
    bool Check2 = new_size <= vec->capacity;
    printf("CHECK: %d\n",Check2);

    if(Check2)
    {
        vec->capacity = old_capacity;
        vec->data = old_data;
    }
    else
    {
        //Asign Values to struct
        vec->capacity = new_cap;
        vec->data = realloc(old_data,new_mem_size);
        for(int i = 0; i < old_size; i++)
        {
            vec->data[i] = old_data[i];
        }
    }
}

void dv_destroy( dbl_vector_t* vec ) 
{
    //Assign Information to be Zero
    vec->size = 0;
    vec->capacity=0;
    free(vec->data);
}

void dv_copy( dbl_vector_t* vec, dbl_vector_t* dest ) 
{
    // INSERT SOLUTION HERE
}

void dv_clear( dbl_vector_t* vec ) 
{
    size_t OLD_Size = vec->size;
    for(int i = 0; i < OLD_Size; i++)
    {
        vec->data[i] = 0;
    }
}

void dv_push( dbl_vector_t* vec, double new_item ) 
{
    //Declare and Store Variables
    size_t OLD_Size = vec->size;
    double* OLD_Data = vec->data;

    //Prepare for storage
    vec->size = OLD_Size+1;
    dv_ensure_capacity(vec,OLD_Size+1);
        
    //Go through old data and reassign to vector
    for(int i = 0; i < OLD_Size; i++)
    {
        vec->data[i] = OLD_Data[i];
    }

    vec->data[OLD_Size] = new_item;

}

void dv_pop( dbl_vector_t* vec ) 
{
    size_t OLD_Size = vec->size;
    double* OLD_Data = vec->data;

    bool Check1 = OLD_Size > 0;

    if(Check1)
    {
        vec->size = OLD_Size-1;
        for(int i = 0; i < OLD_Size-1; i++)
        {
            vec->data[i] = OLD_Data[i];
        }
    }
    else
    {
        vec->size=0;
    }
    

}

double dv_last( dbl_vector_t* vec ) 
{
    double result = NAN;
    
    // INSERT SOLUTION HERE

    return result;
}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) 
{
    /**
    size_t OLD_Size = vec->size;
    double* OLD_Data = vec->data;
    size_t OLD_Capacity = vec->capacity;
    size_t loc = fmin(pos,OLD_Size);

    vec->size = OLD_Size + 1;
    dv_ensure_capacity(vec,OLD_Size+1);

    for(int i = 0; i < (OLD_Size+1); i++)
    {
        if(i < loc)
        {
            vec->data[i] = OLD_Data[i];
        }
        else if(i == loc)
        {
            vec->data[i] = loc;
        }
        else
        {
            vec->data[i] = OLD_Data[i-1];
        }
    }
    **/

}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) 
{
    // INSERT SOLUTION HERE
}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) 
{
    // INSERT SOLUTION HERE
}