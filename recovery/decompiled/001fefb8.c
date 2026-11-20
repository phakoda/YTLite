/* Decompiled from supplied 5.2.2 arm package. VA 0x1fefb8. parseTranscriptFromURL:completion: */

/* Function Stack Size: 0x20 bytes */

void SRTParser::parseTranscriptFromURL_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  ID local_48;
  
  _objc_retain(param_4);
  *(undefined1 *)(param_1 + 0x40) = 1;
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
  local_70 = PTR___NSConcreteStackBlock_01060660;
  local_68 = DAT_00c4c228;
  local_60 = FUN_001ff110;
  puStack_58 = &DAT_01063060;
  local_50 = param_1;
  local_48 = param_4;
  _objc_retain(param_4);
  _objc_msgSend(uVar3,puVar1,param_3,&local_70);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar3);
  _objc_msgSend(uVar4,PTR_s_resume_0114d928);
  _objc_release(uVar4);
  _objc_release(local_48);
  _objc_release(param_4);
  CallSupervisor(0xdbf9);
  return;
}


