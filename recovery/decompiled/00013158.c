/* Decompiled from supplied 5.2.2 arm package. VA 0x13158. FUN_00013158 */

void FUN_00013158(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01225998 = 1;
  (*DAT_01225950)(param_1);
  _objc_msgSend(param_1,PTR_s_accessibilityIdentifier_0114aec0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_00014640(uVar1,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_01152fe0);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000133d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_01153400)[uVar2 & 0xffffffff] + (int)-(DAT_01153410 ^ 0xfa755531)))
            ();
  return;
}


