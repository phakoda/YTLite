/* Decompiled from supplied 5.2.2 arm package. VA 0x27b9d0. FUN_0027b9d0 */

undefined1  [16] FUN_0027b9d0(double param_1,long param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  iVar1 = (int)param_1;
  if (*(int *)(param_2 + 0x2c) <= (int)param_1) {
    iVar1 = *(int *)(param_2 + 0x2c) + -1;
  }
  auVar2._0_8_ = *(ulong *)(*(long *)(param_2 + 0x98) + (long)iVar1 * 8);
  auVar2._8_8_ = 0;
  return auVar2;
}


