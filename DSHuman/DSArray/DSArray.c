//
//  DSArray.c
//  DSHuman
//
//  Created by Denis Sidorov on 04.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include "DSArray.h"

#pragma mark -
#pragma mark - privat declaration

static
void DSArraySetCapacity(DSArray *array, uint64_t capacity);

static
void DSArrayShouldResize(DSArray *array);

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
    if (NULL != array && NULL != *object) {
        uint64_t count = DSArrayGetCount(array);
        if (true = DSArrayShouldResize(array)) {
            DSArrayResize(array, count + 1);
        }
        DSArraySetCount(array, count + 1);
        DSArraySetObjectAtIndex(array, object, count);
    }
    
}

#pragma mark -
#pragma mark - privat implementation
