/* Decompiled from supplied 5.2.2 arm package. VA 0x2495c. FUN_0002495c */

void FUN_0002495c(void)

{
  undefined *puVar1;
  CC_LONG len;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  void *data;
  undefined **ppuVar7;
  long lVar8;
  uchar auStack_f0 [32];
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **local_b0;
  undefined **ppuStack_a8;
  uint uStack_9c;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011592c0;
  local_74 = (uint)(DAT_01225dbc == 0);
  local_88 = &PTR_LAB_011592e0;
  ppuStack_80 = &PTR_LAB_01158940;
  local_98 = &PTR_FUN_011592f8;
  local_b0 = &PTR_LAB_01158940;
  ppuStack_a8 = &PTR_LAB_01158940;
  local_b8 = &PTR_LAB_01159320;
  DAT_01225dbc = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_identifierForVendor_0114b478);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_UUIDString_0114b480);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = PTR_s_length_0114b438;
  uStack_8c = (uint)(lVar4 == 0);
  ppuVar7 = &PTR____CFConstantStringClassReference_01156bf0;
  if (lVar4 != 0) {
    uVar5 = _objc_msgSend(lVar4,PTR_s_length_0114b438);
    uStack_9c = (uint)(uVar5 < 10);
    ppuVar7 = &PTR____CFConstantStringClassReference_01156bf0;
    if (uVar5 >= 10) {
      thunk_FUN_00024f34(local_98[uStack_9c] + (int)-(uRam0000000001159308 ^ 0xf12801db));
      uVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,
                    s_com_dvntm_ytplus_01156bb0);
      uStack_d0 = _objc_retainAutoreleasedReturnValue();
      uStack_c8 = uVar2;
      thunk_FUN_00031998(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_01156c70,lVar4,uVar2);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar2,PTR_s_dataUsingEncoding__0114b460,4);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      uVar6 = _objc_retainAutorelease();
      data = (void *)_objc_msgSend(uVar6,PTR_s_bytes_0114b440);
      len = _objc_msgSend(uVar3,puVar1);
      _CC_SHA256(data,len,auStack_f0);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_stringWithCapacity__0114b488,
                    0x40);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_appendFormat__0114b490;
      lVar8 = 0;
      ppuVar7 = &PTR_s_setTintColor__0114b000;
      while( true ) {
        thunk_FUN_00031a68(ppuVar7,uVar6,puVar1,&PTR____CFConstantStringClassReference_01156c30,
                           auStack_f0[lVar8]);
        uStack_bc = (uint)(lVar8 == 0x1f);
        ppuVar7 = (undefined **)(local_b8[uStack_bc] + (int)-(uRam0000000001159330 ^ 0x290bdfc8));
        if (lVar8 == 0x1f) break;
        lVar8 = lVar8 + 1;
        uStack_bc = 0;
      }
      ppuVar7 = (undefined **)_objc_msgSend(uVar6,PTR_s_copy_0114b058);
      _objc_release(uVar6);
      _objc_release(uVar3);
      _objc_release(uVar2);
      _objc_release(uStack_d0);
      _objc_release(uStack_c8);
    }
  }
  _objc_release(lVar4);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(ppuVar7);
  return;
}


