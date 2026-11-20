/* Decompiled from supplied 5.2.2 arm package. VA 0x256558. _av_crc_get_table */

undefined * _av_crc_get_table(uint param_1)

{
  pthread_once_t *ppVar1;
  code *pcVar2;
  
  switch(param_1) {
  case 0:
    ppVar1 = (pthread_once_t *)&DAT_011d3170;
    pcVar2 = FUN_002566c0;
    break;
  case 1:
    ppVar1 = (pthread_once_t *)&DAT_011d3190;
    pcVar2 = FUN_002567a0;
    break;
  case 2:
    ppVar1 = (pthread_once_t *)&DAT_011d31a0;
    pcVar2 = FUN_00256810;
    break;
  case 3:
    ppVar1 = (pthread_once_t *)&DAT_011d31c0;
    pcVar2 = FUN_002568f8;
    break;
  case 4:
    ppVar1 = (pthread_once_t *)&DAT_011d31d0;
    pcVar2 = FUN_0025696c;
    break;
  case 5:
    ppVar1 = (pthread_once_t *)&DAT_011d31e0;
    pcVar2 = FUN_002569e4;
    break;
  case 6:
    ppVar1 = (pthread_once_t *)&DAT_011d31b0;
    pcVar2 = FUN_00256880;
    break;
  case 7:
    ppVar1 = (pthread_once_t *)&DAT_011d3180;
    pcVar2 = FUN_0025672c;
    break;
  default:
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  _pthread_once(ppVar1,pcVar2);
  return &DAT_01228fb4 + (ulong)param_1 * 0x404;
}


