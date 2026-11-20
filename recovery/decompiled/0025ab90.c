/* Decompiled from supplied 5.2.2 arm package. VA 0x25ab90. _avpriv_alloc_fixed_dsp */

undefined8 * _avpriv_alloc_fixed_dsp(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)_av_malloc(0x38);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = FUN_0025ac08;
    puVar1[1] = FUN_0025acc4;
    puVar1[4] = FUN_0025ad60;
    puVar1[6] = FUN_0025add8;
    puVar1[3] = FUN_0025ad9c;
    puVar1[2] = FUN_0025ad2c;
    puVar1[5] = FUN_0025ae0c;
  }
  return puVar1;
}


