/* Decompiled from supplied 5.2.2 arm package. VA 0x24d19c. FUN_0024d19c */

void FUN_0024d19c(long param_1,undefined2 *param_2,long param_3,short *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  
  sVar4 = 0;
  uVar3 = 0;
  iVar6 = 0x7fffffff;
  for (uVar5 = 0; (short)uVar5 < param_5; uVar5 = uVar5 + 1) {
    iVar7 = (int)(short)(*param_4 - *(short *)(param_3 + (long)sVar4 * 2));
    iVar7 = iVar7 * iVar7;
    for (lVar8 = 2; lVar8 != 8; lVar8 = lVar8 + 2) {
      iVar1 = (int)(short)(*(short *)((long)param_4 + lVar8) -
                          *(short *)(param_3 + (long)sVar4 * 2 + lVar8));
      iVar7 = iVar7 + iVar1 * iVar1;
    }
    sVar4 = sVar4 + 4;
    uVar2 = uVar5;
    if (iVar6 <= iVar7) {
      iVar7 = iVar6;
      uVar2 = uVar3;
    }
    uVar3 = uVar2;
    iVar6 = iVar7;
  }
  for (lVar8 = 0; lVar8 != 8; lVar8 = lVar8 + 2) {
    *(undefined2 *)(param_1 + lVar8) =
         *(undefined2 *)
          (param_3 + (long)(int)(-(uVar3 >> 0xf & 1) & 0xfffc0000 | (uVar3 & 0xffff) << 2) * 2 +
          lVar8);
  }
  *param_2 = (short)uVar3;
  return;
}


