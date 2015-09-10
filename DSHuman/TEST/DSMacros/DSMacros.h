//
//  DSMacros.h
//  DSHuman
//
//  Created by Denis Sidorov on 13.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#ifndef __DSHuman__DSMacros__
#define __DSHuman__DSMacros__

#include <stdio.h>

#define DSMacroGetName(name) \
DSString *DSHumanGetName(DSHuman *ptrhuman) { \
if (ptrhuman != NULL) { \
    return ptrhuman->_name; \
} \

#define DSRetainSetter(object, iVar, newVar) \
if (NULL != object && object->iVar != newVar) { \
DSObjectRetain(newVar); \
DSObjectRelease(object->iVar); \
object->iVar = newVar; \
}

#define performTest(testFunction) \
do { \
_DSPrintTestHeader(); \
printf(" %s started...\n", #testFunction); \
testFunction(); \
_DSPrintTestFooter(); \
printf(" %s finished.\n", #testFunction); \
} while(0)

#endif /* defined(__DSHuman__DSMacros__) */
