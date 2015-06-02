//
//  HomeWork2.c
//  DSStudy
//
//  Created by Denis Sidorov on 20.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>

#include "HomeWork2.h"


typedef enum {
    nothing = 0,
    mother = 3,
    father = 5,
    motherFather = 15
 } DSFamily;

int DSOneOfTheParents (int value) {
    if (value % motherFather == 0) {
        printf("%s", "МамаПапа\n");
        return motherFather;
    } else if (value % mother == 0) {
        printf("%s", "Мама\n");
        return mother;
    } else if (value % father == 0) {
        printf("%s", "Папа\n");
        return father;
    }
    return nothing;
}

void DSTestMamaPapa (int value) {
    for (int i = 1; i < value; i++) {
        printf("%d\n", i);
        DSOneOfTheParents(i);
    }
}




