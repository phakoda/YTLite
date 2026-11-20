/* Decompiled from supplied 5.2.2 arm package. VA 0x51be8. FUN_00051be8 */

undefined8 FUN_00051be8(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  DAT_01226a44 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000d16c0(uVar1,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115eef0);
  _objc_release(uVar1);
  return uVar2;
}


