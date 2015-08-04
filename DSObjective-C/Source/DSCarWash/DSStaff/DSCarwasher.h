//
//  DSCarwasher.h
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSEmployee.h"

@class DSCar;

@interface DSCarwasher : DSEmployee

@property (nonatomic, retain) DSCar *washCar;

- (void)performSpecificOperation;

@end
