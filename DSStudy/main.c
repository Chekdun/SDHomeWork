//
//  DSStudy
//
//  Created by Denis Sidorov on 20.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>

#define DSPrimType(tipe, spec) \
void output_ ##tipe (tipe value) \
{ printf(#spec "\n", value); }

DSPrimType(int, %d)
DSPrimType(float, %f)

int main(int argc, const char * argv[]) {
    
    output_int(5);
    output_float(2.55f);
    
    
    
    
    
    return 0;
}