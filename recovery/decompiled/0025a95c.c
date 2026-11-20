/* Decompiled from supplied 5.2.2 arm package. VA 0x25a95c. _av_file_unmap */

void _av_file_unmap(long param_1,long param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    _munmap();
    return;
  }
  return;
}


