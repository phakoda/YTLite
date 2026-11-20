/* Decompiled from supplied 5.2.2 arm package. VA 0x27ad34. _av_get_picture_type_char */

int _av_get_picture_type_char(int param_1)

{
  if (param_1 - 1U < 7) {
    return (int)(char)(0x62706953425049 >> (((ulong)(param_1 - 1U) & 7) << 3));
  }
  return 0x3f;
}


