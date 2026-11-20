/* Decompiled from supplied 5.2.2 arm package. VA 0x257df8. _av_encryption_init_info_free */

void _av_encryption_init_info_free(undefined8 *param_1)

{
  uint uVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    for (uVar1 = 0; uVar1 < *(uint *)(param_1 + 3); uVar1 = uVar1 + 1) {
      _av_free(*(void **)(param_1[2] + (ulong)uVar1 * 8));
    }
    _av_encryption_init_info_free(param_1[6]);
    _av_free((void *)*param_1);
    _av_free((void *)param_1[2]);
    _av_free((void *)param_1[4]);
    _av_free(param_1);
    return;
  }
  return;
}


