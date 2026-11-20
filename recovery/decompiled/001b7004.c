/* Decompiled from supplied 5.2.2 arm package. VA 0x1b7004. FUN_001b7004 */

void FUN_001b7004(void)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01227abc = 1;
  (*pcRam0000000001227998)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_description_0114af00);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001b95b4(uVar1,PTR_s_containsString__0114af08,
                       &PTR____CFConstantStringClassReference_011b2080);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x001b716c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011b2f90)[uVar2 & 0xffffffff] + (int)-(uRam00000000011b2fa0 ^ 0xa5e6aa74)))()
  ;
  return;
}


