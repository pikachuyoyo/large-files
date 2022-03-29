//
//  SharedUserDefaultsManager.h
//  AgentSDK
//
//  Created by Vidushi Dhiman on 7/30/18.
//

#import <Foundation/Foundation.h>

/*
 This protocol will be used to get shared groupId, which will be used to share data between app and extension.
 */
@protocol SharedUserDefaultsDataSource
@required
/*
 This datasource method needs to be implemented by App as well as extension to set shared groupID
 This is mandatory to use Screen recording Feature
 */
-(NSString *)sharedGroupIdForSharedUserDefaults;

@end

@interface SharedUserDefaultsManager : NSObject

/*
 singleton instance of SharedUserDefaultsManager class
 */
+(instancetype)sharedManager;

/*
 This datasource needs to be set by class which is going to use Screen Recorder.
 SharedUserDefaultsManager *sharedManager = [SharedUserDefaultsManager sharedManager];
 sharedManager = self;
 
 SharedUserDefaultsDataSource protocol has to be implemented by that class.
 
 So that user can assign their shared group id for exchanging data between app and extension.
 */
@property(nonatomic,assign) id<SharedUserDefaultsDataSource> dataSource;

/*
 This method will be called by App for setting configuration after successful enrollment. It is responsible to copying configuration as well as required resources to shared directory. later on this configuration will be used by extension using useAppConfigurationForExtension method. So that extension will be able to enroll with MobiControl.
 */
-(void)setConfigurationForExtension;

/*
 This method will be called by extension.it will read app configuration and required resources shared by app. That will help in making connection with MobiControl.
 
 Call this method from Extension under - (void)broadcastStartedWithSetupInfo:(NSDictionary<NSString *,NSObject *> *)setupInfo {
 
 [[SharedUserDefaultsManager sharedManager] useAppConfigurationForExtension];

 
 */
-(void)useAppConfigurationForExtension;

@end
