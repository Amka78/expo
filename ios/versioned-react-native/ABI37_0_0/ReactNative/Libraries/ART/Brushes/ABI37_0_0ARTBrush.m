/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI37_0_0React/ABI37_0_0ARTBrush.h>

#import <ABI37_0_0React/ABI37_0_0RCTDefines.h>

@implementation ABI37_0_0ARTBrush

- (instancetype)initWithArray:(NSArray *)data
{
  return [super init];
}

ABI37_0_0RCT_NOT_IMPLEMENTED(- (instancetype)init)

- (BOOL)applyFillColor:(CGContextRef)context
{
  return NO;
}

- (void)paint:(CGContextRef)context
{
  // abstract
}

@end
