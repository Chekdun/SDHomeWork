//
//  DSObject.h
//  DSHuman
//
//  Created by Denis Sidorov on 26.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//


#ifndef __DSHuman__DSObject__
#define __DSHuman__DSObject__


#define DSObjectCreateOfType(type) \
__DSObjectCreate(sizeof(type), (DSObjectDeallocatorCallback)__##type##Deallocate)

#define DSPrimitiveGetter(object, ivar) \
return (NULL != object) ? object->_ ##ivar : 0

#define DSPointerValueGetter(object, ivar) \
return (NULL != object) ? object->_ ##ivar : NULL;

typedef void (*DSObjectDeallocatorCallback)(void *);

typedef struct {
    uint64_t _referenceCount;
    DSObjectDeallocatorCallback _deallocator;
} DSObject;

extern
void *__DSObjectCreate(size_t objectSize, DSObjectDeallocatorCallback deallocateCallback);

extern
void *DSObjectRetain(void *object);

extern
void DSObjectRelease(void *object);

extern
uint64_t DSObjectGetReferenceCount(void *object);

extern
void __DSObjectDeallocate(void *object);


#endif /* defined(__DSHuman__DSObject__) */
