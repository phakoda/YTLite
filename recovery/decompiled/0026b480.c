/* Decompiled from supplied 5.2.2 arm package. VA 0x26b480. _av_samples_alloc_array_and_samples */

int _av_samples_alloc_array_and_samples
              (long *param_1,undefined8 param_2,int param_3,undefined4 param_4,uint param_5,
              undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  
  if (param_5 < 0xc) {
    uVar2 = (uint)(0xbe0L >> ((long)(int)param_5 & 0x3fU)) & 1;
  }
  else {
    uVar2 = 0;
  }
  lVar3 = (long)param_3;
  if (uVar2 == 0) {
    lVar3 = 1;
  }
  lVar3 = _av_calloc(lVar3,8);
  *param_1 = lVar3;
  if (lVar3 == 0) {
    iVar1 = -0xc;
  }
  else {
    iVar1 = _av_samples_alloc(lVar3,param_2,param_3,param_4,param_5,param_6);
    if (iVar1 < 0) {
      _av_freep(param_1);
    }
  }
  return iVar1;
}


