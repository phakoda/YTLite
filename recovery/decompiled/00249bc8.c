/* Decompiled from supplied 5.2.2 arm package. VA 0x249bc8. FUN_00249bc8 */

void FUN_00249bc8(short *param_1,undefined4 *param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint *puVar7;
  long lVar8;
  uint uVar9;
  
  lVar4 = 0;
  *param_2 = 0x1000000;
  puVar7 = param_2 + 2;
  lVar5 = -1;
  param_2[1] = *param_1 * -0x400;
  for (lVar6 = 2; lVar6 != 6; lVar6 = lVar6 + 1) {
    param_1 = param_1 + 2;
    *puVar7 = puVar7[-2];
    uVar9 = puVar7[-2];
    for (lVar8 = lVar4; 1 < (int)lVar8 + 2; lVar8 = lVar8 + -1) {
      piVar2 = param_2 + lVar8;
      uVar3 = piVar2[1];
      piVar2[2] = uVar9 + *piVar2 +
                  ((int)*param_1 * ((int)uVar3 >> 0x10) +
                  (((int)((uVar3 - (uVar3 & 0x10000)) * 0x8000) >> 0x10) * (int)*param_1 >> 0xf)) *
                  -4;
      uVar9 = uVar3;
    }
    puVar1 = puVar7 + lVar5;
    lVar5 = lVar5 + -1;
    puVar7 = puVar1 + lVar6;
    *puVar1 = *puVar1 + *param_1 * -0x400;
    lVar4 = lVar4 + 1;
  }
  return;
}


