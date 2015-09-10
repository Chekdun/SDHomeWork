//
//  DSSquareView.m
//  DS-UI
//
//  Created by Denis Sidorov on 10.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSSquareView.h"

@implementation DSSquareView

- (void)setSquarePosition:(DSSquarePositionType)position {
    [self setSquarePosition: position animated:NO];
}

- (void)setSquarePosition:(DSSquarePositionType) position
                 animated:(bool)animated {
    [self setSquarePosition:position
                   animated:NO];
}

- (void)setSquarePosition:(DSSquarePositionType)position
                 animated:(bool)animation
        completionHandler:(void(^)(void))handler {
    
}

@end
