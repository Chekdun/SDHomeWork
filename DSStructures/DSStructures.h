//
//  DSStructures.h
//  DSHuman
//
//  Created by Denis Sidorov on 31.05.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//
//1. Создать структуру, данных, хранящую в себе расположенные в случайном порядке 6 bool, 1 float, 1 int, 1 long long, 3 short, 1 double, 1 указатель на строку.

#ifndef __DSHuman__DSStructures__
#define __DSHuman__DSStructures__

#include <stdio.h>
#include <stdbool.h>

typedef struct DSStruct DSStruct;

struct DSStruct {
    double _dvar;
    short _svar;
    long long _lvar;
    int _ivar;
    float _fvar;
    bool _bvar;
    DSStruct *_friend;
    
};

typedef struct DSStructCompres DSStructCompres;

struct DSStructCompres {
    double _dvar1;
    short  _svar1;
    short  _svar2;
    short  _svar3;
    long long _lvar1;
    int _ivar1;
    float _fvar;
    bool _bvar1:1;
    bool _bvar2:1;
    bool _bvar3:1;
    bool _bvar4:1;
    bool _bvar5:1;
    bool _bvar6:1;
    DSStruct *_friend;
};

struct DSStructUnion {
    double _dvar1;
    short  _svar1;
    short  _svar2;
    short  _svar3;
    long long _lvar1;
    int _ivar1;
    float _fvar;
    bool _bvar1:1;
    bool _bvar2:1;
    bool _bvar3:1;
    bool _bvar4:1;
    bool _bvar5:1;
    bool _bvar6:1;
    DSStruct *_friend;
};



    
    
    

#endif /* defined(__DSHuman__DSStructures__) */
