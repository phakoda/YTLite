/* Decompiled from supplied 5.2.2 arm package. VA 0x26b11c. _av_samples_get_buffer_size */

int _av_samples_get_buffer_size(uint *param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = _av_get_bytes_per_sample(param_4);
  if (param_4 < 0xc) {
    iVar4 = *(int *)(&DAT_00c51930 + (long)(int)param_4 * 0x14);
  }
  else {
    iVar4 = 0;
  }
  if (param_2 < 1 || (int)param_3 < 1) {
    return -0x16;
  }
  if (iVar3 == 0) {
    return -0x16;
  }
  if (param_5 == 0) {
    if (0x7fffffe0 < (int)param_3) {
      return -0x16;
    }
    param_3 = param_3 + 0x1f & 0xffffffe0;
    param_5 = 1;
  }
  iVar2 = 0;
  if (param_5 != 0) {
    iVar2 = 0x7fffffff / param_5;
  }
  if (param_2 <= iVar2) {
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = (0x7fffffff - param_5 * param_2) / iVar3;
    }
    if ((long)(int)param_3 * (long)param_2 - (long)iVar2 == 0 ||
        (long)(int)param_3 * (long)param_2 < (long)iVar2) {
      iVar3 = param_3 * iVar3;
      if (iVar4 == 0) {
        iVar3 = iVar3 * param_2;
      }
      uVar1 = (param_5 + iVar3) - 1U & -param_5;
      if (param_1 != (uint *)0x0) {
        *param_1 = uVar1;
      }
      if (iVar4 == 0) {
        param_2 = 1;
      }
      return uVar1 * param_2;
    }
  }
  return -0x16;
}


