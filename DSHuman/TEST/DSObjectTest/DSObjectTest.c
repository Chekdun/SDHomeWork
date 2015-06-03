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

    // создание объекта
    DSObject *object = DSObjectCreateOfType(DSObject);
    
    //  объект должен быть NULL
    assert(NULL != object);
    
    //  увеличение reference count на 1
    assert(1 == DSObjectGetReferenceCount(object));
    
    //  объект retaning
    DSObject *retaningObject = DSObjectRetain(object);
    
    //      retained объект равен объекту
    assert(object = retaningObject);
    
    //      reference count  у объекта = 2
     assert(2 == DSObjectGetReferenceCount(object));
    
    //  releasing объект
    DSObjectRelease(retaningObject);
    
    //  reference count уменьшился до 1
    assert(1 == DSObjectGetReferenceCount(object));

    DSObjectRelease(object);
    
}









