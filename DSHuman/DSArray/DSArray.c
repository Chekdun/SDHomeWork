//
//  DSArray.c
//  DSHuman
//
//  Created by Denis Sidorov on 04.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <assert.h>

#include "DSArray.h"


#pragma mark -
#pragma mark - privat declaration

static
void DSArraySetCapacity(DSArray *array, uint64_t capacity);

static
bool DSArrayShouldResize(DSArray *array);

static
void DSArrayResize(DSArray *array, uint64_t requiredCapacity);

static
void DSArraySetCount(DSArray *array, uint64_t count);

static
void DSArraySetObjectAtIndex(DSArray *array, object, uint64_t index);


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
        if (true == DSArrayShouldResize(array)) {
            DSArrayResize(array, count + 1);
        }
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

#pragma mark -
#pragma mark - privat implementation



