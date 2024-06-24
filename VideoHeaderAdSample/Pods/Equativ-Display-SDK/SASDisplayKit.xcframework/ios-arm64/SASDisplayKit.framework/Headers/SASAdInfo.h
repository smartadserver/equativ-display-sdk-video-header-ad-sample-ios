//
//  SASAdInfo.h
//  SASDisplayKit
//
//  Created by Guillaume Laubier on 18/09/2023.
//  Copyright © 2023 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SASAdProgrammaticInfo;

/// Model class centralizing useful information for publishers.
@interface SASAdInfo : NSObject

/// The insertion ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *insertionID;

/// The aspect ratio of the ad if available, nil otherwise. This NSNumber contains a Float. Especially useful for banner format, you can easily compute the correct height of your banner by dividing your desired width by this aspectRatio.
@property (readonly, nullable) NSNumber *aspectRatio;

/// All programmatic info corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) SASAdProgrammaticInfo *programmaticInfo;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
