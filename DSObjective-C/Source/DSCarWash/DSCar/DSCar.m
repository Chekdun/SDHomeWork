//
//  DSCar.m
//  DSHuman
//
//  Created by Denis Sidorov on 22.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSCar.h"

@implementation DSCar

#pragma mark -
#pragma mark Initializators and Deallocator

- (instancetype)initWithMoney:(float) money {
    self = [super init];
    if (self) {
        self.money = money;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

+ (instancetype)carWithMoney:(float)money {
    return [[[self alloc] initWithMoney:money] autorelease];
}

- (BOOL)payMoney:(float)amount {
    if ((self.money - amount) < 0) {
        return NO;
    }
    self.money -= amount;
    
    return YES;
}





@end
