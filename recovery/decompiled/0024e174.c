/* Decompiled from supplied 5.2.2 arm package. VA 0x24e174. FUN_0024e174 */

undefined8
FUN_0024e174(long param_1,int param_2,undefined2 *param_3,int param_4,short *param_5,int param_6,
            uint param_7,int param_8)

{
  undefined2 uVar1;
  int iVar2;
  short *psVar3;
  long lVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  
  iVar2 = param_8 + (param_4 + -1) * param_7;
  if ((0 < param_4 && 0 < param_6) && iVar2 < param_2) {
    lVar4 = (long)param_8;
    psVar5 = (short *)(param_1 + (long)param_8 * 2);
    while (lVar4 <= iVar2) {
      iVar6 = 0x800;
      psVar3 = psVar5;
      psVar8 = param_5;
      for (iVar7 = param_6; iVar7 != 0; iVar7 = iVar7 + -1) {
        iVar6 = iVar6 + (int)*psVar3 * (int)*psVar8;
        psVar3 = psVar3 + -1;
        psVar8 = psVar8 + 1;
      }
      iVar6 = iVar6 >> 0xc;
      lVar4 = lVar4 + (int)param_7;
      iVar7 = iVar6;
      if (iVar6 < -0x7fff) {
        iVar7 = -0x8000;
      }
      uVar1 = 0x7fff;
      if (iVar6 < 0x8000) {
        uVar1 = (short)iVar7;
      }
      *param_3 = uVar1;
      psVar5 = (short *)((long)psVar5 +
                        (-(ulong)(param_7 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_7 << 1));
      param_3 = param_3 + 1;
    }
    return 0;
  }
  return 0xffffffff;
}


