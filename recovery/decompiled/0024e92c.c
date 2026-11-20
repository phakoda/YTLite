/* Decompiled from supplied 5.2.2 arm package. VA 0x24e92c. FUN_0024e92c */

uint FUN_0024e92c(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_1 != (uint *)0x0) && (0 < param_2)) {
    uVar3 = 0;
    for (; param_2 != 0; param_2 = param_2 + -1) {
      uVar2 = *param_1;
      uVar1 = -uVar2;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2;
      }
      if (uVar1 <= uVar3) {
        uVar1 = uVar3;
      }
      param_1 = param_1 + 1;
      uVar3 = uVar1;
    }
    if (0x7ffffffe < uVar3) {
      uVar3 = 0x7fffffff;
    }
  }
  return uVar3;
}


