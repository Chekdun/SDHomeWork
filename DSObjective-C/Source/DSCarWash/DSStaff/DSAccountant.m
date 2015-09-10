//
//  DSAccountant.m
//  DSHuman
//
//  Created by Denis Sidorov on 24.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSAccountant.h"
#import "DSCarwasher.h"

@implementation DSAccountant

#pragma mark -
#pragma mark - Public Methods

uint percentageOfProfitsForAccountant = 10;
uint percentageOfProfitsForWasherman = 10;
uint percentageProfit = 10;


- (void)getMoney:(DSCarwasher *)carwasher; {
    if (nil != carwasher ) {
        self.account = carwasher.account;
        carwasher.account = 0;
    }
}

- (void)paySalaryWasherman:(DSCarwasher *)carwasher  {
    float account = self.account;
    if (nil != carwasher) {
        carwasher.salary = (account * percentageOfProfitsForWasherman) / percentageProfit;
        account -= carwasher.salary;
    }
}

- (void)paySalaryAccountant:(DSAccountant *)accountant {
    float account = self.account;
    if (nil != accountant) {
        accountant.salary = (account * percentageOfProfitsForAccountant) / percentageProfit;
        account -= accountant.salary;
    }
}

@end
