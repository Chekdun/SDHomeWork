//
//  DSDirector.h
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSEmployee.h"
@class DSAccountant;
@class DSCarwasher;

@interface DSDirector : DSEmployee

- (void)getMoneyFromAccountant:(DSAccountant *)accountant fromCarwasher:(DSCarwasher *)carwasher;

@end
