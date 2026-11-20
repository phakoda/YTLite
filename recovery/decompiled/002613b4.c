/* Decompiled from supplied 5.2.2 arm package. VA 0x2613b4. _av_rescale_delta */

void _av_rescale_delta(long param_1,long param_2,long param_3,int param_4,long *param_5,long param_6
                      )

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if ((param_2 == -0x8000000000000000) || (param_4 < 0)) {
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  if (param_4 != 0) {
    lVar7 = *param_5;
    lVar6 = (param_6 >> 0x20) * (long)(int)param_1;
    lVar5 = (long)(int)param_6 * (param_1 >> 0x20);
    bVar2 = false;
    bVar3 = true;
    if (lVar7 != -0x8000000000000000) {
      lVar1 = lVar6 - lVar5;
      bVar2 = lVar1 < 0;
      bVar3 = lVar1 == 0;
    }
    if (!bVar3 && bVar2 == (lVar7 != -0x8000000000000000 && SBORROW8(lVar6,lVar5))) {
      uVar4 = _av_rescale_q_rnd(param_2 * 2 + -1,param_1,param_3,2);
      lVar5 = _av_rescale_q_rnd(param_2 << 1 | 1,param_1,param_3,3);
      lVar5 = lVar5 + 1 >> 1;
      if (((long)((uVar4 & 0xfffffffffffffffe) - lVar5) <= lVar7) &&
         (lVar6 = (long)uVar4 >> 1, lVar7 <= lVar5 * 2 - lVar6)) {
        if (lVar7 <= lVar5) {
          lVar5 = lVar7;
        }
        param_2 = lVar6;
        if (lVar6 <= lVar7) {
          param_2 = lVar5;
        }
        *param_5 = param_2 + param_4;
        goto LAB_002614b0;
      }
    }
  }
  lVar5 = _av_rescale_q_rnd(param_2,param_1,param_3,5);
  *param_5 = lVar5 + param_4;
  param_3 = param_1;
LAB_002614b0:
  _av_rescale_q_rnd(param_2,param_3,param_6,5);
  return;
}


