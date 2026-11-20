/* Decompiled from supplied 5.2.2 arm package. VA 0x262338. _av_fast_realloc */

long _av_fast_realloc(long param_1,uint *param_2,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*param_2 < param_3) {
    if (DAT_011d3248 < param_3) {
      param_1 = 0;
      *param_2 = 0;
    }
    else {
      uVar1 = param_3 + (param_3 >> 4) + 0x20;
      uVar3 = (uint)uVar1;
      if (uVar1 <= param_3) {
        uVar3 = (uint)param_3;
        uVar1 = param_3;
      }
      if (DAT_011d3248 <= uVar1) {
        uVar3 = (uint)DAT_011d3248;
        uVar1 = DAT_011d3248;
      }
      param_1 = _av_realloc(param_1,uVar1);
      uVar2 = 0;
      if (param_1 != 0) {
        uVar2 = uVar3;
      }
      *param_2 = uVar2;
    }
  }
  return param_1;
}


