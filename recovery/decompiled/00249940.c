/* Decompiled from supplied 5.2.2 arm package. VA 0x249940. FUN_00249940 */

int FUN_00249940(int param_1,int param_2,uint param_3,undefined2 *param_4)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  
  iVar4 = param_1 * 0x4000;
  iVar3 = 0x666;
  if (0x665 < param_2) {
    iVar3 = param_2;
  }
  puVar7 = (&PTR_DAT_01063740)[(int)param_3];
  uVar5 = 0x20 >> (ulong)(param_3 & 0x1f);
  iVar8 = (int)(uVar5 << 0x10) >> 0x11;
  psVar10 = (short *)(puVar7 + (long)iVar8 * 2);
  iVar11 = 5 - param_3;
  iVar6 = iVar8;
  while (iVar11 = iVar11 + -1, 0 < iVar11) {
    iVar6 = iVar6 >> 1;
    lVar2 = -(long)iVar6;
    if (*psVar10 * iVar3 < iVar4) {
      lVar2 = (long)iVar6;
    }
    iVar1 = -iVar6;
    if (*psVar10 * iVar3 < iVar4) {
      iVar1 = iVar6;
    }
    iVar8 = iVar1 + iVar8;
    psVar10 = psVar10 + lVar2;
  }
  iVar6 = *psVar10 * iVar3;
  if (iVar4 - iVar6 == 0 || iVar4 < iVar6) {
    uVar9 = -(uint)(iVar4 - psVar10[-1] * iVar3 <= iVar6 + param_1 * -0x4000);
  }
  else {
    uVar9 = (uint)(param_1 * -0x4000 + psVar10[1] * iVar3 < iVar4 - iVar6);
  }
  iVar6 = (short)uVar5 + -1;
  iVar4 = uVar9 + iVar8;
  if (iVar6 <= (int)(uVar9 + iVar8)) {
    iVar4 = iVar6;
  }
  *param_4 = (short)iVar4;
  return (int)(short)(*(short *)(puVar7 + (long)iVar4 * 2) * iVar3 + 0x2000U >> 0xe);
}


