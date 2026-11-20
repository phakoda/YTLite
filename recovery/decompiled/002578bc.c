/* Decompiled from supplied 5.2.2 arm package. VA 0x2578bc. _av_dovi_alloc */

long _av_dovi_alloc(undefined8 *param_1)

{
  long lVar1;
  
  lVar1 = _av_mallocz(8);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else if (param_1 != (undefined8 *)0x0) {
    *param_1 = 8;
  }
  return lVar1;
}


