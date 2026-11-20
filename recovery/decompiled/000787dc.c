/* Decompiled from supplied 5.2.2 arm package. VA 0x787dc. FUN_000787dc */

void FUN_000787dc(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeObserver__0114c4b0,param_1);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00078848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01226250)(param_1,param_2);
  return;
}


