// Decompiled hook evidence for YTAppSettingsPresentationData. This is not compilable Logos source.

// +[YTAppSettingsPresentationData settingsCategoryOrder], original IMP slot 0x01225958
/* Decompiled from supplied 5.2.2 arm package. VA 0x13450. FUN_00013450 */

void FUN_00013450(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  (*DAT_01225958)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(mutableCopy));
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithInt:),1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar1,@selector(indexOfObject:),uVar2);
  _objc_release(uVar2);
                    /* WARNING: Could not recover jumptable at 0x00013520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01153420)[lVar3 == 0x7fffffffffffffff] + (int)-(DAT_01153430 ^ 0x9949059f)))
            ();
  return;
}


