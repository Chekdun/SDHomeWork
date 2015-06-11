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
} DSGender;

typedef struct DSHuman DSHuman;

extern
DSHuman *DSHumanCreateWithParametrs(DSGender gender, DSString *name);

extern
DSHuman *DSHumanCreateChild(DSHuman *mama, DSHuman *papa, DSGender gender, DSString *name);

extern
void DSHumanMarriage(DSHuman *human1, DSHuman *human2);

extern
void DSHumanDivorse(DSHuman *human);

#pragma mark -
#pragma mark Accessors

extern
DSString *DSHumanGetName(DSHuman *ptrhuman);

extern
void DSHumanSetName(DSHuman *object, DSString *name);

extern
int DSHumanGetAge(DSHuman *ptrhuman);

extern
DSGender DSHumanGetGender(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetChildren(DSHuman *ptrhuman);

extern
void DSHumanSetChild(DSHuman *human, DSHuman *child);

extern
void DSHumanSetPartner (DSHuman *object, DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetPartner(DSHuman *ptrhuman);

extern
void DSHumanSetMother(DSHuman *object, DSHuman *mother);

extern
DSHuman *DSHumanGetMother(DSHuman *ptrhuman);

extern
void DSHumanSetFather(DSHuman *object, DSHuman *father);

extern
DSHuman *DSHumanGetFather(DSHuman *ptrhuman);

extern
int DSHumanGetChildrenCount(DSHuman *ptrhuman);

extern
void __DSHumanDeallocate(DSHuman *human);

extern
void DSHumanGenderOutput(DSHuman *human);

#endif /* defined(__DSHuman__DSHuman__) */
