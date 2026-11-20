/* Decompiled from supplied 5.2.2 arm package. VA 0x249710. FUN_00249710 */

int FUN_00249710(short *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int *piVar7;
  long lVar8;
  int iVar9;
  int local_6c [5];
  long local_58;
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  local_58 = lVar8;
  iVar4 = (*DAT_0191b7d0)(param_2,(int)param_1[1]);
  iVar4 = FUN_00249884(iVar4 * iVar4);
  param_2 = param_2 + 4;
  iVar9 = (int)param_1[2];
  iVar4 = iVar4 * 0x10000 + -0x180000 >> 0x10;
  iVar5 = 0;
  if (-1 < iVar4) {
    iVar5 = iVar4;
  }
  piVar7 = local_6c;
  for (; 1 < iVar9; iVar9 = iVar9 + -1) {
    iVar4 = FUN_0024e098(param_2,param_2,0x4c,iVar5);
    *piVar7 = iVar4;
    param_2 = param_2 + 0x50;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_6c;
  (*DAT_0191b7e8)(local_6c,(int)((uint)(ushort)param_1[2] * 0x10000 + -0x10000) >> 0x10);
  iVar4 = FUN_00249884();
  iVar5 = (int)param_1[2];
  uVar1 = iVar4 * 0x10000 + -0x140000 >> 0x10;
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    uVar2 = uVar1;
  }
  psVar6 = (short *)&UNK_00c4e426;
  iVar4 = iVar5;
  if (*param_1 != 0x14) {
    psVar6 = &DAT_00c4e424;
  }
  for (; 1 < iVar4; iVar4 = iVar4 + -1) {
    *piVar7 = (int)*psVar6 * (*piVar7 >> (uVar2 & 0x1f));
    psVar6 = psVar6 + 1;
    piVar7 = piVar7 + 1;
  }
  sVar3 = FUN_0024eacc(local_6c,iVar5 * 0x10000 + -0x10000 >> 0x10);
  if (lVar8 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return (int)(short)(sVar3 + 1);
}


