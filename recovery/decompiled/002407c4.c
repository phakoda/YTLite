/* Decompiled from supplied 5.2.2 arm package. VA 0x2407c4. FUN_002407c4 */

void FUN_002407c4(long param_1)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long alStack_160 [2];
  void *pvStack_150;
  long lStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined **local_f8;
  undefined **ppuStack_f0;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011d3090;
  local_74 = (uint)(DAT_012285a0 == 0);
  local_88 = &PTR_LAB_011d30b0;
  local_98 = &PTR_LAB_011d30c8;
  local_a8 = &PTR_LAB_011d30e0;
  local_c0 = &PTR_LAB_011d3100;
  local_80 = &PTR_LAB_011d2ec0;
  local_b8 = &PTR_LAB_011d2ec0;
  local_d0 = &PTR__av_display_rotation_get_011d3118;
  local_e8 = &PTR_LAB_011d2ec0;
  ppuStack_e0 = &PTR_LAB_011d2ec0;
  local_f8 = &PTR_LAB_011d2ec0;
  ppuStack_f0 = &PTR_LAB_011d2ec0;
  DAT_012285a0 = 1;
  ppuStack_140 = &PTR____CFConstantStringClassReference_011d2da0;
  ppuStack_138 = &PTR____CFConstantStringClassReference_011d2e60;
  ppuStack_120 = &PTR____CFConstantStringClassReference_011d2de0;
  ppuStack_118 = &PTR____CFConstantStringClassReference_011d2e20;
  ppuStack_130 = &PTR____CFConstantStringClassReference_011d2ea0;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_systemVersion_0114b3b8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuStack_128 = &PTR____CFConstantStringClassReference_011d2d60;
  uStack_110 = uVar3;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithInt__0114b018,0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uStack_108 = uVar4;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&ppuStack_120,&ppuStack_140,4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                PTR_s_dataWithJSONObject_options_error_0114b4f0,uVar5,0,0);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_8c = (uint)(lVar6 == 0);
  if (lVar6 != 0) {
    uVar2 = _objc_alloc(PTR__OBJC_CLASS___NSString_0114eb38);
    uVar2 = _objc_msgSend(uVar2,PTR_s_initWithData_encoding__0114b428,lVar6,4);
    lVar7 = thunk_FUN_00afc8f0();
    uStack_9c = (uint)(lVar7 == 0);
    if (lVar7 != 0) {
      pvStack_150 = _malloc(1);
      lStack_148 = 0;
      uVar3 = thunk_FUN_00b1b6f0(0,s_Content_Type__application_json_011d2c30);
      thunk_FUN_00241890(lVar7,&DAT_00002712,s_https___api_dvntm_com_api_update_011d2be0);
      thunk_FUN_002418bc(lVar7,0x2f,1);
      uVar4 = _objc_retainAutorelease(uVar2);
      uVar4 = _objc_msgSend(uVar4,PTR_s_UTF8String_0114b498);
      thunk_FUN_00241908(lVar7,&DAT_0000271f,uVar4);
      thunk_FUN_00241934(lVar7,&DAT_00002727,uVar3);
      thunk_FUN_00241960(lVar7,0xd,10);
      thunk_FUN_0024198c(lVar7,0x4e,8);
      thunk_FUN_002419b8(lVar7,&DAT_00004e2b,FUN_0024067c);
      thunk_FUN_002419e4(lVar7,&DAT_00002711,&pvStack_150);
      thunk_FUN_00241a10(lVar7,0x40,1);
      thunk_FUN_00241a3c(lVar7,0x51,2);
      alStack_160[0] = 0;
      thunk_FUN_00afc990(lVar7);
      thunk_FUN_00241a88(lVar7,0x200002,alStack_160);
      thunk_FUN_00b1b804(uVar3);
      thunk_FUN_00afcb1c(lVar7);
      bVar1 = alStack_160[0] != 200 || lStack_148 == 0;
      uStack_ac = (uint)bVar1;
      if (bVar1) {
        _free(pvStack_150);
      }
      else {
        _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,
                      PTR_s_dataWithBytesNoCopy_length_freeW_0114e940,pvStack_150,lStack_148,1);
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                      PTR_s_JSONObjectWithData_options_error_0114b4a0,uVar3,0,0);
        lVar7 = _objc_retainAutoreleasedReturnValue();
        uStack_c4 = (uint)(lVar7 == 0);
        if (lVar7 != 0) {
          _objc_msgSend(lVar7,PTR_s_objectForKeyedSubscript__0114ae80,
                        &PTR____CFConstantStringClassReference_011d2d20);
          uVar4 = _objc_retainAutoreleasedReturnValue();
          uVar8 = _objc_msgSend(uVar4,PTR_s_unsignedLongLongValue_0114e008);
          _objc_release(uVar4);
          bVar1 = uVar8 % 1000000 + (uVar8 / 10000000) * 1000000 == *(long *)(param_1 + 0x28);
          uStack_d4 = (uint)bVar1;
          if (bVar1) {
            _dispatch_block_cancel(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x28))
            ;
          }
        }
        _objc_release(lVar7);
        _objc_release(uVar3);
      }
    }
    _objc_release(uVar2);
  }
  _objc_release(lVar6);
  _objc_release(uVar5);
  CallSupervisor(0x1d85);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


