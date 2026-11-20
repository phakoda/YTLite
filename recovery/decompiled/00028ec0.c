/* Decompiled from supplied 5.2.2 arm package. VA 0x28ec0. FUN_00028ec0 */

void FUN_00028ec0(long param_1,long param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 auStack_110 [16];
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined1 auStack_e0 [16];
  undefined1 auStack_d0 [24];
  undefined **local_b8;
  undefined **local_b0;
  undefined **ppuStack_a8;
  uint uStack_9c;
  undefined **local_98;
  int iStack_8c;
  undefined **local_88;
  undefined8 uStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  puVar1 = PTR_s_dataUsingEncoding__0114b460;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_DAT_011597a0;
  local_74 = (uint)(param_1 != 0 && param_2 != 0);
  local_88 = &PTR_LAB_011597b8;
  local_98 = &PTR_LAB_011597d0;
  local_b0 = &PTR_LAB_01158940;
  ppuStack_a8 = &PTR_LAB_01158940;
  local_b8 = &PTR_LAB_01158940;
  if (param_1 != 0 && param_2 != 0) {
    _objc_retain(param_2);
    _objc_msgSend(param_1,puVar1,4);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _arc4random_buf(auStack_d0,0x10);
    _arc4random_buf(auStack_e0,0xc);
    _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithBytes_length__0114b448,auStack_d0,
                  0x10);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    iVar2 = FUN_00032bd4(param_2,uVar4,&uStack_100);
    _objc_release(param_2);
    iStack_8c = iVar2;
    if (iVar2 == 0) {
      uVar8 = 0;
    }
    else {
      lVar5 = _objc_msgSend(uVar3,PTR_s_length_0114b438);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableData_0114eba0,PTR_s_dataWithLength__0114b450,lVar5);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar7 = _objc_retainAutorelease(uVar3);
      uVar7 = _objc_msgSend(uVar7,PTR_s_bytes_0114b440);
      uVar8 = _objc_retainAutorelease(uVar6);
      uVar8 = _objc_msgSend(uVar8,PTR_s_mutableBytes_0114b458);
      uStack_80 = 0x10;
      iVar2 = FUN_00032d50(0,0,&uStack_100,0x20,auStack_e0,0xc,0,0,uVar7,lVar5,uVar8,auStack_110,
                           &uStack_80);
      uStack_f8 = 0;
      uStack_100 = 0;
      uStack_e8 = 0;
      uStack_f0 = 0;
      uStack_9c = (uint)(iVar2 == 0);
      if (iVar2 == 0) {
        _objc_msgSend(PTR__OBJC_CLASS___NSMutableData_0114eba0,PTR_s_dataWithCapacity__0114b4a8,
                      lVar5 + 0x2c);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        puVar1 = PTR_s_appendBytes_length__0114b4b0;
        _objc_msgSend(uVar7,PTR_s_appendBytes_length__0114b4b0,auStack_d0,0x10);
        _objc_msgSend(uVar7,puVar1,auStack_e0,0xc);
        _objc_msgSend(uVar7,puVar1,auStack_110,0x10);
        _objc_msgSend(uVar7,PTR_s_appendData__0114b4b8,uVar6);
        _objc_msgSend(uVar7,PTR_s_base64EncodedStringWithOptions__0114b4c0,0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar7);
      }
      else {
        uVar8 = 0;
      }
      _objc_release(uVar6);
    }
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  else {
    uVar8 = 0;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar8);
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


