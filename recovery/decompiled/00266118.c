/* Decompiled from supplied 5.2.2 arm package. VA 0x266118. _av_opt_freep_ranges */

void _av_opt_freep_ranges(undefined8 *param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
  plVar1 = (long *)*param_1;
  if (plVar1 != (long *)0x0) {
    lVar2 = 0;
    for (lVar3 = 0; lVar3 < *(int *)((long)plVar1 + 0xc) * (int)plVar1[1]; lVar3 = lVar3 + 1) {
      if (*(long *)(*plVar1 + lVar2) != 0) {
        _av_freep();
        _av_freep(*plVar1 + lVar2);
      }
      lVar2 = lVar2 + 8;
    }
    _av_freep(plVar1);
    _av_freep(param_1);
    return;
  }
  return;
}


