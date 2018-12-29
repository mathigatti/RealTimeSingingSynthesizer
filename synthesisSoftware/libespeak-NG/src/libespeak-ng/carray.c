/*
    Copyright (C) 2005 David Chisnall

    Author:  David Chisnall <csdavec@swan.ac.uk>
    Date:  October 2005
    License:  Modified BSD (see COPYING.BSD)
 */
#include "config.h"
#include <stdlib.h>
#include <string.h>
#include "carray.h"

struct _CArray
{
    void ** array;
    unsigned int elements;
    unsigned int space;
};

//TODO: Optimise this so deleting the first element doesn't require the whole array to be shuffled.

CArray CArrayNew(void)
{
    return CArrayNewWithInitialSize(8);
}

CArray CArrayNewWithInitialSize(unsigned int initialSize)
{
    CArray newArray = malloc(sizeof(struct _CArray));
    newArray->elements = 0;
    newArray->space = initialSize;
    newArray->array = malloc(initialSize * sizeof(void*));
    return newArray;
}
int CArrayResize(CArray array, unsigned int newSize)
{
    void ** resizedArray = realloc(array->array,newSize* sizeof(void*));
    if(resizedArray != NULL)
    {
        array->space = newSize;
        array->array = resizedArray;
        return 0;
    }
    return -1;
}

int CArrayAdd(CArray array, void* object)
{
    if((array->elements + 1) >= array->space)
    {
        if(CArrayResize(array, array->space * 4))
        {
            return -1;
        }
    }
    array->array[array->elements] = object;
    array->elements++;
    return 0;
}

int CArrayAddAtIndex(CArray array, void* object, unsigned int anIndex)
{
    if(anIndex > (array->elements+1))
    {
        return -2;
    }
    if((array->elements+1) >= array->space)
    {
        if(CArrayResize(array, array->space * 2))
        {
            return -1;
        }
    }
    if(anIndex < array->elements)
    {
        size_t bytes = (array->elements - anIndex) * sizeof(void*);
        memmove(&array->array[anIndex+1],&array->array[anIndex],bytes);
    }
    array->array[anIndex] = object;
    array->elements++;
    return 0;   
}

int CArrayAppendArray(CArray array, CArray otherArray)
{
    if(array->space < array->elements + otherArray->elements)
    {
        if(CArrayResize(array,array->elements + otherArray->elements))
        {
            return -1;
        }
    }
    memcpy(&array->array[array->elements], otherArray->array, otherArray->elements);
    array->elements += otherArray->elements;
    return 0;
}

void* CArrayObjectAtIndex(CArray array, unsigned int anIndex)
{
    if(array == NULL 
       ||
       anIndex >= array->elements)
    {
        return NULL;
    }
    return array->array[anIndex];
}

int CArrayRemoveLastObject(CArray array)
{
    if(array->elements > 0)
    {
        array->elements--;
        return 0;
    }
    return -1;
}
int CArrayRemoveObjectAtIndex(CArray array, unsigned int anIndex)
{
    if(anIndex > array->elements)
    {
        return -1;
    }
    if(array->elements == 0)
    {
        return -2;
    }
    if(anIndex < array->elements)
    {
        size_t bytes = (array->elements - (anIndex + 1)) * sizeof(void*);
        memmove(&array->array[anIndex],&array->array[anIndex + 1],bytes);
    }
    array->elements--;
    return 0;
}

int CArrayIndexOfObjectIdenticalTo(CArray array, void* object)
{
    for(int i=0 ; i<(int)array->elements ; i++)
    {
        if(object == array->array[i])
        {
            return i;
        }
    }
    return -1;
}

int CArrayRemoveAllObjects(CArray array, int freeObjects)
{
    if(freeObjects)
    {
        for(unsigned int i=0 ; i<array->elements ; i++)
        {
            free(array->array[i]);
        }
    }
    array->elements = 0;
    return 0;
}

int CArraySwap(CArray array, unsigned int index1, unsigned int index2)
{
    if(array == NULL)
    {
        return -1;
    }
    if(index1 >= array->elements
       ||
       index2 >= array->elements)
    {
        return -2;
    }
    void * a = array->array[index1];
    array->array[index1] = array->array[index2];
    array->array[index2] = a;
    return 0;
}

unsigned int CArrayCount(CArray array)
{
    if(array == NULL)
    {
        return 0;
    }
    return array->elements;
}
void CArrayFree(CArray array)
{
    free(array->array);
    free(array);
}
