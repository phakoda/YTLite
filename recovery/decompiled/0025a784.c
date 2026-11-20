/* Decompiled from supplied 5.2.2 arm package. VA 0x25a784. _av_fifo_drain */

void _av_fifo_drain(long *param_1,int param_2)

{
  ulong uVar1;
  
  uVar1 = param_1[1] + (long)param_2;
  param_1[1] = uVar1;
  if ((ulong)param_1[3] <= uVar1) {
    param_1[1] = uVar1 + (*param_1 - param_1[3]);
  }
  *(int *)(param_1 + 4) = (int)param_1[4] + param_2;
  return;
}


