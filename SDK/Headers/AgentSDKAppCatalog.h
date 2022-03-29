//
//  AgentSDKAppCatalog.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on 2012-08-30.
//  Copyright 2015 SOTI Inc. All rights reserved.
//


#import <UIKit/UIKit.h>

// NOTE: When doing string comparisons using these constants use isEqualToString selector rather than straight '==' as the values are copied from JSON payload.
/*!
    @const AppTypeConsumer
        Predefined NSString* type denoting a consumer app from the App Store.
    @availability v11
 */
extern const NSString* AppTypeConsumer;
/* = "Consumer"     */

/*!
    @const AppTypeEnterprise
        Predefined NSString* type denoting an enterprise app.
    @availability v11
 */
extern const NSString* AppTypeEnterprise;
/* = "Enterprise"   */

/*!
    @const AppInstallStateNotInstalled
        Predefined NSString* type denoting the app is not installed.
    @availability v11
 */
extern const NSString* AppInstallStateNotInstalled;
/* = "NotInstalled" */

/*!
    @const AppInstallStateInstalling
        Predefined NSString* type denoting the app is installing.
    @availability v11
 */
extern const NSString* AppInstallStateInstalling;
/* = "Installing"   */

/*!
    @const AppInstallStateInstalled
        Predefined NSString* type denoting the app is installed.
    @availability v11
 */
extern const NSString* AppInstallStateInstalled;
/* = "Installed"    */

/*!
    @const AppInstallStateOutOfDate
        Predefined NSString* type denoting the app is out of date.
    @availability v11
 */
extern const NSString* AppInstallStateOutOfDate;
/* = "OutOfDate"    */

/*!
    @const AppPurchaseTypeFree
        Predefined NSString* type denoting the app is free.
    @availability v11
 */
extern const NSString* AppPurchaseTypeFree;
/* = "Free"         */

/*!
    @const AppPurchaseTypePrepaid
        Predefined NSString* type denoting the app has been prepaid for.
    @availability v11
 */
extern const NSString* AppPurchaseTypePrepaid;
/* = "Prepaid"      */

/*!
    @const AppPurchaseTypePaid
        Predefined NSString* type denoting the app must be paid for.
    @availability v11
 */
extern const NSString* AppPurchaseTypePaid;
/* = "Paid"         */

/*
 *  AgentSDKApp
 *
 *  Discussion:
 *      This is information about a single application entry within app catalog. Please note the "Desc" field will be empty/nil when entire application catalog is being fetched,
 *      as the payload can be quite large (upto 4K).  In order to retrieve this "Desc" field, you need to call "requestApp" method to get all fields.
 *
 *  NOTES:
 *        1. These property names *must* exactly match the JSON name from server.
 *        2. The property types must also match the JSON to Objective C mapping for JSONKit library, except that NSNulls are mapped to nils
 *
 */
/*!
    This is information about a single application entry within app catalog. Please note the "Desc" field will be empty/nil when entire application catalog is being fetched, as the payload can be quite large (upto 4K).  In order to retrieve this "Desc" field, you need to call "requestApp" method to get all fields.
    
    Notes:
 
    1. These property names *must* exactly match the JSON name from server.
 
    2. The property types must also match the JSON to Objective C mapping for JSONKit library, except that NSNulls are mapped to nils
 
 */
@interface AgentSDKAppCatalogApplication : NSObject

/*!
    One ot the AppType Constants
    @see AppTypeConsumer
    @see AppTypeEnterprise
    @availability v11
 */
@property(nonatomic,retain) NSString           *Type;
// Is equal to one of the string consts in "AppType" above

/*!
    The name of the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *Name;

/*!
    The version of the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *Version;

/*!
    The identifier for the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *AppID;

/*!
    The vendor of the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *Vendor;

/*!
    The description of the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *Description;
// This field can be empty/nil (see comment above).

/*!
    The URL of the app icon.
    @availability v11
 */
@property(nonatomic,retain) NSString           *IconURL;

/*!
    The URLs of the app screenshots.
    @availability v11
 */
@property(nonatomic,retain) NSArray            *ScreenshotURLs;
// This is an array of NSString*

/*!
    One of the AppPurchaseType constants.
    @see AppPurchaseTypeFree
    @see AppPurchaseTypePrepaid
    @see AppPurchaseTypePaid
    @availability v11
 */
@property(nonatomic,retain) NSString           *PurchaseType;
// Is equal to one of the string consts in "AppPurchaseType" above

/*!
    The price of the app.
    @availability v11
 */
@property(nonatomic,retain) NSNumber           *Price;
// float

/*!
    The currency used for the price of the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *Currency;

/*!
    A boolean denoting whether or not the app is mandatory.
    @availability v11
 */
@property(nonatomic,retain) NSNumber           *Mandatory;
// bool

/*!
    One of the AppInstallState constants
    @see AppInstallStateNotInstalled
    @see AppInstallStateInstalling
    @see AppInstallStateInstalled
    @availability v11
 */
@property(nonatomic,retain) NSString           *InstallState;
// Is equal to one of the string consts "AppInstallState" above

/*!
    The URL to install the app.
    @availability v11
 */
@property(nonatomic,retain) NSString           *InstallURL;

/*!
    A template for the URI if the App is configurable. Being configurable means the application can request a special URI to launch the downloaded app by requesting the App details with the App ID. For example this can be used to fill in server connection properties for the user when launching the app. If the URI is not configurable, this property will be empty.
    @availability v11
 */
@property(nonatomic,retain) NSString           *ConfigurationUriTemplate;

@end

/*!
    This is the Application Catalog returned from the server. Use AgentSDKAppCatalogRequest to fetch this object.
    
    Notes:
    
    1. These property names *must* exactly match the JSON name from server.
 
    2. The property types must also match the JSON to Objective C mapping for JSONKit library, except that NSNulls are mapped to nils.
 */
@interface AgentSDKAppCatalog : NSObject

/*!
    The result of an AppCatalog request from the server. If less than zero, other properties in this class will be nil or empty.
    @availability v11
 */
@property(nonatomic,retain) NSNumber           *Result;

/*!
    The URL of the banner.
    @availability v11-v12
 */
@property(nonatomic,retain) NSString           *BannerURL;

/*!*/
@property(nonatomic,retain) NSString           *Product;

/*!*/
@property(nonatomic,retain) NSString           *AppStoreDisabled;
/*!
 List of Agent SDKAppCatalogueApplication objects. This will be nil/empty if there are no applications.
 */
@property(nonatomic,retain) NSArray            *Apps;
// This is an array of AgentSDKAppCatalogApplication objects. If no apps, this will be nil/empty;

@end


/*!
    This is the parsed JSON data for a Configurable URI.
    @availability v11
 */
@interface AgentSDKAppConfigURIData : NSObject

/*!
    The result of the parsed JSON data. A value of -1 indicates an error.
    @availability v11
 */
@property(nonatomic,retain) NSNumber           *Result;

/*!
    The URI with configured parameters.
    @availability v11
 */
@property(nonatomic,retain) NSString           *ConfigurationUri;

/*!
    The error string from the parsed data.
    @availability v11
 */
@property(nonatomic,retain) NSString           *ErrorString;

@end

/*!
    This is status object returned from the server in response to installApp request.
 
    Notes:
 
    1. These property names *must* exactly match the JSON name from server.
 
    2. The property types must also match the JSON to Objective C mapping for JSONKit library, except that NSNulls are mapped to nils
 */
@interface AppCatalogInstallStatus : NSObject

/*!
 
 */
@property(nonatomic,retain) NSNumber  *Result;
/*!
 
 */
@property(nonatomic,retain) NSString  *ErrorString;
/*!
 
 */
@property(nonatomic,retain) NSString  *RedirectURL;

@end

/*!
    Implement this delegation protocol to receive response results.
 */
@protocol AgentSDKAppCatalogRequestProtocol <NSObject>

@required /* must implement all methods */

/*! 
    Called as a result of requestAppCatalog.
    @param catalog
        Contains the app catalog object.
 
 */
- (void) appCatalogResult:(AgentSDKAppCatalog*)catalog;

/*! 
    Called as a result of requestApp.
    @param app
        Contains the application object.
    @availability v11
*/
- (void) appResult:(AgentSDKAppCatalogApplication*)app;

/*!
    Called as a result of requestAppConfigurationURI
    @param URIData
        Contains the data for a configuratble URI
    @availability v11
 */
- (void) appConfigURIResult:(AgentSDKAppConfigURIData*)URIData;


/*! 
    Called as a result of requestAppInstall
    @param installStatus
        Contains the status of the installation.
    @availability v11
 */
- (void) appInstallResult:(AppCatalogInstallStatus*)installStatus;

/*! 
    Called when request fails e.g. connect timeout/error, failed to parse json, etc.
    @param error    
        Contains the error involved in the request failure.
    @availability v11
 */
- (void) requestFailed:(NSString*)error;

@end

/*!
    This class is used to issue requests.
    
    @warning Multiple simultaneous requests should not be issued from the same request object - if this is needed, instantiate new instances.
 */

@interface AgentSDKAppCatalogRequest : NSObject

/*!
    Initializes a AgentSDKAppCatalogueRequest object while setting a delegate which adheres to the AgentSDKAppCatalogueRequestProtocol.
    @param delegate
        An object which adheres to the AgentSDKAppCatalogueRequestProtocol.
    @availability v11
 */
- (id)initWithDelegate:(id<AgentSDKAppCatalogRequestProtocol>)delegate;

// Fetches the entire application catalog from server asynchronously and calls the delegate's appCatalogResult method when complete
/*!
    Fetches the entire application catalog from server asynchronously and calls the delegate's appCatalogResult method when complete.
    @return A Integer denoting whether or not the request was carries out. A return of 0 indicates no catalogue link was found. A return of 1 indicates the request is being carried out.
    @availability v11
 */
- (NSInteger)requestAppCatalog;

/*!
    Fetches data for a single app from server asynchronously and calls the delegate's appResult method when complete. Used to refresh or poll existing app for updates. Also used to fetch all fields (e.g. "Desc") of the AgentSDKAppCatalogApplication.
    @param app
        Contains the data for a single app.
    @availability v11
 */
- (void)requestApp:(AgentSDKAppCatalogApplication*)app;


/*!
    If configured in the App Catalog entry for the specific App, call this to request a URI that can launch the downloaded app with configuration parameters.
    @param app
        The app to be launched.
    @availability v11
 */
- (void)requestAppConfigurationURI:(AgentSDKAppCatalogApplication*)app;

/*!
    This issues a request to server to install consumer or enterprise app from app catalog.
    @param app
        The app to be installed.
    @availability v11
 */
- (void)requestAppInstall:(AgentSDKAppCatalogApplication*)app;

@end
