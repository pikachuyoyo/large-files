//
//  FeatureToggleManager.h
//  AgentSDK
//
//  Created by Vidushi Dhiman on 1/8/18.
//

#import <Foundation/Foundation.h>

@interface FeatureToggleManager : NSObject

/*
 singleton instance of FeatureToggleManager class
 */
+(instancetype)getInstance;

@property (nonatomic,strong) NSString *OverrideRemoteViewEncoding;
@end
