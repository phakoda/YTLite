/* Decompiled from supplied 5.2.2 arm package. VA 0x24f268. _oggpack_writeinit */

void _oggpack_writeinit(undefined8 *param_1)

{
  undefined1 *puVar1;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  puVar1 = _malloc(0x100);
  param_1[2] = puVar1;
  param_1[3] = puVar1;
  *puVar1 = 0;
  param_1[4] = 0x100;
  return;
}


