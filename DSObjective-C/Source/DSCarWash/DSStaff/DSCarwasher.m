//
//  DSCarwasher.m
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSCarwasher.h"

#import "DSCar.h"
#import "DSEmployee.h"
#import "DSEnterprise.h"

@implementation DSCarwasher

- (void)performSpecificOperation {
    if (nil == self.washCar && NO == [self.washCar isDirty]) {
        return;
    }
    [super performSpecificOperation];
    if ([self.washCar payMoney:100]) {
        self.washCar.dirty = NO;
        [self.name addMoney:100 ];
    }
}

@end
