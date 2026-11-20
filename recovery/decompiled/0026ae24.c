/* Decompiled from supplied 5.2.2 arm package. VA 0x26ae24. _av_ripemd_final */

void _av_ripemd_final(byte *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long local_38;
  
  local_38 = *(long *)(param_1 + 8) << 3;
  _av_ripemd_update(param_1,s__00b9cd75,1);
  while ((*(ulong *)(param_1 + 8) & 0x3f) != 0x38) {
    _av_ripemd_update(param_1,"",1);
  }
  _av_ripemd_update(param_1,&local_38,8);
  lVar1 = 0;
  for (lVar2 = 0; lVar2 < (long)(ulong)*param_1; lVar2 = lVar2 + 1) {
    *(undefined4 *)(param_2 + (int)lVar1) = *(undefined4 *)(param_1 + lVar1 + 0x50);
    lVar1 = lVar1 + 4;
  }
  return;
}


