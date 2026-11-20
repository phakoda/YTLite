/* Decompiled from supplied 5.2.2 arm package. VA 0x26c734. _av_spherical_alloc */

long _av_spherical_alloc(undefined8 *param_1)

{
  long lVar1;
  
  lVar1 = _av_mallocz(0x24);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0x24;
  }
  return lVar1;
}


