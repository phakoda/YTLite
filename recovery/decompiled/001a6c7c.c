/* Decompiled from supplied 5.2.2 arm package. VA 0x1a6c7c. prepareMediaForUse: */

/* Function Stack Size: 0x18 bytes */

void DVNMediaPicker::prepareMediaForUse_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 auStack_250 [2];
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined1 auStack_230 [128];
  undefined8 uStack_1b0;
  undefined8 *puStack_1a8;
  long *plStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 *puStack_170;
  ID IStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined1 *puStack_150;
  undefined *puStack_148;
  undefined8 uStack_140;
  undefined *puStack_138;
  undefined8 uStack_130;
  undefined **local_128;
  undefined **local_120;
  undefined **local_118;
  int iStack_10c;
  undefined **local_108;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011ae908;
  local_7c = (uint)(DAT_01227970 == 0);
  local_90 = &PTR_LAB_011ae928;
  local_88 = &PTR_LAB_011ae4f0;
  local_a8 = &PTR_LAB_011ae948;
  ppuStack_a0 = &PTR_LAB_011ae4f0;
  local_c0 = &PTR_LAB_011ae4f0;
  ppuStack_b8 = &PTR_LAB_011ae4f0;
  local_d0 = &PTR_LAB_011ae978;
  ppuStack_c8 = &PTR_LAB_011ae4f0;
  local_e8 = &PTR_LAB_011ae998;
  ppuStack_e0 = &PTR_LAB_011ae4f0;
  local_f8 = &PTR_LAB_011ae9b0;
  local_108 = &PTR_LAB_011ae9c8;
  local_118 = &PTR_LAB_011ae4f0;
  local_120 = &PTR_LAB_011ae4f0;
  local_128 = &PTR_LAB_011ae4f0;
  DAT_01227970 = 1;
  _objc_retain(param_3);
  puVar1 = PTR_ToastManager_0114ecd0;
  uStack_94 = (uint)(param_3 == 0);
  if (param_3 == 0) {
    _objc_msgSend(&PTR____CFConstantStringClassReference_011ae150,PTR_s_ytl_localized_0114d190);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar4,0);
  }
  else {
    thunk_FUN_001a9e38(local_90[uStack_94] + (int)-(DAT_011ae938 ^ 0x1ad97c43),9,1,1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_firstObject_0114b748);
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(param_3,PTR_s_pathExtension_0114dc70);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_138 = PTR_s_stringWithFormat__0114b378;
    thunk_FUN_001a9e9c(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011ae110,uVar4);
    uStack_158 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puStack_1a8 = (undefined8 *)0x0;
    uStack_1b0 = 0;
    uStack_198 = 0;
    plStack_1a0 = (long *)0x0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_178 = 0;
    uStack_180 = 0;
    ppuStack_240 = &PTR____CFConstantStringClassReference_011ae0d0;
    ppuStack_238 = &PTR____CFConstantStringClassReference_011ae010;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &ppuStack_240,2);
    uStack_140 = _objc_retainAutoreleasedReturnValue();
    puStack_148 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar6 = _objc_msgSend(uStack_140,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1b0,
                          auStack_230,0x10);
    puVar2 = PTR_s_removeItemAtPath_error__0114c378;
    puVar1 = PTR_s_stringByAppendingPathComponent__0114b6e8;
    uStack_ac = (uint)(lVar6 == 0);
    uStack_160 = uVar4;
    if (lVar6 != 0) {
      uStack_d4 = (uint)(*plStack_1a0 == *plStack_1a0);
      puStack_170 = auStack_250;
      IStack_168 = param_3;
      puStack_150 = auStack_230;
      if (*plStack_1a0 != *plStack_1a0) {
        _objc_enumerationMutation(uStack_140);
      }
      thunk_FUN_001a9b34(PTR__OBJC_CLASS___NSString_0114eb38,puStack_138,
                         &PTR____CFConstantStringClassReference_011ae110,*puStack_1a8);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_130,puVar1,uVar4);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
      FUN_001a9b94(uVar5,puVar2,uVar7,0);
      _objc_release(uVar7);
      uStack_ec = (uint)(lVar6 == 1);
                    /* WARNING: Could not recover jumptable at 0x001a7618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_e8[uStack_ec] + (int)-(uRam00000000011ae9a8 ^ 0x18f49540)))();
      return;
    }
    _objc_release(uStack_140);
    puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
    _objc_msgSend(uStack_130,puVar1,uStack_158);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar2,PTR_s_fileURLWithPath__0114c430,uVar4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    auStack_250[0] = 0;
    iVar3 = FUN_001a9c5c(uVar5,PTR_s_copyItemAtURL_toURL_error__0114dc68,param_3,uVar7,auStack_250);
    uVar4 = auStack_250[0];
    _objc_retain(auStack_250[0]);
    puVar2 = PTR_ToastManager_0114ecd0;
    iStack_10c = iVar3;
    if (iVar3 == 0) {
      _objc_msgSend(uVar4,PTR_s_localizedDescription_0114c618);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar8,0);
      _objc_release(uVar8);
      thunk_FUN_001a9cb0(&PTR____CFConstantStringClassReference_011ae090,uVar4,param_3);
    }
    else {
      _objc_msgSend(&PTR____CFConstantStringClassReference_011ae050,PTR_s_ytl_localized_0114d190);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar8,1);
      _objc_release(uVar8);
      FUN_001a9d30(uVar5,PTR_s_removeItemAtURL_error__0114dc60,param_3,0);
    }
    _NSTemporaryDirectory();
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_bundleIdentifier_0114b110);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001a9da4(puVar2,puStack_138,&PTR____CFConstantStringClassReference_011adfd0,uVar10);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,puVar1,uVar11);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    FUN_001a9e04(uVar5,PTR_s_removeItemAtPath_error__0114c378,uVar12,0);
    _objc_release(uVar12);
    _objc_release(uVar4);
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(uStack_158);
    _objc_release(uStack_160);
    uVar4 = uStack_130;
  }
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0x33a2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


