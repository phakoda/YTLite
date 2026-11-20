/* Decompiled from supplied 5.2.2 arm package. VA 0x24d0e8. FUN_0024d0e8 */

void FUN_0024d0e8(long param_1,short *param_2,long param_3,short *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  
  sVar4 = 0;
  uVar3 = 0;
  iVar6 = 0x7fffffff;
  for (uVar5 = 0; (short)uVar5 < param_5; uVar5 = uVar5 + 1) {
    iVar8 = (int)(short)(*param_4 - *(short *)(param_3 + (long)sVar4 * 2));
    iVar8 = iVar8 * iVar8;
    for (lVar7 = 0; lVar7 != 4; lVar7 = lVar7 + 2) {
      iVar1 = (int)(short)(*(short *)((long)param_4 + lVar7 + 2) -
                          *(short *)(param_3 + 2 + (long)sVar4 * 2 + lVar7));
      iVar8 = iVar8 + iVar1 * iVar1;
    }
    sVar4 = sVar4 + 3;
    uVar2 = uVar5;
    if (iVar6 <= iVar8) {
      iVar8 = iVar6;
      uVar2 = uVar3;
    }
    uVar3 = uVar2;
    iVar6 = iVar8;
  }
  for (lVar7 = 0; lVar7 != 6; lVar7 = lVar7 + 2) {
    *(undefined2 *)(param_1 + lVar7) =
         *(undefined2 *)
          (param_3 + (long)(int)((-(uVar3 >> 0xf & 1) & 0xfffe0000 | (uVar3 & 0xffff) << 1) +
                                (int)(short)uVar3) * 2 + lVar7);
  }
  *param_2 = (short)uVar3;
  return;
}


