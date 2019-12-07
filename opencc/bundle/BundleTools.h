//
//  BundleTools.h
//  opencc
//
//  Created by Asterisk on 12/07/19.
//  Copyright © 2019 Asterisk. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BUNDLE_NAME @"opencc_data"

NS_ASSUME_NONNULL_BEGIN

@interface BundleTools : NSObject

+ (NSString *)getBundlePath: (NSString *) assetName;
+ (NSBundle *)getBundle;

@end

NS_ASSUME_NONNULL_END
