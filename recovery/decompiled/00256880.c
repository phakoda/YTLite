/* Decompiled from supplied 5.2.2 arm package. VA 0x256880. FUN_00256880 */

void FUN_00256880(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_0122a7cc,0,0x18,0x864cfb,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


