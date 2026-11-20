/* Decompiled from supplied 5.2.2 arm package. VA 0x1809f4. clearCacheWithCompletion: */

/* Function Stack Size: 0x18 bytes */

void YTPSettingsBuilder::clearCacheWithCompletion_
               (ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  
  _objc_retain(param_3,param_2,param_3,param_4);
  _dispatch_get_global_queue(0,0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_00180aac;
  puStack_30 = &DAT_01061490;
  local_28 = param_3;
  _objc_retain(param_3);
  _dispatch_async(uVar1,&local_48);
  _objc_release(uVar1);
  _objc_release(local_28);
  _objc_release(param_3);
  CallSupervisor(0x1566);
  return;
}


