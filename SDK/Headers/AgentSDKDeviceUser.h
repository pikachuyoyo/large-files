//
//  AgentSDKDeviceUser.h
//  SOTI MobiControl SDK
//
//  Created by Soti Inc. on 2012-08-24.
//  Copyright 2013 SOTI Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!The AgentSDKDeviceUser object defines an interface for dealing with user and company information. */
@interface AgentSDKDeviceUser : NSObject


/*!
    Gets the device user object.
    @return A new autoreleased device config object.
    @availability v11
*/
+ (AgentSDKDeviceUser*) user;

/*!
    The location at which the company's icon is stored on the device.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *companyIconImageLocationOnDevice;

/*!
    The name of the company the user belongs to.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *companyName;

/*!
    The main phone number of the company the user belongs to.
    @availability v11
 */

@property(nonatomic,readonly) NSString           *companyPhone;

/*!
    The support phone number of the company the user belongs to.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *companySupportPhone;

/*!
    The support email of the company the user belongs to.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *companySupportEmail;

/*!
    The identifier of the employee.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *employeeID;
// this is custom data from DevUser

/*!
    The users department within the company.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *department;
// "   "

/*!
    The users phone number.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *phoneNumber;

/*!
    The users first name.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *firstName;

/*!
    The users last name.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *lastName;

/*!
    The username of the user.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *userName;

/*!
    The user's principal name(UPN).
    @availability v11
 */
@property(nonatomic,readonly) NSString           *UPN;

/*!
    The user's domain name.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *domainName;

/*!
    The user's email address.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *emailAddress;

-(NSInteger) cVal; //Reserved for future use.

/*!
    Uploads log file to FTP support site.
    @availability v11
 */
-(void) uploadLogFile;

/*!
    Set to YES if Enrollment is prohibited.
    @availability v11
 */
- (BOOL) preventUnenrollment;

@end
