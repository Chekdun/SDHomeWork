//
//  UIColor+DSRandomColor.m
//  DS-UI
//
//  Created by Denis Sidorov on 15.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "UIColor+DSRandomColor.h"

@implementation UIColor (DSRandomColor)

+ (id)randomColor {
    CGFloat red = (CGFloat)(arc4random_uniform(256) / 255.0f);
    CGFloat green = (CGFloat)(arc4random_uniform(256) / 255.0f);
    CGFloat blue = (CGFloat)(arc4random_uniform(256) / 255.0f);
    
    return [UIColor colorWithRed:red green:green blue:blue alpha:1.0f];
}

@end
