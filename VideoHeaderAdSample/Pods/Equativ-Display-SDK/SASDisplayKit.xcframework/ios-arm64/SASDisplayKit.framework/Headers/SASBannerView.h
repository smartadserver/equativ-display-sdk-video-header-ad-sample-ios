//
//  SASBannerView.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 07/03/2022.
//  Copyright © 2022 Smart AdServer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SASDisplayKit/SASAdPlacement.h>
#import <SASDisplayKit/SASBannerViewDelegate.h>
#import <SASDisplayKit/SASParallaxMargins.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A view that loads and displays a banner creative.
 */
@interface SASBannerView : UIView

/// The banner view delegate if any, nil otherwise.
@property (weak, nullable) id<SASBannerViewDelegate> delegate;

/// The modal parent view controller of the current banner.
///
/// This controller will be used as root controller by the SDK if it needs to display a fullscreen controller.
///
/// @note You should always set a valid modal parent view controller, otherwise most post-click interactions
/// will not be able to work properly (post-click modal, StoreKit, …).
@property (weak, nullable) UIViewController *modalParentViewController;

/// A SASParallaxMargins instance representing the margins to apply to the parallax ads.
///
/// To avoid having your parallax ads displayed behind others views, such as navigation bar or tab bar, set the
/// exact size you want for each margin.
///
/// Default value: 0 margin for each side.
@property (strong) SASParallaxMargins *parallaxMargins;

/**
 Attempt to load an ad using the provided ad placement.
 
 @param adPlacement The ad placement used to load the ad.
 */
- (void)loadAdWithAdPlacement:(SASAdPlacement *)adPlacement;

@end

NS_ASSUME_NONNULL_END
