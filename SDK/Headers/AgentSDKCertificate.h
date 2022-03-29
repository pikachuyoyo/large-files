//
//  AgentSdkContentMgmt.h
//  SOTI MobiControl SDK
//
//  Created by Soti Inc. on 2012-08-30.
//  Copyright 2015 SOTI Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef MAC_LIBRARY
#import <Cocoa/Cocoa.h>
#else
#import <UIKit/UIKit.h>
#endif



typedef struct x509_st X509;

/*!
    The AgentSdkCertificateInfo class declares a programmatic interface that stores all aspect of the SDK Certificate.
    @availability v11
 */
@interface AgentSdkCertificateInfo : NSObject
{
}
/*!
    The certificate subject's common name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strSubjectCommonName;

/*!
    The certificate subject's organization name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strSubjectOrganizationName;

/*!
    The certificate subject's locality name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strSubjectLocalityName;

/*!
    The certificate subject's province name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strSubjectStateProvinceName;

/*!
    The certificate subject's country name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strSubjectCountryName;

/*!
    The certificate subject's organizational unit name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strSubjectOrganizationalUnitName;
//

/*!
    The certificate issuer's common name.
    @availability v11
 */
@property (nonatomic, retain) NSString *strIssuerCommonName;

/*!
    The certificate issuer's domain name qualifier.
    @availability v11
 */
@property (nonatomic, retain) NSString *strIssuerDNQualifier;
//

/*!
    The certificate subject's alternative name IP addresses.
    @availability v11
 */
@property (nonatomic, retain) NSArray *strArraySubjectAltNameIPAddresses;

/*!
    The certificate subject's alternative name domain name system names.
    @availability v11
 */
@property (nonatomic, retain) NSArray *strArraySubjectAltNameDNSNames;
//

/*!
    The certificate's version.
    @availability v11
 */
@property (nonatomic, assign) NSUInteger nMiscVersion;

/*!
    The certificate's serial number.
    @availability v11
 */
@property (nonatomic, retain) NSString *strMiscSerialNumber;

/*!
    The certificate's effective date.
    @availability v11
 */
@property (nonatomic, retain) NSDate* dateMiscNotValidBefore;

/*!
    The certificate's expiry date.
    @availability v11
 */
@property (nonatomic, retain) NSDate* dateMiscNotValidAfter;

/*!
    The certificate's public key data.
    @availability v11
 */
@property (nonatomic, retain) NSString *strMiscPublicKeyData;

/*!
    The certificate's thumbprint.
    @availability v11
 */
@property (nonatomic, retain) NSString *strMiscThumbprint;
//




- (id)initWithX509Certificate:(X509 *)certificateX509;


@end
