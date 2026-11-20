/* Decompiled from supplied 5.2.2 arm package. VA 0xc554. FUN_0000c554 */

undefined1  [16] FUN_0000c554(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01225928 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_objectForInfoDictionaryKey__0114ae00,
                &PTR____CFConstantStringClassReference_01151850);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  lVar3 = _objc_msgSend(uVar2,PTR_s_compare_options__0114ae08,
                        &PTR____CFConstantStringClassReference_01151810,0x40);
  if (lVar3 == -1) {
    uVar1 = _objc_getClass((&PTR_LAB_011528f0)[lVar3 == -1] + (int)-(DAT_01152900 ^ 0x2e511935),
                           s_YTIIcon_0115173c);
    _MSHookMessageEx(uVar1,PTR_s_iconType_0114ae10,FUN_0000d264,&DAT_012258d8);
    _objc_getClass(s_QTMIcon_0115172c);
    uVar1 = _object_getClass();
    _MSHookMessageEx(uVar1,PTR_s_imageWithName_color__0114ae18,FUN_0000d508,0x12258e0);
    uVar1 = _objc_getClass(s_YTELMResourceLoader_01151700);
    _MSHookMessageEx(uVar1,PTR_s_imageWithName_color_bundleId__0114ae20,recovered_hook_0000d890,
                     0x12258e8);
    uVar1 = _objc_getClass(s_YTWatchFloatingMiniplayerWithCon_011516a0);
    _MSHookMessageEx(uVar1,PTR_s_layoutSubviews_0114ae28,FUN_0000f74c,&DAT_012258f0);
    _objc_getClass(s_YTVersionUtils_0115164d);
    uVar1 = _object_getClass();
    _MSHookMessageEx(uVar1,PTR_s_appVersion_0114ae30,recovered_hook_0000f7e0,0x12258f8);
    uVar1 = _objc_getClass(s_YTSettingsCell_0115162f);
    _MSHookMessageEx(uVar1,PTR_s_setDetailText__0114ae38,FUN_0000f8d8,0x1225900);
    uVar1 = _objc_getClass(s_ELMTouchCommandPropertiesHandler_01151780);
    _MSHookMessageEx(uVar1,PTR_s_handleTap_0114ae40,FUN_0000fc90,0x1225908);
  }
  _objc_release(uVar2);
  CallSupervisor(0xc467);
  return ZEXT816(0x1f);
}


