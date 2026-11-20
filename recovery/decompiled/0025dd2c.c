/* Decompiled from supplied 5.2.2 arm package. VA 0x25dd2c. _av_hwdevice_hwconfig_alloc */

undefined8 _av_hwdevice_hwconfig_alloc(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(**(long **)(*(long *)(param_1 + 8) + 8) + 0x28) != 0) {
    uVar1 = _av_mallocz();
    return uVar1;
  }
  return 0;
}


