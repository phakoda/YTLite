/* Decompiled from supplied 5.2.2 arm package. VA 0x1fe01c. parseXMLFromURL:forLanguage:videoID:completion: */

/* Function Stack Size: 0x30 bytes */

void SRTParser::parseXMLFromURL_forLanguage_videoID_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *local_90;
  undefined8 local_88;
  code *local_80;
  undefined *puStack_78;
  ID local_70;
  ID local_68;
  ID local_60;
  ID local_58;
  
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  *(undefined1 *)(param_1 + 0x40) = 0;
  puVar2 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar1 = PTR_s_array_0114c388;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar3;
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dataTaskWithURL_completionHandle_0114d920;
  local_90 = PTR___NSConcreteStackBlock_01060660;
  local_88 = DAT_00c4c228;
  local_80 = FUN_001fe1c4;
  puStack_78 = &DAT_01063030;
  local_70 = param_1;
  local_68 = param_4;
  local_60 = param_5;
  local_58 = param_6;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_6);
  _objc_msgSend(uVar3,puVar1,param_3,&local_90);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar3);
  _objc_msgSend(uVar4,PTR_s_resume_0114d928);
  _objc_release(uVar4);
  _objc_release(local_60);
  _objc_release(local_68);
  _objc_release(local_58);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_6);
  CallSupervisor(0x60b5);
  return;
}


