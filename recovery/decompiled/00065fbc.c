/* Decompiled from supplied 5.2.2 arm package. VA 0x65fbc. FUN_00065fbc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00065fbc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  ulong uVar2;
  
  DAT_01226a6c = 1;
  _objc_retain(param_3);
  puVar1 = PTR_s_isEqualToString__0114ae48;
  _objc_retain(param_4);
  uVar2 = FUN_000d6d58(param_3,puVar1,&PTR____CFConstantStringClassReference_01161a00);
  (*_DAT_01225ff8)(param_1,param_2,param_3,param_4);
  _objc_retainAutoreleasedReturnValue();
  _objc_release(param_4);
                    /* WARNING: Could not recover jumptable at 0x0006628c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_0117aa60)[uVar2 & 0xffffffff] +
            (int)-(uRam000000000117aa70 ^ 0xeb5ff2af)))();
  return;
}


