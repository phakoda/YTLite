/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0180. FUN_001c0180 */

undefined1  [16] FUN_001c0180(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined *local_88;
  undefined8 local_80;
  code *local_78;
  undefined *puStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x20),
                PTR_s_setupInterfaceWithText_progress__0114de28,*(undefined8 *)(param_1 + 0x28),
                *(undefined1 *)(param_1 + 0x3c),0,0,0);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_calculateToastParametersWithKeyb_0114dd38,
                &local_48,&uStack_50,&local_58);
  lVar1 = *(long *)(param_1 + 0x20);
  uVar2 = _objc_msgSend(*(undefined8 *)(lVar1 + ToastView::_widthConstraint),PTR_s_constant_0114de30
                       );
  local_88 = PTR___NSConcreteStackBlock_01060660;
  local_80 = DAT_00c4c228;
  local_78 = FUN_001c02b0;
  puStack_70 = &DAT_01062ad0;
  local_60 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  local_68 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(local_48,uStack_50,local_58,uVar2,0x3ff0000000000000,DAT_00c4c2e0,lVar1,
                PTR_s_configureToastAppearanceWithBott_0114de38,&local_88);
  _objc_release(local_60);
  CallSupervisor(0xcc69);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


