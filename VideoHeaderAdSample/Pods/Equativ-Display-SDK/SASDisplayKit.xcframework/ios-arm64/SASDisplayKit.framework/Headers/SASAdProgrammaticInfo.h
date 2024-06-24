//
//  SASAdProgrammaticInfo.h
//  SASDisplayKit
//
//  Created by Guillaume Laubier on 18/09/2023.
//  Copyright © 2023 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Model class, sub module of SASAdInfo model, centralizing useful programmatic information for publishers.
@interface SASAdProgrammaticInfo : NSObject

/// The advertiser ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *advertiserID;

/// The auction ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *auctionID;

/// The buyer ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *buyerID;

/// The campaign ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *campaignID;

/// The creative ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *creativeID;

/// The deal ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *dealID;

/// The dsp ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *dspID;

/// The publisher ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *publisherID;

/// The publisher cleared price corresponding to this ad in his currency if available, nil otherwise.
@property (readonly, nullable) NSString *clearedPricePublisherCurrency;

/// The publisher currency code corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *publisherCurrencyCode;

/// The external deal ID corresponding to this ad if available, nil otherwise.
@property (readonly, nullable) NSString *externalDealID;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
