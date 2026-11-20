/* Decompiled from supplied 5.2.2 arm package. VA 0x24defc. FUN_0024defc */

void FUN_0024defc(int *param_1,long param_2,short *param_3,int param_4,int param_5,uint param_6,
                 ulong param_7)

{
  long lVar1;
  int iVar2;
  long lVar3;
  short *psVar4;
  
  for (lVar1 = 0; lVar1 < param_5; lVar1 = lVar1 + 1) {
    iVar2 = 0;
    *param_1 = 0;
    psVar4 = param_3;
    for (lVar3 = 0; lVar3 < param_4; lVar3 = lVar3 + 1) {
      iVar2 = ((int)*psVar4 * (int)*(short *)(param_2 + lVar3 * 2) >> (param_6 & 0x1f)) + iVar2;
      *param_1 = iVar2;
      psVar4 = psVar4 + 1;
    }
    param_1 = param_1 + 1;
    param_3 = (short *)((long)param_3 +
                       (-(param_7 >> 0x1f & 1) & 0xfffffffe00000000 | (param_7 & 0xffffffff) << 1));
  }
  return;
}


