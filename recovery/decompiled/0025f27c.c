/* Decompiled from supplied 5.2.2 arm package. VA 0x25f27c. _av_image_fill_arrays */

void _av_image_fill_arrays
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,int param_7)

{
  int iVar1;
  long lVar2;
  
  iVar1 = _av_image_check_size(param_5,param_6,0,0);
  if ((-1 < iVar1) && (iVar1 = _av_image_fill_linesizes(param_2,param_4,param_5), -1 < iVar1)) {
    for (lVar2 = 0; lVar2 != 0x10; lVar2 = lVar2 + 4) {
      *(int *)(param_2 + lVar2) = param_7 + -1 + *(int *)(param_2 + lVar2) & -param_7;
    }
    _av_image_fill_pointers(param_1,param_4,param_6,param_3,param_2);
    return;
  }
  return;
}


