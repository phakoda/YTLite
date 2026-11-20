/* Decompiled from supplied 5.2.2 arm package. VA 0x24bce8. FUN_0024bce8 */

void FUN_0024bce8(long param_1,long param_2,int param_3)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  
  iVar3 = 0;
  iVar4 = 0;
  for (lVar2 = 0; lVar2 != 3; lVar2 = lVar2 + 1) {
    sVar1 = (&DAT_00c4f0d4)[lVar2];
    for (lVar6 = 0; iVar5 = (int)sVar1, lVar6 < sVar1; lVar6 = lVar6 + 1) {
      *(undefined2 *)(param_1 + (long)iVar3 * 2 + lVar6 * 2) =
           *(undefined2 *)
            (&DAT_00c4e854 +
            (long)(iVar4 + (int)lVar6 + iVar5 * *(short *)(param_2 + lVar2 * 2)) * 2);
    }
    iVar3 = iVar5 + iVar3;
    iVar4 = iVar4 + (short)(&DAT_00c4f0da)[lVar2] * iVar5;
  }
  if (1 < param_3) {
    iVar3 = 0;
    iVar4 = 0;
    for (lVar2 = 0; lVar2 != 3; lVar2 = lVar2 + 1) {
      sVar1 = (&DAT_00c4f0d4)[lVar2];
      for (lVar6 = 0; iVar5 = (int)sVar1, lVar6 < sVar1; lVar6 = lVar6 + 1) {
        *(undefined2 *)(param_1 + (long)(iVar3 + 10) * 2 + lVar6 * 2) =
             *(undefined2 *)
              (&DAT_00c4e854 +
              (long)(iVar4 + (int)lVar6 + iVar5 * *(short *)(param_2 + (lVar2 + 3) * 2)) * 2);
      }
      iVar3 = iVar5 + iVar3;
      iVar4 = iVar4 + (short)(&DAT_00c4f0da)[lVar2] * iVar5;
    }
  }
  return;
}


