/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4600. mergeVideo:withAudio:captions:duration:completion: */

/* Function Stack Size: 0x38 bytes */

void FFMpegHelper::mergeVideo_withAudio_captions_duration_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,long_long param_6,ID param_7
               ,undefined4 param_8)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puStack_f8;
  undefined8 uStack_f0;
  code *pcStack_e8;
  undefined *puStack_e0;
  ID IStack_d8;
  undefined8 uStack_d0;
  ID IStack_c8;
  ID IStack_c0;
  ID IStack_b8;
  ID IStack_b0;
  long_long lStack_a8;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_011c18b8;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_7);
  uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
  puStack_f8 = PTR___NSConcreteStackBlock_01060660;
  bVar1 = *(char *)(param_1 + 0x28) == '\0';
  local_74 = (uint)bVar1;
  if (!bVar1) {
    puStack_a0 = PTR___NSConcreteStackBlock_01060660;
    uStack_98 = DAT_00c4c228;
    pcStack_90 = FUN_001f47f8;
    puStack_88 = &DAT_01061420;
    _objc_retain(uVar2);
    uStack_80 = uVar2;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_a0);
    _objc_release(uStack_80);
  }
  uVar3 = *(undefined8 *)(param_1 + 8);
  uStack_f0 = DAT_00c4c228;
  pcStack_e8 = FUN_001f4a28;
  puStack_e0 = &UNK_01062fb0;
  IStack_d8 = param_1;
  uStack_d0 = uVar2;
  IStack_c8 = param_3;
  IStack_c0 = param_4;
  IStack_b8 = param_5;
  IStack_b0 = param_7;
  lStack_a8 = param_6;
  _objc_retain(param_7);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_retain(uVar2);
  _dispatch_async(uVar3,&puStack_f8);
  _objc_release(IStack_b0);
  _objc_release(IStack_b8);
  _objc_release(IStack_c0);
  _objc_release(IStack_c8);
  _objc_release(uStack_d0);
  _objc_release(param_7);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0x4417);
  return;
}


