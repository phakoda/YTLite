/* Decompiled from supplied 5.2.2 arm package. VA 0xb3018. FUN_000b3018 */

void FUN_000b3018(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  puVar2 = PTR_s__viewControllerForAncestor_0114ade0;
  DAT_01226e9c = 1;
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_parentViewController_0114ad68;
  _objc_msgSend(uVar4,PTR_s_parentViewController_0114ad68);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001226920 == 0) {
    lRam0000000001226920 =
         _objc_getClass((&PTR_LAB_011817a0)[lRam0000000001226920 == 0] +
                        (int)-(uRam00000000011817b0 ^ 0x3cbcc273),
                        s_YTLivePlayerViewController_01170080);
  }
  lVar6 = lRam0000000001226920;
  _objc_retainAutorelease(lRam0000000001226920);
  uVar3 = FUN_000e8f00(uVar5,PTR_s_isKindOfClass__0114ad70,lVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  if (uVar3 != 0) {
    _objc_msgSend((&PTR__objc_msgSend_011817c0)[uVar3] + (int)-(uRam00000000011817d0 ^ 0x9437fcc7),
                  param_1,puVar2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(uVar5,PTR_s_activeVideoID_0114cc68);
    lVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x000b34f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011817d8)[lVar6 == 0] + (int)-(uRam00000000011817e8 ^ 0xbccb6f1e)))();
    return;
  }
  return;
}


