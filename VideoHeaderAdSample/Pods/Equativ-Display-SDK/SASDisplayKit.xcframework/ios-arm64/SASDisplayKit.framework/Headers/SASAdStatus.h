//
//  SASAdStatus.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 19/07/2022.
//  Copyright © 2022 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The current status of an ad.
typedef NS_ENUM(NSUInteger, SASAdStatus) {  // NOSONAR false positive, Sonar incorrectly see this declaration as a function declaration
    SASAdStatusNotAvailable,
    SASAdStatusLoading,
    SASAdStatusReady,
    SASAdStatusShowing,
};

NS_ASSUME_NONNULL_END
