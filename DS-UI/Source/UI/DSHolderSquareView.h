//
//  DSHolderSquareView.h
//  DS-UI
//
//  Created by Denis Sidorov on 10.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, DSSquarePositionType) {
    DSSquarePositionTopLeftCorner,
    DSSquarePositionTopRightCorner,
    DSSquarePositionBottomLeftCorner,
    DSSquarePositionBottomRightCorner,
    DSSquarePositionSquarePositionCount
};

@interface DSHolderSquareView : UIView
@property (nonatomic, strong)   IBOutlet    UIView      *squareView;
@property (nonatomic, strong)   IBOutlet    UIButton    *actionButton;

@property (nonatomic, unsafe_unretained) DSSquarePositionType squarePosition ;

- (void)setSquarePosition:(DSSquarePositionType) position
                 animated:(bool)animated;

- (void)setSquarePosition:(DSSquarePositionType)position
                 animated:(bool)animation
        completionHandler:(void(^)(void))handler;

- (void)squareMove;




@end
