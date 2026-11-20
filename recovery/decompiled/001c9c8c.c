/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9c8c. showMessageWithText:isSuccess: */

/* Function Stack Size: 0x1c bytes */

void ToastManager::showMessageWithText_isSuccess_(ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  undefined8 local_48;
  ID local_40;
  undefined1 local_38;
  
  _objc_retain(param_3);
  uVar1 = _objc_alloc_init(PTR_ToastView_0114ec98);
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_registerToast__0114dd20,uVar1);
  _objc_release(uVar2);
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_001c9d80;
  puStack_50 = &DAT_01062cc0;
  local_38 = (undefined1)param_4;
  local_48 = uVar1;
  local_40 = param_3;
  _objc_retain(param_3);
  _objc_retain(uVar1);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_68);
  _objc_release(local_40);
  _objc_release(local_48);
  _objc_release(param_3);
  _objc_release(uVar1);
  return;
}


