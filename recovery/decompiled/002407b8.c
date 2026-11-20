/* Decompiled from supplied 5.2.2 arm package. VA 0x2407b8. FUN_002407b8 */

void FUN_002407b8(void)

{
  bool bVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long alStack_170 [2];
  void *pvStack_160;
  long lStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **ppuStack_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **ppuStack_a8;
  uint uStack_9c;
  undefined **ppuStack_98;
  undefined **ppuStack_90;
  uint uStack_84;
  undefined **ppuStack_80;
  long lStack_78;
  
  lVar2 = thunk_FUN_00241798();
  lStack_78 = *(long *)PTR____stack_chk_guard_01060708;
  ppuStack_80 = &PTR_LAB_011d3090;
  uStack_84 = (uint)(DAT_012285a0 == 0);
  ppuStack_98 = &PTR_LAB_011d30b0;
  ppuStack_a8 = &PTR_LAB_011d30c8;
  ppuStack_b8 = &PTR_LAB_011d30e0;
  ppuStack_d0 = &PTR_LAB_011d3100;
  ppuStack_90 = &PTR_LAB_011d2ec0;
  ppuStack_c8 = &PTR_LAB_011d2ec0;
  ppuStack_e0 = &PTR__av_display_rotation_get_011d3118;
  ppuStack_f8 = &PTR_LAB_011d2ec0;
  ppuStack_f0 = &PTR_LAB_011d2ec0;
  ppuStack_108 = &PTR_LAB_011d2ec0;
  ppuStack_100 = &PTR_LAB_011d2ec0;
  DAT_012285a0 = 1;
  ppuStack_150 = &PTR____CFConstantStringClassReference_011d2da0;
  ppuStack_148 = &PTR____CFConstantStringClassReference_011d2e60;
  ppuStack_130 = &PTR____CFConstantStringClassReference_011d2de0;
  ppuStack_128 = &PTR____CFConstantStringClassReference_011d2e20;
  ppuStack_140 = &PTR____CFConstantStringClassReference_011d2ea0;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_systemVersion_0114b3b8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuStack_138 = &PTR____CFConstantStringClassReference_011d2d60;
  uStack_120 = uVar4;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithInt__0114b018,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_118 = uVar5;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&ppuStack_130,&ppuStack_150,4);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                PTR_s_dataWithJSONObject_options_error_0114b4f0,uVar6,0,0);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  uStack_9c = (uint)(lVar7 == 0);
  if (lVar7 != 0) {
    uVar3 = _objc_alloc(PTR__OBJC_CLASS___NSString_0114eb38);
    uVar3 = _objc_msgSend(uVar3,PTR_s_initWithData_encoding__0114b428,lVar7,4);
    lVar8 = thunk_FUN_00afc8f0();
    uStack_ac = (uint)(lVar8 == 0);
    if (lVar8 != 0) {
      pvStack_160 = _malloc(1);
      lStack_158 = 0;
      uVar4 = thunk_FUN_00b1b6f0(0,s_Content_Type__application_json_011d2c30);
      thunk_FUN_00241890(lVar8,&DAT_00002712,s_https___api_dvntm_com_api_update_011d2be0);
      thunk_FUN_002418bc(lVar8,0x2f,1);
      uVar5 = _objc_retainAutorelease(uVar3);
      uVar5 = _objc_msgSend(uVar5,PTR_s_UTF8String_0114b498);
      thunk_FUN_00241908(lVar8,&DAT_0000271f,uVar5);
      thunk_FUN_00241934(lVar8,&DAT_00002727,uVar4);
      thunk_FUN_00241960(lVar8,0xd,10);
      thunk_FUN_0024198c(lVar8,0x4e,8);
      thunk_FUN_002419b8(lVar8,&DAT_00004e2b,FUN_0024067c);
      thunk_FUN_002419e4(lVar8,&DAT_00002711,&pvStack_160);
      thunk_FUN_00241a10(lVar8,0x40,1);
      thunk_FUN_00241a3c(lVar8,0x51,2);
      alStack_170[0] = 0;
      thunk_FUN_00afc990(lVar8);
      thunk_FUN_00241a88(lVar8,0x200002,alStack_170);
      thunk_FUN_00b1b804(uVar4);
      thunk_FUN_00afcb1c(lVar8);
      bVar1 = alStack_170[0] != 200 || lStack_158 == 0;
      uStack_bc = (uint)bVar1;
      if (bVar1) {
        _free(pvStack_160);
      }
      else {
        _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,
                      PTR_s_dataWithBytesNoCopy_length_freeW_0114e940,pvStack_160,lStack_158,1);
        uVar4 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                      PTR_s_JSONObjectWithData_options_error_0114b4a0,uVar4,0,0);
        lVar8 = _objc_retainAutoreleasedReturnValue();
        uStack_d4 = (uint)(lVar8 == 0);
        if (lVar8 != 0) {
          _objc_msgSend(lVar8,PTR_s_objectForKeyedSubscript__0114ae80,
                        &PTR____CFConstantStringClassReference_011d2d20);
          uVar5 = _objc_retainAutoreleasedReturnValue();
          uVar9 = _objc_msgSend(uVar5,PTR_s_unsignedLongLongValue_0114e008);
          _objc_release(uVar5);
          bVar1 = uVar9 % 1000000 + (uVar9 / 10000000) * 1000000 == *(long *)(lVar2 + 0x28);
          uStack_e4 = (uint)bVar1;
          if (bVar1) {
            _dispatch_block_cancel(*(undefined8 *)(*(long *)(*(long *)(lVar2 + 0x20) + 8) + 0x28));
          }
        }
        _objc_release(lVar8);
        _objc_release(uVar4);
      }
    }
    _objc_release(uVar3);
  }
  _objc_release(lVar7);
  _objc_release(uVar6);
  CallSupervisor(0x1d85);
  if (*(long *)PTR____stack_chk_guard_01060708 == lStack_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


