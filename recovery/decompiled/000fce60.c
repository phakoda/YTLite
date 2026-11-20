/* Decompiled from supplied 5.2.2 arm package. VA 0xfce60. FUN_000fce60 */

undefined1  [16] FUN_000fce60(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  code *pcStack_e0;
  undefined *puStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
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
  
  local_38 = &PTR_LAB_01189b60;
  local_3c = (uint)(DAT_01227124 == 0);
  local_50 = &PTR_LAB_01189b80;
  local_48 = &PTR_LAB_011882f0;
  local_68 = &PTR_LAB_011882f0;
  ppuStack_60 = &PTR_LAB_011882f0;
  DAT_01227124 = 1;
  iStack_54 = FUN_001104bc(*(undefined8 *)(param_1 + 0x20),PTR_s_hasContentLength_0114cf20);
  if (iStack_54 == 0) {
    uVar1 = _objc_alloc_init(PTR_ToastView_0114ec98);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01185f50,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar3,0);
    _objc_release(uVar3);
    _objc_release(uVar2);
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x70);
    puStack_f0 = PTR___NSConcreteStackBlock_01060660;
    uStack_e8 = DAT_00c4c228;
    pcStack_e0 = FUN_000fd1c8;
    puStack_d8 = &UNK_01062230;
    uStack_80 = *(undefined1 *)(param_1 + 0x78);
    uStack_c8 = *(undefined8 *)(param_1 + 0x20);
    uVar1 = *(undefined8 *)(param_1 + 0x28);
    uStack_d0 = uVar1;
    uStack_c0 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
    uStack_b8 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
    uStack_b0 = _objc_retain(*(undefined8 *)(param_1 + 0x40));
    uStack_a8 = _objc_retain(*(undefined8 *)(param_1 + 0x48));
    uStack_a0 = _objc_retain(*(undefined8 *)(param_1 + 0x50));
    uStack_98 = _objc_retain(*(undefined8 *)(param_1 + 0x58));
    uStack_90 = _objc_retain(*(undefined8 *)(param_1 + 0x60));
    uStack_88 = _objc_retain(*(undefined8 *)(param_1 + 0x68));
    _objc_msgSend(uVar1,PTR_s_checkSpaceAvailabilityForMedia_c_0114ced0,uVar2,&puStack_f0);
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
  CallSupervisor(0xe6af);
  return ZEXT816(0x1f);
}


