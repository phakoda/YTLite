/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff110. FUN_001ff110 */

void FUN_001ff110(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *puStack_130;
  undefined8 uStack_128;
  code *pcStack_120;
  undefined *puStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
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
  long lStack_b0;
  undefined8 uStack_a8;
  undefined **local_98;
  undefined **local_90;
  undefined **ppuStack_88;
  int iStack_7c;
  undefined **local_78;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011c2878;
  local_4c = (uint)(DAT_01228080 == 0);
  local_60 = &PTR_LAB_011c2898;
  local_78 = &PTR_LAB_011c28b8;
  local_58 = &PTR_LAB_011c25d0;
  local_70 = &PTR_LAB_011c25d0;
  local_90 = &PTR_LAB_011c25d0;
  ppuStack_88 = &PTR_LAB_011c25d0;
  local_98 = &PTR_LAB_011c25d0;
  DAT_01228080 = 1;
  _objc_retain(param_2);
  _objc_retain(param_4);
  uStack_64 = (uint)(param_4 == 0);
  if (param_4 == 0) {
    uVar1 = _objc_alloc(PTR__OBJC_CLASS___NSXMLParser_0114eff8);
    uVar1 = _objc_msgSend(uVar1,PTR_s_initWithData__0114e2f8,param_2);
    _objc_msgSend(uVar1,PTR_s_setDelegate__0114b7d8,*(undefined8 *)(param_1 + 0x20));
    iStack_7c = FUN_00200f44(uVar1,PTR_s_parse_0114e300);
    if (iStack_7c == 0) {
      puStack_130 = PTR___NSConcreteStackBlock_01060660;
      uStack_128 = DAT_00c4c228;
      pcStack_120 = FUN_001ff504;
      puStack_118 = &UNK_01062c50;
      uStack_108 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
      _objc_retain(uVar1);
      uStack_110 = uVar1;
      _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_130);
      _objc_release(uStack_110);
      uVar2 = uStack_108;
    }
    else {
      _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + 8),
                    PTR_s_componentsJoinedByString__0114ded0,
                    &PTR____CFConstantStringClassReference_011c1f70);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      puStack_100 = PTR___NSConcreteStackBlock_01060660;
      uStack_f8 = DAT_00c4c228;
      pcStack_f0 = FUN_001ff474;
      puStack_e8 = &UNK_01062c50;
      uStack_d8 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
      uStack_e0 = uVar2;
      _objc_retain(uVar2);
      _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_100);
      _objc_release(uStack_e0);
      _objc_release(uStack_d8);
    }
    _objc_release(uVar2);
  }
  else {
    puStack_d0 = PTR___NSConcreteStackBlock_01060660;
    uStack_c8 = DAT_00c4c228;
    pcStack_c0 = FUN_001ff438;
    puStack_b8 = &UNK_01062c50;
    uStack_a8 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
    _objc_retain(param_4);
    lStack_b0 = param_4;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_d0);
    _objc_release(lStack_b0);
    uVar1 = uStack_a8;
  }
  _objc_release(uVar1);
  _objc_release(param_4);
  _objc_release(param_2);
  return;
}


