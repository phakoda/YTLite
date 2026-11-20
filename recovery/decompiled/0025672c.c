/* Decompiled from supplied 5.2.2 arm package. VA 0x25672c. FUN_0025672c */

void FUN_0025672c(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_0122abd0,0,8,0x1d,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


