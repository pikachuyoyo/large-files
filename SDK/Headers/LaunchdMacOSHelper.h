//
//  LaunchdMacOSHelper.h
//  AgentSDK
//
//  Created by Harendra Singh on 05/12/17.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>

@protocol CaptureProtocol <NSObject>
-(void)grabScreenShot:(void (^)(NSImage * ))reply;
@end

@interface LaunchdMacOSHelper : NSObject
+ (id)sharedInstance;
-(void)grabScreenShot:(void (^)(NSImage * ))reply;
@property(nonatomic, assign) id <CaptureProtocol> delegate;
@end
