/* Decompiled from supplied 5.2.2 arm package. VA 0x25d8c4. _av_hwframe_transfer_get_formats */

undefined8 _av_hwframe_transfer_get_formats(long param_1)

{
  undefined8 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(**(long **)(*(long *)(param_1 + 8) + 8) + 0x80);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0025d8d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xffffffb2;
}


