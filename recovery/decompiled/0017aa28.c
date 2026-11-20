/* Decompiled from supplied 5.2.2 arm package. VA 0x17aa28. showDonationSheet: */

/* Function Stack Size: 0x18 bytes */

void YTPSettingsBuilder::showDonationSheet_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  ID IStack_68;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011a87c0;
  local_4c = (uint)(DAT_01227538 == 0);
  local_58 = &PTR_LAB_011a7950;
  DAT_01227538 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,
                &PTR____CFConstantStringClassReference_011a5d70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dataTaskWithURL_completionHandle_0114d920;
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_0017adb8;
  puStack_78 = &UNK_010627c0;
  IStack_70 = param_1;
  IStack_68 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,uVar3,&puStack_90);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar4,PTR_s_resume_0114d928);
  _objc_release(uVar4);
  _objc_release(IStack_68);
  _objc_release(param_3);
  return;
}


