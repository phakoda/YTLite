/* Decompiled from supplied 5.2.2 arm package. VA 0x26c950. _av_tea_init */

void _av_tea_init(long param_1,long param_2,undefined4 param_3)

{
  uint uVar1;
  long lVar2;
  
  for (lVar2 = 0; lVar2 != 0x10; lVar2 = lVar2 + 4) {
    uVar1 = (*(uint *)(param_2 + lVar2) & 0xff00ff00) >> 8 |
            (*(uint *)(param_2 + lVar2) & 0xff00ff) << 8;
    *(uint *)(param_1 + lVar2) = uVar1 >> 0x10 | uVar1 << 0x10;
  }
  *(undefined4 *)(param_1 + 0x40) = param_3;
  return;
}


