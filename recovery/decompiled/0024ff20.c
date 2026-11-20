/* Decompiled from supplied 5.2.2 arm package. VA 0x24ff20. _ff_get_cpu_max_align_aarch64 */

int _ff_get_cpu_max_align_aarch64(void)

{
  uint uVar1;
  
  uVar1 = _av_get_cpu_flags();
  return ((uVar1 & 0x20) >> 2) + 8;
}


