/* Decompiled from supplied 5.2.2 arm package. VA 0xc9b60. FUN_000c9b60 */

ulong FUN_000c9b60(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  
  puVar2 = PTR_s__mapkit_isDarkModeEnabled_0114c3f8;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uVar4 = _objc_retain();
  uVar3 = FUN_000eed7c(uVar4,puVar1,puVar2);
  if (uVar3 == 0) {
    _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_1);
    _objc_msgSend(uVar4,PTR_s_traitCollection_0114c858);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    lVar6 = _objc_msgSend(uVar5,PTR_s_userInterfaceStyle_0114c550);
    uVar7 = (ulong)(lVar6 == 2);
    _objc_release(uVar5);
    param_1 = uVar4;
  }
  else {
    uVar7 = FUN_000eeda4((&PTR_LAB_01183550)[uVar3] + (int)-(DAT_01183560 ^ 0x40241dcc),param_1,
                         puVar2);
  }
  _objc_release(param_1);
  return uVar7;
}


