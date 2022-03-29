//
//  ScreenRecorder.h
//  SampleCode
//
//  Created by Vidushi Dhiman on 29/12/17.
//  Copyright © 2017 Vidushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>
#import <CoreMedia/CoreMedia.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreImage/CoreImage.h>
#import <CoreGraphics/CoreGraphics.h>

/*!
 @const kRemoteSessionStarted
 Predefined NSString* type denoting the state of the remote session has been started.
 */
extern NSString * const kRemoteSessionStarted;

/*!
 @const kRemoteSessionStopped
 Predefined NSString* type denoting the state of the remote session has been stopped.
 */
extern NSString * const kRemoteSessionStopped;


@interface ScreenRecorder : NSObject

/*
 This property can be set by extension and will be shared with App. App can use directly or can read using shared groupId with key ’isRecordingInProgress’.
 
 Set YES :
 When user start , resume screen recording
 set NO :
 when user pause , stop or finished recording.
 */
@property(nonatomic,assign) BOOL isRecordingInProgress;

/*
 This property can be set by SDK and will be shared with App. App can use directly or can read using shared groupId with key ’isRemoteControlInProgress’.
 
 set YES :
 When remote session start by administrator from MobiControl web console.
 set NO :
 when remote session stop or terminated by administrator.
 */
@property(nonatomic,assign) BOOL isRemoteControlInProgress;

/*
 This property can be set by SDK and will be shared with App. App can use directly or can read using shared groupId with key ’isMCConnectedFromExtension’.
 
 set YES :
 When Connection from server happened.
 set NO :
 when Connection from server disconnects.
 */
@property(readonly,assign) BOOL isMCConnectedFromExtension;

/*
 This property can be set by SDK and will be shared with Extension. Extension can use directly or can read using shared groupId with key ’isMCConnectedFromAgent’.
 
 set YES :
 When Connection from server happened.
 set NO :
 when Connection from server disconnects.
 */
@property(nonatomic,assign) BOOL isMCConnectedFromAgent;

/*
 This property can be set by SDK and will be shared with App. App can use directly or can read using shared groupId with key ’isConfiguredForEnrollment’.
 
 set YES :
 When MobiControl agent extension is configured with the connection settings to connect to the MobiControl server.
 set NO :
 When MobiControl agent extension is not configured with the connection settings to connect to the MobiControl server.
 */
@property(readonly,assign) BOOL isConfiguredForEnrollment;

/*
 This property can be set by extension and will be shared with SDK. SDK can use directly or can read using shared groupId with key ’isYUV’.
 
 */
@property(nonatomic,readonly) BOOL isYUV;

/*
 singleton instance of ScreenRecorder class
 */
+(instancetype)defaultRecorder;


/*
 This method will be used in - (void)processSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType {
 [[ScreenRecorder defaultRecorder] writeSampleBuffer:sampleBuffer];
 
  This method will convert CMSampleBufferRef to CGImageRef for SDK
 */
-(void)writeSampleBuffer:(CMSampleBufferRef)sampleBuffer;


/*
 This method detects whether run target is App Extension or iOS App.
 */
-(BOOL) isAppExtension;
@end


