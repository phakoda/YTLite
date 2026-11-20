/* Decompiled from supplied 5.2.2 arm package. VA 0x52438. FUN_00052438 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00052438(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226a58 = 1;
  (*_DAT_01225fe0)(param_1);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000d18d0(uVar1,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115f030);
                    /* WARNING: Could not recover jumptable at 0x000525e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a778)[uVar2 & 0xffffffff] + (int)-(uRam000000000117a788 ^ 0x4d951762)))()
  ;
  return;
}


