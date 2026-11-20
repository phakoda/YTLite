/* Decompiled from supplied 5.2.2 arm package. VA 0x261e04. _av_dynarray_add_nofree */

undefined8 _av_dynarray_add_nofree(long *param_1,uint *param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = *param_1;
  uVar1 = *param_2;
  uVar3 = (ulong)(int)uVar1;
  if ((uVar1 - 1 & uVar1) == 0) {
    uVar3 = 1;
    if (uVar1 != 0) {
      uVar3 = (long)(int)(uVar1 << 1);
    }
    if (uVar3 >> 0x1c != 0) {
      return 0xfffffff4;
    }
    lVar2 = _av_realloc(lVar2,uVar3 << 3);
    if (lVar2 == 0) {
      return 0xfffffff4;
    }
  }
  if (uVar3 == 0) {
    return 0xfffffff4;
  }
  *(undefined8 *)(lVar2 + (long)(int)*param_2 * 8) = param_3;
  *param_1 = lVar2;
  *param_2 = *param_2 + 1;
  return 0;
}


