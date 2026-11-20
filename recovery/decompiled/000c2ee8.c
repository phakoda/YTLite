/* Decompiled from supplied 5.2.2 arm package. VA 0xc2ee8. FUN_000c2ee8 */

void FUN_000c2ee8(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  undefined8 local_38;
  
  _objc_retain(param_2);
  _objc_msgSend(PTR__OBJC_CLASS___PHPhotoLibrary_0114ed58,PTR_s_sharedPhotoLibrary_0114c600);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_performChanges_completionHandler_0114c620;
  local_58 = PTR___NSConcreteStackBlock_01060660;
  local_50 = DAT_00c4c228;
  local_48 = FUN_000c2fac;
  puStack_40 = &DAT_01061420;
  local_38 = param_2;
  _objc_retain(param_2);
  _objc_msgSend(uVar2,puVar1,&local_58,&PTR___NSConcreteGlobalBlock_01061e30);
  _objc_release(uVar2);
  _objc_release(local_38);
  _objc_release(param_2);
  return;
}


