//
//  DSAppDelegate.m
//  UITask
//
//  Created by Denis Sidorov on 09.09.15.
//  Copyright (c) 2015 DenisSidorov. All rights reserved.
//

#import "DSAppDelegate.h"
#import "DSConstant.m"
#import "DSLableViewController.h"

@interface DSAppDelegate ()

@end

@implementation DSAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    UIWindow *window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
  //  self.viewController = [[DSLableViewController alloc] initWithNibName:@"DSSquarView" bundle:nil];
    self.window = window;
    window.rootViewController = [UITableViewController new];
    window.backgroundColor = [UIColor grayColor];

    [window makeKeyAndVisible];

    window.rootViewController.view.frame = CGRectMake(0, 0, 100, 100);

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {

}

- (void)applicationDidEnterBackground:(UIApplication *)application {
  
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
   
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
 
}

- (void)applicationWillTerminate:(UIApplication *)application {
 
}

@end
