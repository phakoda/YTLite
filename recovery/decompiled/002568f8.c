/* Decompiled from supplied 5.2.2 arm package. VA 0x2568f8. FUN_002568f8 */

void FUN_002568f8(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_01229bc0,0,0x20,0x4c11db7,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


