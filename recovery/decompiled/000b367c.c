/* Decompiled from supplied 5.2.2 arm package. VA 0xb367c. FUN_000b367c */

void FUN_000b367c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  
  DAT_01226ea0 = 1;
  _objc_retain(param_3);
  (*DAT_01226740)(param_1,param_2,param_3);
  _objc_msgSend(param_1,PTR_s_playerViewDelegate_0114cc70);
  _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_000e8f44(&PTR____CFConstantStringClassReference_01170220);
                    /* WARNING: Could not recover jumptable at 0x000b3bd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181840)[uVar1 & 0xffffffff] + (int)-(DAT_01181850 ^ 0xac5601b4)))();
  return;
}


