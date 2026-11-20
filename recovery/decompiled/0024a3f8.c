/* Decompiled from supplied 5.2.2 arm package. VA 0x24a3f8. FUN_0024a3f8 */

void FUN_0024a3f8(long param_1,long param_2,int param_3)

{
  short *psVar1;
  long lVar2;
  long lVar3;
  short *psVar4;
  long lVar5;
  
  param_2 = param_2 + (long)param_3 * 2;
  for (lVar2 = 0; lVar2 != 0x14; lVar2 = lVar2 + 1) {
    lVar5 = 6;
    psVar4 = (short *)(param_2 + lVar2 * -2 + -0x30);
    for (lVar3 = 0; lVar3 != 8; lVar3 = lVar3 + 2) {
      psVar1 = (short *)((long)&DAT_00c4f538 + lVar5);
      lVar5 = lVar5 + -2;
      *(short *)(param_1 + lVar3) =
           (short)((uint)((int)*psVar4 * (int)*(short *)((long)&DAT_00c4f538 + lVar3)) >> 0xf) +
           (short)((uint)((int)*(short *)(param_2 + -8 + lVar3) * (int)*psVar1) >> 0xf);
      psVar4 = psVar4 + 1;
    }
    param_1 = param_1 + 8;
  }
  return;
}


