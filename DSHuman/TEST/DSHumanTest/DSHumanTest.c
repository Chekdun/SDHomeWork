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


void DSHumanTest(void) {

// Создаем двух человек
    DSHuman *anastasya = DSHumanCreateWithParametrs(DSHumanFemale, "Anastasya");
    DSHuman *andrey = DSHumanCreateWithParametrs(DSHumanMale, "Andrey");

    assert(DSObjectGetReferenceCount(andrey) == 1);
    assert(DSObjectGetReferenceCount(anastasya) == 1);
    
// Женим двух человек
    DSHumanMarriage(andrey, anastasya);
    
    assert(DSObjectGetReferenceCount(andrey) == 2);
    assert(DSObjectGetReferenceCount(anastasya) == 1);

//  валим anastasya
    DSObjectRetain(anastasya);
    assert(DSObjectGetReferenceCount(anastasya)== 2);
    DSObjectRelease(anastasya);
    
//  развод
    DSHumanDivorse(anastasya);
    
    assert(DSObjectGetReferenceCount(anastasya) == 1);
    assert(DSObjectGetReferenceCount(andrey) == 1);
    
//  валим всех
    DSObjectRelease(anastasya);
    DSObjectRelease(andrey);
    
//   создаем ребенка
    DSHumanCreateChild(anastasya, andrey, DSHumanMale, "timo");
    
    
    

}
