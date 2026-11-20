/* Decompiled from supplied 5.2.2 arm package. VA 0x24a830. FUN_0024a830 */

void FUN_0024a830(long param_1,long param_2,short param_3)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  short *psVar5;
  undefined2 *puVar6;
  short sVar7;
  short *psVar8;
  short sVar9;
  
  psVar5 = (short *)(param_1 + 0x12);
  sVar7 = 0x3f;
  psVar8 = &DAT_00c4f19a;
  puVar6 = (undefined2 *)(param_2 + 0x12);
  while (param_3 = param_3 + -1, -1 < param_3) {
    sVar1 = *psVar5;
    sVar9 = sVar7 << 9;
    while( true ) {
      sVar2 = *psVar8;
      bVar3 = false;
      bVar4 = false;
      if (0 < sVar7) {
        bVar4 = SBORROW4((int)sVar2,(int)sVar1);
        bVar3 = (int)sVar2 - (int)sVar1 < 0;
      }
      if (bVar3 == bVar4) break;
      psVar8 = psVar8 + -1;
      sVar7 = sVar7 + -1;
      sVar9 = sVar9 + -0x200;
    }
    psVar5 = psVar5 + -1;
    *puVar6 = (short)((uint)((short)(sVar9 + (short)((uint)((int)*(short *)(&UNK_00c4f296 +
                                                                           (long)sVar7 * 2) *
                                                           (int)(short)(sVar1 - sVar2)) >> 0xb)) *
                            0x6488) >> 0xf);
    puVar6 = puVar6 + -1;
  }
  return;
}


