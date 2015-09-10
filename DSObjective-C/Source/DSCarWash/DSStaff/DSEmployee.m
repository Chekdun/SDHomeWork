//
//  DSEmployee.m
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSEmployee.h"

@implementation DSEmployee

- (id)initWithEmployee:(DSEmployee *)employee
{
    self = [super init];
    if (self) {
        _employee = employee;
    }
    
    return self;
}

- (void) performSpecificOperation {
    
}

@end
