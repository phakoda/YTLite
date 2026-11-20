/* Decompiled from supplied 5.2.2 arm package. VA 0x444d4. FUN_000444d4 */

undefined1  [16] FUN_000444d4(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01225f24 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000481f0(uVar2,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115c830);
  _objc_release(uVar2);
  if (iVar1 == 0) {
    uVar2 = _objc_alloc_init(PTR_WelcomeVC_0114ec90);
    _objc_msgSend(uVar2,PTR_s_setModalPresentationStyle__0114b958,2);
    _objc_msgSend(uVar2,PTR_s_setModalInPresentation__0114b760,1);
    _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_rootViewController_0114b968);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_release(uVar2);
  }
  CallSupervisor(0xd3d5);
  return ZEXT816(0x1f);
}


