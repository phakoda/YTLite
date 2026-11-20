/* Decompiled from supplied 5.2.2 arm package. VA 0x256d3c. FUN_00256d3c */

ulong FUN_00256d3c(ulong param_1,long param_2,int param_3)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = 0;
  for (lVar2 = 0; (int)lVar2 < param_3; lVar2 = lVar2 + 1) {
    uVar1 = param_1 >> ((ulong)*(byte *)(param_2 + lVar2) & 0x3f) & 1 | uVar1 << 1;
  }
  return uVar1;
}


