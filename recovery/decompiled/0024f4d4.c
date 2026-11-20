/* Decompiled from supplied 5.2.2 arm package. VA 0x24f4d4. _oggpack_writeclear */

void _oggpack_writeclear(undefined8 *param_1)

{
  _free((void *)param_1[2]);
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}


