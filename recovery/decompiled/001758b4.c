/* Decompiled from supplied 5.2.2 arm package. VA 0x1758b4. FUN_001758b4 */

undefined1  [16] FUN_001758b4(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = PTR_YTLUserDefaults_0114ead8;
  _objc_msgSend(param_2,PTR_s_sourceView_0114d878);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_exportYtlSettings__0114d880,uVar2);
  _objc_release(uVar2);
  CallSupervisor(0x8384);
  return ZEXT816(0x1f);
}


