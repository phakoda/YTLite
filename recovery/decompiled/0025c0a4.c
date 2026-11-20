/* Decompiled from supplied 5.2.2 arm package. VA 0x25c0a4. FUN_0025c0a4 */

void FUN_0025c0a4(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = -1;
  lVar1 = 0;
  while (lVar2 = lVar2 + 1, lVar2 < *(int *)(param_1 + 0x178)) {
    FUN_0025c40c(*(long *)(param_1 + 0x170) + lVar1);
    lVar1 = lVar1 + 8;
  }
  *(undefined4 *)(param_1 + 0x178) = 0;
  _av_freep((long *)(param_1 + 0x170));
  return;
}


