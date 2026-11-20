/* Decompiled from supplied 5.2.2 arm package. VA 0xfa4e4. FUN_000fa4e4 */

undefined1  [16] FUN_000fa4e4(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  undefined *puStack_e0;
  undefined8 uStack_d8;
  code *pcStack_d0;
  undefined *puStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined1 uStack_80;
  undefined **local_68;
  undefined **ppuStack_60;
  int iStack_54;
  undefined **local_50;
  undefined **local_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011897a8;
  local_3c = (uint)(DAT_01227104 == 0);
  local_50 = &PTR_LAB_011897c8;
  local_48 = &PTR_LAB_011882f0;
  local_68 = &PTR_LAB_011882f0;
  ppuStack_60 = &PTR_LAB_011882f0;
  DAT_01227104 = 1;
  iStack_54 = FUN_0010f5d4(*(undefined8 *)(param_1 + 0x20),PTR_s_hasContentLength_0114cf20);
  if (iStack_54 == 0) {
    uVar1 = _objc_alloc_init(PTR_ToastView_0114ec98);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01185b40,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar3,0);
    _objc_release(uVar3);
    _objc_release(uVar2);
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x60);
    puStack_e0 = PTR___NSConcreteStackBlock_01060660;
    uStack_d8 = DAT_00c4c228;
    pcStack_d0 = FUN_000fa840;
    puStack_c8 = &UNK_010621d0;
    uStack_80 = *(undefined1 *)(param_1 + 0x68);
    uVar1 = *(undefined8 *)(param_1 + 0x28);
    uStack_c0 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
    uStack_b8 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
    uStack_b0 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
    uStack_a8 = _objc_retain(*(undefined8 *)(param_1 + 0x40));
    uStack_a0 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
    uStack_98 = _objc_retain(*(undefined8 *)(param_1 + 0x48));
    uStack_90 = _objc_retain(*(undefined8 *)(param_1 + 0x50));
    uStack_88 = _objc_retain(*(undefined8 *)(param_1 + 0x58));
    _objc_msgSend(uVar1,PTR_s_checkSpaceAvailabilityForMedia_c_0114ced0,uVar2,&puStack_e0);
    _objc_release(uStack_88);
    _objc_release(uStack_90);
    _objc_release(uStack_98);
    _objc_release(uStack_a0);
    _objc_release(uStack_a8);
    _objc_release(uStack_b0);
    _objc_release(uStack_b8);
    uVar1 = uStack_c0;
  }
  _objc_release(uVar1);
  CallSupervisor(0x281a);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


