/* Decompiled from supplied 5.2.2 arm package. VA 0x2547d8. _av_bprint_init_for_buffer */

void _av_bprint_init_for_buffer(undefined8 *param_1,undefined1 *param_2,undefined4 param_3)

{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 2) = param_3;
  *param_2 = 0;
  return;
}


