//
//  SASAdError.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 23/08/2023.
//  Copyright © 2023 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define SASAdErrors @"SASAdErrors"

/**
 Class used to represent a single ad loading error.
 */
@interface SASAdError: NSObject

/// The insertion ID of the ad that has triggered this error if any, nil otherwise.
@property (readonly, nullable) NSString *insertionID;

/// The description of the error preventing the ad adapter from being loaded.
@property (readonly) NSString *error;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
