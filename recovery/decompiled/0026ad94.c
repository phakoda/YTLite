/* Decompiled from supplied 5.2.2 arm package. VA 0x26ad94. _av_ripemd_update */

void _av_ripemd_update(long param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(long *)(param_1 + 8) & 0x3f;
  *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + (ulong)param_3;
  for (; param_3 != 0; param_3 = param_3 - 1) {
    uVar1 = uVar2 + 1;
    *(undefined1 *)(param_1 + (ulong)uVar2 + 0x10) = *param_2;
    uVar2 = uVar1;
    if (uVar1 == 0x40) {
      (**(code **)(param_1 + 0x78))(param_1 + 0x50,param_1 + 0x10);
      uVar2 = 0;
    }
    param_2 = param_2 + 1;
  }
  return;
}


