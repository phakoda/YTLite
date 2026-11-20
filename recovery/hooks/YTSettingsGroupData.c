// Decompiled hook evidence for YTSettingsGroupData. This is not compilable Logos source.

// -[YTSettingsGroupData orderedCategories], original IMP slot 0x01225970
/* Decompiled from supplied 5.2.2 arm package. VA 0x13e04. FUN_00013e04 */

void FUN_00013e04(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = _objc_msgSend(param_1,@selector(type));
  (*DAT_01225970)(param_1,param_2);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00013e94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01153510)[lVar1 == 1] + (int)-(DAT_01153520 ^ 0x675ec12a)))();
  return;
}


