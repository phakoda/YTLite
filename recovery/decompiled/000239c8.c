/* Decompiled from supplied 5.2.2 arm package. VA 0x239c8. FUN_000239c8 */

void FUN_000239c8(void)

{
  uint uVar1;
  CC_LONG len;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  void *data;
  undefined *puVar9;
  undefined **ppuVar10;
  byte in_w11;
  long in_x12;
  undefined1 in_w13;
  long in_x14;
  long lVar11;
  long lStack_b8;
  long lStack_98;
  long lStack_68;
  uchar auStack_60 [40];
  undefined **local_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_01159228;
  local_2c = (uint)DAT_01225d48;
  puVar9 = (&PTR_LAB_01159228)[DAT_01225d48];
  uVar1 = DAT_01159238 ^ 0x20d8821e;
  local_38 = &PTR_LAB_01158940;
  *(undefined1 *)(in_x14 + 5) = in_w13;
  *(byte *)(in_x14 + 6) = *(byte *)(in_x12 + 6) ^ 0xc3;
  *(byte *)(in_x14 + 7) = *(byte *)(in_x12 + 7) ^ 0xfe;
  s__________01156b73[0] = DAT_01156b6a ^ in_w11;
  s__________01156b73[1] = bRam0000000001156b6b ^ 0x5c;
  s__________01156b73[2] = bRam0000000001156b6c ^ 0x7a;
  s__________01156b73[3] = bRam0000000001156b6d ^ 0x4b;
  s__________01156b73[4] = bRam0000000001156b6e ^ 0x1e;
  s__________01156b73[5] = bRam0000000001156b6f ^ 0x62;
  s__________01156b73[6] = bRam0000000001156b70 ^ 0x2b;
  s__________01156b73[7] = bRam0000000001156b71 ^ 0x4d;
  s__________01156b73[8] = bRam0000000001156b72 ^ 0xfd;
  s__02x_01156b65[0] = ~DAT_01156b60;
  s__02x_01156b65[1] = bRam0000000001156b61 ^ 0x40;
  s__02x_01156b65[2] = bRam0000000001156b62 ^ 0x9a;
  s__02x_01156b65[3] = bRam0000000001156b63 ^ 0x16;
  s__02x_01156b65[4] = bRam0000000001156b64 ^ 0x8f;
  *(undefined4 *)(puVar9 + (int)-uVar1) = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_identifierForVendor_0114b478);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_UUIDString_0114b480);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar9 = PTR_s_length_0114b438;
  ppuVar10 = &PTR____CFConstantStringClassReference_01156bf0;
  if (lVar4 != 0) {
    uVar5 = _objc_msgSend(lVar4,PTR_s_length_0114b438);
    ppuVar10 = &PTR____CFConstantStringClassReference_01156bf0;
    if (uVar5 >= 10) {
      thunk_FUN_00024f34(*(long *)(lStack_98 + (ulong)(uVar5 < 10) * 8) +
                         (long)(int)-(uRam0000000001159308 ^ 0xf12801db));
      uVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,
                    s_com_dvntm_ytplus_01156bb0);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_00031998(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_01156c70,lVar4,uVar2);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_dataUsingEncoding__0114b460,4);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar8 = _objc_retainAutorelease();
      data = (void *)_objc_msgSend(uVar8,PTR_s_bytes_0114b440);
      len = _objc_msgSend(uVar7,puVar9);
      _CC_SHA256(data,len,auStack_60);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_stringWithCapacity__0114b488,
                    0x40);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar9 = PTR_s_appendFormat__0114b490;
      lVar11 = 0;
      ppuVar10 = &PTR_s_setTintColor__0114b000;
      while( true ) {
        thunk_FUN_00031a68(ppuVar10,uVar8,puVar9,&PTR____CFConstantStringClassReference_01156c30,
                           auStack_60[lVar11]);
        ppuVar10 = (undefined **)
                   (*(long *)(lStack_b8 + (ulong)(lVar11 == 0x1f) * 8) +
                   (long)(int)-(uRam0000000001159330 ^ 0x290bdfc8));
        if (lVar11 == 0x1f) break;
        lVar11 = lVar11 + 1;
      }
      ppuVar10 = (undefined **)_objc_msgSend(uVar8,PTR_s_copy_0114b058);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar3);
      _objc_release(uVar2);
    }
  }
  _objc_release(lVar4);
  if (*(long *)PTR____stack_chk_guard_01060708 != lStack_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(ppuVar10);
  return;
}


