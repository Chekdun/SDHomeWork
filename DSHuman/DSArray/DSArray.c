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

#pragma mark -
#pragma mark - privat implementation

static
void DSArraySetCapacity(DSArray *array, uint64_t capacity);