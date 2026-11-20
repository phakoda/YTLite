/* Decompiled from supplied 5.2.2 arm package. VA 0x2623b4. FUN_002623b4 */

void FUN_002623b4(long *param_1,uint *param_2,ulong param_3,int param_4)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  
  if (*param_2 < param_3) {
    uVar1 = param_3 + (param_3 >> 4) + 0x20;
    if (uVar1 <= param_3) {
      uVar1 = param_3;
    }
    _av_freep(param_1);
    if (param_4 == 0) {
      lVar2 = _av_malloc(uVar1);
    }
    else {
      lVar2 = _av_mallocz();
    }
    *param_1 = lVar2;
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = (uint)uVar1;
    }
    *param_2 = uVar3;
  }
  else if ((param_3 != 0) && (*param_1 == 0)) {
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  return;
}


