/* Decompiled from supplied 5.2.2 arm package. VA 0x27c328. FUN_0027c328 */

void FUN_0027c328(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(param_1 + 0x48);
  _av_freep(lVar1 + 0x20);
  _av_freep(lVar1 + 0x28);
  uVar2 = 0xffffffffffffffff;
  lVar1 = 0;
  while (uVar2 = uVar2 + 1, uVar2 < *(uint *)(param_1 + 0x40)) {
    _av_freep(*(long *)(param_1 + 0x30) + lVar1);
    lVar1 = lVar1 + 0x40;
  }
  return;
}


