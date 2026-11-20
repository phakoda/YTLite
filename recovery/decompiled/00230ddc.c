/* Decompiled from supplied 5.2.2 arm package. VA 0x230ddc. FUN_00230ddc */

undefined1  [16] FUN_00230ddc(long param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  long *plVar2;
  undefined1 auVar3 [16];
  undefined *puStack_c8;
  undefined8 uStack_c0;
  code *pcStack_b8;
  undefined *puStack_b0;
  long lStack_a8;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  long lStack_80;
  undefined *puStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  undefined *puStack_60;
  long lStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011d1880;
  _objc_retain(param_2);
  _objc_retain(param_3);
  _objc_retain(param_4);
  local_4c = (uint)(param_2 == 0);
  if (param_2 == 0) {
    puStack_c8 = PTR___NSConcreteStackBlock_01060660;
    uStack_c0 = DAT_00c4c228;
    pcStack_b8 = FUN_00231730;
    puStack_b0 = &DAT_01061420;
    plVar2 = &lStack_a8;
    _objc_retain(param_4);
    lStack_a8 = param_4;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_c8);
  }
  else if (*(char *)(param_1 + 0x20) == '\0') {
    puStack_a0 = PTR___NSConcreteStackBlock_01060660;
    uStack_98 = DAT_00c4c228;
    pcStack_90 = FUN_00231550;
    puStack_88 = &DAT_01061420;
    plVar2 = &lStack_80;
    _objc_retain(param_2);
    lStack_80 = param_2;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_a0);
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___PHPhotoLibrary_0114ed58,PTR_s_sharedPhotoLibrary_0114c600);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    puStack_78 = PTR___NSConcreteStackBlock_01060660;
    uStack_70 = DAT_00c4c228;
    pcStack_68 = FUN_0023102c;
    puStack_60 = &DAT_01061420;
    plVar2 = &lStack_58;
    _objc_retain(param_2);
    lStack_58 = param_2;
    _objc_msgSend(uVar1,PTR_s_performChanges_completionHandler_0114c620,&puStack_78,
                  &PTR___NSConcreteGlobalBlock_01063230);
    _objc_release(uVar1);
  }
  _objc_release(*plVar2);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(param_2);
  CallSupervisor(0xe4a7);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


