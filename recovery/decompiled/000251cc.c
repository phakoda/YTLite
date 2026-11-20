/* Decompiled from supplied 5.2.2 arm package. VA 0x251cc. FUN_000251cc */

undefined1  [16] FUN_000251cc(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auVar13 [16];
  undefined8 auStack_110 [2];
  void *pvStack_100;
  undefined8 uStack_f8;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **ppuStack_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  puVar3 = PTR__OBJC_CLASS___NSCharacterSet_0114eb70;
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar2 = PTR_s_URLQueryAllowedCharacterSet_0114b3c0;
  local_68 = &PTR_LAB_01159358;
  local_6c = (uint)(DAT_01225dc8 == 0);
  local_80 = &PTR_LAB_01159378;
  local_90 = &PTR_LAB_01159390;
  local_78 = &PTR_LAB_01158940;
  local_a8 = &PTR_LAB_01158940;
  ppuStack_a0 = &PTR_LAB_01158940;
  local_b8 = &PTR_LAB_011593c0;
  ppuStack_b0 = &PTR_LAB_01158940;
  local_d0 = &PTR_LAB_011593e0;
  ppuStack_c8 = &PTR_LAB_01158940;
  local_e8 = &PTR_LAB_01158940;
  ppuStack_e0 = &PTR_LAB_01158940;
  DAT_01225dc8 = 1;
  uVar12 = *(undefined8 *)(param_1 + 0x20);
  _objc_retain(uVar12);
  _objc_msgSend(puVar3,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,PTR_s_stringByAddingPercentEncodingWit_0114b3c8,uVar6);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar12);
  puVar2 = PTR_s_stringWithFormat__0114b378;
  thunk_FUN_00032060(puVar1,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_01156ff0,
                     s_https___api_dvntm_com_api_accoun_01156dc0,uVar7);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  _objc_release(uVar6);
  lVar8 = thunk_FUN_00afc8f0();
  uStack_84 = (uint)(lVar8 == 0);
  if (lVar8 != 0) {
    pvStack_100 = _malloc(1);
    uStack_f8 = 0;
    auStack_110[0] = 0;
    uVar6 = _objc_retainAutorelease(uVar12);
    uVar6 = _objc_msgSend(uVar6,PTR_s_UTF8String_0114b498);
    thunk_FUN_00031d60(lVar8,&DAT_00002712,uVar6);
    thunk_FUN_00031d8c(lVar8,0x50,1);
    thunk_FUN_00031db8(lVar8,0xd,10);
    thunk_FUN_00031de4(lVar8,0x4e,8);
    thunk_FUN_00031e10(lVar8,&DAT_00004e2b,FUN_000286f4);
    thunk_FUN_00031e3c(lVar8,&DAT_00002711,&pvStack_100);
    thunk_FUN_00031e68(lVar8,0x40,1);
    thunk_FUN_00031e94(lVar8,0x51,2);
    thunk_FUN_00031ec0(lVar8,&UNK_000027f6,s_sha256__ulUAq2OShSsTDjp9IAcba4qk_01156d50);
    iVar4 = thunk_FUN_00afc990(lVar8);
    thunk_FUN_00031f0c(lVar8,0x200002,auStack_110);
    thunk_FUN_00afcb1c(lVar8);
    uStack_94 = (uint)(iVar4 == 0);
    if (iVar4 == 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithBytes_length__0114b448,
                    pvStack_100,uStack_f8);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _free(pvStack_100);
      _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                    PTR_s_JSONObjectWithData_options_error_0114b4a0,uVar6,0,0);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar6);
      goto LAB_00025ed4;
    }
    _free(pvStack_100);
  }
  uVar7 = 0;
LAB_00025ed4:
  _objc_release(uVar12);
  puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
  _objc_msgSend(uVar7,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_01156ef0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_00031f8c(uVar6,PTR_s_boolValue_0114b3d8);
  _objc_release(uVar6);
  uStack_bc = uVar5;
  if (uVar5 == 0) {
    _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061500);
  }
  else {
    _objc_msgSend(local_b8[uVar5] + (int)-(uRam00000000011593d0 ^ 0x280ec6e5),uVar7,puVar1,
                  &PTR____CFConstantStringClassReference_01156f70);
    lVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar1,&PTR____CFConstantStringClassReference_01156f30);
    lVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar1,&PTR____CFConstantStringClassReference_01156fb0);
    lVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_d4 = (uint)((lVar8 != 0 && lVar9 != 0) && lVar10 != 0);
    if ((lVar8 != 0 && lVar9 != 0) && lVar10 != 0) {
      uVar11 = *(undefined8 *)(param_1 + 0x20);
      uVar12 = _objc_msgSend(lVar10,PTR_s_doubleValue_0114b3f0);
      _objc_retain(lVar8);
      _objc_retain(uVar11);
      _objc_retain(lVar9);
      thunk_FUN_000287c0();
      uVar6 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_00028954(&PTR____CFConstantStringClassReference_01156eb0,uVar11,uVar6);
      thunk_FUN_00028954(&PTR____CFConstantStringClassReference_01156e70,lVar8,uVar11);
      _objc_release(lVar8);
      thunk_FUN_00028954(&PTR____CFConstantStringClassReference_01156f30,lVar9,uVar11);
      _objc_release(lVar9);
      thunk_FUN_00031c94(uVar12,PTR__OBJC_CLASS___NSString_0114eb38,puVar2,
                         &PTR____CFConstantStringClassReference_01156e30);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_00028954(&PTR____CFConstantStringClassReference_01156fb0,uVar12,uVar11);
      _objc_release(uVar11);
      _objc_release(uVar12);
      DAT_01225d48 = 0;
      _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_010615a0);
      _objc_release(uVar6);
      DAT_01225d20 = 1;
      thunk_FUN_00026374();
    }
    _objc_release(lVar10);
    _objc_release(lVar9);
    _objc_release(lVar8);
  }
  _objc_release(uVar7);
  CallSupervisor(0x107);
  auVar13._8_8_ = 0x1f;
  auVar13._0_8_ = 0x1a;
  return auVar13;
}


