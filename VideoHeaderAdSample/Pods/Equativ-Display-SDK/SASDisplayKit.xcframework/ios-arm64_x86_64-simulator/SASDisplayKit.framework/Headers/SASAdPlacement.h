//
//  SASAdPlacement.h
//  SASDisplayKit
//
//  Created by Loïc GIRON DIT METAZ on 07/03/2022.
//  Copyright © 2022 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SASSellerDefinedAudience;
@class SASSellerDefinedContent;

/// Contains all available test placements.
typedef NS_ENUM(NSInteger, SASAdPlacementTest) {
    
#pragma mark - Banner ads
    
    /// A placement that will return a HTML banner ad.
    SASAdPlacementTestBannerHTML,
    
    /// A placement that will return a banner ad using MRAID expand feature.
    SASAdPlacementTestBannerMRAIDExpand,
    
    /// A placement that will return a Video banner ad.
    SASAdPlacementTestBannerVideo,
    
    /// A placement that will return a Parallax banner with an HTML creative.
    SASAdPlacementTestBannerParallaxHTML,
    
    /// A placement that will return a Parallax banner with a video creative.
    SASAdPlacementTestBannerParallaxVideo,
    
#pragma mark - Interstitial ads
    
    /// A placement that will return a HTML interstitial ad.
    SASAdPlacementTestInterstitialHTML,
    
    /// A placement that will return a video interstitial ad.
    SASAdPlacementTestInterstitialVideo
    
};
    
/**
 Object that represents an ad placement.
 
 An ad placement aggregates several information like the site id, page id and format id that
 will be used when loading an ad.
 */
@interface SASAdPlacement : NSObject

#pragma mark - Properties

/// The site id that should be used when loading an ad.
@property (readonly) NSInteger siteId;

/// The page id that should be used when loading an ad.
@property (readonly) NSInteger pageId;

/// The format id that should be used when loading an ad.
@property (readonly) NSInteger formatId;

/// A set of keywords that will be used when loading an ad to receive more relevant advertising if necessary, nil otherwise.
@property (readonly, nullable) NSString *keywordTargeting;

/// An array of SASSellerDefinedAudience objects related to this SASAdPlacement, if any. Nil otherwise.
@property (strong, nullable) NSArray<SASSellerDefinedAudience *> *sellerDefinedAudiences;

/// An array of SASSellerDefinedContent objects related to this SASAdPlacement, if any. Nil otherwise.
@property (strong, nullable) NSArray<SASSellerDefinedContent *> *sellerDefinedContents;

/// A Supply Chain Object string representation that will be sent during ad loading to receive more relevant
/// advertising if needed, nil otherwise.
///
/// You should provide a Supply Chain Object if you are reselling inventory from direct publishers.
///
/// You can find more information about Supply Chain Object in the official Equativ documentation:
///
/// https://help.smartadserver.com/s/article/Sellers-json-and-SupplyChain-Object
///
/// You can also find more information on how to serialize a Supply Chain Object into a string in the
/// official IAB documentation:
///
/// https://github.com/InteractiveAdvertisingBureau/openrtb/blob/master/supplychainobject.md#supplychain-for-non-openrtb-requests
@property (strong, nullable) NSString *supplyChainObjectString;

#pragma mark - Initializers

/**
 Initialize a new instance of SASAdPlacement.
 
 @param siteId The site id that should be used when loading an ad.
 @param pageId The page id that should be used when loading an ad.
 @param formatId The format id that should be used when loading an ad.
 
 @return An initialized instance of SASAdPlacement.
 */
- (instancetype)initWithSiteId:(NSInteger)siteId pageId:(NSInteger)pageId formatId:(NSInteger)formatId;

/**
 Initialize a new instance of SASAdPlacement.
 
 @param siteId The site id that should be used when loading an ad.
 @param pageId The page id that should be used when loading an ad.
 @param formatId The format id that should be used when loading an ad.
 @param keywordTargeting A set of keywords that will be used when loading an ad to receive more relevant advertising if necessary, nil otherwise.
 
 @return An initialized instance of SASAdPlacement.
 */
- (instancetype)initWithSiteId:(NSInteger)siteId pageId:(NSInteger)pageId formatId:(NSInteger)formatId keywordTargeting:(nullable NSString *)keywordTargeting NS_DESIGNATED_INITIALIZER;

/**
 Initialize a new instance of SASAdPlacement corresponding to a test ad.
 
 A test ad will always deliver and will always be from a specific type.
 You can use these tests to verify that your integration will work properly with all types of ads.
 
 Available test ads are listed in the SASAdPlacementTest object.
 
 @warning If you set a test placement, make sure to remove it before
 submitting your application to the App Store.
 
 @param type The type of ad you want to get when loading ads.
 
 @return An initialized instance of SASAdPlacement corresponding to a test ad.
 */
- (instancetype)initWithTestAd:(SASAdPlacementTest)type;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Convenient initializers

/**
 Returns an initialized SASAdPlacement object.
 
 @param siteId The site id that should be used when loading an ad.
 @param pageId The page id that should be used when loading an ad.
 @param formatId The format id that should be used when loading an ad.
 
 @return An initialized instance of SASAdPlacement.
 */
+ (instancetype)adPlacementWithSiteId:(NSInteger)siteId pageId:(NSInteger)pageId formatId:(NSInteger)formatId;

/**
 Returns an initialized SASAdPlacement object.
 
 @param siteId The site id that should be used when loading an ad.
 @param pageId The page id that should be used when loading an ad.
 @param formatId The format id that should be used when loading an ad.
 @param keywordTargeting A set of keywords that will be used when loading an ad to receive more relevant advertising if necessary, nil otherwise.
 
 @return An initialized instance of SASAdPlacement.
 */
+ (instancetype)adPlacementWithSiteId:(NSInteger)siteId pageId:(NSInteger)pageId formatId:(NSInteger)formatId keywordTargeting:(nullable NSString *)keywordTargeting;

/**
 Returns an initialized SASAdPlacement object corresponding to a test ad.
 
 A test ad will always deliver and will always be from a specific type.
 You can use these tests to verify that your integration will work properly with all types of ads.
 
 Available test ads are listed in the SASAdPlacementTest object.
 
 @warning If you set a test placement, make sure to remove it before
 submitting your application to the App Store.
 
 @param type The type of ad you want to get when loading ads.
 
 @return An initialized instance of SASAdPlacement corresponding to a test ad.
 */
+ (instancetype)adPlacementWithTestAd:(SASAdPlacementTest)type;

@end

NS_ASSUME_NONNULL_END
