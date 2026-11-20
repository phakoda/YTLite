/* Decompiled from supplied 5.2.2 arm package. VA 0x25ae0c. FUN_0025ae0c */

ulong FUN_0025ae0c(long param_1,long param_2,int param_3)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = 0x40000000;
  for (lVar2 = 0; lVar2 < param_3; lVar2 = lVar2 + 1) {
    uVar1 = uVar1 + (long)*(int *)(param_2 + lVar2 * 4) * (long)*(int *)(param_1 + lVar2 * 4);
  }
  return uVar1 >> 0x1f;
}


