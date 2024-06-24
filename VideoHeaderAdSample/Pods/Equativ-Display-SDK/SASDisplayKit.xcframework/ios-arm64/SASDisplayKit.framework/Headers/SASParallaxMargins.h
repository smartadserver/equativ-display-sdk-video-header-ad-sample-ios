//
//  SASParallaxMargins.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 30/01/2024.
//  Copyright © 2024 Smart AdServer. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents the margins to apply to parallax ads.
 */
@interface SASParallaxMargins : NSObject

/// The left margin to be applied to the parallax.
@property (readonly) CGFloat left;

/// The top margin to be applied to the parallax.
@property (readonly) CGFloat top;

/// The right margin to be applied to the parallax.
@property (readonly) CGFloat right;

/// The bottom margin to be applied to the parallax.
@property (readonly) CGFloat bottom;

/**
 Returns an initialized SASParallaxMargins object.
 
 @param left The left margin.
 @param top The top margin.
 @param right The right margin.
 @param bottom The bottom margin.
 @return An initialized instance of SASParallaxMargins. 
 */
+ (instancetype)parallaxMarginsWithLeft:(CGFloat)left
                                    top:(CGFloat)top
                                  right:(CGFloat)right
                                 bottom:(CGFloat)bottom;

/**
 Returns a new parallax margins instance representing the addition of this instance and the
 instance provided as parameter.
 
 @param otherParallaxMargins The parallax margins instance to be added to the current one.
 @return A new parallax margins instance representing the addition of this instance and the
 instance provided as parameter.
 */
- (SASParallaxMargins *)parallaxMarginsByAddingParallaxMargins:(SASParallaxMargins *)otherParallaxMargins;

/**
 Initialize a new instance of SASParallaxMargins.
 
 @param left The left margin.
 @param top The top margin.
 @param right The right margin.
 @param bottom The bottom margin.
 @return An initialized instance of SASParallaxMargins.
 */
- (instancetype)initWithLeft:(CGFloat)left
                         top:(CGFloat)top
                       right:(CGFloat)right
                      bottom:(CGFloat)bottom NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
