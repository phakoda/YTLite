/* Decompiled from supplied 5.2.2 arm package. VA 0x11bec. FUN_00011bec */

void FUN_00011bec(void)

{
  undefined8 uVar1;
  
  DAT_01225990 = 1;
  uVar1 = _objc_getClass(s_YTCollectionViewController_01152e80);
  _MSHookMessageEx(uVar1,PTR_s_collectionView_didSelectItemAtIn_0114af20,FUN_00012658,0x1225948);
  uVar1 = _objc_getClass(s_YTQTMButton_01152e4a);
  _MSHookMessageEx(uVar1,PTR_s_layoutSubviews_0114ae28,FUN_00013158,&DAT_01225950);
  _objc_getClass(s_YTAppSettingsPresentationData_01152e20);
  uVar1 = _object_getClass();
  _MSHookMessageEx(uVar1,PTR_s_settingsCategoryOrder_0114af28,FUN_00013450,&DAT_01225958);
  uVar1 = _objc_getClass(s_YTSettingsSectionController_01152d90);
  _MSHookMessageEx(uVar1,PTR_s_setSelectedItem__0114af30,FUN_00013588,0x1225960);
  uVar1 = _objc_getClass(s_YTSettingsSectionItemManager_01152dd0);
  FUN_00014080(uVar1,PTR_s_updateYTLiteSectionWithEntry__0114af38,FUN_00013858,s_v____01152df2);
  _MSHookMessageEx(uVar1,PTR_s_updateSectionForCategory_withEnt_0114af40,FUN_00013d6c,0x1225968);
  uVar1 = _objc_getClass(s_YTSettingsGroupData_01152d50);
  _MSHookMessageEx(uVar1,PTR_s_orderedCategories_0114af48,FUN_00013e04,&DAT_01225970);
  return;
}


