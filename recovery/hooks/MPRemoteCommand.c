// Decompiled hook evidence for MPRemoteCommand. This is not compilable Logos source.

// -[MPRemoteCommand addTarget:action:], original IMP slot 0x01225f38
/* Decompiled from supplied 5.2.2 arm package. VA 0x4e6fc. FUN_0004e6fc */

void FUN_0004e6fc(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  undefined8 uVar2;
  long lVar3;
  
  _objc_retain(param_3);
  (*DAT_01225f38)(param_1,param_2,param_3,param_4);
  _objc_msgSend(PTR__OBJC_CLASS___MPRemoteCommandCenter_0114ecc8,@selector(sharedCommandCenter))
  ;
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(previousTrackCommand));
  lVar3 = _objc_retainAutoreleasedReturnValue();
  bVar1 = lVar3 != param_1 | DAT_01226848;
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0004e7f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a298)[(ulong)bVar1 & 1] + (int)-(DAT_0117a2a8 ^ 0x17bee725)))();
  return;
}


