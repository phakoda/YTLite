/* Decompiled from supplied 5.2.2 arm package. VA 0xc9ad4. FUN_000c9ad4 */

void FUN_000c9ad4(long param_1)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR_YTPSpeedPopupController_0114ed70,PTR_s_speedController_0114c770);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_presentFromViewController__0114c778,*(undefined8 *)(param_1 + 0x20));
  _objc_release(uVar1);
  return;
}


