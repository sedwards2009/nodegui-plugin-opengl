export function isTypedArray(arg: any): arg is NodeJS.TypedArray {
  return arg.BYTES_PER_ELEMENT !== undefined && arg.buffer !== undefined;
}
