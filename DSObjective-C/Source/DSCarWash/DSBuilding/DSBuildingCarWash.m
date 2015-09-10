//
//  DSBuildingCarWash.m
//  DSHuman
//
//  Created by Denis Sidorov on 21.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSBuildingCarWash.h"

@class DSBuildingCarWash;

@interface DSBuildingCarWash ()

@property (nonatomic, readwrite) NSMutableArray *mutableCars;

@end

@implementation DSBuildingCarWash
@dynamic cars;

#pragma mark -
#pragma mark Initializations and Deallocator

- (void)dealloc {
    self.mutableCars = nil;
    
    [super dealloc];
}

- (instancetype)initWithCars:(NSMutableArray *)mutableCars
{
    self = [super init];
    if (self) {
        self.mutableCars = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark
#pragma mark Accessors

-(NSArray *)cars {
    return [[self.mutableCars copy] autorelease];
}

#pragma mark
#pragma mark Public Methods

- (void)addCars:(DSCar *)car {
    NSMutableArray *mutableCars = self.mutableCars;
    if (![mutableCars containsObject:car]) {
        [self.mutableCars addObject:car];
    }
}

- (void)removeCar:(DSCar *)car {
    [self.mutableCars removeObject:car];
}

- (BOOL)washRoomFree {
    return nil == self.mutableCars;
}


@end




