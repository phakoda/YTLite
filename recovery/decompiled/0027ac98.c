/* Decompiled from supplied 5.2.2 arm package. VA 0x27ac98. _avutil_version */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _avutil_version(void)

{
  long lVar1;
  
  if ((DAT_0122b3ec & 1) == 0) {
    lVar1 = _llrint(_DAT_00c51f28);
    if (lVar1 != 0x1000000000000000) {
      _av_log(0,0x10,"Libavutil has been linked to a broken llrint()\n");
    }
    DAT_0122b3ec = 1;
  }
  return 0x383764;
}


