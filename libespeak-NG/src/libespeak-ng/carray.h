/**
    Copyright (C) 2005 David Chisnall

    Date:  October 2005
    License:  Modified BSD (see COPYING.BSD)
 */

#ifndef __ESPEAKNG_C_ARRAY_INCLUDED__
#define __ESPEAKNG_C_ARRAY_INCLUDED__

/**
 * Opaque type representing a thin layer of abstraction around a dynamic C
 * array.  An CArray can be used to store any pointer type.
 */
typedef struct _CArray* CArray;

/**
 * Creates a new array with some default initial capacity.
 */
CArray CArrayNew(void);
/**
 * Creates a new array with a specified initial capacity.
 */
CArray CArrayNewWithInitialSize(unsigned int initialSize);

/**
 * Adds object at the end of array, allocating more space if needed.
 */
int CArrayAdd(CArray array, void* object);
/**
 * Adds object to array at anIndex, replacing the existing value at that index.
 */
int CArrayAddAtIndex(CArray array, void* object, unsigned int anIndex);

/**
 * Appends the contents of otherArray to array.
 */
int CArrayAppendArray(CArray array, CArray otherArray);

/**
 * Returns the value at the specified index.
 */
void* CArrayObjectAtIndex(CArray array, unsigned int anIndex);
/**
 * Swap the values at two indexes.
 */
int CArraySwap(CArray array, unsigned int index1, unsigned int index2);

/**
 * Removes the object at the specified index.  All subsequent objects will
 * moved up the array by one element.
 */
int CArrayRemoveObjectAtIndex(CArray array, unsigned int anIndex);
/**
 * Removes the last object from an array.
 */
int CArrayRemoveLastObject(CArray array);
/**
 * Removes all objects from the array, giving an empty array.
 */
int CArrayRemoveAllObjects(CArray array, int freeObjects);
/**
 * Returns the number of objects in the array.
 */
unsigned int CArrayCount(CArray array);
/**
 * Returns the index of the specified value.
 */
int CArrayIndexOfObjectIdenticalTo(CArray array, void* object);
/**
 * Destroy the array.
 */
void CArrayFree(CArray array);
#endif
