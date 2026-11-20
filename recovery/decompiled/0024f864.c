/* Decompiled from supplied 5.2.2 arm package. VA 0x24f864. _oggpack_reset */

void _oggpack_reset(undefined8 *param_1)

{
  if (param_1[3] != 0) {
    param_1[3] = (undefined1 *)param_1[2];
    *(undefined1 *)param_1[2] = 0;
    *param_1 = 0;
    *(undefined4 *)(param_1 + 1) = 0;
  }
  return;
}


