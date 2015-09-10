//
//  DSCar.h
//  DSHuman
//
//  Created by Denis Sidorov on 22.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DSCar : NSObject

@property (nonatomic, assign, getter = isDirty) BOOL    dirty;
@property (nonatomic, assign)                   float   money;

+ (instancetype)carWithMoney:(float)money;

- (instancetype)initWithMoney:(float)money;
- (BOOL)payMoney:(float)amount;


@end
