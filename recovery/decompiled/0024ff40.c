/* Decompiled from supplied 5.2.2 arm package. VA 0x24ff40. _ff_float_dsp_init_aarch64 */

void _ff_float_dsp_init_aarch64(undefined8 *param_1)

{
  uint uVar1;
  
  uVar1 = _av_get_cpu_flags();
  if ((uVar1 >> 5 & 1) != 0) {
    param_1[8] = _ff_butterflies_float_neon;
    param_1[9] = _ff_scalarproduct_float_neon;
    param_1[4] = _ff_vector_dmul_scalar_neon;
    *param_1 = _ff_vector_fmul_neon;
    param_1[1] = _ff_vector_fmac_scalar_neon;
    param_1[7] = _ff_vector_fmul_reverse_neon;
    param_1[3] = _ff_vector_fmul_scalar_neon;
    param_1[6] = _ff_vector_fmul_add_neon;
    param_1[5] = _ff_vector_fmul_window_neon;
  }
  return;
}


