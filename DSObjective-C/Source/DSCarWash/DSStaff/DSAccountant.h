//
//  DSAccountant.h
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSEmployee.h"

@class DSCarwasher;

@interface DSAccountant : DSEmployee
- (void)getMoney:(DSCarwasher *)carwasher;
- (void)paySalaryWasherman:(DSCarwasher *)carwasher;
- (void)paySalaryAccountant:(DSAccountant *)accountant;

@end
