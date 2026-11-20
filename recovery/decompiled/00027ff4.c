/* Decompiled from supplied 5.2.2 arm package. VA 0x27ff4. FUN_00027ff4 */

void FUN_00027ff4(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_80;
  undefined **ppuStack_78;
  undefined8 uStack_70;
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  puVar2 = PTR__OBJC_CLASS___NSDictionary_0114eb40;
  puVar1 = PTR_s_dictionaryWithObjects_forKeys_co_0114b420;
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011596a0;
  local_54 = (uint)(DAT_01225df8 == 0);
  local_60 = &PTR_LAB_01158940;
  DAT_01225df8 = 1;
  uStack_a0 = *(undefined8 *)PTR__kSecClass_01060d38;
  uStack_98 = *(undefined8 *)PTR__kSecAttrService_01060d30;
  uStack_80 = *(undefined8 *)PTR__kSecClassGenericPassword_01060d40;
  ppuStack_78 = &PTR____CFConstantStringClassReference_01157420;
  uStack_90 = *(undefined8 *)PTR__kSecAttrAccount_01060d00;
  uStack_70 = param_1;
  _objc_retain(param_1);
  _objc_msgSend(puVar2,puVar1,&uStack_80,&uStack_a0,3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_1);
  _SecItemDelete(uVar3);
  _objc_release(uVar3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


