/* Decompiled from supplied 5.2.2 arm package. VA 0x1f8b00. FUN_001f8b00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001f8b00(long param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 auStack_e0 [2];
  undefined8 auStack_d0 [2];
  undefined8 auStack_c0 [2];
  undefined8 auStack_b0 [3];
  undefined **local_98;
  undefined **ppuStack_90;
  uint uStack_84;
  undefined **local_80;
  undefined **ppuStack_78;
  uint uStack_6c;
  undefined **local_68;
  undefined **ppuStack_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011c1ae8;
  local_54 = (uint)(DAT_0122802c == 0);
  local_68 = &PTR_LAB_011c1b08;
  ppuStack_60 = &PTR_LAB_011c1600;
  local_80 = &PTR_LAB_011c1b28;
  ppuStack_78 = &PTR_LAB_011c1600;
  local_98 = &PTR_LAB_011c1600;
  ppuStack_90 = &PTR_LAB_011c1600;
  DAT_0122802c = 1;
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x18),PTR_s_hide_0114d0a0);
  *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28) = 0;
  puVar2 = PTR__OBJC_CLASS___NSError_0114ef98;
  iVar1 = *(int *)(param_1 + 0x38);
  uStack_6c = (uint)(iVar1 == _RETURN_CODE_SUCCESS);
  if (iVar1 == _RETURN_CODE_SUCCESS) {
    (**(code **)(*(long *)(param_1 + 0x30) + 0x10))
              (*(long *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0x28),0);
  }
  else {
    uStack_84 = (uint)(iVar1 == __RETURN_CODE_CANCEL);
    if (iVar1 == __RETURN_CODE_CANCEL) {
      auStack_c0[0] = *(undefined8 *)PTR__NSLocalizedDescriptionKey_01060380;
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_011bea20,0,0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      auStack_b0[0] = uVar6;
      _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                    PTR_s_dictionaryWithObjects_forKeys_co_0114b420,auStack_b0,auStack_c0,1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_errorWithDomain_code_userInfo__0114df58,
                    &PTR____CFConstantStringClassReference_011be9e0,0,uVar4);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
      _objc_release(uVar6);
      _objc_release(uVar3);
      (**(code **)(*(long *)(param_1 + 0x30) + 0x10))(*(long *)(param_1 + 0x30),0,uVar5);
    }
    else {
      uVar6 = *(undefined8 *)(param_1 + 0x20);
      _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_getLastCommandOutput_0114e2a8);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_getCleanLog__0114e2b0,uVar3);
      _objc_release(uVar3);
      puVar2 = PTR__OBJC_CLASS___NSError_0114ef98;
      auStack_e0[0] = *(undefined8 *)PTR__NSLocalizedDescriptionKey_01060380;
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_011be9a0,0,0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      auStack_d0[0] = uVar6;
      _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                    PTR_s_dictionaryWithObjects_forKeys_co_0114b420,auStack_d0,auStack_e0,1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_errorWithDomain_code_userInfo__0114df58,
                    &PTR____CFConstantStringClassReference_011be9e0,0,uVar4);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
      _objc_release(uVar6);
      _objc_release(uVar3);
      (**(code **)(*(long *)(param_1 + 0x30) + 0x10))(*(long *)(param_1 + 0x30),0,uVar5);
    }
    _objc_release(uVar5);
  }
  CallSupervisor(0xb1dd);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


