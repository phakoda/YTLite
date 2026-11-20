/* Decompiled from supplied 5.2.2 arm package. VA 0xbb0e0. FUN_000bb0e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000bb0e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 auStack_2a0 [128];
  undefined8 uStack_220;
  undefined8 *puStack_218;
  long *plStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined *puStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined1 *puStack_1a0;
  undefined *puStack_198;
  undefined8 *puStack_190;
  undefined *puStack_188;
  undefined8 uStack_180;
  undefined *puStack_178;
  undefined *puStack_170;
  undefined **local_168;
  undefined **ppuStack_160;
  undefined **local_150;
  undefined **local_140;
  undefined **ppuStack_138;
  undefined **local_128;
  undefined **local_118;
  undefined **ppuStack_110;
  uint uStack_104;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **local_e0;
  undefined **ppuStack_d8;
  uint uStack_cc;
  undefined **local_c8;
  int iStack_bc;
  undefined **local_b8;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  int iStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011822d0;
  local_7c = (uint)(DAT_01226f14 == 0);
  local_90 = &PTR_LAB_011822f0;
  local_a0 = &PTR_LAB_01182308;
  local_b8 = &PTR_LAB_01182328;
  local_c8 = &PTR_LAB_01182340;
  local_88 = &PTR_LAB_01175340;
  local_b0 = &PTR_LAB_01175340;
  local_e0 = &PTR_LAB_01175340;
  ppuStack_d8 = &PTR_LAB_01175340;
  local_e8 = &PTR_LAB_01182368;
  local_100 = &PTR_LAB_01182388;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_011823a8;
  ppuStack_110 = &PTR_LAB_01175340;
  local_128 = &PTR_LAB_011823c0;
  local_140 = &PTR_LAB_011823e0;
  ppuStack_138 = &PTR_LAB_01175340;
  local_150 = &PTR_LAB_011823f8;
  local_168 = &PTR_LAB_01175340;
  ppuStack_160 = &PTR_LAB_01175340;
  if (DAT_01226f14 == 0) {
    s_noLinkTracking_0117152f[0] = DAT_01171520 ^ 0x75;
    s_noLinkTracking_0117152f[1] = bRam0000000001171521 ^ 0x12;
    s_noLinkTracking_0117152f[2] = bRam0000000001171522 ^ 0x77;
    s_noLinkTracking_0117152f[3] = bRam0000000001171523 ^ 0x43;
    s_noLinkTracking_0117152f[4] = bRam0000000001171524 ^ 0xb5;
    s_noLinkTracking_0117152f[5] = cRam0000000001171525;
    s_noLinkTracking_0117152f[6] = bRam0000000001171526 ^ 0x9b;
    s_noLinkTracking_0117152f[7] = bRam0000000001171527 ^ 0xa1;
    s_noLinkTracking_0117152f[8] = bRam0000000001171528 ^ 0xd3;
    s_noLinkTracking_0117152f[9] = bRam0000000001171529 ^ 0x53;
    s_noLinkTracking_0117152f[10] = bRam000000000117152a ^ 0x67;
    s_noLinkTracking_0117152f[0xb] = bRam000000000117152b ^ 5;
    s_noLinkTracking_0117152f[0xc] = bRam000000000117152c ^ 0xc1;
    s_noLinkTracking_0117152f[0xd] = bRam000000000117152d ^ 0xaa;
    s_noLinkTracking_0117152f[0xe] = bRam000000000117152e ^ 0x67;
    s__redirect_011714fe[0] = DAT_011714f4 ^ 0x6a;
    s__redirect_011714fe[1] = DAT_011714f5 ^ 0x70;
    s__redirect_011714fe[2] = DAT_011714f6 ^ 0xc4;
    s__redirect_011714fe[3] = DAT_011714f7 ^ 0x91;
    s__redirect_011714fe[4] = DAT_011714f8 ^ 0x83;
    s__redirect_011714fe[5] = DAT_011714f9 ^ 0x90;
    s__redirect_011714fe[6] = DAT_011714fa ^ 1;
    s__redirect_011714fe[7] = DAT_011714fb ^ 0x1c;
    s__redirect_011714fe[8] = DAT_011714fc ^ 0x35;
    s__redirect_011714fe[9] = DAT_011714fd ^ 0x86;
    s_youtube_com_01171514[0] = DAT_01171508 ^ 0xb5;
    s_youtube_com_01171514[1] = DAT_01171509 ^ 0x96;
    s_youtube_com_01171514[2] = DAT_0117150a ^ 0x2f;
    s_youtube_com_01171514[3] = DAT_0117150b ^ 0x3e;
    s_youtube_com_01171514[4] = DAT_0117150c ^ 0x7b;
    s_youtube_com_01171514[5] = DAT_0117150d ^ 0x9f;
    s_youtube_com_01171514[6] = DAT_0117150e ^ 0x44;
    s_youtube_com_01171514[7] = DAT_0117150f ^ 0x4c;
    s_youtube_com_01171514[8] = DAT_01171510 ^ 0x20;
    s_youtube_com_01171514[9] = DAT_01171511 ^ 0x4c;
    s_youtube_com_01171514[10] = DAT_01171512 ^ 0x48;
    s_youtube_com_01171514[0xb] = DAT_01171513 ^ 0x12;
    s_q_011714f2[0] = DAT_011714f0 ^ 0x9e;
    s_q_011714f2[1] = DAT_011714f1 ^ 0x6d;
  }
  DAT_01226f14 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  iStack_94 = FUN_000eb158(&PTR____CFConstantStringClassReference_01171620);
  if (iStack_94 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSURLComponents_0114edc8,
                  PTR_s_componentsWithURL_resolvingAgain_0114cdd8,param_3,0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_host_0114cde0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uStack_a4 = FUN_000eb0ec(uVar3,PTR_s_containsString__0114af08,
                             &PTR____CFConstantStringClassReference_011715a0);
    if (uStack_a4 == 0) {
      _objc_release(local_a0[uStack_a4] + (int)-(uRam0000000001182318 ^ 0xd030ce40),uVar3);
    }
    else {
      uStack_1a8 = param_2;
      puStack_1a0 = auStack_2a0;
      _objc_msgSend(uVar2,PTR_s_path_0114cde8);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      iVar1 = FUN_000eb200(uVar4,PTR_s_isEqualToString__0114ae48,
                           &PTR____CFConstantStringClassReference_01171560);
      _objc_release(uVar4);
      _objc_release(uVar3);
      param_2 = uStack_1a8;
      iStack_bc = iVar1;
      if (iVar1 != 0) {
        uStack_1f8 = 0;
        uStack_200 = 0;
        uStack_1e8 = 0;
        uStack_1f0 = 0;
        puStack_218 = (undefined8 *)0x0;
        uStack_220 = 0;
        uStack_208 = 0;
        plStack_210 = (long *)0x0;
        uStack_1d8 = uVar2;
        uStack_1d0 = param_1;
        uStack_1c8 = param_5;
        uStack_1c0 = param_4;
        uStack_1b0 = param_3;
        _objc_msgSend(uVar2,PTR_s_queryItems_0114cb28);
        uStack_180 = _objc_retainAutoreleasedReturnValue();
        puStack_1b8 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
        lVar5 = _objc_msgSend(uStack_180,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_220
                              ,puStack_1a0,0x10);
        uStack_cc = (uint)(lVar5 == 0);
        if (lVar5 != 0) {
          puStack_178 = PTR_s_isEqualToString__0114ae48;
          puStack_170 = PTR_s_name_0114ca28;
          puStack_188 = PTR_s_value_0114cdf0;
          puStack_198 = PTR_s_URLWithString__0114b3d0;
          uStack_ec = (uint)(*plStack_210 == *plStack_210);
          puStack_190 = &uStack_220;
          if (*plStack_210 != *plStack_210) {
            _objc_enumerationMutation
                      (local_e8[uStack_ec] + (int)-(uRam0000000001182378 ^ 0xf0a9f9c0),uStack_180);
          }
          _objc_msgSend(*puStack_218,puStack_170);
          uVar2 = _objc_retainAutoreleasedReturnValue();
          uStack_104 = FUN_000eb134(uVar2,puStack_178,
                                    &PTR____CFConstantStringClassReference_011715e0);
                    /* WARNING: Could not recover jumptable at 0x000bb750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(local_100[uStack_104] + (int)-(uRam0000000001182398 ^ 0x26c29b78)))();
          return;
        }
        _objc_release(local_c8[uStack_cc] + (int)-(uRam0000000001182350 ^ 0xa21cf1a5),uStack_180);
        uVar2 = uStack_1d8;
        param_3 = uStack_1b0;
        param_4 = uStack_1c0;
        param_5 = uStack_1c8;
        param_2 = uStack_1a8;
        param_1 = uStack_1d0;
      }
    }
    _objc_release(uVar2);
  }
  (*_DAT_01226818)(param_1,param_2,param_3,param_4,param_5);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


