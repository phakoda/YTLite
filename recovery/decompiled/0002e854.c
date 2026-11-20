/* Decompiled from supplied 5.2.2 arm package. VA 0x2e854. FUN_0002e854 */

undefined8 FUN_0002e854(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auStack_2b0 [16];
  undefined1 auStack_2a0 [16];
  undefined1 auStack_290 [16];
  undefined1 auStack_280 [128];
  undefined8 uStack_200;
  undefined8 *puStack_1f8;
  long *plStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined1 *puStack_1b8;
  undefined1 *puStack_1b0;
  undefined1 *puStack_1a8;
  undefined *puStack_1a0;
  undefined8 uStack_198;
  long lStack_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined1 *puStack_170;
  undefined *puStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined **local_150;
  undefined **local_148;
  undefined **local_140;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_01159e90;
  local_8c = (uint)(DAT_01225e2c == 0);
  local_a0 = &PTR_LAB_01159eb0;
  local_b0 = &PTR_LAB_01159ec8;
  local_98 = &PTR_LAB_01158940;
  local_c8 = &PTR_LAB_01158940;
  ppuStack_c0 = &PTR_LAB_01158940;
  local_d0 = &PTR_LAB_01159ef0;
  local_e8 = &PTR_LAB_01159f10;
  ppuStack_e0 = &PTR_LAB_01158940;
  local_100 = &PTR_LAB_01159f30;
  ppuStack_f8 = &PTR_LAB_01158940;
  local_110 = &PTR_LAB_01159f48;
  local_120 = &PTR_LAB_01159f60;
  local_130 = &PTR_LAB_01159f78;
  local_140 = &PTR_LAB_01158940;
  local_148 = &PTR_LAB_01158940;
  local_150 = &PTR_LAB_01158940;
  DAT_01225e2c = 1;
  local_180 = param_2;
  local_178 = param_1;
  _objc_retain(param_1);
  _objc_retain(param_2);
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___NSData_0114eb98);
  puVar1 = PTR_s_initWithBase64EncodedString_opti_0114b430;
  lStack_190 = _objc_msgSend(uVar2,PTR_s_initWithBase64EncodedString_opti_0114b430,param_1,0);
  uStack_a4 = (uint)(lStack_190 == 0);
  if (lStack_190 == 0) {
    _objc_release(local_a0[uStack_a4] + (int)-(DAT_01159ec0 ^ 0xdabc91ae),0);
    _objc_release(param_3);
    _objc_release(param_2);
    _objc_release(param_1);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    return 0;
  }
  puStack_1a0 = puVar1;
  puStack_1b8 = auStack_2a0;
  puStack_1b0 = auStack_290;
  puStack_1a8 = auStack_2b0;
  uStack_188 = param_3;
  _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,
                s______BEGIN_PUBLIC_KEY______MIIBI_01158510);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_string_0114b508);
  uStack_160 = _objc_retainAutoreleasedReturnValue();
  puStack_1f8 = (undefined8 *)0x0;
  uStack_200 = 0;
  uStack_1e8 = 0;
  plStack_1f0 = (long *)0x0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_198 = uVar2;
  _objc_msgSend(uVar2,PTR_s_componentsSeparatedByString__0114b510,
                &PTR____CFConstantStringClassReference_01158780);
  uStack_158 = _objc_retainAutoreleasedReturnValue();
  puStack_168 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lVar3 = _objc_msgSend(uStack_158,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_200,
                        auStack_280,0x10);
  puVar1 = PTR_s_hasPrefix__0114aea0;
  uStack_b4 = (uint)(lVar3 == 0);
  if (lVar3 == 0) {
    _objc_release(uStack_158);
    uVar2 = _objc_alloc(PTR__OBJC_CLASS___NSData_0114eb98);
    lVar3 = _objc_msgSend(uVar2,puStack_1a0,uStack_160,0);
    uStack_124 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x00030788. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)(local_120[uStack_124] + (int)-(uRam0000000001159f70 ^ 0xb045fd62)))();
    return uVar2;
  }
  uStack_d4 = (uint)(*plStack_1f0 == *plStack_1f0);
  puStack_170 = auStack_280;
  if (*plStack_1f0 != *plStack_1f0) {
    _objc_enumerationMutation(uStack_158);
  }
  uStack_ec = FUN_000344f0(*puStack_1f8,puVar1,&PTR____CFConstantStringClassReference_01158740);
                    /* WARNING: Could not recover jumptable at 0x00030604. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(local_e8[uStack_ec] + (int)-(uRam0000000001159f20 ^ 0x837bde41)))();
  return uVar2;
}


