//
//  DSHuman.c
//  DSHuman
//
//  Created by Denis Sidorov on 26.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "DSHuman.h"
#include "DSObject.h"
#include "DSString.h"
#include "DSMacros.h"





struct DSHuman {
    DSObject _superObject;
    
    DSString *_name;
    int _age;
    DSHumanGender _sex;
    DSHuman *_children[20];
    DSHuman *_partner;
    DSHuman *_mother;
    DSHuman *_father;
    int _childrenCount;
};

const
uint64_t kDSChildrenNotFound = UINT64_MAX;

const
uint64_t kDSChildrenCountMax = 20;

#pragma mark -
#pragma mark - Privat Declaration

static
void  DSHumanSetSex (DSHuman *human, DSHumanGender sex);

static
void DSHumanSetName(DSHuman *object, DSString *name);

static
void DSHumanSetPartner (DSHuman *object, DSHuman *ptrhuman);

static
void DSHumanSetMother(DSHuman *object, DSHuman *mother);

static
void DSHumanSetFather(DSHuman *object, DSHuman *father);

#pragma mark -
#pragma mark - Public Implementation

DSHuman *DSHumanCreateWithParametrs(DSHumanGender gender, char *name) {
    DSHuman *newHuman = DSObjectCreateOfType(DSHuman);
    newHuman->_sex = gender;
    DSString *nameValue = DSStringCreateWithData(name);
    DSHumanSetName(newHuman, nameValue);
    DSObjectRelease(nameValue);
    return newHuman;
}
void DSHumanMarriage(DSHuman *human1, DSHuman *human2) {
    DSHumanGender humanGender = DSHumanGetGender(human1);
    if (NULL != human1
        && NULL != human2
        && DSHumanGetGender(human1) != DSHumanGetGender(human2)
        && DSHumanGetGender(human1) != DSHumanUndefined
        && DSHumanGetGender(human2) != DSHumanUndefined) {
        DSHuman *woman = (humanGender == DSHumanFemale) ? human1 : human2;
        DSHuman *man = (humanGender == DSHumanMale) ? human1 : human2;
        
        if (DSHumanGetPartner(woman) !=man) {
            DSHumanDivorse(woman);
            DSHumanDivorse(man);
            
            DSObjectRetain(man);
            
            woman->_partner = man;
            man->_partner = woman;
        }
    }
}

void DSHumanDivorse(DSHuman *human) {
    if (NULL != human && DSHumanGetPartner(human) != NULL) {
        DSHuman *humanPartner = DSHumanGetPartner(human);
        DSHuman *man = (DSHumanGetGender(human) == DSHumanMale) ? human : humanPartner;
        humanPartner->_partner = NULL;
        human->_partner = NULL;
        DSObjectRelease(man);
    }
}

DSString *DSHumanGetName(DSHuman *ptrhuman) {
    DSPointerValueGetter(ptrhuman, name);
}

int DSHumanGetAge(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman->_age : 0;
}

DSHumanGender DSHumanGetGender(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman->_sex : 0;
    }

DSHuman *DSHumanGetPartner(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman->_partner : NULL;
}

DSHuman *DSHumanGetMother(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman->_mother : 0;
}

DSHuman *DSHumanGetFather(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman->_father : 0;
}

void DSHumanGenderOutput(DSHuman *human) {
    if (DSHumanGetGender(human) == 1) {
        printf("Gender of %s is male\n", DSStringGetData(DSHumanGetName(human)));
        return;
    }
    if (DSHumanGetGender(human) == 2) {
        printf("Gender of %s is female\n", DSStringGetData(DSHumanGetName(human)));
    } else {
        printf("Gender of %s is unknow\n", DSStringGetData(DSHumanGetName(human)));
    }
}


DSHuman *DSHumanCreateChild(DSHuman *mama, DSHuman *papa, DSHumanGender gender, char *name) {
    if (NULL != mama && NULL != papa) {
        DSHuman *newChild = DSHumanCreateWithParametrs(gender, name);
        
        DSHumanAddChild(mama, newChild);
        DSHumanAddChild(papa, newChild);
        DSHumanSetMother(newChild, mama);
        DSHumanSetFather(newChild, papa);
        DSObjectRelease(newChild);
        
        return newChild;
    }
    return 0;
}

void DSHumanRemoveChild(DSHuman *object, DSHuman *child) {
    if (NULL != child) {
        
        uint64_t index = DSHumanGetIndexOfChild(object, child);
        uint64_t count = DSHumanGetChildrenCount(object);
        
        if (index != kDSChildrenNotFound) {
            while (index < count) {
                object->_children[index] = object->_children[index + 1];
                index++;
            }
            object->_childrenCount--;
            DSObjectRelease(child);
        }
    }
}

DSHuman *DSHumanGetChildren(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _children[0] : NULL;
}

int DSHumanGetChildrenCount(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _childrenCount : 0;
}

void DSHumanAddChild(DSHuman *human, DSHuman *child) {
    if (NULL != human) {
        for (int index = 0; index < 20; index++) {
            if (human->_children[index] == NULL) {
                DSHuman *previousChild = human->_children[index];
                if (previousChild != child) {
                    DSObjectRetain(child);
                    DSObjectRelease(previousChild);
                    
                    human->_children[index] = child;
                    human->_childrenCount++;
                }
                break;
            }
        }
    }
}

uint64_t DSHumanGetIndexOfChild(DSHuman *object, DSHuman *child) {
    uint64_t result = kDSChildrenNotFound;
    if (NULL != object) {
        for (uint64_t index = 0; index < kDSChildrenCountMax; index++) {
            if (object->_children[index] == child) {
                result = index;
            }
        }
    }
    
    return result;
}

void __DSHumanDeallocate(DSHuman *human) {
    DSHumanDivorse(human);
    DSHumanSetName(human, NULL);
    
    __DSObjectDeallocate(human);
}

#pragma mark -
#pragma mark - Privat Declaration

void DSHumanSetName(DSHuman *object, DSString *name) {
    if (NULL != object && object->_name != name) {
        DSObjectRetain(name);
        DSObjectRelease(object->_name);
        object->_name = name;
    }
}

void DSHumanSetPartner(DSHuman *object, DSHuman *partner) {
    if (NULL != object) {
        object->_partner = partner;
    }
}

void DSHumanSetMother(DSHuman *object, DSHuman *mother) {
    if (NULL != object && NULL != mother) {
        object->_mother = mother;
    }
}

void DSHumanSetFather(DSHuman *object, DSHuman *father) {
    if (NULL != object && NULL != father) {
        object->_father = father;
    }
}

