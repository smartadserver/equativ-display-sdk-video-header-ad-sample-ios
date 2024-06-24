//
//  SASConfiguration.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 30/03/2022.
//  Copyright © 2022 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SASSecondaryImplementationInfo;

/**
 Hold the configuration of the Display SDK.
 
 @note This singleton class is used for the initial SDK configuration. This configuration is MANDATORY
 and should be done before performing any ad call. Check the complete documentation for more information.
 */
@interface SASConfiguration : NSObject

/// The shared instance of the SASConfiguration object.
@property (class, nonatomic, readonly) SASConfiguration *sharedInstance NS_SWIFT_NAME(shared);

/// YES if the SDK has been configured (using the `SASConfiguration.configure()` method), NO otherwise.
@property (readonly, getter=isConfigured) BOOL configured NS_SWIFT_NAME(configured);

/// Ad call timeout in seconds.
@property (assign) NSTimeInterval adCallTimeout;

/// Additional implementation information that can be provided to the SDK when integrated as secondary SDK.
@property (strong, nullable) SASSecondaryImplementationInfo *secondaryImplementationInfo;

/// YES if the SDK needs to display debug informations in the Xcode console, NO otherwise.
@property (assign, getter=isLoggingEnabled) BOOL loggingEnabled NS_SWIFT_NAME(loggingEnabled);

/// The bundle for localized strings, nil to use the default localized strings.
///
/// The Display SDK embeds some localized string in English and French. You can add support for other
/// languages by providing localized strings from your own app's bundle.
///
/// Check the documentation for the full list of string's keys.
@property (strong, strong) NSBundle *stringsBundle;

/// YES if the SDK is allowed to retrieve the user's location available in the app, NO otherwise.
@property (assign, getter=isAutomaticLocationDetectionAllowed) BOOL automaticLocationDetectionAllowed NS_SWIFT_NAME(automaticLocationDetectionAllowed);

/**
 Configure the SDK.
 
 @warning You must call this method before performing any ad call, otherwise the SDK will crash!
 */
- (void)configure;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
