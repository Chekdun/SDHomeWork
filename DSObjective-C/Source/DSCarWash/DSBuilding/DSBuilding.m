//
//  DSBuilding.m
//  DSHuman
//
//  Created by Denis Sidorov on 21.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSBuilding.h"

@class DSOrganism;

@interface DSBuilding ()
@property (nonatomic, readwrite) NSMutableArray *mutableWorkplace;
@property (nonatomic, readwrite) NSMutableArray *mutableEmployee;

@end

@implementation DSBuilding

@dynamic workplace;
@dynamic employee;

- (void) dealloc {
    self.name = nil;
    self.mutableWorkplace = nil;
    self.mutableEmployee = nil;
    
    [super dealloc];
}

- (instancetype) initWithName:(NSString *)name
                    workplace:(NSArray *)workplace
                     employee:(NSArray *)employee
{
    self = [super init];
    if (self) {
        self.name = name;
        self.mutableWorkplace = [NSMutableArray array];
        self.mutableEmployee = [NSMutableArray array];
    }
    return self;
}

#pragma mark
#pragma mark Accessors

- (NSArray *)workplace {
    return [[self.mutableWorkplace copy] autorelease];
}

- (NSArray *) employee {
    return [[self.mutableEmployee copy] autorelease];
}

#pragma mark
#pragma mark Public Methods

- (void)addWorkplace:(DSBuilding *)workplace {
    NSMutableArray *mutableWorkplace = self.mutableWorkplace;
    if (![mutableWorkplace containsObject:workplace]) {
        [self.mutableWorkplace addObject:workplace];
    }
}

- (void)removeWorkplace:(DSBuilding *)workplace {
    [self.mutableWorkplace removeObject:workplace];
}

-(void)addEmployeeObject:(DSBuilding *)employee {
    NSMutableArray *mutableEmployee = self.mutableEmployee;
    if (![mutableEmployee containsObject:employee]) {
        [self.mutableEmployee addObject:employee];
    }
}

- (void)removeEmployee:(DSBuilding *)employee {
    [self.mutableEmployee removeObject:employee];
}

- (id)performGenderSpecificOperation {
    return nil;
}

@end
