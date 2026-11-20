/* Decompiled from supplied 5.2.2 arm package. VA 0xa8894. FUN_000a8894 */

void FUN_000a8894(undefined8 param_1)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 auStack_3c0 [272];
  undefined1 *puStack_2b0;
  undefined **local_288;
  undefined **ppuStack_280;
  undefined **local_270;
  undefined **local_268;
  undefined **ppuStack_260;
  undefined **local_250;
  undefined **ppuStack_248;
  undefined **local_238;
  undefined **local_228;
  undefined **ppuStack_220;
  undefined **local_210;
  undefined **local_200;
  undefined **ppuStack_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1c8;
  undefined **local_1c0;
  undefined **ppuStack_1b8;
  undefined **local_1a8;
  undefined **ppuStack_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_168;
  undefined **local_160;
  undefined **ppuStack_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_128;
  undefined **ppuStack_120;
  undefined **local_110;
  undefined **ppuStack_108;
  undefined **local_f8;
  undefined **local_f0;
  undefined **ppuStack_e8;
  undefined **local_d8;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  puVar1 = PTR_s_activeVideo_0114c788;
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01180d48;
  local_7c = (uint)(DAT_01226e18 == 0);
  local_90 = &PTR_LAB_01180d68;
  local_a0 = &PTR_LAB_01180d80;
  local_b0 = &PTR_LAB_01180d98;
  local_88 = &PTR_LAB_01175340;
  local_c8 = &PTR_LAB_01180db8;
  ppuStack_c0 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_01180dd0;
  local_f0 = &PTR_LAB_01175340;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_f8 = &PTR_LAB_01180df8;
  local_110 = &PTR_LAB_01180e18;
  ppuStack_108 = &PTR_LAB_01175340;
  local_128 = &PTR_LAB_01180e38;
  ppuStack_120 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_01180e50;
  local_148 = &PTR_LAB_01180e68;
  local_160 = &PTR_LAB_01175340;
  ppuStack_158 = &PTR_LAB_01175340;
  local_168 = &PTR_LAB_01180e90;
  local_180 = &PTR_LAB_01180eb0;
  ppuStack_178 = &PTR_LAB_01175340;
  local_190 = &PTR_LAB_01180ec8;
  local_1a8 = &PTR_LAB_01180ee8;
  ppuStack_1a0 = &PTR_LAB_01175340;
  local_1c0 = &PTR_LAB_01175340;
  ppuStack_1b8 = &PTR_LAB_01175340;
  local_1c8 = &PTR_LAB_01180f10;
  local_1d8 = &PTR_LAB_01180f28;
  local_1e8 = &PTR_LAB_01180f40;
  local_200 = &PTR_LAB_01180f60;
  ppuStack_1f8 = &PTR_LAB_01175340;
  local_210 = &PTR_LAB_01180f78;
  local_228 = &PTR_LAB_01180f98;
  ppuStack_220 = &PTR_LAB_01175340;
  local_238 = &PTR_LAB_01180fb0;
  local_250 = &PTR_LAB_01180fd0;
  ppuStack_248 = &PTR_LAB_01175340;
  local_268 = &PTR_LAB_01175340;
  ppuStack_260 = &PTR_LAB_01175340;
  local_270 = &PTR_LAB_01180ff8;
  local_288 = &PTR_LAB_01175340;
  ppuStack_280 = &PTR_LAB_01175340;
  DAT_01226e18 = 1;
  puStack_2b0 = auStack_3c0;
  _objc_msgSend(param_1,PTR_s_activeVideo_0114c788);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    uVar2 = FUN_000e7310(param_1,PTR_s_isMDXActive_0114cb78);
    _objc_release(lVar3);
    uStack_a4 = uVar2;
    if (uVar2 == 0) {
      _objc_msgSend(local_a0[uVar2] + (int)-(uRam0000000001180d90 ^ 0x6badf75c),param_1,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_selectableAudioFormats_0114cbe8);
      lVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_release();
      _objc_release(uVar4);
      uStack_b4 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x000a9158. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_b0[uStack_b4] + (int)-(uRam0000000001180da8 ^ 0xc467b091)))();
      return;
    }
  }
  CallSupervisor(0x2936);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


