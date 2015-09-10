//
//  NSObject+DSExtentions.m
//  DSHuman
//
//  Created by Denis Sidorov on 20.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "NSObject+DSExtentions.h"

@implementation NSObject (DSExtentions)

+ (id)object {
    
    return [[[self alloc] init] autorelease];
}

@end
