//
//  DSOrganismMale.m
//  DSHuman
//
//  Created by Denis Sidorov on 14.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSOrganismMale.h"
#import "DSOrganism.h"

@implementation DSOrganismMale


- (void)fight {
    NSLog(@"%@Fight!!!", self.name);
}

- (void)performGenderSpecificOperation{
    [self fight];
}

@end
