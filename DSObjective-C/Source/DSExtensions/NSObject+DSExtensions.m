//
//  NSObject+DSExtensions.m
//  DSHuman
//
//  Created by Denis Sidorov on 14.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "NSObject+DSExtensions.h"

@implementation NSObject (MRFObjectExtensions)

+ (id)object {
    return [[[self alloc] init] autorelease];
}

@end
