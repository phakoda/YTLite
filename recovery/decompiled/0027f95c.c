/* Decompiled from supplied 5.2.2 arm package. VA 0x27f95c. FUN_0027f95c */

void FUN_0027f95c(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x48);
  _av_freep(lVar1 + 0x20);
  _av_freep(lVar1 + 0x28);
  _av_freep(lVar1 + 0x48);
  if (*(long *)(lVar1 + 0x38) != 0) {
    _av_freep();
  }
  _av_freep((long *)(lVar1 + 0x38));
  return;
}


