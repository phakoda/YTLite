/* Decompiled from supplied 5.2.2 arm package. VA 0x26d67c. FUN_0026d67c */

undefined8 FUN_0026d67c(int param_1)

{
  int *piVar1;
  ulong uVar2;
  
  uVar2 = 0;
  do {
    if (8 < uVar2) {
      return 0xffffffff;
    }
    piVar1 = &DAT_00c51df4 + uVar2;
    uVar2 = uVar2 + 1;
  } while (*piVar1 != param_1);
  return 0;
}


