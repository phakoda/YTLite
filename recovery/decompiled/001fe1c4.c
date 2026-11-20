/* Decompiled from supplied 5.2.2 arm package. VA 0x1fe1c4. FUN_001fe1c4 */

undefined1  [16] FUN_001fe1c4(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  long lStack_70;
  undefined8 uStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011c2798;
  _objc_retain(param_2);
  _objc_retain(param_4);
  local_5c = (uint)(param_4 == 0);
  if (param_4 == 0) {
    uVar2 = _objc_alloc(PTR__OBJC_CLASS___NSXMLParser_0114eff8);
    uVar2 = _objc_msgSend(uVar2,PTR_s_initWithData__0114e2f8,param_2);
    _objc_msgSend(uVar2,PTR_s_setDelegate__0114b7d8,*(undefined8 *)(param_1 + 0x20));
    iVar1 = FUN_00200a78(uVar2,PTR_s_parse_0114e300);
    if (iVar1 == 0) {
      puStack_100 = PTR___NSConcreteStackBlock_01060660;
      uStack_f8 = DAT_00c4c228;
      pcStack_f0 = FUN_001fe508;
      puStack_e8 = &UNK_01062c50;
      uStack_d8 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
      _objc_retain(uVar2);
      uStack_e0 = uVar2;
      _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_100);
      _objc_release(uStack_e0);
      uVar4 = uStack_d8;
    }
    else {
      uStack_98 = 0;
      _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_srtForLanguage_videoID_error__0114e308,
                    *(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x30),&uStack_98);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      uVar4 = uStack_98;
      _objc_retain(uStack_98);
      puStack_d0 = PTR___NSConcreteStackBlock_01060660;
      uStack_c8 = DAT_00c4c228;
      pcStack_c0 = FUN_001fe4cc;
      puStack_b8 = &UNK_01063000;
      uStack_a0 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
      uStack_a8 = uVar4;
      uStack_b0 = uVar3;
      _objc_retain(uVar4);
      _objc_retain(uVar3);
      _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_d0);
      _objc_release(uStack_a8);
      _objc_release(uStack_b0);
      _objc_release(uStack_a0);
      _objc_release(uVar3);
    }
    _objc_release(uVar4);
  }
  else {
    puStack_90 = PTR___NSConcreteStackBlock_01060660;
    uStack_88 = DAT_00c4c228;
    pcStack_80 = FUN_001fe490;
    puStack_78 = &UNK_01062c50;
    uStack_68 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
    _objc_retain(param_4);
    lStack_70 = param_4;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_90);
    _objc_release(lStack_70);
    uVar2 = uStack_68;
  }
  _objc_release(uVar2);
  _objc_release(param_4);
  _objc_release(param_2);
  CallSupervisor(0x247f);
  return ZEXT816(0x1f);
}


