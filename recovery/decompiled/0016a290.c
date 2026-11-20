/* Decompiled from supplied 5.2.2 arm package. VA 0x16a290. FUN_0016a290 */

void FUN_0016a290(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  _objc_retain(param_2);
  puVar1 = PTR_s_length_0114b438;
  uVar2 = _objc_msgSend(param_2,PTR_s_length_0114b438);
  if (uVar2 < 0x20) {
    lVar3 = _objc_msgSend(param_2,puVar1);
    if (lVar3 == 0) {
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_sbPrivateUserID_0114c2a8);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    _objc_retain((&PTR_LAB_011a8130)[0x1f < uVar2] + (int)-(DAT_011a8140 ^ 0xe366b329),param_2);
    uVar5 = param_2;
  }
  _objc_release(param_2);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return;
}


