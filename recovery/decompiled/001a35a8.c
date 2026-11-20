/* Decompiled from supplied 5.2.2 arm package. VA 0x1a35a8. FUN_001a35a8 */

undefined1  [16] FUN_001a35a8(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  double dVar3;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_FUN_011ae7f8;
  _objc_retain(param_2);
  local_3c = (uint)(param_2 == 0);
  if (param_2 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___AVAsset_0114ef30,PTR_s_assetWithURL__0114dc18,param_2);
    lVar1 = _objc_retainAutoreleasedReturnValue();
    if (lVar1 == 0) {
      uStack_58 = 0;
      uStack_50 = 0;
      uStack_48 = 0;
    }
    else {
      _objc_msgSend(&uStack_58,lVar1,PTR_s_duration_0114dc20);
    }
    uStack_68 = uStack_50;
    uStack_70 = uStack_58;
    uStack_60 = uStack_48;
    dVar3 = (double)_CMTimeGetSeconds(&uStack_70);
    if (10.0 < dVar3) {
      _dispatch_async((&PTR_LAB_011ae838)[10.0 < dVar3] + (int)-(uRam00000000011ae848 ^ 0x887c88d6),
                      PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_010628c0);
    }
    else {
      _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_tempCopyOfURL__0114dc28,param_2);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      puStack_a0 = PTR___NSConcreteStackBlock_01060660;
      uStack_98 = DAT_00c4c228;
      pcStack_90 = FUN_001a397c;
      puStack_88 = &DAT_01061f70;
      uStack_80 = *(undefined8 *)(param_1 + 0x20);
      uStack_78 = uVar2;
      _objc_retain();
      _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_a0);
      _objc_release(uStack_78);
      _objc_release(uVar2);
    }
    _objc_release(lVar1);
  }
  _objc_release(param_2);
  CallSupervisor(0xa3ca);
  return ZEXT816(0x1f);
}


