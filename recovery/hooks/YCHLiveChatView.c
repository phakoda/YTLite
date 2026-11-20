// Decompiled hook evidence for YCHLiveChatView. This is not compilable Logos source.

// -[YCHLiveChatView layoutSubviews], original IMP slot 0x01226738
/* Decompiled from supplied 5.2.2 arm package. VA 0xb2580. FUN_000b2580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b2580(undefined8 param_1)

{
  undefined8 uVar1;
  
  DAT_01226e98 = 1;
  (*_DAT_01226738)(param_1);
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(parentViewController));
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x000b2a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181708)[lRam0000000001226920 == 0] +
            (int)-(uRam0000000001181718 ^ 0x869031ee)))();
  return;
}



// -[YCHLiveChatView didTapYtlButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xb3018. FUN_000b3018 */

void FUN_000b3018(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  puVar2 = @selector(_viewControllerForAncestor);
  DAT_01226e9c = 1;
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(parentViewController);
  _objc_msgSend(uVar4,@selector(parentViewController));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001226920 == 0) {
    lRam0000000001226920 =
         _objc_getClass((&PTR_LAB_011817a0)[lRam0000000001226920 == 0] +
                        (int)-(uRam00000000011817b0 ^ 0x3cbcc273),
                        s_YTLivePlayerViewController_01170080);
  }
  lVar6 = lRam0000000001226920;
  _objc_retainAutorelease(lRam0000000001226920);
  uVar3 = FUN_000e8f00(uVar5,@selector(isKindOfClass:),lVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  if (uVar3 != 0) {
    _objc_msgSend((&PTR__objc_msgSend_011817c0)[uVar3] + (int)-(uRam00000000011817d0 ^ 0x9437fcc7),
                  param_1,puVar2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(uVar5,@selector(activeVideoID));
    lVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x000b34f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011817d8)[lVar6 == 0] + (int)-(uRam00000000011817e8 ^ 0xbccb6f1e)))();
    return;
  }
  return;
}


