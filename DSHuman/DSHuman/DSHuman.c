//
//  DSHuman.c
//  DSHuman
//
//  Created by Denis Sidorov on 26.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>


#include "DSHuman.h"
#include "DSObject.h"
#include "DSString.h"


struct DSHuman {
    DSObject _superObject;
    
    DSString *_name;
    int _age;
    DSGender _sex;
    DSHuman *_children[20];
    DSHuman *_partner;
    DSHuman *_mother;
    DSHuman *_father;
    int _childrenCount;
};

#pragma mark -
#pragma mark - Public Implementation

DSHuman *DSHumanCreateWithParametrs(DSGender gender, char *name) {
    DSHuman *newHuman = DSObjectCreateOfType(DSHuman);
    newHuman->_sex = gender;
    DSString *nameValue = DSStringCreateWithData(name);
    newHuman->_name = nameValue;
    DSObjectRelease(nameValue);
    return newHuman;
}

void DSHumanMarriage(DSHuman *human1, DSHuman *human2) {
    DSGender humanGender = DSHumanGetGender(human1);
    if (NULL != human1 && NULL != human2 && DSHumanGetGender(human1) != DSHumanGetGender(human2)) {
        DSHuman *woman = (humanGender == DSHumanFemale) ? human1 : human2;
        DSHuman *man = (humanGender == DSHumanMale) ? human1 : human2;
        
        if (DSHumanGetPartner(woman) !=man) {
            DSHumanDivorse(woman);
            DSHumanDivorse(DSHumanGetPartner(man));
            
            DSObjectRetain(man);
            
            woman -> _partner = man;
            man -> _partner = woman;
        }
    }
}

char *DSHumanGetName(DSHuman *ptrhuman) {
    if (ptrhuman != NULL) {
        return ptrhuman->_name;
    }
    
    return NULL;
}

int DSHumanGetAge( DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _age : 0;
}

DSGender DSHumanGetGender( DSHuman *ptrhuman) {
    if (ptrhuman != NULL) {
        return ptrhuman -> _sex;
    }
    
    return DSHumanUndefined;
}

DSHuman *DSHumanGetChildren(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _children[0] : NULL;
}

DSHuman *DSHumanGetPartner(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _partner : NULL;
}

DSHuman *DSHumanGetMother(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _mother : 0;
}

DSHuman *DSHumanGetFather(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _father : 0;
}

int DSHumanGetChildrenCount(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _childrenCount : 0;
}



void __DSHumanDeallocate(DSHuman *human) {
    __DSObjectDeallocate(human);
}

void DSHumanGenderOutput(DSHuman *human) {
    if (DSHumanGetGender(human) == 1) {
        printf("Gender of %s is male\n", DSHumanGetName(human));
        return;
    }
    if (DSHumanGetGender(human) == 2) {
        printf("Gender of %s is female\n", DSHumanGetName(human));
    } else {
        printf("Gender of %s is male\n", DSHumanGetName(human));
    }
}

DSHuman *DSHumanCreateChild(DSHuman *mama, DSHuman *papa, DSGender gender, char *name) {
    DSHuman *child = DSHumanCreateWithParametrs(gender, name);
    child->_mother = mama;
    child->_father = papa;
   
    DSHumanSetChild(mama, child);
    DSHumanSetChild(papa, child);
    
    return child;

}

void DSHumanSetChild(DSHuman *human, DSHuman *child) {
    for (int iterator = 0; iterator < 20; iterator++) {
        if (human->_children[iterator] == NULL) {
            human->_children[iterator] = child;
            human->_childrenCount++;
            break;
        }
    }
}

void DSHumanDivorse(DSHuman *human) {
  if (NULL != human && DSHumanGetPartner(human) != NULL) {
        DSHuman *man = (DSHumanGetGender(human) == DSHumanMale) ? human : human->_partner;
        human->_partner->_partner = NULL;
        human->_partner = NULL;
        DSObjectRelease(man);
    }
}
    





