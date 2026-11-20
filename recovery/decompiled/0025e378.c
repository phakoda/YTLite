/* Decompiled from supplied 5.2.2 arm package. VA 0x25e378. FUN_0025e378 */

undefined8 FUN_0025e378(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = _av_buffer_pool_get(*(undefined8 *)(param_1 + 0x38));
  *(long *)(param_2 + 0x120) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = *(undefined8 *)(lVar1 + 8);
    *(undefined4 *)(param_2 + 0x74) = 0xa0;
    *(undefined8 *)(param_2 + 0x18) = uVar2;
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x4c);
    uVar2 = 0;
    *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_1 + 0x50);
  }
  return uVar2;
}


