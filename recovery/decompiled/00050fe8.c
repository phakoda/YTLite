/* Decompiled from supplied 5.2.2 arm package. VA 0x50fe8. FUN_00050fe8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00050fe8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a34 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d1438(uVar2,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115ec40);
  _objc_release(uVar2);
  if (iVar1 == 0) {
    (*_DAT_01225fa0)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


