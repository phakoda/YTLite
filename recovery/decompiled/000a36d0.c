/* Decompiled from supplied 5.2.2 arm package. VA 0xa36d0. FUN_000a36d0 */

void FUN_000a36d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  
  puVar2 = PTR_YTPSleepTimer_0114eaf0;
  puVar1 = PTR_s_sharedTimer_0114aed8;
  DAT_01226e00 = 1;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_cancelIfPlayerClosed_0114cb40);
  _objc_release(uVar3);
  _canRememberLoopMode = 0;
  (*DAT_01226638)(param_1,param_2,param_3,param_4,param_5);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  lVar4 = _ytpInt(&PTR____CFConstantStringClassReference_0116d230);
                    /* WARNING: Could not recover jumptable at 0x000a3f08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01180370)[lVar4 == 0] + (int)-(DAT_01180380 ^ 0xc5ebab7)))();
  return;
}


