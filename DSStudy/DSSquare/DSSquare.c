//
//  DSSquare.c
//  DSStudy
//
//  Created by Denis Sidorov on 21.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>

#include "DSSquare.h"




int main(int argc, const char * argv[]) {
    
    int i, N;
    printf("Введите число N:");
    scanf("%d", &N);
    for ( i=1; i<=N; i++)
    { printf("Квадрат числа %d равен %d\n", i, i*i);
    }
    
    
}
