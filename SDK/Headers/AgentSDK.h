//
//  AgentSDK.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on Oct 10, 2013.
//  Copyright 2015 SOTI Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#ifdef MAC_LIBRARY
#define NOMINMAX
#import <Cocoa/Cocoa.h>
#import <CoreLocation/CoreLocation.h>
#elif IOS_LIBRARY
#import <UIKit/UIKit.h>
#endif

#import "AgentSDKCertificate.h"

//
@class AgentLogEvent;
//

/*!
    @typedef kAppConfigResults
    @discussion Used to obtain Deployment Server connection parameters.
    @constant KAppConfigDeviceLessThanIOS7
        Device iOS version does not support App Config. The SDK-enabled App must be installed on iOS 7 and higher.
    @constant KAppConfigInitiationSuccess
        Device connected successfully using App Config.
    @constant KAppConfigNotFound
        Device's App Config was not found. The SDK-enabled might not have been installed via the MobiControl App Catalog, or the Configuration Command was not provided in the App Catalog entry.
    @constant kAppConfigUnknownError
        Unknown error occurred with App Config.
    @constant kAppConfigUnknownState
        Device's App Config has unknown State.
    @availability v11
 */
typedef enum KAppConfigResults : NSInteger {
    KAppConfigDeviceLessThanIOS7,
    KAppConfigInitiationSuccess,
    KAppConfigNotFound,
    kAppConfigUnknownError,
    kAppConfigUnknownState,
} KAppConfigResults;

/*!
    @typedef EnrollmentState
    @discussion Type used to represent current enrollment status.
    @constant kEnrollmentStateNotEnrolled
        Device is not enrolled.
    @constant kEnrollmentStateEnrolling
        Device is currently enrolling.
    @constant kEnrollmentStateEnrolled
        Device is enrolled.
    @availability v11
 */
typedef enum {
    kEnrollmentStateNotEnrolled,
    kEnrollmentStateEnrolling,
    kEnrollmentStateEnrolled
} EnrollmentState;

/*!
    @typedef AuthenticationType
    @discussion Type used to represent current enrollment authentication status.
    @constant kAuthenticationTypeSimple
        Static password as defined in the corresponding Add Device Rule.
    @constant kAuthenticationTypeAD
        Directory service (LDAP) credentials of the authenticating user as defined in the corresponding Add Device Rule.
    @availability v12
 */
typedef enum {
    kAuthenticationTypeSimple,
    kAuthenticationTypeAD,
    kAuthenticationTypeToken
} AuthenticationType;

/*!
    @typedef APP_CAPABILITIES
    @discussion Type used to represent the app's required capabilities.
    @constant kAPP_CAPABILITIES_ALL
        All app capabilities are required
    @constant kAPP_CAPABILITIES_REMOTEVIEW
        Only Remove View capability is required
 */

typedef enum {
    kAPP_CAPABILITIES_ALL = 0xFFFFFFFF,
    kAPP_CAPABILITIES_REMOTEVIEW = 1,
}APP_CAPABILITIES;

/*!
    @typedef EnrollmentStatus
    @discussion Type used to represent current enrollment status that is always sent after connecting to Deployment Server.
    @const kEnrollmentStatusEnrolled
    Predefined EnrollmentStatus type denoting the SDK-enabled App is currently enrolled.
    @const kEnrollmentStatusRequired
    Predefined EnrollmentStatus type denoting the SDK-enabled App must enroll.
    @const kEnrollmentStatusFailedOsVersion
    Predefined EnrollmentStatus type denoting the OS version of the device is incompatible with the filters defined in the Add Device Rule.
    @const kEnrollmentStatusInvalidId
    Predefined EnrollmentStatus type denoting an invalid enrollment ID was specified.
    @const kEnrollmentStatusValidId
    Predefined EnrollmentStatus type denoting a valid enrollment ID was specified.
    @availability v11
 */
typedef NSString* EnrollmentStatus;
extern const EnrollmentStatus kEnrollmentStatusEnrolled;
extern const EnrollmentStatus kEnrollmentStatusRequired;
extern const EnrollmentStatus kEnrollmentStatusFailedOsVersion;
extern const EnrollmentStatus kEnrollmentStatusInvalidId;
extern const EnrollmentStatus kEnrollmentStatusValidId;

 /*!
    @typedef ConnectionStatus
    @discussion Represents the connection status between the SDK-enabled App and the Deployment Server as a result of connecting or disconnecting.
    @const kConnectionStatusOK
    Predefined ConnectionStatus type denoting the SDK-enabled App is successfully connected.
    @const kConnectionStatusFailed
    Predefined ConnectionStatus type denoting the SDK-enabled App failed to connect to Deployment Server.
    @const kConnectionStatusUnverified
     Predefined ConnectionStatus type denoting the SDK-enabled App failed to verify the Deployment Server certificate and requires user to explicity trust and continue with the connection attempt.
    @const kConnectionStatusUntrusted
    Predefined ConnectionStatus type denoting SDK-enabled App failed to verify the Deployment Server certificate and will not proceed with the connection.
    @const kConnectionStatusDisconnected
    Predefined ConnectionStatus type denoting the SDK-enabled App is now disconnected.
    @const kConnectionStatusRequireSimpleAuth
    Predefined ConnectionStatus type denoting the SDK-enabled App requires Simple Authentication.
    @const kConnectionStatusTokenFailureRequireSimpleAuth
    Predefined ConnectionStatus type denoting SDK-enabled App agent requires Simple Authentication after token authentication failure.
    @const kConnectionStatusRequireLoginAuth
    Predefined ConnectionStatus type denoting SDK-enabled App agent requires Directory Services Authentication.
    @const kConnectionStatusTokenFailureRequireADAuth
    Predefined ConnectionStatus type denoting the SDK-enabled App requires Directory Service Authentication after token authentication failure.
    @const kConnectionStatusFailedLoginAuth
    Predefined ConnectionStatus type denoting Login Authentication failed.
    @availability v11
 */
typedef NSString* ConnectionStatus;
extern const ConnectionStatus kConnectionStatusOK;
extern const ConnectionStatus kConnectionStatusFailed;
extern const ConnectionStatus kConnectionStatusUnverified;
extern const ConnectionStatus kConnectionStatusUntrusted;
extern const ConnectionStatus kConnectionStatusDisconnected;
extern const ConnectionStatus kConnectionStatusRequireSimpleAuth;
extern const ConnectionStatus kConnectionStatusFailedSimpleAuth;
extern const ConnectionStatus kConnectionStatusTokenFailureRequireSimpleAuth;
extern const ConnectionStatus kConnectionStatusRequireLoginAuth;
extern const ConnectionStatus kConnectionStatusTokenFailureRequireADAuth;
extern const ConnectionStatus kConnectionStatusFailedLoginAuth;
extern const ConnectionStatus kConnectionStatusError;
extern const ConnectionStatus kConnectionStatusFailedAll;
/*!
    @typedef RemoteViewStatus
    @discussion Type used to represent the remote view connection status as a result of connecting or disconnecting.
    @const kRemoteViewStatusStarted
    Predefined RemoteViewStatus type denoting remote view is started.
    @const kRemoteViewStatusStopped
    Predefined RemoteViewStatus type denoting remote view is stopped.
    @const kRemoteViewStatusBroken
    Predefined RemoteViewStatus type denoting remote view is broken.
    @availability v11
 */
typedef NSString* RemoteViewStatus;
extern const RemoteViewStatus kRemoteViewStatusStarted;
extern const RemoteViewStatus kRemoteViewStatusStopped;
extern const RemoteViewStatus kRemoteViewStatusBroken;

/*!
    @typedef TermsAndConditionStatus
    @discussion Info regarding what the Deployment Server is telling the SDK-enabled App to do about Terms and Conditions.
    @const kTermsAndConditionsStatusPending
    Predefined TermsAndConditionsStatus type denoting new pending Terms and Conditions have been sent by Deployment Server which need to be accepted or rejected.
    @const kTermsAndConditionsStatusNotRequired
    Predefined TermsAndConditionsStatus type denoting existing Terms and Conditions have been cancelled.
    @const kTermsAndConditionsStatusAccepted
    Predefined TermsAndConditionsStatus type denoting Terms and Conditions have been accepted.
    @const kTermsAndConditionsStatusRejected
    Predefined TermsAndConditionsStatus type denoting Terms and Conditions have been rejected.
    @availability v11
 */
typedef NSString* TermsAndConditionStatus;
extern const TermsAndConditionStatus kTermsAndConditionStatusPending;
extern const TermsAndConditionStatus kTermsAndConditionStatusNotRequired;
extern const TermsAndConditionStatus kTermsAndConditionStatusAccepted;
extern const TermsAndConditionStatus kTermsAndConditionStatusRejected;

/*! Implement this delegation protocol to receive feedback on core events for your registered delegates with AgentSdkCore.*/
@protocol AgentSdkCoreProtocol <NSObject>

@required

@optional

/*!
    Called as a result of connectToDS operation. Disconnect will be sent if already connected.
    @param status
        Contains connection status.
    @param error
        Contains error message containing brief description in case of connection failure.
    @availability v11
 */
- (void) connectionStatusUpdate:(ConnectionStatus)status errorMsg:(NSString*)error;

/*!
     Called from Deployment Server when Terms and Conditions are updated.
    @param status
        Contains Terms and Conditions Status. Codes used here are Accepted, Pending and Cancelled.
    @param link
        Contains URL for user to visit for acceptance of Terms and Conditions if status is Accepted or Pending, else parameter will be nil.
    @param acceptedDate
        Contains Date of acceptance if status is Accepted.
    @availability v11
 */
- (void) termsAndConditionStatusUpdate:(TermsAndConditionStatus)status tcLink:(NSString *)link tcAcceptedDate:(NSDate *)acceptedDate;

/*!
    Called when administrator starts or stops a remote view session via Web Console.
    @param status
        Contains current status of remote view.
    @availability v11
 */
- (void) remoteViewStatusUpdate:(RemoteViewStatus)status;
/*!
 Called when a mouse event is recieved from the administrator via Web Console while taking RC. This is only valid if remote view session has started.
 @param info
 Constains cordiname x, y and type .
 cordiname : x,y (position where clicked) , type : PKK_MOUSE_EVENTS
 @availability v14.1
 */
- (void)mouseEvent:(NSDictionary *)info;


/*!
 Called when a key event is recieved from the administrator via Web Console while taking RC. This is only valid if remote view session has started.
 @param info
 Constains keyCoode and keyStatus.
 keyCode : a, b, c etc , keyStatus : Shift, Command, Control , Shift+Command etc
 @availability v14.1
 */
- (void)injectingChar:(NSDictionary *)info;

/*!
    Called when a chat message is recieved from the administrator via Web Console. This is only valid if remote view session has started.
    @param message
        Constains message sent by admin during remote chat.
    @availability v11
 */
- (void) chatMessageReceived:(NSString*)message;

/*! 
    Called when an event occurs from SDK. This method is meant for debugging.
    @param agentLogEvent 
        Contains event log message from SDK.
    @availability v11
 */
- (void) eventLog:(AgentLogEvent*)agentLogEvent;

/*! 
    Server sent request to wipe app data because device has been deleted from the system. App should delete any state/date and reset itself. After this command, app will be disconnected from server and will be required to enroll again.
    @availability v11
 */
- (void) appWipe;

/*! 
    When the SDK-enabled App receives the application catalog URL, this event is triggered. The message is only used for BACKWARDS Compabilitiy with pre-version 10 servers. To get the actual post 10 app catalog, the API is part of the app catalog API. This function is here becuase it is of special case needs to access to special functions.
    @param message
        Contains URL to web app catalog. This is only used for backwards compatibility with pre-version 10 servers.
    @availability v11
 */
- (void) appCatalogLinkReceived:(NSString *)message;

/*!
    Called when the device name is updated.
    @param deviceName
        Contains updated device name
    @availability v11
 */
- (void) deviceNameUpdate:(NSString *)deviceName;

/*!
    Called when the agent profile setting is changed.
    @param key
        Contains key for profile setting
    @param value
        Contains new value for changed profile setting
    @availability v11
 */
- (void) agentProfileSetting:(NSString *)key changed:(NSString *)value;

@end

/*! The AgentLogEvent class declares a programmatic interface for an object that stores agent event logs. */
@interface AgentLogEvent : NSObject <NSCoding> //  so it can be serialized/deserialized
{
@private
    NSString *message;
    NSDate *date;
}

/*!
    Message in agent event log.
 */
@property (nonatomic, strong) NSString *message;

/*!
    Date of agent event.
 */
@property (nonatomic, strong) NSDate *date;

@end

/*! The AuthenticationData class declares a programmatic interface for an object that stores a username and a password for authentication.*/
@interface AuthenticationData : NSObject

/*! username is required for AD authentication. */
@property (nonatomic, strong) NSString *authenticationUsername;
/*! password is required for either Simple or AD authentication. */
@property (nonatomic, strong) NSString *authenticationPassword;
/*! password is required for either Simple or AD authentication. */
@property (nonatomic, strong) NSString *authenticationToken;

@end
//
@interface AgentSdkCore : NSObject


@property (atomic, strong) NSString *agentURI;


/*!
    A Boolean value denoting the availability of the App Configuration.
 */
@property (readonly, atomic) BOOL appConfigAvailable;


/*!
 Registers the delegate for this class.
 An object that adheres to the AgentSdkCoreProtocol.
 @availability v11
 */
- (void) connectToDSManually;
/*!
    Gets singleton of AgentSdkCore.
    @return The AgentSdkCore singleton.
    @availability v11
 */
+ (AgentSdkCore*) getInstance;

/*!
    Registers the delegate for this class.
    @param delegate
        An object that adheres to the AgentSdkCoreProtocol.
    @availability v11
 */
- (void) registerDelegate:(id<AgentSdkCoreProtocol>)delegate;

/*! 
    Deregisters the delegate from this class.
    @param delegate
        An object that adheres to the AgentSdkCoreProtocol.
    @availability v11
 */
- (void) deRegisterDelegate:(id<AgentSdkCoreProtocol>)delegate;

/*! 
    Checks if the SDK-enabled App is configured with Deployment Server connection parameters.
 
    If return value is true, connectToDS will succeed. Otherwise, connectToDSUsingAppConfig should be called to obtain the connnection parameters.
    @return A Boolean value denoting whether or not the SDK-enabled App is configured with Deployment Server connection parameters.
    @availability v11
 */
- (bool) isConfiguredWithDeploymentServer;

/*! 
    Gets and stores Deployment Server connection parameters provided by MobiControl, and attempts a connection to the Deployment Server. Requires that the App be installed by MobiControl's App Catalog as "Managed". See the "MobiControl SDK for iOS Integration Guide" for the configuration syntax and additional details.
    @return The App configuration result of the attempt.
    @availability v11
 */
- (KAppConfigResults) connectToDSUsingAppConfig;

/*! 

    Attempts to connect to the Deployment Server using the stored server address. A connection is automatically established when the application is brought to the foreground so this method need only be called if the connection is lost or intentionally disconnected. The delegate connectionStatusUpdate will be called upon completion.
    @availability v11
 */
- (void) connectToDS;

/*! 
    Disconnects from the Deployment Server.
    @availability v11
 */
- (void) disconnect;

/*! 
    Checks if the SDK-enabled App is connected to the Deployment Server.
    @return A Boolean value denoting whether or not the SDK-enabled App is connected to the Deployment Server.
    @availability v11
 */
- (BOOL) isConnected;


- (NSString *)getConnectedServerName;

/*! 
    Gets the current status of the Terms and Conditions. If no Terms and Conditions exist, method will return nil.
    @return The status of the current Terms and Conditions.
    @availability v11
 */
- (TermsAndConditionStatus) getTermsAndConditionStatus;

/*! 
    Gets the URL to the current the Terms and Conditions.
    @return The URL to the current Terms and Conditions.
    @availability v11
 */
- (NSString *) getTermsAndConditionsLink;

/*! 
    Gets the date when Terms and Conditions were accepted.
    @return The date when Terms and Conditions were accepted.
    @availability v11
 */
- (NSDate *) getTermsAndConditionsAcceptedDate;

/*! 
    Called when the user accepts the current Terms and Conditions.
    @availability v11
 */
- (void) acceptTermsAndConditions;

/*! 
    Called when the user rejects the current Terms and Conditions.
    @availability v11
 */
- (void) rejectTermsAndConditions;

/*! 
    Gets the current enrollment state of the SDK-enabled application.
    @return The current enrollment state of the SDK-enabled application. Will return either Enrolled, Enrolling or Required.
    @availability v11
 */
- (EnrollmentState) getEnrollmentState;

/*! 
    Gets the URL to the application catalog.
    @return The URL to the Application Catalog.
    @availability v11
 */
- (NSString *) getAppCatalogLink;

/*! 
    Get the unverified Deployment Server info (in response to a connectionStatusUpdate with status kConnectionStatusUnverified) in the event trust validation of the server failed.
    @return The unverified Deployment Server information.
    @availability v11
 */
- (NSString *) getUnverifiedDeploymentServerName;

- (NSString *)getFailedDeploymentServerName;

/*!
    Gets the unverfied Deployment Server certificate in the event trust validation of the server failed.
    @return The unverified Deployment Server certificate.
    @availability v11
 */
- (AgentSdkCertificateInfo *) getUnverifiedDeploymentServerCertificate;

/*!
    Saves the user response to an unverified Deployment Server connection (in response to a connectionStatusUpdate with status kConnectionStatusUnverified). Value is remembered for subsequent connection attempts.
    @param isDeploymentServerTrusted
        A Boolean value denoting whether or not the Deployment Server is trusted.
    @availability v11
 */
- (void) setUserResponseToUnverifiedDeploymentServer:(BOOL)isDeploymentServerTrusted;

/*!
    Returns whether the MobiControl administrator has allowed agent unenrollment using the "Advanced Settings > Agent Settings" policy. When un-enrollment is disabled the end user is not able to initiate un-enrollment from the "Device Configuration" screen of the MobiControl agent. An SDK-enabled App may wisht o link similar functionality to this setting. This setting does not prevent an end-user from removing the MobiControl Management Profile from the iOS Settings screen.
    @return A boolean value denoting whether or not un-enrollment is allowed.
    @availability v12
 */
- (BOOL) allowUnenroll;

/*!
    Authenticates client data using a specific authentication type. During a Deployment Server connection attempt ConnectionStatus may indicate a requirement for the SDK-enabled App to authenticate the connection, usually when the authentication token provided in the App Config has expired. If authentication is required the type of authentication will correspond to the Add Device Rule that was initially used for enrollment or, if not found, the default Add Device Rule.
    @param authenticationData
        Contains data that is to be authenticated.
    @param authenticationType
        Contains type of authentication to be carried out.
    @availability v11
 */
- (void)authenticateClient:(AuthenticationData *)authenticationData withType:(AuthenticationType)authenticationType;


/*!
    Used to set the application's required capabilities.
    @param appCapability
        The app's capabilities
    @availability v13.4.0 MR8 or greater OR v14.1.4 or greater
 */
-(void)setAppCapability:(APP_CAPABILITIES)appCapability;


/*!
    iOS SDK could perform some operation(s) (location data collection) at the Background.
    Background Fetch is an API involved here and used by SDK.
    Background Fetch is controlled by an Application (all settings, API calls, etc.).
    A Client is obligated to implement "application: performFetchWithCompletionHandler:" method of the UIApplicationDelegate and delegate the call to the performBackgroundOperation.
    That's to allow SDK to perform backgroung operation(s).
    The operation takes about 3 seconds
    @param completionHandler
        Completion handler - the same as passed to UIApplicationDelegate's method application: performFetchWithCompletionHandler:
 
    @availability v11
 */


#ifdef MAC_LIBRARY
- (void)appAwake;

/*
 This method will be used by Mac for updating location from Mac Agent to Helper daemon
 */
- (void)locationManagerdidUpdateLocations:(NSArray *)locations;
- (void)locationManagerdidFailWithError:(NSError *)error;

#else
- (void) performBackgroundOperation:(void (^)(UIBackgroundFetchResult))completionHandler;
#endif

@end

