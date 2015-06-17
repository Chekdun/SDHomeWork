//
//  DSHuman.h
//  DSHuman
//
//  Created by Denis Sidorov on 26.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#ifndef __DSHuman__DSHuman__
#define __DSHuman__DSHuman__

#include <stdio.h>

#include "DSString.h"

typedef enum {
    DSHumanUndefined,
    DSHumanMale,
    DSHumanFemale
} DSHumanGender;

typedef struct DSHuman DSHuman;

extern
DSHuman *DSHumanCreateWithParametrs(DSHumanGender gender, char *name);

extern
DSHuman *DSHumanCreateChild(DSHuman *mama, DSHuman *papa, DSHumanGender gender, char *name);

extern
void DSHumanMarriage(DSHuman *human1, DSHuman *human2);

extern
void DSHumanDivorse(DSHuman *human);

#pragma mark -
#pragma mark Accessors

extern
DSString *DSHumanGetName(DSHuman *ptrhuman);

extern
int DSHumanGetAge(DSHuman *ptrhuman);

extern
DSHumanGender DSHumanGetGender(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetChildren(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetPartner(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetMother(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetFather(DSHuman *ptrhuman);

extern
int DSHumanGetChildrenCount(DSHuman *ptrhuman);

extern
void __DSHumanDeallocate(DSHuman *human);

extern
void DSHumanAddChild(DSHuman *human, DSHuman *child);

extern
void DSHumanGenderOutput(DSHuman *human);

extern
void DSHumanRemoveChild(DSHuman *object, DSHuman *child);

#endif /* defined(__DSHuman__DSHuman__) */
