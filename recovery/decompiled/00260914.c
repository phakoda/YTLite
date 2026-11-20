/* Decompiled from supplied 5.2.2 arm package. VA 0x260914. _av_vlog */

void _av_vlog(long *param_1,ulong param_2)

{
  ulong uVar1;
  
  if ((param_1 != (long *)0x0) && (*param_1 != 0)) {
    uVar1 = *(ulong *)(*param_1 + 0x18);
    if ((0x320f01 < (int)uVar1 && 7 < (int)param_2) && (uVar1 >> 0x20 != 0)) {
      param_2 = (ulong)(uint)(*(int *)((long)param_1 + ((long)uVar1 >> 0x20)) + (int)param_2);
    }
  }
  if (PTR__av_log_default_callback_011d31f0 != (undefined *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00260964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR__av_log_default_callback_011d31f0)(param_1,param_2);
    return;
  }
  return;
}


