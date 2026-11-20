/* Decompiled from supplied 5.2.2 arm package. VA 0x25ef70. FUN_0025ef70 */

void FUN_0025ef70(void *param_1,long param_2,void *param_3,long param_4,size_t param_5,int param_6)

{
  long lVar1;
  
  if ((param_1 == (void *)0x0) || (param_3 == (void *)0x0)) {
    return;
  }
  lVar1 = -param_4;
  if (-1 < param_4) {
    lVar1 = param_4;
  }
  if ((long)param_5 <= lVar1) {
    lVar1 = -param_2;
    if (-1 < param_2) {
      lVar1 = param_2;
    }
    if ((long)param_5 <= lVar1) {
      param_6 = param_6 + 1;
      while (param_6 = param_6 + -1, 0 < param_6) {
        _memcpy(param_1,param_3,param_5);
        param_1 = (void *)((long)param_1 + param_2);
        param_3 = (void *)((long)param_3 + param_4);
      }
      return;
    }
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


