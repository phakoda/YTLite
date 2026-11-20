/* Decompiled from supplied 5.2.2 arm package. VA 0x26e054. FUN_0026e054 */

uint FUN_0026e054(undefined8 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)param_1;
  if (param_2 < 3) {
    uVar1 = uVar1 & 1;
  }
  else if ((uVar1 & param_2 >> 1) == 0) {
    iVar2 = FUN_0026e054(param_1,param_2 >> 1,param_3);
    uVar1 = iVar2 << 1;
  }
  else {
    iVar2 = FUN_0026e054(param_1,param_2 >> 2,param_3);
    if (((uVar1 & param_2 >> 2) == 0) == param_3) {
      uVar1 = iVar2 * 4 | 1;
    }
    else {
      uVar1 = iVar2 * 4 - 1;
    }
  }
  return uVar1;
}


