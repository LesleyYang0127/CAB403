#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dbl_vector.h"

#define DV_INITIAL_CAPACITY 4
#define DV_GROWTH_FACTOR 1.25


//TODO LIST
/**
 *
 * 1. There is an error in pushing not sure what is occuring but it doesn't happen in the pushing function
 * 2. Insert Into has an error (this could be because old data is being updated)
 *  
 **/
void dv_init( dbl_vector_t* vec ) 
{
    size_t new_mem_size = sizeof(double)*DV_INITIAL_CAPACITY;
    //Set that there is no data
    vec->size = 0;
    //Set the capacity to initial value
    vec->capacity = DV_INITIAL_CAPACITY;
    //Allocate Apporporate Memory
    printf("Here when assigning memory");
    vec->data = malloc(new_mem_size);
    printf("Passed memory \n");
}

void dv_ensure_capacity( dbl_vector_t* vec, size_t new_size ) 
{
    //Initialise Vairables
    size_t old_capacity = vec->capacity;
    size_t old_size = vec->size;
    double* old_data = vec->data;
    size_t new_capacity = fmax(old_capacity*DV_GROWTH_FACTOR,new_size);
    size_t new_mem_size = sizeof(double *) * new_size;
    vec->size = new_size;
    bool Check = new_size <= old_capacity;

    if(Check)
    {
        vec->capacity = old_capacity;
    }
    else
    {
        vec->capacity = new_capacity;
        vec->data = realloc(old_data,new_mem_size);
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
    /***
    //Initial check
    bool Initial = &vec != &dest;
    printf("Result of Copy: %d \n", Initial);
    size_t size_to_copy;
    if(Initial)
    {
        size_to_copy = vec->size;
        printf("Size to Copy: %ld \n",size_to_copy );
        dv_ensure_capacity(dest,size_to_copy);
        printf("This is here\n");
        for(int i = 0; i < size_to_copy; i++)
        {
            dest->data[i] = vec->data[i];
        }
    }
    ***/
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
    
    size_t current_size = vec->size;

    if(current_size > 0)
    {
        result = vec->data[current_size - 1];
    }

    return result;
}

void dv_insert_at( dbl_vector_t* vec, size_t pos, double new_item ) 
{
    //Initilise Variables    
    size_t OLD_Size = vec->size;

    //Intilise a copy array
    double TO_Add[OLD_Size];
    for(int j = 0; j < OLD_Size; j++)
    {
        TO_Add[j] = vec->data[j];
    }
    
    size_t OLD_Capacity = vec->capacity;
    vec->size = OLD_Size + 1;
    dv_ensure_capacity(vec,OLD_Size+1);
    

    //Go though the data and add it to the array (skip new item)
    for(size_t i = 0; i < vec->size; i++)
    {

        if(i < pos)
        {
            vec->data[i] = TO_Add[i];
        }
        else if (i > pos)
        {
            vec->data[i] = TO_Add[i-1];
        }  
    }
    //Insert new item into location
    vec->data[pos] = new_item;

}

void dv_remove_at( dbl_vector_t* vec, size_t pos ) 
{
    size_t OLD_Size = (vec->size);
    double* OLD_Data = (vec->data);

    bool check = pos >= OLD_Size;

    if(!check)
    {
        vec->size = OLD_Size - 1;
        for(int i = 0; i < OLD_Size; i++)
        if(i < pos)
        {
            vec->data[i] = OLD_Data[i];
        }
        else if (i > pos)
        {
            vec->data[i-1] = OLD_Data[i+1]; 
        }
    }

}

void dv_foreach( dbl_vector_t* vec, void (*callback)(double, void*), void* info ) 
{
    size_t Traverse_Size = vec->size;
    double placeholder;

    for(int i = 0; i < Traverse_Size; i++)
    {
        placeholder = vec->data[i];
        callback(placeholder,info);
    }
}