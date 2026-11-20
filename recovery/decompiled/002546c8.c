/* Decompiled from supplied 5.2.2 arm package. VA 0x2546c8. _av_bprint_init */

void _av_bprint_init(long *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined1 *)((long)param_1 + 0x14) = 0;
  uVar1 = 0x3ec;
  if (param_3 != 1) {
    uVar1 = param_3;
  }
  *param_1 = (long)param_1 + 0x14;
  uVar2 = uVar1;
  if (0x3eb < uVar1) {
    uVar2 = 0x3ec;
  }
  *(uint *)((long)param_1 + 0xc) = uVar2;
  *(uint *)(param_1 + 2) = uVar1;
  if (uVar2 < param_2) {
    FUN_00254704(param_1,param_2 - 1);
    return;
  }
  return;
}


