/* Decompiled from supplied 5.2.2 arm package. VA 0x10927c. FUN_0010927c */

undefined8 FUN_0010927c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  puVar1 = PTR_s_audioTrack_0114cbf8;
  _objc_retain(param_3);
  _objc_msgSend(param_2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_displayName_0114d068;
  _objc_msgSend(uVar3,PTR_s_displayName_0114d068);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar5,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(uVar4,PTR_s_compare__0114d070,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  return uVar7;
}


