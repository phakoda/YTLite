/* Decompiled from supplied 5.2.2 arm package. VA 0x100af0. FUN_00100af0 */

undefined1  [16] FUN_00100af0(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  double dVar6;
  
  DAT_01227154 = 1;
  dVar6 = (double)_objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_contentVideoMediaTime_0114cfb0
                               );
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_contentVideoID_0114cef0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_001119b8(puVar1,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_01186890,uVar2,(long)dVar6);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setString__0114b8a8,uVar3);
  _objc_release(uVar2);
  if (DAT_012270a8 == 0) {
    DAT_012270a8 = _objc_getClass((&PTR_LAB_01189fc8)[DAT_012270a8 == 0] +
                                  (int)-(DAT_01189fd8 ^ 0x11cd1651),s_YTToastController_011867b0);
  }
  _objc_retainAutorelease();
  uVar2 = _objc_alloc();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01186850,0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_showMessage__0114cfa8,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar2);
  _objc_release(uVar3);
  CallSupervisor(0x1c2b);
  return ZEXT816(0x1f);
}


