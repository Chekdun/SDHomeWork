//
//  DSEnterprise.h
//  DSHuman
//
//  Created by Denis Sidorov on 27.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import <Foundation/Foundation.h>


@class DSCar;
@class DSDirector;
@class DSCarwasher;
@class DSAccountant;

@interface DSEnterprise : NSObject

@property (nonatomic, readonly)     DSDirector      *director;
@property (nonatomic, readonly)     DSAccountant    *accountant;
@property (nonatomic, readonly)     DSCarwasher     *carwasher;

@property (nonatomic, readonly)     float   cost;
@property (nonatomic, assign)       float   money;
@property (nonatomic, assign)       float   totalMoney;
@property (nonatomic, assign)       float   profit;

- (instancetype)initWithCapacity:(NSUInteger)capacity;

- (BOOL)washCar:(DSCar *)car;

- (void)addMoney:(float)account;
- (void)addProfit:(float)account;


@end
