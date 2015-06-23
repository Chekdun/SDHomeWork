//
//  DSArray.c
//  DSHuman
//
//  Created by Denis Sidorov on 04.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "DSMacros.h"
#include "DSArray.h"

static const uint64_t kDSArrayMaximumCapacity = UINT64_MAX - 1;



#pragma mark -
#pragma mark - privat declaration

static
uint64_t DSArrayGetCapacity(DSArray *array);

static
void DSArraySetCapacity(DSArray *array, uint64_t capacity);

static
void DSArrayResizeIfNeeded(DSArray *array);

static
bool DSArrayShouldResize(DSArray *array);

static
uint64_t DSArrayPrefferedCapacity(DSArray *array);

static
void DSArraySetCount(DSArray *array, uint64_t count);

static
void DSArraySetObjectAtIndex(DSArray *array, void *object, uint64_t index);

#pragma mark -
#pragma mark - public methods

void *DSArrayCreateWithCapacity(uint64_t capacity) {
    DSArray *result = DSObjectCreateOfType(DSArray);
    
    DSArraySetCapacity(result, capacity);
    
    return result;
}
void __DSArrayDiallocate(void *object) {
    DSArrayRemoveAllObjects(object);             
    //DSArraySetCapacity(object, 0);
    
    __DSObjectDeallocate(object);
}

void DSArrayAddObject (DSArray *array, void *object) {
    if (NULL != array && NULL != object) {
        uint64_t count = DSArrayGetCount(array);
        
        DSArraySetCount(array, count + 1);
        DSArraySetObjectAtIndex(array, object, count);
    }
}

uint64_t DSArrayGetCount( DSArray *array) {
    return NULL != array ? array->_count : 0;
}

bool DSArrayContainsObject(DSArray *array, void *object) {
    return (NULL != array) && (kDSNotFound != DSArrayGetIndexOfObject(array, object));
}

uint64_t DSArrayGetIndexObject(DSArray *array, void *object) {
    if (NULL == array) {
        return 0;
    }
    
    if (NULL == object) {
        return kDSNotFound;
    }
    
    uint64_t result = kDSNotFound;
    uint64_t count = DSArrayGetCount(array);
    for (uint64_t index = 0; index < count; index++) {
        if (DSArrayGetObjectAtIndex(array, index) == object) {
            result = index;
            break;
        }
    }
    
    return result;
}

void *DSArrayGetObjectAtIndex(DSArray *array, uint64_t index) {
    void *result = NULL;
    if (NULL != array) {
        
        assert(DSArrayGetCount(array) > index);
        
        result = array->_data[index];
        }
    return result;
}

void DSArrayRemoveObjectAtIndex(DSArray *array, uint64_t index) {
    if (NULL != array) {
        DSArraySetObjectAtIndex(array, NULL, index);
        uint64_t count = DSArrayGetCount(array);
        
        void **data = array->_data;
        if (index < (count - 1)) {
            uint64_t elementsCount = count - (index + 1);
            
            memmove(&data[index], &data[index +1], elementsCount + sizeof(*data));
        }
        data[count - 1] = NULL;
        
        DSArraySetCount(array, count - 1);
    }
}

void DSArrayRemoveAllObjects(DSArray *array) {
    if (NULL != array) {
        uint64_t count = DSArrayGetCount(array);
        for (uint64_t index = 0; index < count; index++) {
            DSArraySetObjectAtIndex(array, NULL, index);
        }
        
        DSArraySetCapacity(array, 0);
    }
}

#pragma mark -
#pragma mark - privat implementation

uint64_t DSArrayGetCapacity(DSArray *array) {
    return (NULL != array) ? array->_capacity : 0;
}

void DSArraySetCapacity(DSArray *array, uint64_t capacity) {
    if (NULL != array && array->_capacity != capacity) {
        assert(kDSArrayMaximumCapacity >= capacity);
        
        size_t size = capacity * sizeof(*array->_data);
        if (0 == size && NULL != array->_data) {
            free(array->_data);
            array->_data = NULL;
        } else {
            array->_data = realloc(array->_data, size);
            
            assert(NULL != array->_data);
        }
        
        if (capacity > array->_capacity) {
            void *startPointer = array->_data + array->_capacity;
            size_t numberOfBytes = (capacity - array->_capacity) * sizeof(*array->_data);
            
            memset(startPointer, 0, numberOfBytes);
        }
        
        array->_capacity = capacity;
    }
}

void DSArrayResizeIfNeeded(DSArray *array) {
    if (DSArrayShouldResize(array)) {
        DSArraySetCapacity(array, DSArrayPrefferedCapacity(array));
    }
}

bool DSArrayShouldResize(DSArray *array) {
    return (NULL != array) && (array->_capacity != DSArrayPrefferedCapacity(array));
}

uint64_t DSArrayPrefferedCapacity(DSArray *array) {
    if (NULL != array) {
        uint64_t count = DSArrayGetCount(array);
        uint64_t capacity = DSArrayGetCapacity(array);
        
        if (count == capacity) {
            return capacity;
        }
        if (count < capacity) {
            return count;
        } else {
            return 2 * count;
        }
    }
    return 0;
}


void DSArraySetCount(DSArray *array, uint64_t count) {
    if(array != NULL) {
        assert(kDSArrayMaximumCapacity >= count);
        
        array->_count = count;
        
        DSArrayResizeIfNeeded(array);
    }
}

void DSArraySetObjectAtIndex(DSArray *array, void *object, uint64_t index) {
    if (NULL == array) {
        return;
    }
    
    assert(index < DSArrayGetCount(array));
    
    DSObject *currentObject = array->_data[index];
    if (currentObject != object) {
        DSObjectRetain(object);
        DSObjectRelease(currentObject);
        
        array->_data[index] = object;
    }
}










