//
//  MobiControlMessageCenterMessage.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on 2014-03-11.
//  Copyright (c) 2015 SOTI. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!The MobiControlMessageCenterMessage object stores all details relating to a single non-chat message.*/
@interface MobiControlMessageCenterMessage : NSObject
//
/*!
    The text of the message body.
    @availability v11
 */
@property (nonatomic, strong) NSString *body;

/*!
    The date of the message.
    @availability v11
 */
@property (nonatomic, strong) NSDate *date;

/*!
    A Boolean value denoting whether or not the message is unread.
    @availability v11
 */
@property (nonatomic, assign) BOOL unread;
//
@property (nonatomic, assign) BOOL isSelected;

@end
