//
//  HomeWork2.c
//  DSStudy
//
//  Created by Denis Sidorov on 20.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>

#include "HomeWork2.h"

int func (int value) {
    if (value % 3 == 0){
        printf("mama\n");
    }
    if (value % 5 == 0){
        printf("papa\n");
    }
    if (value % 15 == 0){
        printf("mamapapa\n");
    }
    return 0;
    
}


int main(int argc, const char * argv[]) {
    //func(1000);
    for (int a = 0; a < 1000; a++){
        printf("%d\n", a);
        func(a);
    }
    
    return 0;
}
