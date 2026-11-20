/* Decompiled from supplied 5.2.2 arm package. VA 0x253a60. _av_d2str */

long _av_d2str(void)

{
  long lVar1;
  
  lVar1 = _av_malloc(0x10);
  if (lVar1 != 0) {
    ___snprintf_chk(lVar1,0x10,0,0xffffffffffffffff,"%f");
  }
  return lVar1;
}


