/* Decompiled from supplied 5.2.2 arm package. VA 0x256308. _av_get_cpu_flags */

void _av_get_cpu_flags(void)

{
  if (DAT_011d3160 == -1) {
    DAT_011d3160 = _ff_get_cpu_flags_aarch64();
  }
  return;
}


