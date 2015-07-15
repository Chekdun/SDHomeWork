//
//  DSOrganismFemale.m
//  DSHuman
//
//  Created by Denis Sidorov on 14.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSOrganismFemale.h"

@implementation DSOrganismFemale

- (instancetype)giveBirth {
    DSOrganismGender randomGender = arc4random_uniform(2) + 1;
    if (kDSOrganismGenderFemale) {
        return [[[[self class] alloc] initWithGender:randomGender] autorelease];
    }
}

- (void)performGenderSpecificOperation {
    [self giveBirth];
}

@end
