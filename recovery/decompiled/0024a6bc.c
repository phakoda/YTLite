/* Decompiled from supplied 5.2.2 arm package. VA 0x24a6bc. FUN_0024a6bc */

void FUN_0024a6bc(long param_1,long param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  for (lVar3 = 0; lVar3 < param_3; lVar3 = lVar3 + 1) {
    uVar2 = *(short *)(param_1 + lVar3 * 2) * 0xa2fa;
    lVar1 = 0x3f;
    if ((int)uVar2 >> 0x18 < 0x40) {
      lVar1 = (long)(short)(char)(uVar2 >> 0x18);
    }
    *(short *)(param_2 + lVar3 * 2) =
         *(short *)(&DAT_00c4f11c + lVar1 * 2) +
         (short)((uVar2 >> 0x10 & 0xff) * (int)*(short *)(&DAT_00c4f19c + lVar1 * 2) >> 0xc);
  }
  return;
}


