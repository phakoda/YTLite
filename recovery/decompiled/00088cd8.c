/* Decompiled from supplied 5.2.2 arm package. VA 0x88cd8. FUN_00088cd8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00088cd8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01226ce4 = 1;
  _objc_retain(param_3);
  lVar1 = _ytpInt(&PTR____CFConstantStringClassReference_01167f80);
  if (lVar1 == 0) {
    (*_DAT_01226440)(param_1,param_2,param_3);
  }
  else {
    uVar2 = _objc_alloc(PTR__OBJC_CLASS___UILongPressGestureRecognizer_0114ed30);
    uVar2 = _objc_msgSend(uVar2,PTR_s_initWithTarget_action__0114c530,param_1,
                          PTR_s_speedmasterYtLite__0114bfb8);
    _objc_msgSend(DAT_00c4c2e0,uVar2,PTR_s_setMinimumPressDuration__0114c538);
    lVar1 = _ytpInt(&PTR____CFConstantStringClassReference_01167f80);
    if (lVar1 != 0) {
      _objc_msgSend(param_1,PTR_s_addGestureRecognizer__0114c540,uVar2);
    }
    _objc_release(uVar2);
  }
  _objc_release(param_3);
  CallSupervisor(0x5635);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


