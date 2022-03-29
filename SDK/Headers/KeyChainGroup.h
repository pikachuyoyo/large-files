//
//  KeyChainGroup.h
//  AgentSDK
//
//  Created by Vidushi Dhiman on 6/28/18.
//

#import <Foundation/Foundation.h>
/*
 This protocol will be used to get Keychain Access Group, which will be used to share Keychain between app and extension.
 */
@protocol KeyChainGroupDataSource
@required
/*
 This datasource method needs to be implemented by App as well as extension to set shared Keychain Path
 This is mandatory to use KeyChain Group
 */
-(NSString*)sharedKeychainPath;
@end

@interface KeyChainGroup : NSObject

/*
 singleton instance of KeyChainGroup class
 */
+(instancetype)getInstance;
/*
 This datasource needs to be set by class which is going to use KeyChainGroup.
 ScreenRecorder *recorder = [ScreenRecorder defaultRecorder];
 recorder.dataSource = self;
 
 KeyChainGroupDataSource protocol has to be implemented by that class.
 
 So that user can assign there Keychain Access Group id for exchanging keychain between app and extension.
 */
@property(nonatomic,assign) id<KeyChainGroupDataSource> dataSource;

@property(nonatomic,readonly) NSString *keychainGroupId;

@end
