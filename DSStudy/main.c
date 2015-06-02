//
//  DSStudy
//
//  Created by Denis Sidorov on 20.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "HomeWork1.h"
#include "HomeWork2.h"
#include "HomeWork3.h"
#include "HomeWork4.h"

//#define DSCallSizeof(type)
#define DSCallMacroRimType
 \
//printf("Size of " #type " = %lu bytes\n", sizeof (type))
//
//#define DSPrimType(type, spec) \
//void output_ ##type (type value) \
//{ printf(#spec "\n", value); }
//
//DSPrimType(int, %d)
//DSPrimType(float, %f)
//DSPrimType(double, %d)

int main(int argc, const char * argv[]) {

    DSCallSizeof(char);
    DSCallSizeof(int);
    DSCallSizeof(float);
    DSCallSizeof(long);
    DSCallSizeof(long);
    
    DSTestMamaPapa(100);
    
    return 0;
}
