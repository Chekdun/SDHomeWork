//
//  DSHumanTest.c
//  DSHuman
//
//  Created by Denis Sidorov on 27.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <stdio.h>
#include "DSHumanTest.h"
#include "DSHuman.h"



//void DSHumanTest(void) {
//printf("Размер структуры %lu\n", sizeof(DSStructCompres));
//// printf("Размер структуры уменьшенный%lu\n", sizeof(DSStructUnion));
//printf("Размер структуры уменьшенный %lu\n", sizeof(DSStruct));
//
//DSHuman *vasilisa = DSHumanCreateWithParametrs(DSHumanFemale, "Vasilisa");
//DSHuman *roma = DSHumanCreateWithParametrs(DSHumanMale, "Roma");
//
////
//assert(NULL != vasilisa);
//assert(NULL != roma);
//
////
//assert(1 == DSObjectGetReferenceCount(vasilisa));
//assert(1 == DSObjectGetReferenceCount(roma));
//
//
//printf("Name of created object is: %s\n", DSHumanGetName(vasilisa));
//printf("Name of created object is: %s\n", DSHumanGetName(roma));
//
//DSHumanGenderOutput(vasilisa);
//DSHumanGenderOutput(roma);
//DSHuman *petro = DSHumanCreateChild(vasilisa, roma, DSHumanMale, "Petro");
//DSHuman *katya = DSHumanCreateChild(vasilisa, roma, DSHumanFemale, "Katya");
//
//DSObjectRelease(petro);
//DSObjectRelease(roma);
//DSObjectRelease(vasilisa);
//DSObjectRelease(katya);
//}