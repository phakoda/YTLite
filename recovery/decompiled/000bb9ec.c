/* Decompiled from supplied 5.2.2 arm package. VA 0xbb9ec. FUN_000bb9ec */

void FUN_000bb9ec(void)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226f18 = 1;
  (*DAT_01226820)();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000eb490(uVar1,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_01171840);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000bbfe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01182440)[uVar2 & 0xffffffff] + (int)-(DAT_01182450 ^ 0xc23e043d)))();
  return;
}


