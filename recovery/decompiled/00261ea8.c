/* Decompiled from supplied 5.2.2 arm package. VA 0x261ea8. _av_dynarray_add */

void _av_dynarray_add(long *param_1,uint *param_2,undefined8 param_3)

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
    if ((uVar3 >> 0x1c != 0) || (lVar2 = _av_realloc(lVar2,uVar3 << 3), lVar2 == 0))
    goto LAB_00261f30;
  }
  if (uVar3 != 0) {
    *(undefined8 *)(lVar2 + (long)(int)*param_2 * 8) = param_3;
    *param_1 = lVar2;
    *param_2 = *param_2 + 1;
    return;
  }
LAB_00261f30:
  *param_2 = 0;
  _av_freep(param_1);
  return;
}


