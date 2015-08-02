#import <notify.h>
#import <objc/message.h>
#import <SystemConfiguration/CaptiveNetwork.h>

#define kPrefsChangedNotification "com.a3tweaks.asphaleia/ReloadPrefs"
#define addObserver(c, n) CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), NULL, (c), CFSTR(n), NULL, CFNotificationSuspensionBehaviorCoalesce)
#define loadPreferences() preferencesChangedCallback(NULL, NULL, NULL, NULL, NULL)

#define kSecuredAppsKey @"securedApps"
#define kSecuredFoldersKey @"securedFolders"
#define kSecuredPanelsKey @"securedPanels"
#define kSecureSwitcherKey @"secureSwitcher"
#define kSecureAppArrangementKey @"preventAppDeletion"
#define kObscureAppContentKey @"obscureAppContent"
#define kObscureBannerKey @"obscureBanners"
#define kUnsecureUnlockToAppKey @"easyUnlockIntoApp"
#define kWifiUnlockKey @"wifiUnlock"
#define kWifiUnlockNetworkKey @"wifiNetwork"
#define kSecureSpotlightKey @"secureSpotlight"
#define kSecurePowerDownKey @"preventPowerOff"
#define kSecureControlCentreKey @"secureCC"
#define kVibrateOnFailKey @"vibrateOnFail"
#define kProtectAllAppsKey @"globalAppSecurity"
#define kDynamicSelectionKey @"dynamicSelection"
#define kAppExitUnlockTimeKey @"timeInterval"
#define kResetAppExitTimerOnLockKey @"ResetTimerOnLock"
#define kDelayAfterLockKey @"delayAfterLock"
#define kDelayAfterLockTimeKey @"timeIntervalLock"
#define kControlPanelInAppsKey @"controlPanelAllowedInApps"
#define kEnableControlPanelKey @"controlPanel"
#define kPasscodeKey @"passcode"
#define kPasscodeEnabledKey @"simplePasscode"
#define kTouchIDEnabledKey @"touchID"
#define kSecurePhotosKey @"securePhotos"
#define kPhotosMessageCount @"photosMsgDisplayCount"

static NSString *const kPreferencesFilePath = @"/var/mobile/Library/Preferences/com.a3tweaks.asphaleia8.plist";

void preferencesChangedCallback(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo);
BOOL shouldRequireAuthorisationOnWifi(void);
BOOL isTouchIDDevice(void);
BOOL passcodeEnabled(void);
BOOL touchIDEnabled(void);
NSString *getPasscode(void);
BOOL shouldEnableControlPanel(void);
BOOL shouldAllowControlPanelInApps(void);
NSInteger appSecurityDelayTimeInterval(void);
BOOL shouldDelayAppSecurity(void);
BOOL shouldResetAppExitTimerOnLock(void);
NSInteger appExitUnlockTimeInterval(void);
BOOL shouldUseDynamicSelection(void);
BOOL shouldProtectAllApps(void);
BOOL shouldVibrateOnIncorrectFingerprint(void);
BOOL shouldSecureControlCentre(void);
BOOL shouldSecurePowerDownView(void);
BOOL shouldSecureSpotlight(void);
BOOL shouldUnsecurelyUnlockIntoApp(void);
BOOL shouldObscureAppContent(void);
BOOL shouldObscureNotifications(void);
BOOL shouldSecureSwitcher(void);
BOOL shouldSecureAppArrangement(void);
BOOL shouldSecurePhotos(void);
BOOL shouldShowPhotosProtectMsg(void);
NSArray *getProtectedAppsNoBullshit(void);
NSArray *getProtectedApps(void);
NSArray *getProtectedFolders(void);
NSArray *getProtectedPanels(void);

@interface ASPreferencesHandler : NSObject
@property (nonatomic, retain) NSDictionary *prefs;
@property BOOL asphaleiaDisabled;
@property BOOL appSecurityDisabled;
+(instancetype)sharedInstance;
@end