/* Decompiled from supplied 5.2.2 arm package. VA 0x248a78. FUN_00248a78 */

void FUN_00248a78(long param_1,short *param_2)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short *psVar10;
  long lVar11;
  
  psVar10 = &DAT_00c4f624;
  for (lVar11 = 0; lVar11 != 0x10; lVar11 = lVar11 + 4) {
    sVar2 = param_2[2];
    sVar8 = psVar10[-2];
    sVar3 = param_2[1];
    sVar9 = psVar10[-1];
    sVar4 = *param_2;
    sVar5 = *psVar10;
    *(int *)(param_1 + lVar11) =
         (int)sVar8 * (int)sVar2 + (int)sVar9 * (int)sVar3 + (int)sVar5 * (int)sVar4;
    sVar6 = param_2[3];
    sVar7 = psVar10[1];
    *(int *)(param_1 + lVar11 + 0x10) =
         (int)sVar8 * (int)sVar6 + (int)sVar9 * (int)sVar2 + (int)sVar5 * (int)sVar3 +
         (int)sVar7 * (int)sVar4;
    psVar1 = psVar10 + 2;
    psVar10 = psVar10 + 7;
    *(int *)(param_1 + lVar11 + 0x20) =
         (int)sVar8 * (int)param_2[4] + (int)sVar9 * (int)sVar6 + (int)sVar5 * (int)sVar2 +
         (int)sVar7 * (int)sVar3 + (int)*psVar1 * (int)sVar4;
  }
  psVar10 = &DAT_00c4f624;
  for (lVar11 = 0; lVar11 != 0x10; lVar11 = lVar11 + 4) {
    sVar2 = param_2[4];
    psVar1 = psVar10 + -1;
    sVar3 = param_2[3];
    sVar4 = *psVar10;
    sVar5 = param_2[2];
    sVar6 = psVar10[1];
    sVar7 = psVar10[2];
    psVar10 = psVar10 + 7;
    *(int *)(param_1 + 0x30 + lVar11) =
         (int)*psVar1 * (int)sVar2 + (int)sVar4 * (int)sVar3 + (int)sVar6 * (int)sVar5 +
         (int)sVar7 * (int)param_2[1];
    *(int *)(param_1 + 0x30 + lVar11 + 0x10) =
         (int)sVar4 * (int)sVar2 + (int)sVar6 * (int)sVar3 + (int)sVar7 * (int)sVar5;
  }
  return;
}


