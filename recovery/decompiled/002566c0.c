/* Decompiled from supplied 5.2.2 arm package. VA 0x2566c0. FUN_002566c0 */

void FUN_002566c0(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_01228fb4,0,8,7,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


