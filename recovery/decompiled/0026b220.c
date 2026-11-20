/* Decompiled from supplied 5.2.2 arm package. VA 0x26b220. _av_samples_fill_arrays */

void _av_samples_fill_arrays
               (long *param_1,int *param_2,long param_3,int param_4,undefined4 param_5,uint param_6,
               undefined4 param_7)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int local_44;
  
  if (param_6 < 0xc) {
    iVar3 = *(int *)(&DAT_00c51930 + (long)(int)param_6 * 0x14);
  }
  else {
    iVar3 = 0;
  }
  iVar1 = _av_samples_get_buffer_size(&local_44,param_4,param_5,param_6,param_7);
  if (-1 < iVar1) {
    *param_1 = param_3;
    param_3 = param_3 + local_44;
    for (lVar2 = 1; (iVar3 != 0 && (lVar2 < param_4)); lVar2 = lVar2 + 1) {
      param_1[lVar2] = param_3;
      param_3 = param_3 + local_44;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_44;
    }
  }
  return;
}


