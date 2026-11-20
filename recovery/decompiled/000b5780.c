/* Decompiled from supplied 5.2.2 arm package. VA 0xb5780. FUN_000b5780 */

void FUN_000b5780(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  DAT_01226ecc = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_msgSend(param_1,PTR_s_valueForKey__0114ae90,&PTR____CFConstantStringClassReference_011707b0)
  ;
  lVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uVar2 = FUN_000e99cc(&PTR____CFConstantStringClassReference_01170730);
  uVar1 = 0;
  if (lVar3 != 0) {
    uVar1 = uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x000b5dac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181a90)[uVar1] + (int)-(uRam0000000001181aa0 ^ 0xc7ecf749)))();
  return;
}


