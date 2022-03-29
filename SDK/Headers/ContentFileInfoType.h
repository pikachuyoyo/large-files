//
//  ContentFileInfoType.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on 2/26/2014.
//  Copyright (c) 2015 SOTI. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!The ContentFileInfoType object stores all details relating to a single content file. */
@interface ContentFileInfoType : NSObject 

/*!
    The expiration date of the file.
    @availability v11
 */
@property (nonatomic, retain) NSDate *expirationDate;

/*!
    The date at which the file was last modified.
    @availability v11
 */
@property (nonatomic, retain) NSDate *lastModifiedDate;

/*!
    The date when the file becomes available.
    @availability v11
 */
@property (nonatomic, retain) NSDate *effectiveDate;

/*!
    The date the file was created.
    @availability v11
 */
@property (nonatomic, retain) NSDate *creationDate;


/*!
    The description of the file.
    @availability v11
 */
@property (nonatomic, retain) NSString *fileDescription;

/*!
    The friendly name for the file.
    @availability v11
 */
@property (nonatomic, retain) NSString *friendlyFileName;

/*!
    The physical full name for the file.
    @availability v11
 */
@property (nonatomic, retain) NSString *physicalFullFileName;

/*!
    The source name for the file.
    @availability v11
 */
@property (nonatomic, retain) NSString *sourceFileName;

/*!
    The user-modifiable notes regarding the file.
    @availability v11
 */
@property (nonatomic, retain) NSString *userNotes;


/*!
    A Boolean value denoting whether or not to allow copying of the file.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *allowCopy;

/*!
    A Boolean value denoting whether or not to allow sharing of the file.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *allowShare;

/*!
    The connection types over which file download is available over.
    @see AGENT_SDK_CONTENT_MGMT_CONN_TYPE_NONE
    @see AGENT_SDK_CONTENT_MGMT_CONN_TYPE_WIFI
    @see AGENT_SDK_CONTENT_MGMT_CONN_TYPE_CELLULAR
    @see AGENT_SDK_CONTENT_MGMT_CONN_TYPE_ROAMING
    @availability v12
 */
@property (nonatomic, retain) NSNumber *availableOverConnectionTypesNative;

/*!
    The identifier of the file.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *fileId;

/*!
    The size of the file.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *fileSize;

/*!
    A Boolean value denoting whether or not the file of it's latest version.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *isLatestFileVersion;

/*!
    A Boolean value denoting whether or not the file is considered new.
    The field is not controlled/changed/modified by SDK layer somehow. Just keeps this value at the storage.
    It's NO by default.
    Client is responsible for changing the value.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *isNew;

/*!
    A Boolean value denoting whether or not the file is on demand.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *isOnDemand;

/*!
    The version number of the file.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *versionNo;

/*!
    The attributes of a file, e.g. readonly, directory, normal, etc.
    @availability v11
 */
@property (nonatomic, retain) NSNumber *fileAttributes;

/*!
    The list of categories the file falls under.
    @availability v11
 */
@property (nonatomic, retain) NSArray *categories;

/*!
    A Boolean value denoting whether or not the file is in fact a directory of files.
    @availability v11
 */
@property (nonatomic, readonly) BOOL isDirectory;

/*!
    File download status.
    @availability v11
 */
@property (nonatomic, retain) NSNumber * fileStatus;

@end
