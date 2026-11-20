/* Decompiled from supplied 5.2.2 arm package. VA 0x51d7c. FUN_00051d7c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00051d7c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a48 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d1748(uVar2,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115ef50);
  _objc_release(uVar2);
  if (iVar1 != 0) {
    _dispatch_get_global_queue(0,0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _dispatch_async(uVar2,&PTR___NSConcreteGlobalBlock_01061a40);
    _objc_release(uVar2);
  }
  uVar2 = (*_DAT_01225fc8)(param_1,param_2,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  return uVar2;
}


