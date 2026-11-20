/* Decompiled from supplied 5.2.2 arm package. VA 0x2567a0. FUN_002567a0 */

void FUN_002567a0(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_012293b8,0,0x10,0x8005,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


