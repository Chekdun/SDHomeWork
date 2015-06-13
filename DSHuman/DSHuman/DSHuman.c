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

static
void  DSHumanSetSex (DSHuman *human, DSGender sex) {
    if (NULL != human) {
        human->_sex = sex;
    }
}

DSHuman *DSHumanCreateWithParametrs(DSGender gender, DSString *name) {
    DSHuman *newHuman = DSObjectCreateOfType(DSHuman);
    newHuman->_sex = gender;
    DSString *nameValue = DSStringCreateWithData(name);
    DSHumanSetName(newHuman, nameValue);
    DSObjectRelease(nameValue);
    return newHuman;
}

DSHuman *DSHumanCreateChild(DSHuman *mama, DSHuman *papa, DSGender gender, DSString *name) {
    if (NULL != mama && NULL != papa) {
    DSHuman *child = DSHumanCreateWithParametrs(gender, name);
    child->_mother = mama;
    child->_father = papa;
    DSObjectRetain(child);
    
    DSHumanAddChild(mama, child);
    DSHumanAddChild(papa, child);
    
    return child;
    }
    return 0;
}

void DSHumanMarriage(DSHuman *human1, DSHuman *human2) {
    DSGender humanGender = DSHumanGetGender(human1);
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
    if (ptrhuman != NULL) {
        return ptrhuman->_name;
    }
    
    return NULL;
}

void DSHumanSetName(DSHuman *object, DSString *name) {
    if (NULL != object && object->_name != name) {
        DSObjectRetain(name);
        DSObjectRelease(object->_name);
        object->_name = name;
    }
}

int DSHumanGetAge(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _age : 0;
}

DSGender DSHumanGetGender(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _sex : 0;
    }

DSHuman *DSHumanGetChildren(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _children[0] : NULL;
}

void DSHumanAddChild(DSHuman *human, DSHuman *child) {
    if (NULL != human) {
        for (int index = 0; index < 20; index++) {
            if (human->_children[index] == NULL) {
                DSHuman previousChild = human->_children[index];
                if (previousChild != child) {
                    DSObjectRetain(child);
                    DSObjectRetain(previousChild);
                
                human->_children[index] = child;
                human->_childrenCount++;
                    }
                break;
            }
        }
    }
}

void DSHumanSetPartner(DSHuman *object, DSHuman *partner) {
    if (NULL != object) {
        object->_partner = partner;
    }
}

DSHuman *DSHumanGetPartner(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _partner : NULL;
}

void DSHumanSetMother(DSHuman *object, DSHuman *mother) {
    if (NULL != object && NULL != mother) {
        object->_mother = mother;
    }
}

DSHuman *DSHumanGetMother(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _mother : 0;
}

void DSHumanSetFather(DSHuman *object, DSHuman *father) {
    if (NULL != object && NULL != father) {
        object->_father = father;
    }
}

DSHuman *DSHumanGetFather(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _father : 0;
}

int DSHumanGetChildrenCount(DSHuman *ptrhuman) {
    return (NULL != ptrhuman) ? ptrhuman -> _childrenCount : 0;
}



void __DSHumanDeallocate(DSHuman *human) {
    DSHumanDivorse(human);
    DSHumanSetName(human, NULL);
    
    
    __DSObjectDeallocate(human);
}

void DSHumanGenderOutput(DSHuman *human) {
    if (DSHumanGetGender(human) == 1) {
        printf("Gender of %s is male\n", DSStringGetData(DSHumanGetName(human)));
        return;
    }
    if (DSHumanGetGender(human) == 2) {
        printf("Gender of %s is female\n", DSStringGetData(DSHumanGetName(human)));
    } else {
        printf("Gender of %s is male\n", DSStringGetData(DSHumanGetName(human)));
    }
}
















