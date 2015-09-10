//
//  DSObjectTest.c
//  DSHuman
//
//  Created by Denis Sidorov on 03.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include "assert.h"

#include "DSObjectTest.h"
#include "DSObject.h"
#include "DSHuman.h"


#pragma mark -
#pragma mark - privat declaration

void DSObjectCreationTest();

#pragma mark -
#pragma mark - public implementation

void DSObjectBiheviorTest();

#pragma mark -
#pragma mark - privat implementaion

void DSObjectCreationTest() {

    // create of object
    DSObject *object = DSObjectCreateOfType(DSObject);
    
    //  object must be NULL
    assert(NULL != object);
    
    //   reference count  1
    assert(1 == DSObjectGetReferenceCount(object));
    
    //  object retaning
    DSObject *retaningObject = DSObjectRetain(object);
    
    //      object = retaningObject
    assert(object = retaningObject);
    
    //      object reference count = 2
     assert(2 == DSObjectGetReferenceCount(object));
    
    //  releasing object
    DSObjectRelease(retaningObject);
    
    //  reference count must be 1
    assert(1 == DSObjectGetReferenceCount(object));

    DSObjectRelease(object);
    
}









