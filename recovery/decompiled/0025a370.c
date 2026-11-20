/* Decompiled from supplied 5.2.2 arm package. VA 0x25a370. _av_fifo_space */

int _av_fifo_space(int *param_1)

{
  return (param_1[6] - *param_1) - (param_1[9] - param_1[8]);
}


