/* Decompiled from supplied 5.2.2 arm package. VA 0x16a0f8. FUN_0016a0f8 */

void FUN_0016a0f8(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  _objc_retain(param_2);
  puVar1 = PTR_s_length_0114b438;
  lVar2 = _objc_msgSend(param_2,PTR_s_length_0114b438);
  if (lVar2 == 0x40) {
    _objc_retain((&PTR_LAB_011a80f0)[lVar2 == 0x40] + (int)-(DAT_011a8100 ^ 0x6579c533),param_2);
    uVar6 = param_2;
  }
  else {
    lVar2 = _objc_msgSend(param_2,puVar1);
    puVar1 = PTR_s_standardUserDefaults_0114afa0;
    if (lVar2 == 0) {
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_sbPrivateUserID_0114c2a8);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_sbPublicUserID__0114c2b0,uVar5);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
      _objc_release(uVar4);
      _objc_release(uVar3);
    }
    else {
      uVar6 = 0;
    }
  }
  _objc_release(param_2);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
  return;
}


