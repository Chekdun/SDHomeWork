//
//  DSSquareView.m
//  DS-UI
//
//  Created by Denis Sidorov on 10.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSHolderSquareView.h"
#import "UIColor+DSRandomColor.h"

static const NSTimeInterval kDSAnimationDuration    = 1;
static const NSTimeInterval kDSAnimationDelay       = 0.1f;

@interface DSHolderSquareView ()
@property (nonatomic, assign, getter=isMoving)  BOOL  moving;

- (NSString *)buttonForSquareMoving;
- (void)moving;

@end

@implementation DSHolderSquareView

#pragma mark -
#pragma mark Public

- (void)setSquarePosition:(DSSquarePositionType)position {
    [self setSquarePosition: position animated:NO];
}

- (void)setSquarePosition:(DSSquarePositionType) position
                 animated:(bool)animated {
    [self setSquarePosition:position
                   animated:animated];
}

- (void)setSquarePosition:(DSSquarePositionType)position
                 animated:(bool)animated
        completionHandler:(void(^)(void))handler
{
    UIView *squareView = self.squareView;
    CGRect destinationFrame = [self squarePositionFrame:position];
    NSTimeInterval interval = animated ? kDSAnimationDuration : 0;
    
    [UIView animateWithDuration:interval
                          delay:kDSAnimationDelay
                        options:UIViewAnimationCurveEaseInOut | UIViewAnimationOptionAllowUserInteraction
                     animations:^{
                         squareView.frame = destinationFrame;
                         squareView.backgroundColor = [UIColor randomColor];
                     }
                     completion:^(BOOL finished) {
                         _squarePosition = position;
                         
                         if (handler) {
                             handler();
                         }
                     }];
    }

- (void)squareMove {
    self.moving = !self.moving;
    [self.actionButton setTitle:[self buttonForSquareMoving] forState:UIControlStateNormal];
    [self moving];
}

#pragma mark -
#pragma mark Private

- (CGRect)squarePositionFrame:(DSSquarePositionType)position {
    CGRect subview = self.squareView.frame;
    CGRect superview = self.superview.bounds;
    double pointX = CGRectGetWidth(superview) - CGRectGetWidth(subview);
    double pointY = CGRectGetHeight(superview) - CGRectGetHeight(subview);
    CGPoint point = CGPointZero;
    
    switch (position) {
        case DSSquarePositionTopRightCorner:
            point.x = pointX;
            break;
            
        case DSSquarePositionBottomLeftCorner:
            point.y = pointY;
            break;
            
        case DSSquarePositionBottomRightCorner:
            point.x = pointX;
            point.y = pointY;
            break;
            
        default:
            break;
    }
    
    subview.origin = point;
    
    return subview;
}

- (NSString *)buttonForSquareMoving {
    return self.moving ? @"STOP" : @"MOVE";
}

- (void)moving {
    if (self.moving) {
        __weak typeof(self) weakSelf = self;
        DSSquarePositionType position = (self.squarePosition + 1) % DSSquarePositionSquarePositionCount;
        
        [weakSelf setSquarePosition:position
                           animated:YES
                  completionHandler:^{[self moving];}];
    }
}

- (IBAction)onButton:(id)sender {
    [self buttonForSquareMoving];
    
    self.moving = self.moving ? NO : YES;
    
    [self moveSquareToRandomPosition];
}

- (void)moveSquareToRandomPosition {
    DSSquarePositionType position = (arc4random_uniform(DSSquarePositionSquarePositionCount));
    
    if (self.moving) {
        [self.squareView setSquarePosition:position animated:YES completionHandler:^{
            [self moveSquareToRandomPosition];
        }];
    }
}
@end
