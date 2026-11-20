/* Decompiled from supplied 5.2.2 arm package. VA 0x2569e4. FUN_002569e4 */

void FUN_002569e4(void)

{
  int iVar1;
  
  iVar1 = _av_crc_init(&DAT_0122a3c8,1,0x10,&DAT_0000a001,0x404);
  if (-1 < iVar1) {
    return;
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


