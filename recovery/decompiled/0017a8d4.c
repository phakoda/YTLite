/* Decompiled from supplied 5.2.2 arm package. VA 0x17a8d4. FUN_0017a8d4 */

undefined1  [16] FUN_0017a8d4(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01227534 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_resetUserDefaults_0114d908);
  puVar1 = PTR_ToastManager_0114ecd0;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a5cd0,PTR_s_ytl_localized_0114d190);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar2,1);
  _objc_release(uVar2);
  CallSupervisor(0xdd3c);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


