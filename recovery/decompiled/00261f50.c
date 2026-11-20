/* Decompiled from supplied 5.2.2 arm package. VA 0x261f50. _av_dynarray2_add */

void * _av_dynarray2_add(long *param_1,uint *param_2,ulong param_3,void *param_4)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  void *pvVar4;
  ulong uVar5;
  
  uVar3 = *param_2;
  uVar5 = (ulong)(int)uVar3;
  if ((uVar3 - 1 & uVar3) == 0) {
    uVar5 = 1;
    if (uVar3 != 0) {
      uVar5 = (long)(int)(uVar3 << 1);
    }
    uVar1 = 0;
    if (param_3 != 0) {
      uVar1 = 0x7fffffff / param_3;
    }
    if ((uVar5 <= uVar1) && (lVar2 = _av_realloc(*param_1,uVar5 * param_3), lVar2 != 0)) {
      *param_1 = lVar2;
      goto LAB_00261fbc;
    }
  }
  else {
LAB_00261fbc:
    if (uVar5 != 0) {
      uVar3 = *param_2;
      pvVar4 = (void *)(*param_1 + (long)(int)uVar3 * param_3);
      if (param_4 != (void *)0x0) {
        _memcpy(pvVar4,param_4,param_3);
        uVar3 = *param_2;
      }
      uVar3 = uVar3 + 1;
      goto LAB_00261ffc;
    }
  }
  _av_freep(param_1);
  uVar3 = 0;
  pvVar4 = (void *)0x0;
LAB_00261ffc:
  *param_2 = uVar3;
  return pvVar4;
}


