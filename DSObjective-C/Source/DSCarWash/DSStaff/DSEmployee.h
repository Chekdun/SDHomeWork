//
//  DSEmployee.h
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DSBuilding.h"

@class DSEnterprise;

@interface DSEmployee : NSObject
@property (nonatomic, copy)                         NSString    *name;
@property (nonatomic, assign)                       DSBuilding  *building;
@property (nonatomic, assign)                       DSEmployee  *employee;
@property (nonatomic, readonly, getter = isBusy)    BOOL        busy;
@property (nonatomic, assign)                       float       money;
@property (nonatomic, assign)                       uint        salary;
@property (nonatomic, copy)                         NSString    *experience;
@property (nonatomic, assign)                       float       account;


- (id)initWithEmployee:(DSEnterprise *)employee;

- (void) performSpecificOperation;



@end
