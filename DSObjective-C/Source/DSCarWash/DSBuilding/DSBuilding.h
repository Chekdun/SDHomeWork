//
//  DSBuilding.h
//  DSHuman
//
//  Created by Denis Sidorov on 21.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DSOrganism;

@interface DSBuilding : NSObject
@property (nonatomic, copy)             NSString        *name;
@property (nonatomic, assign, readonly) NSArray         *workplace;
@property (nonatomic, assign, readonly) NSArray         *employee;
@property (nonatomic, assign)           uint8_t         humanCapacity;

- (instancetype)initWithWorkplace:(NSArray *)workplace
                         employee:(NSArray *)employee;

- (instancetype)initWithHumanCapacity:(uint8_t)HumanCapacity;

- (void)addWorkplace:(DSBuilding *)workplace;
- (void)removeWorkplace:(DSBuilding *)workplace;

- (void)addEmployee:(DSBuilding *)employee;
- (void)removeEmployee:(DSBuilding *)employee;

- (id)performSpecificOperation;

@end
