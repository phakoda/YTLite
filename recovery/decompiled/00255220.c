/* Decompiled from supplied 5.2.2 arm package. VA 0x255220. _av_buffer_make_writable */

undefined8 _av_buffer_make_writable(long *param_1)

{
  int iVar1;
  long lVar2;
  long local_28;
  
  lVar2 = *param_1;
  iVar1 = _av_buffer_is_writable(lVar2);
  if (iVar1 == 0) {
    local_28 = _av_buffer_alloc(*(undefined4 *)(lVar2 + 0x10));
    if (local_28 == 0) {
      return 0xfffffff4;
    }
    _memcpy(*(void **)(local_28 + 8),*(void **)(lVar2 + 8),(long)*(int *)(lVar2 + 0x10));
    FUN_00255160(param_1,&local_28);
  }
  return 0;
}


