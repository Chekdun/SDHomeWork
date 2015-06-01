//
//  HomeWork3.c
//  DSStudy
//
//  Created by Denis Sidorov on 20.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>

#include "HomeWork3.h"

//#define DSPrimitiveType(value) \
//printf("%d\n", value); \
//        void DSPrimitiveType(int value) {
//        printf("Value Int", value);




#define DSPrimType(type, spec) \
    void output_ ##type (type value) \
        { printf(#spec "\n", value); }

DSPrimType(int, %d)
DSPrimType(float, %f)

#define DSCallMacroPrimType

//void callMacro_##type (type value); \
//{ printf(#spec "\n", value); }
//
int main(int argc, const char * argv[]) {

    output_int(5);
    output_float(2.55f);
    
    
    
    
    
    return 0;
}
