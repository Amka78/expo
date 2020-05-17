/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ABI36_0_0RCTSurfaceRootShadowView;

@protocol ABI36_0_0RCTSurfaceRootShadowViewDelegate <NSObject>

- (void)rootShadowView:(ABI36_0_0RCTSurfaceRootShadowView *)rootShadowView didChangeIntrinsicSize:(CGSize)instrinsicSize;
- (void)rootShadowViewDidStartRendering:(ABI36_0_0RCTSurfaceRootShadowView *)rootShadowView;
- (void)rootShadowViewDidStartLayingOut:(ABI36_0_0RCTSurfaceRootShadowView *)rootShadowView;

@end

NS_ASSUME_NONNULL_END
