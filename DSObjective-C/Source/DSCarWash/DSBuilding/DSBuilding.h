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
@property (nonatomic, copy)             NSString    *name;
@property (nonatomic, assign, readonly) NSArray     *workplace;
@property (nonatomic, assign, readonly) NSArray     *employee;

- (instancetype)initWithName:(NSString *)name
                   workplace:(NSArray *)workplace
                    employee:(NSArray *)employee;

- (void)addWorkplace:(DSBuilding *)workplace;
- (void)removeWorkplace:(DSBuilding *)workplace;

- (void)addEmployeeObject:(DSBuilding *)employee;
- (void)removeEmployee:(DSBuilding *)employee;

- (id) performGenderSpecificOperation;

@end
