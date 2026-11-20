/* Decompiled from supplied 5.2.2 arm package. VA 0x106840. downloadVideoWithFormat:audioFormat:fileName:extension:videoID:playerVC:sender: */

/* Function Stack Size: 0x48 bytes */

void DownloadMenuHelper::
     downloadVideoWithFormat_audioFormat_fileName_extension_videoID_playerVC_sender_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               ID param_8,ID param_9)

{
  undefined *puVar1;
  undefined *local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined *puStack_a0;
  ID local_98;
  ID local_90;
  ID local_88;
  ID local_80;
  ID local_78;
  ID local_70;
  ID local_68;
  
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_7);
  _objc_retain(param_8);
  puVar1 = PTR_s_getCaptionsUrlSheet_sender_compl_0114d030;
  local_b8 = PTR___NSConcreteStackBlock_01060660;
  local_b0 = DAT_00c4c228;
  local_a8 = FUN_001069d0;
  puStack_a0 = &DAT_01062350;
  local_98 = param_1;
  local_90 = param_3;
  local_88 = param_4;
  local_80 = param_5;
  local_78 = param_6;
  local_70 = param_7;
  local_68 = param_8;
  _objc_retain();
  _objc_retain(param_7);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,param_8,param_9,&local_b8);
  _objc_release(local_68);
  _objc_release(local_70);
  _objc_release(local_78);
  _objc_release(local_80);
  _objc_release(local_88);
  _objc_release(local_90);
  _objc_release(param_8);
  _objc_release(param_7);
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xf950);
  return;
}


