/* Decompiled from supplied 5.2.2 arm package. VA 0x266920. FUN_00266920 */

uint FUN_00266920(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 - 0x30;
  if (9 < uVar1) {
    if (param_1 - 0x61U < 6) {
      return param_1 - 0x57;
    }
    uVar1 = param_1 - 0x37;
    if (5 < param_1 - 0x41U) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}


