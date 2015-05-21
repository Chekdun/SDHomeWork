//
//  DSFunc.c
//  DSStudy
//
//  Created by Denis Sidorov on 21.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include "DSFunc.h"
//
//  main.c
//  222
//
//  Created by Denis Sidorov on 10.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#include <stdio.h>
#define p 3.14
#define ddd(value) printf("%d\n", value);
#define aaa(tipe, spec) void func7 (tipe value) { printf(#spec "\n", value); }

void func5 (int value) {
    printf("%d\n", value);
}
void func6 (double value) {
    printf("%f\n", value);
}

aaa(char, %c);


int func (int value) {
    if (value % 2 != 0){
        value += 1;
        printf("%d\n", value);

    }
    return value;
}

void func1 (int value1, int value2) {
    if (value1 > value2) {
        printf("%d\n", value1);
    } else {
        printf("%d\n", value2);
}
}
void func2 (int value1, int value2, int value3) {
    if (value1 > value2 && value1 > value3) {
        printf("%d\n", value1);
    }
    if (value2 > value3 && value2 > value1) {
        printf("%d\n", value2);
    }
    if (value3 > value1 && value3 > value2) {
        printf("%d\n", value3);
    }
}
void func3 (int value1, int value2, int value3, int value4) {
    int max = value1;
    if (value2 > max) {
        max = value2;
    }
    if (value3 > max) {
        max = value3;
    }
    if (value4 > max) {
        max = value4;
    }
    printf("%d\n", max);
}

void func4 (int value1, int value2, int value3, int value4, int value5) {
    int min = value1;
    if (value2 < min) {
        min = value2;
    }
    if (value2 < min) {
        min = value3;
    }
    if (value4 < min) {
        min = value4;
    }
    if (value5 < min) {
        min = value5;
    }
    printf("%d\n", min);

}


int main(int argc, const char * argv[]) {
        func(15);
        func1(9, 7);
        func2(35, 111, 911);
        func3(232, 434, 99, 513);
        func4(99, 93, 91, 96, 95);
        int a = func(11);
        a *= p;
        printf("%d\n", a);
    
    ddd(99);
    func5(100);
    //func7("ABC");
    
    
    
    
    
    
    
    return 0;
}

