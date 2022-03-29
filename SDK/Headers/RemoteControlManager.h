//
//  RemoteChatManager.h
//  SDK
//
//  Created by SOTI Inc. on 2014-04-29.
//  Copyright (c) 2015 SOTI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/*!
    @typedef RemoteSessionStatus
    @discussion Type used to represent the remote session connection status as a result of connecting or disconnecting.
    @availability v11
 */
typedef NSString* RemoteSessionStatus;

/*!
    @const kRemoteSessionStatusStarted
    Predefined RemoteSessionStatus type denoting remote session is started.
    @availability v11
 */
extern const RemoteSessionStatus kRemoteSessionStatusStarted;

/*!
    @const kRemoteSessionStatusStopped
    Predefined RemoteSessionStatus type denoting remote session is stopped.
    @availability v11
 */
extern const RemoteSessionStatus kRemoteSessionStatusStopped;

/*!
    @const kRemoteSessionStatusBroken
    Predefined RemoteSessionStatus type denoting remote session is broken.
    @availability v11
 */
extern const RemoteSessionStatus kRemoteSessionStatusBroken;

/*!
    @const kRemoteSessionStateChanged
    Predefined NSString* type denoting the state of the remote session has been changed.
    @availability v11
 */
extern NSString * const kRemoteSessionStateChanged;

/*!
    @const kRemoteSessionChatMessageReceived
    Predefined NSString* type denoting the a remote session chat message has been received.
    @availability v11
 */
extern NSString * const kRemoteSessionChatMessageReceived;

/*!The RemoteChatMessage object stores all details relating to a single remote chat message.*/
@interface RemoteChatMessage : NSObject

/*!
    The message text.
    @availability v11
 */
@property (strong, nonatomic) NSString *message;

/*!
    A Boolean value denoting if the message is coming from the Web Console (remote) or if the message is from the agent (not remote).
    @availability v11
 */
@property (nonatomic) BOOL isRemote;

/*!
    A Boolean value denoting whether or not the message is read.
    @availability v11
 */
@property (nonatomic) BOOL isRead;



@end

/*!The RemoteControlManager singleton object defines an interface to manage remote chat messages.*/
@interface RemoteControlManager : NSObject

/*!
    An array holding all the RemoteChatMessage instances for the current remote session.
    @availability v11
 */
@property (strong, nonatomic) NSMutableArray *messagesPerSession;

/*!
    Gets the singleton instance of the remote control manager.
    @return The singleton instance of RemoteControlManager.
    @availability v11
 */
+ (id)defaultRemoteControlManager;

/*!
    Sends a remote chat message to the administrator's Web Console
    @param message
        The chat message text to send to the Web Console.
    @availability v11
 */
- (void)sendRemoteChatMessage:(NSString *)message;

/*!
    Gets the count of unread remote chat messages.
    @return The number of unread remote chat messages.
    @availability v11
 */
- (NSInteger)getUnreadRemoteMessageCount;


/*!
 Check if remote control is active.
 @return YES : if active.
 @return NO : if Not Active.
 @availability v14
 */
@property (nonatomic,readonly) BOOL isRemoteActive;

-(void)restartCapture;
@end
