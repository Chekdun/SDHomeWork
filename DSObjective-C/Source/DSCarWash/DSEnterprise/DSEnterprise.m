//
//  DSEnterprise.m
//  DSHuman
//
//  Created by Denis Sidorov on 27.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSEnterprise.h"
#import "DSEmployee.h"
#import "DSCarwasher.h"
#import "DSAccountant.h"
#import "DSDirector.h"
#import "DSCar.h"
#import "DSBuilding.h"
#import "DSBuildingCarWash.h"
#import "DSMacros.h"

@interface DSEnterprise ()
@property (nonatomic, assign)   DSDirector      *director;
@property (nonatomic, assign)   DSAccountant    *accountant;
@property (nonatomic, assign)   DSBuilding      *buildingCarWash;
@property (nonatomic, assign)   DSBuilding      *buildingAdministration;

@end

@implementation DSEnterprise

#pragma mark -
#pragma mark Deallocations and Initializations  

- (void) dealloc {
    self.director = nil;
    self.accountant = nil;
    self.buildingCarWash = nil;
    self.buildingAdministration = nil;
    
    [super dealloc];
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    self = [super init];
    if (self) {
        _director = [self getDirector];
        _accountant = [self getAccountant];
        _buildingCarWash = [self getBuildingCarWash];
    }
    
    return self;
}

- (id) getDirector {
    DSDirector *director = [[[DSDirector alloc] initWithEmployee:self] autorelease];
 
    return director;
}

- (id) getAccountant {
    DSAccountant *accountant = [[[DSAccountant alloc] initWithEmployee:self] autorelease];
    
    return accountant;
}

- (id) getBuildingCarWash {
    uint capacity = 1;
    NSMutableArray *carWashers =[NSMutableArray arrayWithCapacity:capacity];
    for (NSUInteger i = 0; i < capacity; ++i) {
        DSCarwasher *carWasher = [[[DSCarwasher alloc] initWithEmployee:self] autorelease];
        [carWashers addObject:carWasher];
    }
    NSMutableArray *washRooms = [NSMutableArray arrayWithCapacity:capacity];
    for (NSUInteger i = 0; i < capacity; ++i) {
        DSBuilding *washRoom = [[[DSBuilding alloc] init] autorelease];
        [washRooms addObject:washRoom];
    }
    
        DSBuildingCarWash *buildingCarWash = [[DSBuildingCarWash alloc]
                                              initWithWorkplace:washRooms
                                              employee:carWashers];
        
        return buildingCarWash;
}


#pragma mark -
#pragma mark Public Methods

- (BOOL)washCar:(DSCar *)car {
    BOOL result = NO;
    DSCarwasher *carWasher = self.carwasher;
    if (carWasher) {
        carWasher.washCar = car;
        [carWasher performSpecificOperation];
        carWasher.washCar = nil;
        result = YES;
    }
    
    return result;
}

- (void)addMoney:(float)account {
    self.money += account;
    self.totalMoney += account;
}

- (void)addProfit:(float)account {
    self.profit += account;
}

@end
