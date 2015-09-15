//
//  DSSquareViewController.m
//  UITask
//
//  Created by Denis Sidorov on 09.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSSquareViewController.h"
#import "DSHolderSquareView.h"

@interface DSSquareViewController ()

@property (nonatomic, readonly) DSHolderSquareView *squareView;

@end

@implementation DSSquareViewController

@dynamic squareView;

#pragma mark
#pragma marc Accessors

- (DSHolderSquareView *)squareView {
    if ([self isViewLoaded] && [self.view isKindOfClass:[DSHolderSquareView class]]) {
        return (DSHolderSquareView *)self.view;
    }
    return nil;
}

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad {
   [super viewDidLoad];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
     }

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
