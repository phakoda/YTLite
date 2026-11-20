/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0af0. FUN_001c0af0 */

void FUN_001c0af0(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *puStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_setupInterfaceWithText_progress__0114de28,
                *(undefined8 *)(param_1 + 0x28),0,0,0,1);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_calculateToastParametersWithKeyb_0114dd38,
                &uStack_48,&local_50,&local_58);
  lVar1 = *(long *)(param_1 + 0x20);
  uVar2 = _objc_msgSend(*(undefined8 *)(lVar1 + ToastView::_widthConstraint),PTR_s_constant_0114de30
                       );
  local_80 = PTR___NSConcreteStackBlock_01060660;
  local_78 = DAT_00c4c228;
  local_70 = FUN_001c0bf4;
  puStack_68 = &DAT_01061940;
  local_60 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(uStack_48,local_50,local_58,uVar2,0x3ff0000000000000,DAT_00c4c2e0,lVar1,
                PTR_s_configureToastAppearanceWithBott_0114de38,&local_80);
  return;
}


