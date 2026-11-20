/* Decompiled from supplied 5.2.2 arm package. VA 0x27464. FUN_00027464 */

void FUN_00027464(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined1 auStack_130 [16];
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined1 *puStack_100;
  undefined **local_f8;
  undefined **ppuStack_f0;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  int iStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined8 uStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01159568;
  _objc_retain(param_2);
  puVar1 = PTR__OBJC_CLASS___NSData_0114eb98;
  local_7c = (uint)(param_2 == 0);
  local_90 = &PTR_LAB_01159580;
  local_a0 = &PTR_LAB_01159598;
  local_b0 = &PTR_LAB_011595b0;
  local_c0 = &PTR_LAB_011595c8;
  local_d0 = &PTR_LAB_011595e0;
  local_e8 = &PTR_LAB_01158940;
  ppuStack_e0 = &PTR_LAB_01158940;
  local_f8 = &PTR_LAB_01158940;
  ppuStack_f0 = &PTR_LAB_01158940;
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    _objc_retain(local_78[local_7c] + (int)-(DAT_01159578 ^ 0x86619df2),param_1);
    uVar3 = _objc_alloc(puVar1);
    lVar4 = _objc_msgSend(uVar3,PTR_s_initWithBase64EncodedString_opti_0114b430,param_1,0);
    _objc_release(param_1);
    puVar1 = PTR_s_length_0114b438;
    uVar3 = 0;
    uStack_94 = (uint)(lVar4 == 0);
    if (lVar4 != 0) {
      uVar5 = _objc_msgSend(lVar4,PTR_s_length_0114b438);
      uVar3 = 0;
      uStack_a4 = (uint)(uVar5 < 0x2d);
      if (uVar5 >= 0x2d) {
        uVar3 = _objc_retainAutorelease
                          (local_a0[uStack_a4] + (int)-(uRam00000000011595a8 ^ 0xce53873c),lVar4);
        lVar6 = _objc_msgSend(uVar3,PTR_s_bytes_0114b440);
        _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithBytes_length__0114b448,lVar6,
                      0x10);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        lVar8 = _objc_msgSend(lVar4,puVar1);
        iStack_b4 = FUN_000326d4(param_2,uVar7,&uStack_120);
        if (iStack_b4 == 0) {
          uVar3 = 0;
        }
        else {
          puStack_100 = (undefined1 *)&puStack_100;
          _objc_msgSend(PTR__OBJC_CLASS___NSMutableData_0114eba0,PTR_s_dataWithLength__0114b450,
                        lVar8 + -0x2c);
          uVar9 = _objc_retainAutoreleasedReturnValue();
          uVar3 = _objc_retainAutorelease();
          uVar3 = _objc_msgSend(uVar3,PTR_s_mutableBytes_0114b458);
          uStack_88 = 0x10;
          iVar2 = FUN_00032770(1,0,&uStack_120,0x20,lVar6 + 0x10,0xc,0,0,lVar6 + 0x2c,lVar8 + -0x2c,
                               uVar3,auStack_130,&uStack_88);
          uVar3 = 0;
          uStack_118 = 0;
          uStack_120 = 0;
          uStack_108 = 0;
          uStack_110 = 0;
          uStack_c4 = (uint)(iVar2 == 0);
          if (iVar2 == 0) {
            iVar2 = _memcmp(auStack_130,(void *)(lVar6 + 0x1c),0x10);
            uVar3 = 0;
            uStack_d4 = (uint)(iVar2 == 0);
            if (iVar2 == 0) {
              uVar3 = _objc_alloc(PTR__OBJC_CLASS___NSString_0114eb38);
              uVar3 = _objc_msgSend(uVar3,PTR_s_initWithData_encoding__0114b428,uVar9,4);
            }
          }
          _objc_release(uVar9);
        }
        _objc_release(uVar7);
      }
    }
    _objc_release(lVar4);
  }
  _objc_release(param_2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return;
}


