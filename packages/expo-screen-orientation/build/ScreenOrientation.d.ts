import { Subscription } from '@unimodules/core';
import { Orientation, OrientationChangeEvent, OrientationChangeListener, OrientationLock, PlatformOrientationInfo, WebOrientationLock, WebOrientation, SizeClassIOS, ScreenOrientationInfo } from './ScreenOrientation.types';
export { Orientation, OrientationLock, PlatformOrientationInfo, OrientationChangeListener, OrientationChangeEvent, WebOrientationLock, WebOrientation, SizeClassIOS, ScreenOrientationInfo, };
export declare function lockAsync(orientationLock: OrientationLock): Promise<void>;
export declare function lockPlatformAsync(options: PlatformOrientationInfo): Promise<void>;
export declare function unlockAsync(): Promise<void>;
export declare function getOrientationAsync(): Promise<Orientation>;
export declare function getOrientationLockAsync(): Promise<OrientationLock>;
export declare function getPlatformOrientationLockAsync(): Promise<PlatformOrientationInfo>;
export declare function supportsOrientationLockAsync(orientationLock: OrientationLock): Promise<boolean>;
export declare function addOrientationChangeListener(listener: OrientationChangeListener): Subscription;
export declare function removeOrientationChangeListeners(): void;
export declare function removeOrientationChangeListener(subscription: Subscription): void;
