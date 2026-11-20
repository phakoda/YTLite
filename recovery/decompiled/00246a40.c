/* Decompiled from supplied 5.2.2 arm package. VA 0x246a40. FUN_00246a40 */

short FUN_00246a40(uint param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    sVar2 = 0;
  }
  else {
    param_1 = param_1 ^ (int)param_1 >> 0x1f;
    uVar3 = 0;
    if (param_1 >> 0xf == 0) {
      uVar3 = 0x10;
    }
    uVar1 = uVar3 | 8;
    if ((0xff800000U >> (ulong)uVar3 & param_1) != 0) {
      uVar1 = uVar3;
    }
    uVar3 = uVar1 | 4;
    if ((0xf8000000U >> (ulong)uVar1 & param_1) != 0) {
      uVar3 = uVar1;
    }
    uVar1 = uVar3 | 2;
    if ((0xe0000000U >> (ulong)uVar3 & param_1) != 0) {
      uVar1 = uVar3;
    }
    sVar2 = (short)uVar1;
    if ((0xc0000000U >> (ulong)(uint)(int)sVar2 & param_1) == 0) {
      sVar2 = sVar2 + 1;
    }
  }
  return sVar2;
}


