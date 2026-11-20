/* Decompiled from supplied 5.2.2 arm package. VA 0x10b56c. FUN_0010b56c */

undefined1  [16] FUN_0010b56c(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  code *pcStack_a0;
  undefined *puStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_0118b0d8;
  local_5c = (uint)(DAT_0122720c == 0);
  local_68 = &PTR_LAB_011882f0;
  DAT_0122720c = 1;
  uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01187ce0,0,0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_showToast__0114d088,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  uVar4 = _objc_alloc_init(PTR_SRTParser_0114ee00);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_URL_0114c578);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_languageCode_0114cbc0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puStack_b0 = PTR___NSConcreteStackBlock_01060660;
  uStack_a8 = DAT_00c4c228;
  pcStack_a0 = FUN_0010b894;
  puStack_98 = &DAT_01062400;
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  uStack_88 = *(undefined8 *)(param_1 + 0x30);
  uStack_90 = uVar2;
  uStack_80 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  puVar1 = PTR_s_parseXMLFromURL_forLanguage_vide_0114d0b0;
  _objc_retain(uVar2);
  _objc_msgSend(uVar4,puVar1,uVar5,uVar6,uVar3,&puStack_b0);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uStack_80);
  _objc_release(uStack_90);
  _objc_release(uVar2);
  _objc_release(uVar4);
  CallSupervisor(0xee17);
  return ZEXT816(0x1f);
}


