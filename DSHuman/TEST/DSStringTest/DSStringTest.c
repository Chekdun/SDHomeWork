//
//  DSStringTest.c
//  DSHuman
//
//  Created by Denis Sidorov on 02.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <assert.h>

#include "DSStringTest.h"
#include "DSString.h"
#include "DSObject.h"

void DSStringTest(void) {
    // create string with "Value"
    DSString *newString = DSStringCreateWithData("Value");
    
    //  created string != NULL
    assert(NULL != newString);
    
    //  length of string = 5
    assert(5 == DSStringGetLength(newString));
    
    DSObjectRelease(newString);
}