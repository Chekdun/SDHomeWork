//
//  DSDirector.m
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSDirector.h"
#import "DSAccountant.h"
#import "DSCarwasher.h"

@implementation DSDirector

#pragma mark -
#pragma mark - Public Method

- (void)getMoneyFromAccountant:(DSAccountant *)accountant fromCarwasher:(DSCarwasher *)carwasher {
    if (nil != accountant && nil != carwasher) {
        self.account = accountant.account - (carwasher.salary + accountant.salary);
        accountant.account = 0;
    }
}

@end

