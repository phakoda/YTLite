/* Decompiled from supplied 5.2.2 arm package. VA 0x539fc. FUN_000539fc */

void FUN_000539fc(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  puVar1 = PTR_s_boolForKey__0114ada8;
  DAT_01226a64 = 1;
  uVar2 = FUN_000d21d4(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115f320);
  if (uVar2 == 0) {
    uVar2 = FUN_000d2278((&PTR_LAB_0117a958)[uVar2] + (int)-(DAT_0117a968 ^ 0x4f94833e));
    if ((uVar2 == 0) ||
       (iVar3 = FUN_000d2164((&PTR_LAB_0117a970)[uVar2] + (int)-(uRam000000000117a980 ^ 0xd3b3a3c2))
       , iVar3 != 0)) {
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      iVar3 = FUN_000d21ac(uVar4,puVar1,&PTR____CFConstantStringClassReference_0115f2e0);
      _objc_release(uVar4);
      if (iVar3 != 0) {
        uVar4 = _objc_alloc_init(PTR_ToastView_0114ec98);
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
        uVar5 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar5,PTR_s_localizedStringForKey_value_tabl_0114b278,
                      &PTR____CFConstantStringClassReference_0115f2a0,0,0);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x4024000000000000,uVar4,PTR_s_showProgressiveToastWithText_dur_0114ba88,uVar6
                      ,0);
        _objc_release(uVar6);
        _objc_release(uVar5);
        (*(code *)PTR__objc_release_01061028)(uVar4);
        return;
      }
    }
  }
  return;
}


