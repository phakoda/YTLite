/* Decompiled from supplied 5.2.2 arm package. VA 0x231730. FUN_00231730 */

undefined1  [16] FUN_00231730(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  
  puVar2 = PTR_ToastManager_0114ecd0;
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  DAT_01228428 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011d0fc0,0,0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_localizedDescription_0114c618);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00234580(puVar1,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d0f80,uVar4,uVar5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar6,0);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  CallSupervisor(0x4aec);
  auVar7._8_8_ = 0x1f;
  auVar7._0_8_ = 0x1a;
  return auVar7;
}


