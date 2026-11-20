/* Decompiled from supplied 5.2.2 arm package. VA 0x27078. FUN_00027078 */

void FUN_00027078(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 auStack_120 [2];
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e0;
  undefined **ppuStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_01159508;
  local_74 = (uint)(DAT_01225de8 == 0);
  local_88 = &PTR_LAB_01159528;
  ppuStack_80 = &PTR_LAB_01158940;
  local_a0 = &PTR_LAB_01159548;
  ppuStack_98 = &PTR_LAB_01158940;
  local_b0 = &PTR_LAB_01158940;
  DAT_01225de8 = 1;
  _objc_retain(param_1);
  _objc_retain(param_2);
  uStack_110 = *(undefined8 *)PTR__kSecClass_01060d38;
  uStack_e0 = *(undefined8 *)PTR__kSecClassGenericPassword_01060d40;
  uStack_108 = *(undefined8 *)PTR__kSecAttrService_01060d30;
  ppuStack_d8 = &PTR____CFConstantStringClassReference_011572d0;
  uStack_100 = *(undefined8 *)PTR__kSecAttrAccount_01060d00;
  uStack_f8 = *(undefined8 *)PTR__kSecReturnData_01060d98;
  uStack_d0 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithBool__0114b418,1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uStack_f0 = *(undefined8 *)PTR__kSecMatchLimit_01060d68;
  uStack_c0 = *(undefined8 *)PTR__kSecMatchLimitOne_01060d78;
  uStack_c8 = uVar2;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&uStack_e0,&uStack_110,5);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  auStack_120[0] = 0;
  iVar1 = _SecItemCopyMatching(uVar3,auStack_120);
  uStack_8c = (uint)(iVar1 == 0);
  if (iVar1 == 0) {
    uVar4 = _objc_alloc(PTR__OBJC_CLASS___NSString_0114eb38);
    uVar2 = auStack_120[0];
    lVar5 = _objc_msgSend(uVar4,PTR_s_initWithData_encoding__0114b428,auStack_120[0],4);
    _objc_release(uVar2);
  }
  else {
    lVar5 = 0;
  }
  _objc_release(uVar3);
  uStack_a4 = (uint)(lVar5 == 0);
  if (lVar5 == 0) {
    uVar2 = 0;
  }
  else {
    thunk_FUN_00027464(local_a0[uStack_a4] + (int)-(uRam0000000001159558 ^ 0xf667f6f4),lVar5,param_2
                      );
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(lVar5);
  _objc_release(param_2);
  _objc_release(param_1);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


