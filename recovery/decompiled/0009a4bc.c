/* Decompiled from supplied 5.2.2 arm package. VA 0x9a4bc. FUN_0009a4bc */

void FUN_0009a4bc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 auStack_490 [48];
  undefined1 auStack_460 [128];
  undefined1 auStack_3e0 [64];
  undefined1 auStack_3a0 [128];
  undefined1 auStack_320 [112];
  undefined1 auStack_2b0 [64];
  undefined1 *puStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined1 *puStack_250;
  undefined1 *puStack_238;
  undefined1 *puStack_210;
  undefined1 *puStack_208;
  undefined1 *puStack_200;
  undefined **local_1f8;
  undefined **ppuStack_1f0;
  undefined **local_1e0;
  undefined **local_1d0;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b0;
  undefined **local_1a0;
  undefined **local_190;
  undefined **ppuStack_188;
  undefined **local_178;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **ppuStack_150;
  undefined **local_140;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_120;
  undefined **local_110;
  undefined **local_108;
  undefined **ppuStack_100;
  undefined **local_f0;
  undefined **ppuStack_e8;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__objc_msgSend_0117f620;
  local_7c = (uint)(DAT_01226dcc == 0);
  local_a8 = &PTR__objc_msgSend_0117f660;
  local_90 = &PTR_LAB_0117f640;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_01175340;
  local_c0 = &PTR_LAB_0117f680;
  ppuStack_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR_FUN_0117f6a0;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_f0 = &PTR__objc_msgSend_0117f6c0;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_01175340;
  ppuStack_100 = &PTR_LAB_01175340;
  local_110 = &PTR_LAB_0117f6e8;
  local_120 = &PTR__objc_msgSend_0117f700;
  local_138 = &PTR_LAB_01175340;
  ppuStack_130 = &PTR_LAB_01175340;
  local_140 = &PTR_LAB_0117f728;
  local_158 = &PTR__objc_msgSend_0117f748;
  ppuStack_150 = &PTR_LAB_01175340;
  local_170 = &PTR_LAB_01175340;
  ppuStack_168 = &PTR_LAB_01175340;
  local_178 = &PTR_LAB_0117f770;
  local_190 = &PTR_LAB_0117f790;
  ppuStack_188 = &PTR_LAB_01175340;
  local_1a0 = &PTR_LAB_0117f7a8;
  local_1b0 = &PTR_LAB_0117f7c0;
  local_1c8 = &PTR_LAB_01175340;
  ppuStack_1c0 = &PTR_LAB_01175340;
  local_1d0 = &PTR_LAB_0117f7e8;
  local_1e0 = &PTR_LAB_0117f800;
  local_1f8 = &PTR_LAB_01175340;
  ppuStack_1f0 = &PTR_LAB_01175340;
  DAT_01226dcc = 1;
  puStack_250 = auStack_3a0;
  puStack_210 = auStack_460;
  puStack_270 = auStack_490;
  local_268 = param_2;
  uStack_260 = param_3;
  local_258 = param_1;
  _objc_retain(param_3);
  puVar1 = PTR_s_controller_0114c8f0;
  _objc_msgSend(param_1,PTR_s_controller_0114c8f0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(DAT_012268e8 == 0);
  if (DAT_012268e8 == 0) {
    DAT_012268e8 = _objc_getClass(local_90[uStack_94] + (int)-(DAT_0117f650 ^ 0x152af54c),
                                  s_ELMNodeController_0116b590);
  }
  lVar2 = DAT_012268e8;
  _objc_retainAutorelease(DAT_012268e8);
  uVar3 = FUN_000e3d24(uVar4,PTR_s_isKindOfClass__0114ad70,lVar2);
  _objc_release(uVar4);
  uVar4 = uStack_260;
  uStack_ac = uVar3;
  if (uVar3 != 0) {
    puStack_238 = auStack_320;
    puStack_208 = auStack_2b0;
    puStack_200 = auStack_3e0;
    _objc_msgSend(local_a8[uVar3] + (int)-(uRam000000000117f670 ^ 0xf576a00),local_258,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_owningComponent_0114ca90);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_description_0114af00);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = FUN_000e3f74(uVar4,PTR_s_containsString__0114af08,
                             &PTR____CFConstantStringClassReference_0116b790);
                    /* WARNING: Could not recover jumptable at 0x0009b82c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_c0[uStack_c4] + (int)-(DAT_0117f690 ^ 0xe1c7e10d)))();
    return;
  }
  (*DAT_012265d8)(local_258,local_268,uStack_260);
  _objc_release(uVar4);
  CallSupervisor(0x5314);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


