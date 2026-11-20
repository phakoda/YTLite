/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2be4. isFullscreen */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isFullscreen(ID param_1,SEL param_2)

{
  bool bVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  bVar1 = FUN_001c7ce4(uVar2,PTR_s_isFullscreen_0114c730);
  _objc_release(uVar2);
  return bVar1;
}


