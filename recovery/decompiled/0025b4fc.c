/* Decompiled from supplied 5.2.2 arm package. VA 0x25b4fc. _av_frame_alloc */

long _av_frame_alloc(void)

{
  long lVar1;
  
  lVar1 = _av_mallocz(0x218);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    *(undefined8 *)(lVar1 + 0x60) = 0;
    FUN_0025b53c(lVar1);
  }
  return lVar1;
}


