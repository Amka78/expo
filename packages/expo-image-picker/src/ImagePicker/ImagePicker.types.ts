export enum MediaTypeOptions {
  All = 'All',
  Videos = 'Videos',
  Images = 'Images',
}

export type ImageInfo = {
  uri: string;
  /**
   * Web-only processing.
   * Returns an image file.
   *
   * @type {File}
   */
  file?: File;
  width: number;
  height: number;
  type?: 'image' | 'video';
};

export type ImagePickerResult = { cancelled: true } | ({ cancelled: false } & ImageInfo);

export type ImagePickerOptions = {
  allowsEditing?: boolean;
  aspect?: [number, number];
  quality?: number;
  allowsMultipleSelection?: boolean;
  mediaTypes?: MediaTypeOptions;
  exif?: boolean;
  base64?: boolean;
};

export type OpenFileBrowserOptions = {
  mediaTypes: MediaTypeOptions;
  capture?: boolean;
  allowsMultipleSelection: boolean;
};
