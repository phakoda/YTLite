/* Decompiled from supplied 5.2.2 arm package. VA 0x1ec890. importYtlSettings: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::importYtlSettings_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID IStack_38;
  
  _objc_retain(param_3,param_2,param_3,param_4);
  _objc_msgSend(param_1,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_presentDocumentPicker__0114e160;
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001ec964;
  puStack_48 = &DAT_01062e70;
  local_40 = param_3;
  IStack_38 = param_1;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_60);
  _objc_release(uVar2);
  _objc_release(local_40);
  _objc_release(param_3);
  CallSupervisor(0xa857);
  return;
}


