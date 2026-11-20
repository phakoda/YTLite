/* Decompiled from supplied 5.2.2 arm package. VA 0x28954. FUN_00028954 */

void FUN_00028954(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b0;
  undefined **ppuStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined **local_78;
  uint uStack_6c;
  undefined **local_68;
  undefined **ppuStack_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_01159740;
  local_54 = (uint)(DAT_01225e08 == 0);
  local_68 = &PTR_LAB_01159760;
  ppuStack_60 = &PTR_LAB_01158940;
  local_78 = &PTR_LAB_01158940;
  DAT_01225e08 = 1;
  _objc_retain(param_1);
  thunk_FUN_00028ec0(param_2,param_3);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dataUsingEncoding__0114b460;
  uStack_6c = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    _objc_retain(param_1);
    _objc_msgSend(lVar2,puVar1,4);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uStack_e0 = *(undefined8 *)PTR__kSecClass_01060d38;
    uStack_b0 = *(undefined8 *)PTR__kSecClassGenericPassword_01060d40;
    uStack_d8 = *(undefined8 *)PTR__kSecAttrService_01060d30;
    ppuStack_a8 = &PTR____CFConstantStringClassReference_011575d0;
    uStack_d0 = *(undefined8 *)PTR__kSecAttrAccount_01060d00;
    uStack_c8 = *(undefined8 *)PTR__kSecValueData_01060da8;
    uStack_c0 = *(undefined8 *)PTR__kSecAttrAccessible_01060cf0;
    uStack_90 = *(undefined8 *)PTR__kSecAttrAccessibleAfterFirstUnlock_01060cf8;
    uStack_a0 = param_1;
    uStack_98 = uVar3;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&uStack_b0,&uStack_e0,5);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_1);
    _SecItemDelete(uVar4);
    _SecItemAdd(uVar4,0);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  _objc_release(lVar2);
  _objc_release(param_1);
  CallSupervisor(0xea32);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_48) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


