//  Copyright © 2019 650 Industries. All rights reserved.

NS_ASSUME_NONNULL_BEGIN

@interface EXUpdatesAsset : NSObject

/**
 * properties determined by asset source
 */
@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSString *type;
@property (nullable, nonatomic, strong) NSURL *url;
@property (nullable, nonatomic, strong) NSDictionary *metadata;
@property (nullable, nonatomic, strong) NSString *mainBundleDir; // used for embedded assets
@property (nullable, nonatomic, strong) NSString *mainBundleFilename; // used for embedded assets
@property (nonatomic, assign) BOOL isLaunchAsset;

/**
 * properties determined at runtime by updates implementation
 */
@property (nullable, nonatomic, strong) NSDate *downloadTime;
@property (nullable, nonatomic, strong) NSString *filename;
@property (nullable, nonatomic, strong) NSString *contentHash;
@property (nullable, nonatomic, strong) NSDictionary *headers;

- (instancetype)initWithKey:(NSString *)key type:(NSString *)type;

@end

NS_ASSUME_NONNULL_END
