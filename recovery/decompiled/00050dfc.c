/* Decompiled from supplied 5.2.2 arm package. VA 0x50dfc. FUN_00050dfc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00050dfc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a30 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d13f0(uVar2,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115ebe0);
  _objc_release(uVar2);
  if (iVar1 == 0) {
    (*_DAT_01225f98)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xd24d);
  return ZEXT816(0x1f);
}


