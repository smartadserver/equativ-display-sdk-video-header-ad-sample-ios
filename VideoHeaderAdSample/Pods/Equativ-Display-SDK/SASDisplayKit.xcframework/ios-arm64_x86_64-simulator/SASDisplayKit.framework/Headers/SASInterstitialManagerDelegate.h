//
//  SASInterstitialManagerDelegate.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 20/07/2022.
//  Copyright © 2022 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SASInterstitialManager;
@class SASAdInfo;

/**
 SASInterstitialManager delegate.
 */
@protocol SASInterstitialManagerDelegate <NSObject>

@required

/**
 Called when the interstitial manager has loaded an ad successfully.
 
 The ad can be shown using the 'showFromViewController:' method.
 
 @param interstitialManager The instance of SASInterstitialManager calling the delegate.
 @param adInfo The instance of SASAdInfo related to the loaded ad.
 */
- (void)interstitialManager:(SASInterstitialManager *)interstitialManager didLoadWithInfo:(SASAdInfo *)adInfo;

/**
 Called when the interstitial manager fails to load the ad.
 
 @param interstitialManager The instance of SASInterstitialManager calling the delegate.
 @param error The error preventing the interstitial from being loaded.
 */
- (void)interstitialManager:(SASInterstitialManager *)interstitialManager didFailToLoadWithError:(NSError *)error NS_SWIFT_NAME( interstitialManager(_:didFailToLoad:) );

@optional

/**
 Called when the interstitial manager has displayed the interstitial (as a fullscreen modal view controller).
 
 @param interstitialManager The instance of SASInterstitialManager calling the delegate.
 */
- (void)interstitialManagerDidShow:(SASInterstitialManager *)interstitialManager;

/**
 Called when the interstitial manager did fail to show the interstitial.
 
 @param interstitialManager The instance of SASInterstitialManager calling the delegate.
 @param error The error preventing the interstitial from being loaded.
 */
- (void)interstitialManager:(SASInterstitialManager *)interstitialManager didFailToShowWithError:(NSError *)error NS_SWIFT_NAME( interstitialManager(_:didFailToShow:) );

/**
 Called when the fullscreen modal view controller is closed.
 
 @param interstitialManager The instance of SASInterstitialManager calling the delegate.
 */
- (void)interstitialManagerDidClose:(SASInterstitialManager *)interstitialManager;

/**
 Called when a valid click is registered on the interstitial ad.
 
 @param interstitialManager The instance of SASInterstitialManager calling the delegate.
 */
- (void)interstitialManagerClicked:(SASInterstitialManager *)interstitialManager;

@end

NS_ASSUME_NONNULL_END
