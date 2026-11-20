/* Decompiled from supplied 5.2.2 arm package. VA 0x27b06c. _ff_nlmeans_init_aarch64 */

void _ff_nlmeans_init_aarch64(undefined8 *param_1)

{
  uint uVar1;
  
  uVar1 = _av_get_cpu_flags();
  if ((uVar1 >> 5 & 1) != 0) {
    *param_1 = _ff_compute_safe_ssd_integral_image_neon;
  }
  return;
}


