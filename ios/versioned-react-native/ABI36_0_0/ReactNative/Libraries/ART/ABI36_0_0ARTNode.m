/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI36_0_0React/ABI36_0_0ARTNode.h>

#import <ABI36_0_0React/ABI36_0_0ARTContainer.h>

@implementation ABI36_0_0ARTNode

- (void)insertABI36_0_0ReactSubview:(UIView *)subview atIndex:(NSInteger)atIndex
{
  [super insertABI36_0_0ReactSubview:subview atIndex:atIndex];
  [self insertSubview:subview atIndex:atIndex];
  [self invalidate];
}

- (void)removeABI36_0_0ReactSubview:(UIView *)subview
{
  [super removeABI36_0_0ReactSubview:subview];
  [self invalidate];
}

- (void)didUpdateABI36_0_0ReactSubviews
{
  // Do nothing, as subviews are inserted by insertABI36_0_0ReactSubview:
}

- (void)setOpacity:(CGFloat)opacity
{
  [self invalidate];
  _opacity = opacity;
}

- (void)setTransform:(CGAffineTransform)transform
{
  [self invalidate];
  super.transform = transform;
}

- (void)invalidate
{
  id<ABI36_0_0ARTContainer> container = (id<ABI36_0_0ARTContainer>)self.superview;
  [container invalidate];
}

- (void)renderTo:(CGContextRef)context
{
  if (self.opacity <= 0) {
    // Nothing to paint
    return;
  }
  if (self.opacity >= 1) {
    // Just paint at full opacity
    CGContextSaveGState(context);
    CGContextConcatCTM(context, self.transform);
    CGContextSetAlpha(context, 1);
    [self renderLayerTo:context];
    CGContextRestoreGState(context);
    return;
  }
  // This needs to be painted on a layer before being composited.
  CGContextSaveGState(context);
  CGContextConcatCTM(context, self.transform);
  CGContextSetAlpha(context, self.opacity);
  CGContextBeginTransparencyLayer(context, NULL);
  [self renderLayerTo:context];
  CGContextEndTransparencyLayer(context);
  CGContextRestoreGState(context);
}

- (void)renderLayerTo:(CGContextRef)context
{
  // abstract
}

@end
