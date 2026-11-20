/* Decompiled from supplied 5.2.2 arm package. VA 0x2661a4. _av_opt_is_set_to_default */

ulong _av_opt_is_set_to_default(long param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  
  uVar2 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((uint)(*(ulong *)(param_2 + 0x10) >> 0x20) < 0x13) {
                    /* WARNING: Could not recover jumptable at 0x002661f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)(&DAT_0026652c +
                        *(int *)(&DAT_0026652c + (*(ulong *)(param_2 + 0x10) >> 0x20) * 4)))();
      return uVar1;
    }
    _av_log(param_1,0x18,"Not supported option type: %d, option name: %s\n");
    uVar2 = 0xbaa8beb0;
  }
  return (ulong)uVar2;
}


