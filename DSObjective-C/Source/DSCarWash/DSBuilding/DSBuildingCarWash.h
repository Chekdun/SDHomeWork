//
//  DSBuildingCarWash.h
//  DSHuman
//
//  Created by Denis Sidorov on 21.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSBuilding.h"

@class DSCar;

@interface DSBuildingCarWash : DSBuilding
@property (nonatomic, copy, readonly) NSArray *cars;

- (instancetype) initWithCars:(NSMutableArray *)mutableCars;

- (void)addCars:(DSCar *)car;
- (void)removeCar:(DSCar *)car;

- (BOOL)washRoomFree;

@end
