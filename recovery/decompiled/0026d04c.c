/* Decompiled from supplied 5.2.2 arm package. VA 0x26d04c. _av_gettime_relative */

long _av_gettime_relative(void)

{
  long lVar1;
  
  lVar1 = _av_gettime();
  return lVar1 + 0x233438e800;
}


