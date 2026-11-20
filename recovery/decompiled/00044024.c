/* Decompiled from supplied 5.2.2 arm package. VA 0x44024. FUN_00044024 */

undefined1  [16] FUN_00044024(long param_1)

{
  undefined8 uVar1;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_setAlpha__0114b698);
  _CGAffineTransformMakeScale(&local_50,DAT_00c4c250,DAT_00c4c250);
  uStack_78 = uStack_48;
  local_80 = local_50;
  uStack_68 = uStack_38;
  uStack_70 = uStack_40;
  uStack_58 = uStack_28;
  local_60 = local_30;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_setTransform__0114b910,&local_80);
  _objc_msgSend(0x4049000000000000,*(undefined8 *)(param_1 + 0x28),PTR_s_setConstant__0114b920);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x30),PTR_s_view_0114b090);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_layoutIfNeeded_0114b928);
  _objc_release(uVar1);
  CallSupervisor(0x5f0e);
  return ZEXT816(0x1f);
}


