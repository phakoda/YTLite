/* Decompiled from supplied 5.2.2 arm package. VA 0x1cb938. FUN_001cb938 */

undefined1  [16] FUN_001cb938(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  long alStack_120 [8];
  undefined **local_e0;
  undefined **ppuStack_d8;
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_b8;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_011b5a78;
  local_74 = (uint)(DAT_01227cd8 == 0);
  local_88 = &PTR_LAB_011b5a98;
  local_a0 = &PTR_LAB_011b5ab8;
  local_b8 = &PTR_LAB_011b5ad8;
  local_80 = &PTR_LAB_011b59b0;
  local_98 = &PTR_LAB_011b59b0;
  local_b0 = &PTR_LAB_011b59b0;
  local_d0 = &PTR_LAB_011b59b0;
  ppuStack_c8 = &PTR_LAB_011b59b0;
  local_e0 = &PTR_LAB_011b59b0;
  ppuStack_d8 = &PTR_LAB_011b59b0;
  DAT_01227cd8 = 1;
  uStack_8c = (uint)(param_4 == 0);
  if (param_4 != 0) {
    _objc_msgSend(param_4,PTR_s_localizedDescription_0114c618);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001ccdd8(&PTR____CFConstantStringClassReference_011b58d0,uVar2);
    _objc_release(uVar2);
    (**(code **)(*(long *)(param_1 + 0x20) + 0x10))(*(long *)(param_1 + 0x20),0);
    CallSupervisor(0x3633);
    return ZEXT816(0x1f);
  }
  alStack_120[0] = 0;
  _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                PTR_s_JSONObjectWithData_options_error_0114b4a0,param_2,0,alStack_120);
  _objc_retainAutoreleasedReturnValue();
  lVar1 = alStack_120[0];
  _objc_retain(alStack_120[0]);
  uStack_a4 = (uint)(lVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x001cc6b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar3 = (*(code *)(local_a0[uStack_a4] + (int)-(uRam00000000011b5ac8 ^ 0xb9948609)))();
  return auVar3;
}


