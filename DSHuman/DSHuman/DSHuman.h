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

typedef enum {
    DSHumanUndefined,
    DSHumanMale,
    DSHumanFemale
} DSGender;

typedef struct DSHuman DSHuman;

extern
DSHuman *DSHumanCreateWithParametrs(DSGender gender, char *name);

extern
void DSHumanMarriage(DSHuman *human1, DSHuman *human2);

extern
DSHuman *DSHumanCreateChild(DSHuman *mama, DSHuman *papa, DSGender gender, char *name);

extern
char *DSHumanGetName(DSHuman *ptrhuman);

extern
int DSHumanGetAge(DSHuman *ptrhuman);

extern
DSGender DSHumanGetGender(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetChildren(DSHuman *ptrhuman);

extern
void DSHumanSetChild (DSHuman *human, DSHuman *child);

extern
DSHuman *DSHumanGetPartner(DSHuman *ptrhuman);

extern
DSHuman DSHumanSetPartner(DSHuman *partner);

extern
DSHuman *DSHumanGetMother(DSHuman *ptrhuman);

extern
DSHuman *DSHumanGetFather(DSHuman *ptrhuman);

extern
int DSHumanGetChildrenCount(DSHuman *ptrhuman);


extern
void __DSHumanDeallocate(DSHuman *human);

extern
void DSHumanGenderOutput(DSHuman *human);

extern
void DSHumanDivorse(DSHuman *human);





#endif /* defined(__DSHuman__DSHuman__) */
