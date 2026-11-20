/* Decompiled from supplied 5.2.2 arm package. VA 0x1f80b4. FUN_001f80b4 */

undefined1  [16] FUN_001f80b4(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  code *pcStack_a0;
  undefined *puStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011c1a88;
  local_6c = (uint)(DAT_0122801c == 0);
  local_78 = &PTR_LAB_011c1600;
  DAT_0122801c = 1;
  *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28) = 1;
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x20) = *(undefined8 *)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x10);
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x10) = 0;
  _objc_release(uVar2);
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_resetStatistics_0114e270);
  puVar1 = PTR___NSConcreteStackBlock_01060660;
  uVar2 = DAT_00c4c228;
  puStack_b0 = PTR___NSConcreteStackBlock_01060660;
  uStack_a8 = DAT_00c4c228;
  pcStack_a0 = FUN_001f83ec;
  puStack_98 = &DAT_01061f70;
  uStack_90 = *(undefined8 *)(param_1 + 0x20);
  uStack_88 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_b0);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x30),PTR_s_URLByDeletingLastPathComponent_0114e288);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_URLByAppendingPathComponent__0114b258,
                &PTR____CFConstantStringClassReference_011be7f0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  FUN_001fd7fc(uVar3,PTR_s_removeItemAtURL_error__0114dc60,uVar4,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_setLogDelegate__0114e2a0,
                *(undefined8 *)(param_1 + 0x20));
  _dispatch_get_global_queue(0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puStack_100 = puVar1;
  uStack_f8 = uVar2;
  pcStack_f0 = FUN_001f8644;
  puStack_e8 = &DAT_01062bc0;
  uStack_e0 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  uVar2 = *(undefined8 *)(param_1 + 0x38);
  uStack_c0 = *(undefined8 *)(param_1 + 0x40);
  uStack_d0 = *(undefined8 *)(param_1 + 0x20);
  uStack_d8 = uVar4;
  _objc_retain(uVar2);
  uStack_c8 = uVar2;
  _objc_retain(uVar4);
  _dispatch_async(uVar3,&puStack_100);
  _objc_release(uVar3);
  _objc_release(uStack_c8);
  _objc_release(uStack_d8);
  _objc_release(uStack_e0);
  _objc_release(uVar4);
  _objc_release(uStack_88);
  CallSupervisor(0x1a96);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


