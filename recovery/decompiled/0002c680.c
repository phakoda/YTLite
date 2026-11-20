/* Decompiled from supplied 5.2.2 arm package. VA 0x2c680. FUN_0002c680 */

undefined8
FUN_0002c680(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  undefined *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined ***pppuVar7;
  undefined8 auStack_2b0 [2];
  undefined8 auStack_2a0 [2];
  undefined8 auStack_290 [2];
  undefined1 auStack_280 [128];
  undefined8 uStack_200;
  undefined8 *puStack_1f8;
  long *plStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 *puStack_1b8;
  undefined8 *puStack_1b0;
  undefined8 *puStack_1a8;
  undefined8 uStack_1a0;
  undefined *puStack_198;
  long lStack_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined1 *puStack_160;
  undefined *puStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined **local_140;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01159d78;
  local_7c = (uint)(DAT_01225e28 == 0);
  local_90 = &PTR_LAB_01159d98;
  local_a0 = &PTR_LAB_01159db0;
  local_c0 = &PTR_LAB_01159dd8;
  local_88 = &PTR_LAB_01158940;
  local_b8 = &PTR_LAB_01158940;
  ppuStack_b0 = &PTR_LAB_01158940;
  local_d8 = &PTR_LAB_01159df8;
  ppuStack_d0 = &PTR_LAB_01158940;
  local_f0 = &PTR_LAB_01159e18;
  ppuStack_e8 = &PTR_LAB_01158940;
  local_100 = &PTR_FUN_01159e30;
  local_110 = &PTR_LAB_01159e48;
  local_120 = &PTR_LAB_01159e60;
  local_130 = &PTR_LAB_01158940;
  local_138 = &PTR_LAB_01158940;
  local_140 = &PTR_LAB_01158940;
  DAT_01225e28 = 1;
  local_188 = param_4;
  local_180 = param_5;
  local_178 = param_3;
  local_170 = param_2;
  local_168 = param_1;
  _objc_retain(param_1);
  _objc_retain(param_2);
  _objc_retain(param_3);
  _objc_retain(param_5);
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___NSData_0114eb98);
  puVar1 = PTR_s_initWithBase64EncodedString_opti_0114b430;
  lVar5 = _objc_msgSend(uVar4,PTR_s_initWithBase64EncodedString_opti_0114b430,param_1,0);
  uStack_94 = (uint)(lVar5 == 0);
  pppuVar7 = (undefined ***)(local_90[uStack_94] + (int)-(DAT_01159da8 ^ 0xeb0df0c1));
  if (lVar5 != 0) {
    puStack_198 = puVar1;
    puStack_1b8 = auStack_2a0;
    puStack_1b0 = auStack_290;
    puStack_1a8 = auStack_2b0;
    lStack_190 = lVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,
                  s______BEGIN_PUBLIC_KEY______MIIBI_01158080);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_string_0114b508);
    uStack_150 = _objc_retainAutoreleasedReturnValue();
    puStack_1f8 = (undefined8 *)0x0;
    uStack_200 = 0;
    uStack_1e8 = 0;
    plStack_1f0 = (long *)0x0;
    uStack_1d8 = 0;
    uStack_1e0 = 0;
    uStack_1c8 = 0;
    uStack_1d0 = 0;
    uStack_1a0 = uVar4;
    _objc_msgSend(uVar4,PTR_s_componentsSeparatedByString__0114b510,
                  &PTR____CFConstantStringClassReference_011582f0);
    uStack_148 = _objc_retainAutoreleasedReturnValue();
    puStack_158 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar5 = _objc_msgSend(uStack_148,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_200,
                          auStack_280,0x10);
    puVar1 = PTR_s_hasPrefix__0114aea0;
    uStack_a4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      uStack_c4 = (uint)(*plStack_1f0 == *plStack_1f0);
      puStack_160 = auStack_280;
      if (*plStack_1f0 != *plStack_1f0) {
        _objc_enumerationMutation(uStack_148);
      }
      uStack_dc = FUN_000341a8(*puStack_1f8,puVar1,&PTR____CFConstantStringClassReference_01158270);
                    /* WARNING: Could not recover jumptable at 0x0002e4e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)(local_d8[uStack_dc] + (int)-(uRam0000000001159e08 ^ 0x344b979d)))();
      return uVar4;
    }
    _objc_release(uStack_148);
    uVar6 = _objc_alloc(PTR__OBJC_CLASS___NSData_0114eb98);
    uVar4 = uStack_150;
    lVar5 = _objc_msgSend(uVar6,puStack_198,uStack_150,0);
    _objc_release(uVar4);
    _objc_release(uStack_1a0);
    param_2 = local_170;
    param_3 = local_178;
    param_5 = local_180;
    puVar2 = puStack_1b8;
    uStack_114 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      uVar6 = *(undefined8 *)PTR__kSecAttrKeyTypeRSA_01060d20;
      uVar4 = *(undefined8 *)PTR__kSecAttrKeyClass_01060d08;
      *puStack_1b8 = *(undefined8 *)PTR__kSecAttrKeyType_01060d18;
      puVar2[1] = uVar4;
      puVar3 = puStack_1b0;
      uVar4 = *(undefined8 *)PTR__kSecAttrKeyClassPublic_01060d10;
      *puStack_1b0 = uVar6;
      puVar3[1] = uVar4;
      _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                    PTR_s_dictionaryWithObjects_forKeys_co_0114b420,puVar3,puVar2,2);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = puStack_1a8;
      *puStack_1a8 = 0;
      lVar5 = _SecKeyCreateWithData(lVar5,uVar4,puVar2);
      uStack_124 = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x0002e704. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)(local_120[uStack_124] + (int)-(uRam0000000001159e70 ^ 0x6801a2ed)))();
      return uVar4;
    }
    _objc_release(0);
    pppuVar7 = &local_90;
    lVar5 = lStack_190;
    param_1 = local_168;
  }
  _objc_release(pppuVar7,lVar5);
  _objc_release(param_5);
  _objc_release(param_3);
  _objc_release(param_2);
  _objc_release(param_1);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return 0;
}


