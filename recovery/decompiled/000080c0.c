/* Decompiled from supplied 5.2.2 arm package. VA 0x80c0. FUN_000080c0 */

void FUN_000080c0(undefined8 param_1,undefined8 param_2)

{
  if (DAT_01225848 != -1) {
    _dispatch_once(&DAT_01225848,&PTR___NSConcreteGlobalBlock_010613c0);
  }
                    /* WARNING: Could not recover jumptable at 0x000080fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01225838)(param_1,param_2);
  return;
}


