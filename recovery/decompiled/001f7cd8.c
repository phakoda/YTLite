/* Decompiled from supplied 5.2.2 arm package. VA 0x1f7cd8. cutAudio:duration:completion: */

/* Function Stack Size: 0x28 bytes */

void FFMpegHelper::cutAudio_duration_completion_
               (ID param_1,SEL param_2,ID param_3,long_long param_4,ID param_5,undefined4 param_6)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  undefined8 uStack_a8;
  ID IStack_a0;
  ID IStack_98;
  long_long lStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined *puStack_70;
  undefined8 uStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011c1a48;
  _objc_retain(param_3);
  _objc_retain(param_5);
  uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
  puStack_d0 = PTR___NSConcreteStackBlock_01060660;
  bVar1 = *(char *)(param_1 + 0x28) == '\0';
  local_5c = (uint)bVar1;
  if (!bVar1) {
    puStack_88 = PTR___NSConcreteStackBlock_01060660;
    uStack_80 = DAT_00c4c228;
    pcStack_78 = FUN_001f7e7c;
    puStack_70 = &DAT_01061420;
    _objc_retain(uVar2);
    uStack_68 = uVar2;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_88);
    _objc_release(uStack_68);
  }
  uVar3 = *(undefined8 *)(param_1 + 8);
  uStack_c8 = DAT_00c4c228;
  pcStack_c0 = FUN_001f80b4;
  puStack_b8 = &DAT_01062bc0;
  IStack_b0 = param_1;
  uStack_a8 = uVar2;
  IStack_a0 = param_3;
  IStack_98 = param_5;
  lStack_90 = param_4;
  _objc_retain(param_5);
  _objc_retain(param_3);
  _objc_retain(uVar2);
  _dispatch_async(uVar3,&puStack_d0);
  _objc_release(IStack_98);
  _objc_release(IStack_a0);
  _objc_release(uStack_a8);
  _objc_release(param_5);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0xd8bf);
  return;
}


