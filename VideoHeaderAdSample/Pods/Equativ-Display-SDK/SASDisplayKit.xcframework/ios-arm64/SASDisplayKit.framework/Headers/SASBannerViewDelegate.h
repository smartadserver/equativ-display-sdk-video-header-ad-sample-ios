//
//  SASBannerViewDelegate.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 24/03/2022.
//  Copyright © 2022 Smart AdServer. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SASBannerView;
@class SASAdInfo;

/**
 SASBannerView delegate.
 */
@protocol SASBannerViewDelegate <NSObject>

@required

/**
 Called when the banner view has loaded an ad successfully.
 
 @param bannerView The instance of SASBannerView calling the delegate.
 @param adInfo The instance of SASAdInfo related to the loaded ad.
 */
- (void)bannerView:(SASBannerView *)bannerView didLoadWithInfo:(SASAdInfo *)adInfo;

/**
 Called when the banner view fails to load the ad.
 
 @param bannerView The instance of SASBannerView calling the delegate.
 @param error The error preventing the banner from being loaded.
 */
- (void)bannerView:(SASBannerView *)bannerView didFailToLoadWithError:(NSError *)error NS_SWIFT_NAME( bannerView(_:didFailToLoad:) );

@optional

/**
 Called when a valid click is registered on the banner view.
 
 @param bannerView The instance of SASBannerView calling the delegate.
 */
- (void)bannerViewClicked:(SASBannerView *)bannerView;

/**
 Called when the banner requests to be closed.
 
 @note Some ad formats might want to close the banner ad by themself (for instance some video ads). It is
 the app responsability to actually close the banner ad, aka to remove it from the views' hierarchy. If the
 app does nothing or does not implement this delegate, the ad will not be closed.
 
 @param bannerView The instance of SASBannerView requesting to be closed.
 */
- (void)bannerViewDidRequestClose:(SASBannerView *)bannerView;

@end

NS_ASSUME_NONNULL_END
