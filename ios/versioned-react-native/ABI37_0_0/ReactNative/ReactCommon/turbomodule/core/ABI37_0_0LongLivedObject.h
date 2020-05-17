/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>
#include <unordered_set>

namespace ABI37_0_0facebook {
namespace ABI37_0_0React {

/**
 * A simple wrapper class that can be registered to a collection that keep it
 * alive for extended period of time. This object can be removed from the
 * collection when needed.
 *
 * The subclass of this class must be created using std::make_shared<T>().
 * After creation, add it to the `LongLivedObjectCollection`.
 * When done with the object, call `allowRelease()` to allow the OS to release
 * it.
 */
class LongLivedObject {
 public:
  void allowRelease();

 protected:
  LongLivedObject();
};

/**
 * A singleton collection for the `LongLivedObject`s.
 */
class LongLivedObjectCollection {
 public:
  static LongLivedObjectCollection &get();

  LongLivedObjectCollection(LongLivedObjectCollection const &) = delete;
  void operator=(LongLivedObjectCollection const &) = delete;

  void add(std::shared_ptr<LongLivedObject> o);
  void remove(const LongLivedObject *o);
  void clear();

 private:
  LongLivedObjectCollection();
  std::unordered_set<std::shared_ptr<LongLivedObject>> collection_;
};

} // namespace ABI37_0_0React
} // namespace ABI37_0_0facebook
