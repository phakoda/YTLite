// Decompiled hook evidence for ASDisplayNode. This is not compilable Logos source.

// -[ASDisplayNode copiedComment], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4ce78. FUN_0004ce78 */

void FUN_0004ce78(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004ce78);
  return;
}



// -[ASDisplayNode setCopiedComment:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4ce84. FUN_0004ce84 */

undefined1  [16] FUN_0004ce84(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004ce78,param_3,1);
  CallSupervisor(0x9fe4);
  return ZEXT816(0x1f);
}



// -[ASDisplayNode copiedURL], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4cebc. FUN_0004cebc */

void FUN_0004cebc(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004cebc);
  return;
}



// -[ASDisplayNode setCopiedURL:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4cec8. FUN_0004cec8 */

undefined1  [16] FUN_0004cec8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004cebc,param_3,1);
  CallSupervisor(0xde28);
  return ZEXT816(0x1f);
}



// -[ASDisplayNode setYogaChildren:], original IMP slot 0x012265d8
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
  puVar1 = @selector(controller);
  _objc_msgSend(param_1,@selector(controller));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(DAT_012268e8 == 0);
  if (DAT_012268e8 == 0) {
    DAT_012268e8 = _objc_getClass(local_90[uStack_94] + (int)-(DAT_0117f650 ^ 0x152af54c),
                                  s_ELMNodeController_0116b590);
  }
  lVar2 = DAT_012268e8;
  _objc_retainAutorelease(DAT_012268e8);
  uVar3 = FUN_000e3d24(uVar4,@selector(isKindOfClass:),lVar2);
  _objc_release(uVar4);
  uVar4 = uStack_260;
  uStack_ac = uVar3;
  if (uVar3 != 0) {
    puStack_238 = auStack_320;
    puStack_208 = auStack_2b0;
    puStack_200 = auStack_3e0;
    _objc_msgSend(local_a8[uVar3] + (int)-(uRam000000000117f670 ^ 0xf576a00),local_258,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(owningComponent));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(description));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = FUN_000e3f74(uVar4,@selector(containsString:),
                             @"shorts_action_bar.eml");
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



// -[ASDisplayNode dealloc], original IMP slot 0x012265e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x9c03c. FUN_0009c03c */

void FUN_0009c03c(undefined8 param_1,undefined8 param_2)

{
  _objc_msgSend(DAT_01225f30,@selector(removeObjectForKey:),param_1);
                    /* WARNING: Could not recover jumptable at 0x0009c080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_012265e0)(param_1,param_2);
  return;
}



// -[ASDisplayNode setFrame:], original IMP slot 0x012265e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x9c084. FUN_0009c084 */

void FUN_0009c084(undefined8 param_1)

{
  undefined1 auStack_370 [312];
  undefined1 *puStack_238;
  undefined **local_230;
  undefined **ppuStack_228;
  undefined **local_218;
  undefined **local_208;
  undefined **ppuStack_200;
  undefined **local_1f0;
  undefined **ppuStack_1e8;
  undefined **local_1d8;
  undefined **local_1d0;
  undefined **ppuStack_1c8;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_170;
  undefined **local_160;
  undefined **ppuStack_158;
  undefined **local_148;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_120;
  undefined **ppuStack_118;
  undefined **local_108;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_e8;
  undefined **local_e0;
  undefined **local_d0;
  undefined **local_c0;
  undefined **local_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__objc_msgSend_0117f828;
  local_7c = (uint)(DAT_01226dd4 == 0);
  local_90 = &PTR__objc_msgSend_0117f848;
  local_a0 = &PTR__objc_msgSend_0117f860;
  local_b0 = &PTR__objc_msgSend_0117f878;
  local_c0 = &PTR_LAB_0117f890;
  local_d0 = &PTR_LAB_0117f8a8;
  local_e8 = &PTR_LAB_0117f8c8;
  local_88 = &PTR_LAB_01175340;
  local_e0 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_01175340;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_0117f8f0;
  local_120 = &PTR_LAB_0117f910;
  ppuStack_118 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_0117f930;
  ppuStack_130 = &PTR_LAB_01175340;
  local_148 = &PTR_LAB_0117f948;
  local_160 = &PTR_LAB_0117f968;
  ppuStack_158 = &PTR_LAB_01175340;
  local_170 = &PTR_LAB_0117f980;
  local_180 = &PTR__objc_msgSend_0117f998;
  local_190 = &PTR_LAB_0117f9b0;
  local_1a0 = &PTR_LAB_0117f9c8;
  local_1b8 = &PTR_LAB_0117f9e8;
  ppuStack_1b0 = &PTR_LAB_01175340;
  local_1d0 = &PTR_LAB_01175340;
  ppuStack_1c8 = &PTR_LAB_01175340;
  local_1d8 = &PTR_LAB_0117fa10;
  local_1f0 = &PTR_LAB_0117fa30;
  ppuStack_1e8 = &PTR_LAB_01175340;
  local_208 = &PTR_LAB_0117fa50;
  ppuStack_200 = &PTR_LAB_01175340;
  local_218 = &PTR_LAB_0117fa68;
  local_230 = &PTR_LAB_01175340;
  ppuStack_228 = &PTR_LAB_01175340;
  DAT_01226dd4 = 1;
  puStack_238 = auStack_370;
  (*DAT_012265e8)(param_1);
  uStack_94 = FUN_000e4120(@"commentManager");
                    /* WARNING: Could not recover jumptable at 0x0009cbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_90[uStack_94] + (int)-(DAT_0117f858 ^ 0xbfb82ddb)))();
  return;
}


