/* Decompiled from supplied 5.2.2 arm package. VA 0x25c40c. FUN_0025c40c */

void FUN_0025c40c(long *param_1)

{
  long lVar1;
  
  lVar1 = *param_1;
  _av_buffer_unref(lVar1 + 0x20);
  _av_dict_free(lVar1 + 0x18);
  _av_freep(param_1);
  return;
}


