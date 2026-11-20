/* Decompiled from supplied 5.2.2 arm package. VA 0x10a480. FUN_0010a480 */

undefined1  [16] FUN_0010a480(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  undefined8 uStack_70;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118af88;
  local_4c = (uint)(DAT_01227200 == 0);
  local_58 = &PTR_LAB_011882f0;
  DAT_01227200 = 1;
  uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01187a80,0,0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_showToast__0114d088,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  uVar3 = _objc_alloc_init(PTR_SRTParser_0114ee00);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_URL_0114c578);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_parseTranscriptFromURL_completio_0114d090;
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_0010a768;
  puStack_78 = &DAT_010623d0;
  uStack_70 = uVar2;
  _objc_retain(uVar2);
  _objc_msgSend(uVar3,puVar1,uVar4,&puStack_90);
  _objc_release(uVar4);
  _objc_release(uStack_70);
  _objc_release(uVar2);
  _objc_release(uVar3);
  CallSupervisor(0x8dbd);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


