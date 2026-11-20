/* Decompiled from supplied 5.2.2 arm package. VA 0x2551dc. _av_buffer_is_writable */

bool _av_buffer_is_writable(long *param_1)

{
  if ((*(byte *)(*param_1 + 0x20) & 1) == 0) {
    return *(int *)(*param_1 + 0xc) == 1;
  }
  return false;
}


