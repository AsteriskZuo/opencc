//
//  BundleToolsCpp.hpp
//  opencc
//
//  Created by Asterisk on 12/07/19.
//  Copyright © 2019 Asterisk. All rights reserved.
//

#ifndef BundleToolsCpp_hpp
#define BundleToolsCpp_hpp

#import <CoreFoundation/CoreFoundation.h>
#include <string>

class BundleToolsCpp {
public:
    BundleToolsCpp();
    virtual ~BundleToolsCpp();
    
    static CFStringRef getBundlePath(const CFStringRef assetName);
    static CFBundleRef getBundle();
    static std::string getResourceDirectory();
    
private:
    CFBundleRef cfBundle;
};

#endif /* BundleToolsCpp_hpp */
