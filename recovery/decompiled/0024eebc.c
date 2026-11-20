/* Decompiled from supplied 5.2.2 arm package. VA 0x24eebc. FUN_0024eebc */

int FUN_0024eebc(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar3 = param_1 + -0x40000000;
  if (param_1 < 0x40000000) {
    iVar3 = param_1;
  }
  uVar7 = (uint)(0x3fffffff < param_1);
  uVar2 = uVar7 << 0x1e | 0x10000000;
  uVar7 = uVar7 << 0x10;
  uVar4 = 0;
  if ((int)uVar2 <= iVar3) {
    uVar7 = (uint)(0x3fffffff < param_1) << 0x10 | 0x8000;
    uVar4 = uVar2;
  }
  uVar2 = (uVar7 >> 0xf) << 0x1c | 0x4000000;
  uVar5 = 0;
  if ((int)uVar2 <= (int)(iVar3 - uVar4)) {
    uVar7 = uVar7 | 0x4000;
    uVar5 = uVar2;
  }
  iVar3 = (iVar3 - uVar4) - uVar5;
  uVar2 = (uVar7 >> 0xe) << 0x1a | 0x1000000;
  uVar4 = 0;
  if ((int)uVar2 <= iVar3) {
    uVar7 = uVar7 | 0x2000;
    uVar4 = uVar2;
  }
  iVar3 = iVar3 - uVar4;
  iVar1 = uVar7 * 0x800 + 0x400000;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x1000;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x400 + 0x100000;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x800;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x200 + 0x40000;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x400;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x100 + 0x10000;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x200;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x80 + 0x4000;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x100;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x40 + 0x1000;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x80;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x20 + 0x400;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x40;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 0x10 + 0x100;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x20;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 8 + 0x40;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 0x10;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 4 + 0x10;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 8;
    iVar6 = iVar1;
  }
  iVar3 = iVar3 - iVar6;
  iVar1 = uVar7 * 2 + 4;
  iVar6 = 0;
  if (iVar1 <= iVar3) {
    uVar7 = uVar7 | 4;
    iVar6 = iVar1;
  }
  uVar2 = uVar7 | 2;
  if (iVar3 - iVar6 <= (int)uVar7) {
    uVar2 = uVar7;
  }
  return (int)uVar2 >> 1;
}


