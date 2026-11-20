/* Decompiled from supplied 5.2.2 arm package. VA 0x246ca0. FUN_00246ca0 */

void FUN_00246ca0(int param_1,int param_2,undefined2 param_3,uint param_4,int param_5,int param_6,
                 int *param_7,short *param_8,undefined2 *param_9,undefined2 *param_10)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  sVar5 = *param_8;
  iVar7 = sVar5 - param_2;
  if (sVar5 < param_2) {
    uVar6 = 0;
    iVar7 = 0x1f;
    if (param_2 - sVar5 < 0x20) {
      iVar7 = param_2 - sVar5;
    }
    uVar8 = (uint)(short)iVar7;
  }
  else {
    uVar8 = 0;
    iVar2 = 0x1f;
    if (iVar7 < 0x20) {
      iVar2 = iVar7;
    }
    uVar6 = (uint)(short)iVar2;
  }
  if (*param_7 >> (uVar8 & 0x1f) < param_1 >> (uVar6 & 0x1f)) {
    if (param_4 == 0) {
      uVar8 = 0;
    }
    else {
      uVar6 = param_4 ^ (int)param_4 >> 0x1f;
      uVar8 = 0;
      if (uVar6 >> 0xf == 0) {
        uVar8 = 0x10;
      }
      uVar3 = uVar8 | 8;
      if ((0xff800000U >> (ulong)uVar8 & uVar6) != 0) {
        uVar3 = uVar8;
      }
      uVar4 = uVar3 | 4;
      if ((0xf8000000U >> (ulong)uVar3 & uVar6) != 0) {
        uVar4 = uVar3;
      }
      uVar8 = uVar4 | 2;
      if ((0xe0000000U >> (ulong)uVar4 & uVar6) != 0) {
        uVar8 = uVar4;
      }
      if ((0xc0000000U >> (ulong)(uint)(int)(short)uVar8 & uVar6) == 0) {
        uVar8 = (int)(short)uVar8 + 1;
      }
    }
    sVar5 = (short)(0x10 - uVar8);
    uVar6 = (param_6 + sVar5) * -0x10000 + 0x1f0000 >> 0x10;
    uVar3 = 0x1f;
    if ((int)uVar6 < 0x20) {
      uVar3 = uVar6;
    }
    sVar1 = (short)(param_4 << (ulong)(-(int)sVar5 & 0x1f));
    if (0xffff < (int)((0x10 - uVar8) * 0x10000)) {
      sVar1 = (short)((int)param_4 >> ((int)sVar5 & 0x1fU));
    }
    iVar7 = sVar1 * param_5 >> (uVar3 & 0x1f);
    if (iVar7 < 0x5334) {
      if (iVar7 < -0x5333) {
        iVar7 = 0xaccd;
      }
    }
    else {
      iVar7 = 0x5333;
    }
    *param_10 = (short)iVar7;
    *param_7 = param_1;
    *param_8 = (short)param_2;
    *param_9 = param_3;
  }
  return;
}


