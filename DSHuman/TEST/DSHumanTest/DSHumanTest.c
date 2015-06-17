//
//  DSHumanTest.c
//  DSHuman
//
//  Created by Denis Sidorov on 04.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <assert.h>

#include "DSHumanTest.h"
#include "DSHuman.h"
#include "DSObject.h"
#include "DSMacros.h"


void DSHumanTest(void) {
    
   
    
    

//  Create 2 human
    DSHuman *anastasya = DSHumanCreateWithParametrs(DSHumanFemale, "Anastasya");
    DSHuman *andrey = DSHumanCreateWithParametrs(DSHumanMale, "Andrey");

    assert(DSObjectGetReferenceCount(andrey) == 1);
    assert(DSObjectGetReferenceCount(anastasya) == 1);
    
//  maried
    DSHumanMarriage(andrey, anastasya);
    assert(DSHumanGetPartner(anastasya) == andrey);
    assert(DSHumanGetPartner(andrey) == anastasya);
    
    
    assert(DSObjectGetReferenceCount(andrey) == 2);
    assert(DSObjectGetReferenceCount(anastasya) == 1);
    
    //  divorce anasatasye
    DSHumanDivorse(anastasya);
    
    assert(DSObjectGetReferenceCount(anastasya) == 1);
    assert(DSObjectGetReferenceCount(andrey) == 1);
    
    assert(DSHumanGetPartner(anastasya) == NULL);
    assert(DSHumanGetPartner(andrey) == NULL);
    
//  create child
    DSHuman *timo = DSHumanCreateChild(anastasya, andrey, DSHumanMale, "Timo");

    assert(DSHumanGetChildrenCount(anastasya) == 1);
    assert(DSHumanGetChildrenCount(andrey) == 1);
    assert(DSObjectGetReferenceCount(timo) == 2);

//  remove child, Anastasya children count must be 1
    DSHumanRemoveChild(anastasya, timo);
    
    assert(DSObjectGetReferenceCount(timo) == 1);
    
//  kill all
    DSObjectRelease(anastasya);
    DSObjectRelease(andrey);
    DSObjectRelease(timo);
    
}
