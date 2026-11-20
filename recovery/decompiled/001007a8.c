/* Decompiled from supplied 5.2.2 arm package. VA 0x1007a8. FUN_001007a8 */

undefined1  [16] FUN_001007a8(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01227150 = 1;
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setString__0114b8a8,uVar3);
  _objc_release(uVar1);
  if (DAT_012270a8 == 0) {
    DAT_012270a8 = _objc_getClass((&PTR__objc_msgSend_01189f88)[DAT_012270a8 == 0] +
                                  (int)-(uRam0000000001189f98 ^ 0x3de14722),
                                  s_YTToastController_01186730);
  }
  _objc_retainAutorelease();
  uVar1 = _objc_alloc();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01186770,0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_showMessage__0114cfa8,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0xf957);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


