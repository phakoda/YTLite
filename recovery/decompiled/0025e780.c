/* Decompiled from supplied 5.2.2 arm package. VA 0x25e780. _av_image_fill_max_pixsteps */

void _av_image_fill_max_pixsteps(undefined8 *param_1,undefined8 *param_2,long param_3)

{
  long lVar1;
  int *piVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  piVar2 = (int *)(param_3 + 0x1c);
  for (lVar1 = 0; lVar1 != 4; lVar1 = lVar1 + 1) {
    if ((*(int *)((long)param_1 + (long)piVar2[-1] * 4) < *piVar2) &&
       (*(int *)((long)param_1 + (long)piVar2[-1] * 4) = *piVar2, param_2 != (undefined8 *)0x0)) {
      *(int *)((long)param_2 + (long)piVar2[-1] * 4) = (int)lVar1;
    }
    piVar2 = piVar2 + 8;
  }
  return;
}


