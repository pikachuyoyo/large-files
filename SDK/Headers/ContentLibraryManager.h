//
//  ContentLibraryManager.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on 12/19/2013.
//  Copyright (c) 2015 SOTI. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef MAC_LIBRARY
#import <Cocoa/Cocoa.h>
#else
#import <UIKit/UIKit.h>
#endif

#import <CoreData/CoreData.h>

@class ContentFileInfoType;

/*!
    @typedef ContentFileInfoState
    @discussion Used to denote the status of a file.
    @const kNotDownloaded
        The file is not downloaded.
    @const kDownloaded
        The file is downloaded.
    @const kDownloading
        The file is downloading.
    @const kQueued
        The file is queued.
    @const kCorrupted
        The file is corrupted.
    @availability v11
 */
typedef NS_ENUM(NSInteger, ContentFileInfoState)
{
    kNotDownloaded,
    kDownloaded,
    kDownloading,
    kQueued,
    kCorrupted
};

/*!
    The ContentLibraryManagerDelegate protocol defines methods called throughout the file download process.
 */
@protocol ContentLibraryManagerDelegate <NSObject>

@optional
/*!
    Called when a file download request is succesful.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version nuumber of the file.
    @availability v11
 */
- (void)fileDownloadRequestSucceded:(NSInteger)fileId version:(NSInteger)versionNo;

/*!
    Called when a file download request fails.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version nuumber of the file.
    @param error
        The message providing information regarding the error.
    @availability v11
 */
- (void)fileDownloadRequestFailed:(NSInteger)fileId version:(NSInteger)versionNo withError:(NSString *)error;

/*!
    Called when a file dowload fails.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @param error
        The message providing information regarding the error.
    @availability v11
 */
- (void)fileDownloadFailed:(NSInteger)fileId version:(NSInteger)versionNo withError:(NSString *)error;

/*!
    Called when a file finishes downloading.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @availability v11
 */
- (void)fileDownloaded:(NSInteger)fileId version:(NSInteger)versionNo;

/*!
    Called when a file starts downloading.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @availability v11
 */
- (void)fileDownloadStarted:(NSInteger)fileId version:(NSInteger)versionNo;


/*!
    Called repetitively as a file is being downloaded.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @param progress
        The percentage of the file that has been downloaded.
    @availability v11
 */
- (void)fileDownloadProgress:(NSInteger)fileId version:(NSInteger)versionNo progressPercentage:(uint64_t)progress;
/*!
    Called when the info regarding a file changes.
    @availability v11
 */
- (void)fileInfoChanged;

/*!
    Called when the info regarding a file changes.
    @availability v11
 */
- (void)fileInfoChanged:(NSInteger)fileId versionNo:(NSInteger)versionNo;

/*!
    Content Information Snippet.
    @availability v11
 */
- (void)contentInfoSnippet:(NSArray *)contentInfo byPath:(NSString *)path;
- (void)contentInfoScanByPathFinished:(NSString *)path;

/*!
    Get All Content Info instances
    @param contentInfo
        Keep instances of ContentInfoFileType object
    @availability v11
 */
- (void) allContentInfo:(NSArray *)contentInfo;
- (void) getAllContentInfoFinished;

@end

/*!
    The ContentLibraryManager singleton object represents an interface for the storage and retrieval of all content files.
    @availability v11
 */
@interface ContentLibraryManager : NSObject

/*!
    The amount of files in the content library.
    @availability v11
 */
@property (readonly, nonatomic) NSInteger contentInfoCount;

/*!
    The amount of downloaded files in the content library.
    @availability v11
 */
@property (readonly, nonatomic) NSInteger downloadedContentInfoCount;

/*!
    The amount of ineffective downloaded files in the content library.
    @availability v11
 */
@property (readonly, nonatomic) NSInteger ineffectiveDownloadedContentInfoCount;

/*!
    The absolute path of the content library.
    @availability v11
 */
@property (readonly, nonatomic) NSString *contentLibraryAbsolutePath;


/*!
 The absolute path of the File Sync Items.
 */
@property (readonly, nonatomic) NSString *dataPath;

/*!
    Registers the delegate for this class.
    @param delegate
        An object that adheres to the ContentLibraryManagerDelegate protocol.
    @availability v11
 */
- (void)registerDelegate:(id<ContentLibraryManagerDelegate>)delegate;

/*!
    Deregisters the delegate from this class.
    @param delegate
        An object that adheres to the ContentLibraryManagerDelegate protocol.
    @availability v11
 */
- (void)deRegisterDelegate:(id<ContentLibraryManagerDelegate>)delegate;

/*!
    Gets singleton instance of the content libray manager.
    @return Singleton of ContentLibraryManager
    @availability v11
 */
+ (ContentLibraryManager *)instance;

/*!
    Gets contents of a certain path.
    @param path
        The path of the folder from which to get the contents.
    @param isRecursive
        A Boolean value denoting whether or not to also step into subfolders and return their contents as subarrays.
    @return The array of ContentFileInfoType instances that represent content of a folder py path.
    @availability v11
 */
- (NSArray *)getContentsByPath:(NSString *)path recursive:(BOOL) isRecursive;
/*!
    Gets contents of a certain path.
    @param path
        The path of the folder from which to get the contents.
    @param isRecursive
        A Boolean value denoting whether or not to also step into subfolders and return their contents as subarrays.
    @return The number of files being returned.
    @availability v11
 */
- (NSInteger)getContentsAsynchronouslyByPath:(NSString *)path recursive:(BOOL) isRecursive;

/*!
    @return Array of File Sync items
    @availability v11
 */
- (NSArray *)getFileSyncRootItem;

/*!
    Gets ContentFileInfoType instances of all available content info files.
    @return An array of all ContentFileInfoType instances in storage. For files that have more than one version, the latest version is returned.
    @availability v11
 */
- (NSArray *)getAllContentInfo;

/*!
    Removes all content info files.
    @return NO in a case if operation failed.
    @availability v11
 */
- (BOOL)removeAllContentInfo;

/*!
 A Boolean value denoting whether or not Asynchronous operation of getting contents from given path is completed.
 */
@property (assign, atomic) BOOL isAsynchronousOperationFinished;
/*!
 Number of versioned files which are not the latest version. it will help in calculating total number of files
 */
@property (nonatomic) NSInteger versionedFilesCount;

/*!
    Gets the list of all the categories for all the content files.
    @return An array of all categories as NSString* instances.
    @availability v11
 */
- (NSArray *)getAllCategories;

/*!
    Gets the content info for a specific file and version.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @return The ContentFileInformation instance for the file and version if it exists.
    @availability v11
 */
- (ContentFileInfoType *)getContentInfoByFileId:(NSNumber *)fileId andVersion:(NSNumber *)versionNo;


/*!
    Gets list of ContentFileInfoType instances. Each of them represent corresponding version.
    @param fileId
        The identifier of the file.
    @return An array of ContentFileInfoType instances for all the versions of the file.
    @availability v11
 */
- (NSArray *)getAllContentInfoVersions:(NSNumber *)fileId;

/*!
    Saves content file info to data storage.
    @param contentFileInfo
        The ContentFileInfoType instance to be saved.
    @availability v11
 */
- (void)saveContentInfo:(ContentFileInfoType *)contentFileInfo;


/*!
    Removes particular File Version form File system. Only content removed - item itself stays alive.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @return NO in a case if operation failed.
    @availability v11
 */
- (BOOL)deleteContentInfoByFileId:(NSNumber *)fileId andVersion:(NSNumber *)versionNo;

/*!
    Gets a file info state of a file version.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @return The state of a specific file version.
    @see ContentFileInfoState
    @availability v11
 */
- (ContentFileInfoState)getContentFileInfoStateByFileId:(NSNumber *)fileId andVersion:(NSNumber *)versionNo;

/*!
    Requests to download a specific file version.
    @param fileId
        The identifier of the file.
    @param versionNo
        The version number of the file.
    @return NO in a case if operation failed.
    @availability v11
 */
- (BOOL)requestToDownloadFileByFileId:(NSNumber *)fileId andVersion:(NSNumber *)versionNo;


/*!
    Requests to download all latest versions of non-mandatory files.
    @return NO in a case if operation failed.
    @availability v11
 */
- (BOOL)requestToDownloadAllFiles;

-(BOOL)deleteAllDBStore;

-(NSArray*)getAllContentFiles;
-(NSInteger)filterFilesCount:(NSArray *)filters;

@end
