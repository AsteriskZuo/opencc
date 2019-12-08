//
//  BundleToolsCpp.cpp
//  opencc
//
//  Created by Asterisk on 12/07/19.
//  Copyright © 2019 Asterisk. All rights reserved.
//

#include "BundleToolsCpp.hpp"
#include <iostream>
#include <string>

BundleToolsCpp::BundleToolsCpp()
{
    
}
BundleToolsCpp::~BundleToolsCpp()
{
    
}

std::string BundleToolsCpp::getResourceDirectory()
{
    std::string resdir;
    CFBundleRef mainBundle = BundleToolsCpp::getBundle();
    CFURLRef mainBundleUrl = CFBundleCopyBundleURL(mainBundle);
    CFRelease(mainBundle);
    if (mainBundleUrl) {
        CFStringRef url = CFURLGetString(mainBundleUrl);
        const int bufferLength = 256;
        char buffer[bufferLength] = {0};
        CFStringGetCString(url, buffer, bufferLength, kCFStringEncodingUTF8);
        CFRelease(mainBundleUrl);
        std::size_t actualBufferLength = std::strlen(buffer);
        resdir = std::string(buffer, actualBufferLength);
        std::size_t pos = resdir.find_first_of(u8"file://");
        if (std::string::npos != pos) {
            resdir = resdir.substr(7);
        }
        std::string subdir = u8"opencc_data.bundle/Contents/Resources/";
        resdir.append(subdir);
    }
    return resdir;
}

CFStringRef BundleToolsCpp::getBundlePath(const CFStringRef assetName)
{
    CFBundleRef mainBundle = BundleToolsCpp::getBundle();
    CFURLRef mainBundleUrl = CFBundleCopyBundleURL(mainBundle);
    return CFSTR("");
}
CFBundleRef BundleToolsCpp::getBundle()
{
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef mainBundleUrl = CFBundleCopyBundleURL(mainBundle);
//    CFDictionaryRef maindir = CFBundleGetInfoDictionary(mainBundle);
//    CFArrayRef allbundles = CFBundleGetAllBundles();
//
//    for (int i = 0; i < CFArrayGetCount(allbundles); ++i) {
//        CFBundleRef bundle = (CFBundleRef)CFArrayGetValueAtIndex(allbundles, i);
//        if (bundle) {
//            CFStringRef identifier = CFBundleGetIdentifier(bundle);
//            if (identifier) {
//                const char* str = CFStringGetCStringPtr(identifier, kCFStringEncodingMacRoman);
//                if (str) {
//                    std::cout << str << std::endl;
//                } else {
//                    std::cout << std::endl;
//                }
//
//                static const int buffer_length = 64;
//                char buffer[buffer_length] = {0};
//                CFStringGetCString(identifier, buffer, buffer_length, kCFStringEncodingMacRoman);
//                std::cout << buffer << std::endl;
//                std::memset(buffer, 0, buffer_length);
//
//                CFRelease(identifier);
//            }
//
//            CFURLRef url = CFBundleCopyExecutableURL(bundle);
//            if (url) {
//                CFStringRef urlstr = CFURLGetString(url);
//                if (urlstr) {
//                    const char* str = CFStringGetCStringPtr(urlstr, kCFStringEncodingMacRoman);
//                    if (str) {
//                        std::cout << "url:" << str << std::endl;
//                    } else {
//                        std::cout << std::endl;
//                    }
//                } else {
//                    std::cout << std::endl;
//                }
//                CFRelease(url);
//            }
//
//        }
//    }
    
    
    

    
//    CFBundleCreateBundlesFromDirectory(kCFAllocatorDefault, mainBundleUrl, CFSTR("bundle"));
    CFRelease(mainBundleUrl);
//    CFRelease(mainBundle);
//    CFRelease(maindir);
//    CFRelease(allbundles);
    return mainBundle;
}
