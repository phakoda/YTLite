/* Decompiled from supplied 5.2.2 arm package. VA 0x254cb4. _av_bprint_clear */

void _av_bprint_clear(undefined8 *param_1)

{
  if (*(int *)(param_1 + 1) != 0) {
    *(undefined1 *)*param_1 = 0;
    *(undefined4 *)(param_1 + 1) = 0;
  }
  return;
}


