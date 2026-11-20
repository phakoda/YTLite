/* Decompiled from supplied 5.2.2 arm package. VA 0x25b5f4. _av_frame_unref */

void _av_frame_unref(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 != 0) {
    FUN_0025c0a4(param_1);
    lVar2 = 0x120;
    while (lVar2 + 8 != 0x168) {
      _av_buffer_unref(param_1 + lVar2);
      lVar2 = lVar2 + 8;
    }
    lVar2 = -1;
    lVar1 = 0;
    while (lVar2 = lVar2 + 1, lVar2 < *(int *)(param_1 + 0x168)) {
      _av_buffer_unref(*(long *)(param_1 + 0x160) + lVar1);
      lVar1 = lVar1 + 8;
    }
    _av_freep((long *)(param_1 + 0x160));
    _av_dict_free(param_1 + 0x1b0);
    _av_buffer_unref(param_1 + 0x1d8);
    _av_buffer_unref(param_1 + 0x1e0);
    _av_buffer_unref(param_1 + 0x1e8);
    _av_buffer_unref(param_1 + 0x210);
    FUN_0025b53c(param_1);
    return;
  }
  return;
}


