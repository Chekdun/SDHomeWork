//
//  DSString.h
//  DSHuman
//
//  Created by Denis Sidorov on 02.06.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#ifndef __DSHuman__DSString__
#define __DSHuman__DSString__

#include <stdio.h>

typedef struct DSString DSString;

extern
DSString *DSStringCreateWithData(char *data);

extern
void __DSStringDeallocate(DSString *string);

extern
uint64_t DSStringGetLength(DSString *string);

extern
char *DSStringGetData(DSString *string);


#endif /* defined(__DSHuman__DSString__) */
