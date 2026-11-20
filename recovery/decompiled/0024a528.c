/* Decompiled from supplied 5.2.2 arm package. VA 0x24a528. FUN_0024a528 */

undefined8 FUN_0024a528(long param_1,ulong param_2,int param_3)

{
  short sVar1;
  short sVar2;
  undefined8 uVar3;
  short *psVar4;
  long lVar5;
  short *psVar6;
  short sVar7;
  int iVar8;
  long lVar9;
  
  uVar3 = 0;
  iVar8 = 0;
  do {
    if (iVar8 == 2) {
      return uVar3;
    }
    psVar4 = (short *)(param_1 + 2);
    for (lVar9 = 0; lVar9 < param_3; lVar9 = lVar9 + 1) {
      psVar6 = psVar4;
      for (lVar5 = 0; lVar5 < (int)param_2 + -1; lVar5 = lVar5 + 1) {
        sVar1 = *psVar6;
        sVar2 = psVar6[-1];
        sVar7 = sVar2;
        if ((int)sVar1 - (int)sVar2 < 0x13f) {
          if ((int)sVar2 <= (int)sVar1) {
            sVar7 = sVar2 + -0xa0;
            psVar6[-1] = sVar7;
            sVar2 = sVar1;
          }
          *psVar6 = sVar2 + 0xa0;
          uVar3 = 1;
        }
        if (sVar7 < 0x52) {
          psVar6[-1] = 0x52;
LAB_0024a600:
          uVar3 = 1;
        }
        else if (0x647b < sVar7) {
          psVar6[-1] = 0x647b;
          goto LAB_0024a600;
        }
        psVar6 = psVar6 + 1;
      }
      psVar4 = (short *)((long)psVar4 +
                        (-(param_2 >> 0x1f & 1) & 0xfffffffe00000000 | (param_2 & 0xffffffff) << 1))
      ;
    }
    iVar8 = iVar8 + 1;
  } while( true );
}


