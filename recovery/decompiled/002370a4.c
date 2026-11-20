/* Decompiled from supplied 5.2.2 arm package. VA 0x2370a4. FUN_002370a4 */

undefined1  [16] FUN_002370a4(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_blackColor_0114c400);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c2f0,uVar2,PTR_s_colorWithAlphaComponent__0114b548);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_view_0114b090);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setBackgroundColor__0114b550,uVar3);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_layoutIfNeeded_0114b928);
  _objc_release(uVar2);
  CallSupervisor(0x1957);
  return ZEXT816(0x1f);
}


