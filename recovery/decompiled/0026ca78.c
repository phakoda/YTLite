/* Decompiled from supplied 5.2.2 arm package. VA 0x26ca78. FUN_0026ca78 */

void FUN_0026ca78(int *param_1,uint *param_2,uint *param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = param_1[0x10];
  uVar4 = (*param_3 & 0xff00ff00) >> 8 | (*param_3 & 0xff00ff) << 8;
  uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
  uVar5 = (param_3[1] & 0xff00ff00) >> 8 | (param_3[1] & 0xff00ff) << 8;
  uVar5 = uVar5 >> 0x10 | uVar5 << 0x10;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 1;
  }
  iVar1 = iVar1 >> 1;
  if (param_4 == 0) {
    iVar6 = -1;
    iVar7 = -0x61c88647;
    while (iVar6 = iVar6 + 1, iVar6 < iVar1) {
      uVar4 = (param_1[1] + (uVar5 >> 5) ^ *param_1 + uVar5 * 0x10 ^ iVar7 + uVar5) + uVar4;
      uVar2 = iVar7 + uVar4;
      iVar7 = iVar7 + -0x61c88647;
      uVar5 = (param_1[2] + uVar4 * 0x10 ^ uVar2 ^ param_1[3] + (uVar4 >> 5)) + uVar5;
    }
  }
  else {
    iVar7 = iVar1 * -0x61c88647;
    iVar6 = -1;
    while (iVar6 = iVar6 + 1, iVar6 < iVar1) {
      uVar5 = uVar5 - (param_1[2] + uVar4 * 0x10 ^ iVar7 + uVar4 ^ param_1[3] + (uVar4 >> 5));
      uVar2 = iVar7 + uVar5;
      iVar7 = iVar7 + 0x61c88647;
      uVar4 = uVar4 - (*param_1 + uVar5 * 0x10 ^ uVar2 ^ param_1[1] + (uVar5 >> 5));
    }
    if (param_5 != (uint *)0x0) {
      uVar2 = (*param_5 & 0xff00ff00) >> 8 | (*param_5 & 0xff00ff) << 8;
      uVar3 = (param_5[1] & 0xff00ff00) >> 8 | (param_5[1] & 0xff00ff) << 8;
      uVar4 = (uVar2 >> 0x10 | uVar2 << 0x10) ^ uVar4;
      uVar5 = (uVar3 >> 0x10 | uVar3 << 0x10) ^ uVar5;
      *(undefined8 *)param_5 = *(undefined8 *)param_3;
    }
  }
  uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
  uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
  *param_2 = uVar4 >> 0x10 | uVar4 << 0x10;
  param_2[1] = uVar5 >> 0x10 | uVar5 << 0x10;
  return;
}


