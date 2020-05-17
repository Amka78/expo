/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ABI37_0_0React/components/image/ImageShadowNode.h>
#include <ABI37_0_0React/core/ConcreteComponentDescriptor.h>
#include <ABI37_0_0React/imagemanager/ImageManager.h>
#include <ABI37_0_0React/utils/ContextContainer.h>

namespace ABI37_0_0facebook {
namespace ABI37_0_0React {

/*
 * Descriptor for <Image> component.
 */
class ImageComponentDescriptor final
    : public ConcreteComponentDescriptor<ImageShadowNode> {
 public:
  ImageComponentDescriptor(
      EventDispatcher::Shared eventDispatcher,
      ContextContainer::Shared const &contextContainer)
      : ConcreteComponentDescriptor(eventDispatcher),
        imageManager_(std::make_shared<ImageManager>(contextContainer)){};

  void adopt(UnsharedShadowNode shadowNode) const override {
    ConcreteComponentDescriptor::adopt(shadowNode);

    assert(std::dynamic_pointer_cast<ImageShadowNode>(shadowNode));
    auto imageShadowNode =
        std::static_pointer_cast<ImageShadowNode>(shadowNode);

    // `ImageShadowNode` uses `ImageManager` to initiate image loading and
    // communicate the loading state and results to mounting layer.
    imageShadowNode->setImageManager(imageManager_);
  }

 private:
  const SharedImageManager imageManager_;
};

} // namespace ABI37_0_0React
} // namespace ABI37_0_0facebook
