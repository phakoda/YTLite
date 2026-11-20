/* Decompiled from supplied 5.2.2 arm package. VA 0x25ae6c. _avpriv_float_dsp_alloc */

undefined8 * _avpriv_float_dsp_alloc(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)_av_mallocz(0x58);
  if (puVar1 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  else {
    *puVar1 = FUN_0025af2c;
    puVar1[10] = FUN_0025af58;
    puVar1[1] = FUN_0025af84;
    puVar1[2] = FUN_0025afdc;
    puVar1[3] = FUN_0025afb4;
    puVar1[4] = FUN_0025b00c;
    puVar1[7] = FUN_0025b0c8;
    puVar1[8] = FUN_0025b0fc;
    puVar1[6] = FUN_0025b094;
    puVar1[5] = FUN_0025b034;
    puVar1[9] = _avpriv_scalarproduct_float_c;
    _ff_float_dsp_init_aarch64(puVar1);
  }
  return puVar1;
}


