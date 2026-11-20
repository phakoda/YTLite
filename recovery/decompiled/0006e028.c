/* Decompiled from supplied 5.2.2 arm package. VA 0x6e028. FUN_0006e028 */

void FUN_0006e028(void)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226adc = 1;
  (*DAT_012260c0)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_description_0114af00);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000d8958(uVar1,PTR_s_containsString__0114af08,
                       &PTR____CFConstantStringClassReference_011632f0);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0006e208. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117b5b8)[uVar2 & 0xffffffff] + (int)-(DAT_0117b5c8 ^ 0x4dc1af06)))();
  return;
}


