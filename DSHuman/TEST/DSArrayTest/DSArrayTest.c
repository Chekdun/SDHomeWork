//
//  DSArrayTest.c
//  DSHuman
//
//  Created by Denis Sidorov on 04.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//


#include <assert.h>

#include "DSArrayTest.h"
#include "DSArray.h"
#include "DSMacros.h"

#pragma mark -
#pragma mark Private Declarations

static
void DSArrayOneObjectBehaviourTest(void);

static
void DSArrayMultipleObjectBehaviourTest(void);

#pragma mark -
#pragma mark Public

void DSArrayBehaviourTest() {
    DSArrayOneObjectBehaviourTest();
    DSArrayMultipleObjectBehaviourTest();
}

#pragma mark -
#pragma mark Private Implementations

void DSArrayOneObjectBehaviourTest(void) {
    //  after array was created
    DSArray *array = DSObjectCreateOfType(DSArray);
    
    //      array must not be NULL
    assert(NULL != array);
    
    //      array retain count must be equal 1
    assert(1 == DSObjectGetReferenceCount(array));
    
    //      array objects count muts be equal 0
    assert(0 == DSArrayGetCount(array));
    
    // after object was created
    DSObject *object = DSObjectCreateOfType(DSObject);
    
    //      object must not be NULL
    assert(NULL != object);
    
    //      object reference count must be equal to 1
    assert(1 == DSObjectGetReferenceCount(object));
    
    //      object index in array must be invalid (object not found)
    assert(kDSNotFound == DSArrayGetIndexOfObject(array, object));
    
    // after object was added to array
    DSArrayAddObject(array, object);
    
    //      array count must be equal to 1
    assert(1 == DSArrayGetCount(array));
    
    //      array reference count must not change
    assert(1 == DSObjectGetReferenceCount(array));
    
    //      object index in array must be 0
    assert(0 == DSArrayGetIndexOfObject(array, object));
    
    //      object reference count must be incremented by 1
    assert(2 == DSObjectGetReferenceCount(object));
    
    //      array object at index 0 must be equal to added object
    assert(DSArrayGetObjectAtIndex(array, 0) == object);
    
    //      array must contain an object
    assert(true == DSArrayContainsObject(array, object));
    
    
    // after object was removed from array
    DSArrayRemoveObjectAtIndex(array, 0);
    
    //      array count must be equal to 0
    assert (0 == DSArrayGetCount(array));
    
    //      array reference count must not change
    assert(DSObjectGetReferenceCount(object) == DSObjectGetReferenceCount(array));
    
    //      object index in array must be invalid (object not found)
    assert(kDSNotFound == DSArrayGetIndexOfObject(array, object));
    
    //      object reference count must be decremented by 1
    assert(1 == DSObjectGetReferenceCount(object));
    
    //      array must not contain an object
    assert(false == DSArrayContainsObject(array, object));
    
    DSObjectRelease(object);
    DSObjectRelease(array);
}

void DSArrayMultipleObjectBehaviourTest(void) {

//  after one origin object was added 5 times in array
    DSArray *array = DSObjectCreateOfType(DSArray);
    DSObject *orirginObject = DSObjectCreateOfType(DSObject);
    for (uint64_t iterator = 0; iterator < 5; iterator++) {
        DSArrayAddObject(array, orirginObject);
    }
    
    //      array count must be equal to 5
    assert(5 == DSArrayGetCount(array));
    
    //      objects at indices 0 - 4 must be equal to object
    for (uint64_t index = 0; index < 5; index++) {
        assert(DSArrayGetObjectAtIndex(array, index) == orirginObject);
    }
    
    //  after added another object2 (not equal to origin object)
    DSObject *object2 = DSObjectCreateOfType(DSObject);
    DSArrayAddObject(array, object2);
    
    //      array count must be equal to 6
    assert(6 == DSArrayGetCount(array));
    
    //      objects at indices 0 - 4 must be equal to origin object
    for (uint64_t index = 0; index < 5; index++) {
        assert(DSArrayGetObjectAtIndex(array, index) == orirginObject);
    }
    
    //      added object2 must be at index 4
    assert(DSArrayGetObjectAtIndex(array, 4) == orirginObject);
    
    // after object at index 3 was removed
    DSArrayRemoveObjectAtIndex(array, 3);
    
    //      array count must be equal to 5
    assert(5 == DSArrayGetCount(array));
    
    //      objects at indices 0 - 3 must be equal to origin object
    for (uint64_t index = 0; index < 4; index++) {
        assert(DSArrayGetObjectAtIndex(array, index) == orirginObject);
    }
    
    //      added object2 must be at index 4
    assert(DSArrayGetObjectAtIndex(array, 4));
    
    // after removing all object from array
    DSArrayRemoveAllObjects(array);
    
    //      array must be empty
    assert(0 == DSArrayGetCount(array));
    
    //      array must no contain origin object ang object2
    assert(false == DSArrayContainsObject(array, orirginObject));
    assert(false == DSArrayContainsObject(array, object2));
    
    DSObjectRelease(object2);
    DSObjectRelease(orirginObject);
    DSObjectRelease(array);
}
