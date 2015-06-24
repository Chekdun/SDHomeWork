//
//  DSArray.h
//  DSHuman
//
//  Created by Denis Sidorov on 04.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#ifndef __DSHuman__DSArray__
#define __DSHuman__DSArray__

#include <stdio.h>
#include <stdbool.h>

#include "DSObject.h"


static const uint64_t kDSNotFound = UINT64_MAX;

typedef struct {
    DSObject _super;
    
    void **_data;
    uint64_t _count;
    uint64_t _capacity;
} DSArray;

extern
void *DSArrayCreateWithCapacity(uint64_t capacity);

extern
void DSArrayAddObject(DSArray *array, void *object);

extern
uint64_t DSArrayGetCount(DSArray *array);

extern
bool DSArrayContainsObject(DSArray *array, void *object);

extern
uint64_t DSArrayGetIndexOfObject(DSArray *array, void *object);

extern
void *DSArrayGetObjectAtIndex(DSArray *array, uint64_t index);

extern
void DSArrayRemoveObjectAtIndex(DSArray *array, uint64_t index);

extern
void DSArrayRemoveAllObjects(DSArray *array);

extern
void __DSArrayDeallocate(void *object);

//static
//void DSArraySetCapacity(DSArray *array, uint64_t capacity);
//
//



#endif /* defined(__DSHuman__DSArray__) */
