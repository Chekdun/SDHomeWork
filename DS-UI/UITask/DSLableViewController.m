//
//  DSLableViewController.m
//  UITask
//
//  Created by Denis Sidorov on 09.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSLableViewController.h"
#import "DSConstant.m"

@interface DSLableViewController ()

@property (nonatomic, weak) UIView *testView;

@end

@implementation DSLableViewController

- (void)viewDidLoad {
   [super viewDidLoad];
    
   UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
   view.backgroundColor = [UIColor greenColor];
    [self.view addSubview:view];
    
    self.testView = view;
}

- (void) viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    [UIView animateWithDuration:5
                          delay:1
                        options:UIViewAnimationOptionCurveEaseInOut
                     animations:^{
                         self.testView.center = CGPointMake(CGRectGetWidth(self.view.bounds) - CGRectGetWidth(self.testView.frame) / 2, 200);
                     }
                     completion:^(BOOL finished) {
                         NSLog(@"animation is finished! %d", finished);
      }];
     }

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
