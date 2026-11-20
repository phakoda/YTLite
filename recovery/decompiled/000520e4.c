/* Decompiled from supplied 5.2.2 arm package. VA 0x520e4. FUN_000520e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000520e4(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226a54 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,PTR_s_integerForKey__0114b3a8,
                        &PTR____CFConstantStringClassReference_0115efd0);
  _objc_release(uVar1);
  if (lVar2 < 2) {
    if (lVar2 == 1) {
      return 1;
    }
  }
  else if (lVar2 < 4) {
    if (lVar2 == 2) {
      return 0;
    }
  }
  else if (lVar2 == 4) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000523e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*_DAT_01225fd8)(param_1,param_2);
  return uVar1;
}


