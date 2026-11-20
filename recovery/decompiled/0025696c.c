/* Decompiled from supplied 5.2.2 arm package. VA 0x25696c. FUN_0025696c */

void FUN_0025696c(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_01229fc4,1,0x20,0xedb88320,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


