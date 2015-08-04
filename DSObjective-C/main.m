//
//  main.m
//  DSObjective-C
//
//  Created by Denis Sidorov on 08.07.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DSOrganismTest.h"
#import "DSExtensionsTest.h"
#import "DSCarWashTest.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
    // [DSOrganismTest organismTest];
//    [DSExtensionsTest extensionsTest];
    [DSCarWashTest perfomCarWashTests];
    }
    
    
    return 0;
}
