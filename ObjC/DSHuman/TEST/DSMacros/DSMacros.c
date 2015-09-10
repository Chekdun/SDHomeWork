//
//  DSMacros.c
//  DSHuman
//
//  Created by Denis Sidorov on 13.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include "DSMacros.h"


#pragma mark -
#pragma mark Private Declarations

static uint8_t kDSTestLevel = 0;

static
void DSPrintMinusSymbolCountOf(uint8_t count);

#pragma mark -
#pragma mark Public Implementations

void _DSPrintTestHeader(void) {
    DSPrintMinusSymbolCountOf(++kDSTestLevel);
}

void _DSPrintTestFooter(void) {
    DSPrintMinusSymbolCountOf(kDSTestLevel--);
}

#pragma mark -
#pragma mark Private Implementations

void DSPrintMinusSymbolCountOf(uint8_t count) {
    printf("\n");
    for(uint8_t iterator = 0; iterator < count; iterator ++) {
        printf("-");
    }
}
