/* Decompiled from supplied 5.2.2 arm package. VA 0x25a4d0. _av_fifo_grow */

undefined8 _av_fifo_grow(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar1 = (param_1[9] - param_1[8]) + param_2;
  if (CARRY4(param_1[9] - param_1[8],param_2)) {
    return 0xffffffea;
  }
  uVar2 = param_1[6] - *param_1;
  if (uVar2 < uVar1) {
    if (uVar1 <= uVar2 * 2) {
      uVar1 = uVar2 * 2;
    }
    uVar3 = _av_fifo_realloc2(param_1,uVar1);
    return uVar3;
  }
  return 0;
}


