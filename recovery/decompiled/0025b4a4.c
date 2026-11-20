/* Decompiled from supplied 5.2.2 arm package. VA 0x25b4a4. _av_frame_get_side_data */

int * _av_frame_get_side_data(long param_1,int param_2)

{
  int *piVar1;
  long lVar2;
  
  lVar2 = 0;
  do {
    if (*(int *)(param_1 + 0x178) <= lVar2) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(*(long *)(param_1 + 0x170) + lVar2 * 8);
    lVar2 = lVar2 + 1;
  } while (*piVar1 != param_2);
  return piVar1;
}


