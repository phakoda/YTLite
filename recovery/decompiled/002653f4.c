/* Decompiled from supplied 5.2.2 arm package. VA 0x2653f4. _av_opt_set_defaults2 */

void _av_opt_set_defaults2(undefined8 param_1,uint param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = 0;
  while( true ) {
    do {
      lVar1 = _av_opt_next(param_1,lVar1);
      if (lVar1 == 0) {
        return;
      }
    } while (((*(uint *)(lVar1 + 0x30) & param_2) != param_3) ||
            ((*(uint *)(lVar1 + 0x30) & 0x80) != 0));
    if ((uint)(*(ulong *)(lVar1 + 0x10) >> 0x20) < 0x13) break;
    _av_log(param_1,0x30,"AVOption type %d of option %s not implemented yet\n");
  }
                    /* WARNING: Could not recover jumptable at 0x0026549c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&DAT_0026558c + *(int *)(&DAT_0026558c + (*(ulong *)(lVar1 + 0x10) >> 0x20) * 4)))();
  return;
}


