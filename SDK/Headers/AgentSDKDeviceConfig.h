//
//  AgentDeviceConfig.h
//  SOTI MobiControl SDK
//
//  Created by SOTI Inc. on 2012-08-21.
//  Copyright 2015 SOTI Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef MAC_LIBRARY
#import <Cocoa/Cocoa.h>
#else
#import <UIKit/UIKit.h>
#endif

/*!The AgentSDKDeviceConfig object defines an interface for retrieving key device information.*/
@interface AgentSDKDeviceConfig : NSObject

/*!
    Gets the device config object.
    @return A new autoreleased device config object.
    @availability v11
 */
+ (AgentSDKDeviceConfig*) config;

/*!
    The name of the device. Taken from UIDevice for convenience.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *name;

/*!
    The model of the device. Taken from UIDevice for convenience.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *model;

/*!
    The current version of the operating system. Taken from UIDevice for convenience.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *systemVersion; // iOS version


#ifdef MAC_LIBRARY

/*!
 The battery state for the device i.e. Taken from MacDevice for convenience.
 @availability v14.1
 */
@property(nonatomic,readonly) int batteryState;
@property(nonatomic,assign) CGSize displaySize;

#elif IOS_LIBRARY
/*!
 The battery state for the device i.e. Taken from UIDevice for convenience.
 @availability v11
 */
@property(nonatomic,readonly) UIDeviceBatteryState batteryState;
#endif



/*!
    The battery charge level for the device. Taken from UIDevice for convenience.
    @availability v11
 */
@property(nonatomic,readonly) float              batteryLevel;

/*!
    The universal unique identifier (UUID) of the device. This can be the iOS Device UDID or some other UUID.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *deviceID;

/*!
    The version of the agent, e.g., "9.02.3453".
    @availability v11
 */
@property(nonatomic,readonly) NSString           *agentVersion;

/*!
    A Boolean value denoting whether or not the Terms and conditions have been accepted.    
    @availability v11
 */
@property(nonatomic,readonly) BOOL               tcAccepted;

/*!
    A Boolean value denoting whether or not the device has been jailbroken.
    @availability v11
 */
@property(nonatomic,readonly) BOOL               jailBroken;

/*!
    A Boolean value denoting whether or not a wifi network is currently available. This is mutually exclusive with @link cellularNetworkReachable @/link.
    @availability v11
 */
@property(nonatomic,readonly) BOOL               wifiNetworkReachable;


@property(nonatomic,readonly) BOOL               isNetworkReachable;


/*!
    A Boolean value denoting whether or not a cellular network is currently available. This is mutually exclusive with @link wifiNetworkReachable @/link.
    @availability v11
 */
@property(nonatomic,readonly) BOOL               cellularNetworkReachable;

/*!
    The IP address of the wifi connection.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *wifiIpAddress;


/*!
 The IP address of the Ethernet connection.
 @availability v11
 */
@property(nonatomic,readonly) NSString           *ethernetAddress;

/*!
    The MAC address of the wifi connection.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *wifiMacAddress;

/*!
    The IP address of the cellular connection.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *cellularIpAddress;

/*!
    The carrier network of the subscriber based on the currently installed SIM. If no SIM is installed, this property will return nil.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *subscriberCarrierNetwork;

/*!
    The mobile country code(MCC) of the subscriber's carrier based on the currently installed SIM. If no SIM is installed, this property will return nil.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *subscriberMCC;

/*!
    The mobile network code(MNC) of the subscriber's carrier based on the currently installed SIM. If no SIM is installed, this property will return nil.
    @availability v11
 */
@property(nonatomic,readonly) NSString           *subscriberMNC;

/*!
    The free memory of the device in bytes.
    @availability v11
 */
@property(nonatomic,readonly) uint64_t           freeMemory;

/*!
    The total memory of the device in bytes.
    @availability v11
 */
@property(nonatomic,readonly) uint64_t           totalMemory;

/*!
    The free storage space of the device in bytes.
    @availability v11
 */
@property(nonatomic,readonly) double           freeStorageSpace;

/*!
    The total storage space of the device in bytes.
    @availability v11
 */
@property(nonatomic,readonly) double           totalStorageSpace;


/*!
 The rssi of the network.
 @availability v14.3
 */
@property(nonatomic,readonly) long           rssi;

/*!
 The ssid of the network.
 @availability v14.3
 */
@property(nonatomic,readonly) NSString           *ssid;

/*!
 The bssid of the network.
 @availability v14.3
 */
@property(nonatomic,readonly) NSString           *bssid;


@end
