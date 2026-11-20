/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2c38. isPinnedTop */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isPinnedTop(ID param_1,SEL param_2)

{
  bool bVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  bVar1 = FUN_001c7d2c(uVar2,PTR_s_isPinnedTop_0114dd48);
  _objc_release(uVar2);
  return bVar1;
}


