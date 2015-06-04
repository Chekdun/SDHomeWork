//
//  DSString.c
//  DSHuman
//
//  Created by Denis Sidorov on 02.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <string.h>
#include <stdlib.h>

#include "DSString.h"
#include "DSObject.h"

struct DSString {
    DSObject _superObject;
    
    uint64_t _length;
    char *_data;
};

#pragma mark -
#pragma mark - Privat Declaration

static
void DSStringSetLength(DSString *string, uint64_t length);

static
void DSStringSetData(DSString *string, char *data);

#pragma mark -
#pragma mark - Public Implementation

DSString *DSStringCreateWithData(char *data) {
    DSString *newString = DSObjectCreateOfType(DSString);
    DSStringSetLength(newString, strlen(data));
    DSStringSetData(newString, data);
    
    return newString;
}

void __DSStringDeallocate(DSString *string) {
    DSStringSetLength(string, 0);
    __DSObjectDeallocate(string);
}

uint64_t DSStringGetLength(DSString *string) {
    return (NULL != string) ? string->_length : 0;
}

char *DSStringGetData(DSString *string) {
     return (NULL != string) ? string->_data : NULL;
}

#pragma mark -
#pragma mark - Privat Emplementation

void DSStringSetLength(DSString *string, uint64_t length) {
    if (NULL != string && length != DSStringGetLength(string)) {
        if (0 == length && NULL != DSStringGetData(string)) {
            free(string->_data);
            string->_data = NULL;
        }
        
        string->_data = calloc(length + 1, sizeof(char));
        string->_length = length;
    }
}

void DSStringSetData(DSString *string, char *data) {
    if (NULL != string && data != DSStringGetData(string)) {
        string->_data = strdup(data);
    }
}

