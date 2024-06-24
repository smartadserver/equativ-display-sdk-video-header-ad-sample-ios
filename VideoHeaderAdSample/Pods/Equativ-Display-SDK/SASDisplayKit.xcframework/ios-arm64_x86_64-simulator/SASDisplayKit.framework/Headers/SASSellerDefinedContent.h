//
//  SASSellerDefinedContent.h
//  SASDisplayKit
//
//  Created by Julien GOMEZ on 10/08/2023.
//  Copyright © 2023 Smart AdServer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SASSellerDefinedSegment;

/**
 Object representing a Seller Defined Content. More info here: https://documentation.smartadserver.com/displaySDK8/sellerdefinedaudience.html
 */
@interface SASSellerDefinedContent : NSObject <NSCoding>

/// The ID of the Seller Defined Content if any, nil otherwise.
@property (nonatomic, readonly, nullable) NSString *ID;

/// The name of the Seller Defined Content if any, nil otherwise.
@property (nonatomic, readonly, nullable) NSString *name;

/// An array of SASSellerDefinedSegment related to this Seller Defined Content if any, nil otherwise.
@property (nonatomic, readonly, nullable) NSArray<SASSellerDefinedSegment *> *segments;

/**
 Initialize a new instance of SASSellerDefinedContent.
 
 @param ID The ID of the Seller Defined Content if any, nil otherwise.
 @param name The name of the Seller Defined Content if any, nil otherwise.
 @param segments An array of SASSellerDefinedSegment related to this Seller Defined Content if any, nil otherwise.
 
 @return An initialized instance of SASSellerDefinedContent.
 */
- (instancetype)initWithID:(nullable NSString *)ID name:(nullable NSString *)name segments:(nullable NSArray<SASSellerDefinedSegment *> *)segments NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
