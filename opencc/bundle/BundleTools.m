//
//  BundleTools.m
//  opencc
//
//  Created by Asterisk on 12/07/19.
//  Copyright © 2019 Asterisk. All rights reserved.
//

#import "BundleTools.h"

@implementation BundleTools

+ (NSBundle *)getBundle{
    NSURL* url2 = [[NSBundle mainBundle] resourceURL];
    NSString* path2 = [[NSBundle mainBundle] resourcePath];
    NSURL    *ur3= [[NSBundle mainBundle] URLForResource:BUNDLE_NAME withExtension:@"bundle"];
    NSArray<NSBundle *> * list = [NSBundle allBundles];
    for (NSBundle* bundle in list) {
        if (bundle) {
            NSURL* _url = [bundle resourceURL];
            if (_url) {
                NSLog(@"%@", [_url absoluteString]);
            }
        }
    }
    
    NSArray<NSBundle *> * frameworks = NSBundle.allFrameworks;
    for (NSBundle* bundle in frameworks) {
        if (bundle) {
            NSString* identifier = [bundle bundleIdentifier];
            NSLog(@"identifier:%@", identifier);
            NSURL* _url = [bundle resourceURL];
            if (_url) {
                NSLog(@"url:%@", [_url absoluteString]);
            }
        }
    }
    
    NSString* name = NSStringFromClass([self class]);
    NSURL    *url=  [[NSBundle bundleForClass:[self class]] URLForResource:BUNDLE_NAME withExtension:@"bundle"];
    NSBundle *bundle = [NSBundle bundleWithURL:url];
    return bundle;
}

+ (NSString *)getBundlePath: (NSString *) assetName{
    NSBundle *myBundle = [BundleTools getBundle];
    if (myBundle && assetName) {
        return [[myBundle resourcePath] stringByAppendingPathComponent: assetName];
    }
    return nil;
}

@end
