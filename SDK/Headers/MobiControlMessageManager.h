//
//  MobiControlMessageManager.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on 2014-03-07.
//  Copyright (c) 2015 SOTI. All rights reserved.
//

#import <Foundation/Foundation.h>
//
@class MobiControlMessageCenterMessage;

/*!*/
#define kMessagesStateChangedNotification @"kMessagesStateChangedNotification"


//
/*!The MobiControlMessageManager singleton object defines an interface to manage non-chat messages.*/
@interface MobiControlMessageManager : NSObject
//
/*!
    Gets the singleton instance of the message manager.
    @return The singleton instance of MobiControlMessageManager.
    @availability v11
 */
+ (id)defaultMobiControlMessageManager;
//

/*!
    Gets all messages.
    @return An array of all the MobiControlMessageCenterMessage instances.
    @availability v11
 */
- (NSArray *)getAllMobiControlMessageCenterMessages;

/*!
    Deletes a specific message.
    @param message 
        The message to be deleted.
    @return A Boolean value denoting whether or not the deletion was successful.
    @availability v11
 */
- (BOOL)deleteMessage:(MobiControlMessageCenterMessage *)message;

/*!
    Deletes all messages.
    @availability v11
 */
- (void)deleteAllMessages;

/*!
    Marks a specific message as read.
    @param message
        The message to be marked as read.
    @availability v11
 */
- (void)markMessageAsRead:(MobiControlMessageCenterMessage *)message;

/*!
    Marks all messages as read.
    @availability v11
 */
- (void)markAllMessagesAsRead;

@end
