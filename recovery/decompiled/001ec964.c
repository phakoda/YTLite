/* Decompiled from supplied 5.2.2 arm package. VA 0x1ec964. FUN_001ec964 */

undefined1  [16] FUN_001ec964(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  long alStack_f0 [2];
  long alStack_e0 [2];
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_c0;
  undefined **ppuStack_b8;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  uint uStack_74;
  undefined **local_70;
  undefined **ppuStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011bd108;
  local_5c = (uint)(DAT_01227eb8 == 0);
  local_80 = &PTR_LAB_011bd140;
  local_98 = &PTR_LAB_011bd160;
  local_a8 = &PTR_LAB_011bd178;
  local_70 = &PTR_LAB_011bd128;
  ppuStack_68 = &PTR_LAB_011bce10;
  local_90 = &PTR_LAB_011bce10;
  local_c0 = &PTR_LAB_011bce10;
  ppuStack_b8 = &PTR_LAB_011bce10;
  local_d0 = &PTR_LAB_011bce10;
  ppuStack_c8 = &PTR_LAB_011bce10;
  DAT_01227eb8 = 1;
  _objc_retain(param_2);
  uStack_74 = (uint)(param_2 == 0);
  if (param_2 == 0) {
    _NSLog(local_70[uStack_74] + (int)-(DAT_011bd138 ^ 0xa428383b),
           &PTR____CFConstantStringClassReference_011bcb90);
    (**(code **)(*(long *)(param_1 + 0x20) + 0x10))(*(long *)(param_1 + 0x20),0);
  }
  else {
    alStack_e0[0] = 0;
    _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithContentsOfURL_options_er_0114e148,
                  param_2,0,alStack_e0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    lVar1 = alStack_e0[0];
    _objc_retain(alStack_e0[0]);
    uStack_84 = (uint)(lVar1 == 0);
    if (lVar1 == 0) {
      alStack_f0[0] = 0;
      _objc_msgSend(PTR__OBJC_CLASS___NSPropertyListSerialization_0114efc8,
                    PTR_s_propertyListWithData_options_for_0114e150,uVar2,0,0,alStack_f0);
      _objc_retainAutoreleasedReturnValue();
      lVar1 = alStack_f0[0];
      _objc_retain(alStack_f0[0]);
      uStack_9c = (uint)(lVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x001ed308. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      auVar3 = (*(code *)(local_98[uStack_9c] + (int)-(uRam00000000011bd170 ^ 0xea3018e7)))();
      return auVar3;
    }
    thunk_FUN_001ef164(local_80[uStack_84] + (int)-(uRam00000000011bd150 ^ 0x42e2fb4e),
                       &PTR____CFConstantStringClassReference_011bcc10,lVar1);
    (**(code **)(*(long *)(param_1 + 0x20) + 0x10))(*(long *)(param_1 + 0x20),0);
    _objc_release(uVar2);
    _objc_release(lVar1);
  }
  _objc_release(param_2);
  CallSupervisor(0x474);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


