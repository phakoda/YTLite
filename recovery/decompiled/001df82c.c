/* Decompiled from supplied 5.2.2 arm package. VA 0x1df82c. FUN_001df82c */

void FUN_001df82c(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined1 auStack_2b0 [192];
  long alStack_1f0 [10];
  undefined1 *puStack_1a0;
  undefined **local_178;
  undefined **ppuStack_170;
  undefined **local_168;
  undefined **ppuStack_160;
  undefined **local_150;
  undefined **local_140;
  undefined **ppuStack_138;
  undefined **local_128;
  undefined **local_118;
  undefined **ppuStack_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_f0;
  undefined **local_e0;
  undefined **local_d0;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011b9a70;
  local_7c = (uint)(DAT_01227e18 == 0);
  local_90 = &PTR_LAB_011b9a90;
  local_a8 = &PTR_LAB_011b9ab0;
  local_88 = &PTR_LAB_011b97a0;
  local_a0 = &PTR_LAB_011b97a0;
  local_c0 = &PTR_LAB_011b9ad0;
  ppuStack_b8 = &PTR_LAB_011b97a0;
  local_d0 = &PTR_LAB_011b9ae8;
  local_e0 = &PTR_LAB_011b9b00;
  local_f0 = &PTR_LAB_011b97a0;
  local_100 = &PTR_LAB_011b9b28;
  ppuStack_f8 = &PTR_LAB_011b97a0;
  local_118 = &PTR_LAB_011b9b48;
  ppuStack_110 = &PTR_LAB_011b97a0;
  local_128 = &PTR_LAB_011b9b60;
  local_140 = &PTR_LAB_011b9b80;
  ppuStack_138 = &PTR_LAB_011b97a0;
  local_150 = &PTR_LAB_011b9b98;
  local_168 = &PTR_LAB_011b97a0;
  ppuStack_160 = &PTR_LAB_011b97a0;
  local_178 = &PTR_LAB_011b97a0;
  ppuStack_170 = &PTR_LAB_011b97a0;
  DAT_01227e18 = 1;
  puStack_1a0 = auStack_2b0;
  _objc_retain(param_2);
  _objc_retain(param_3);
  _objc_retain(param_4);
  uStack_94 = (uint)(param_4 == 0);
  if (param_4 == 0) {
    alStack_1f0[0] = 0;
    _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                  PTR_s_JSONObjectWithData_options_error_0114b4a0,param_2,0,alStack_1f0);
    _objc_retainAutoreleasedReturnValue();
    lVar1 = alStack_1f0[0];
    _objc_retain(alStack_1f0[0]);
    uStack_ac = (uint)(lVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x001dfb24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_a8[uStack_ac] + (int)-(DAT_011b9ac0 ^ 0x6c73e37b)))();
    return;
  }
  (**(code **)(*(long *)(param_1 + 0x20) + 0x10))(*(long *)(param_1 + 0x20),0,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(param_2);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


