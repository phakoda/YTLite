/* Decompiled from supplied 5.2.2 arm package. VA 0x292b8. FUN_000292b8 */

void FUN_000292b8(void)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auStack_4f0 [160];
  undefined1 auStack_450 [32];
  undefined1 auStack_430 [176];
  undefined1 *puStack_380;
  undefined1 *puStack_378;
  undefined1 *puStack_370;
  undefined **local_368;
  undefined **ppuStack_360;
  undefined **local_358;
  undefined **ppuStack_350;
  undefined **local_340;
  undefined **local_330;
  undefined **local_320;
  undefined **local_310;
  undefined **local_300;
  undefined **local_2f0;
  undefined **local_2e0;
  undefined **ppuStack_2d8;
  undefined **local_2d0;
  undefined **ppuStack_2c8;
  undefined **local_2b8;
  undefined **local_2a8;
  undefined **ppuStack_2a0;
  undefined **local_298;
  undefined **ppuStack_290;
  undefined **local_280;
  undefined **ppuStack_278;
  undefined **local_270;
  undefined **ppuStack_268;
  undefined **local_258;
  undefined **local_248;
  undefined **local_238;
  undefined **ppuStack_230;
  undefined **local_228;
  undefined **ppuStack_220;
  undefined **local_218;
  undefined **ppuStack_210;
  undefined **local_200;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1d0;
  undefined **local_1c8;
  undefined **local_1b8;
  undefined **local_1a8;
  undefined **local_198;
  undefined **local_190;
  undefined **local_188;
  undefined **local_180;
  undefined **local_178;
  undefined **local_168;
  undefined **local_158;
  undefined **local_150;
  undefined **local_140;
  undefined **local_138;
  undefined **local_128;
  undefined **local_118;
  undefined **local_108;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **ppuStack_a8;
  uint local_9c;
  undefined **local_98;
  long local_90;
  
  local_90 = *(long *)PTR____stack_chk_guard_01060708;
  local_98 = &PTR_LAB_01159828;
  local_9c = (uint)(DAT_01225e18 == 0);
  local_b0 = &PTR_LAB_01159848;
  ppuStack_a8 = &PTR_LAB_01158940;
  local_c0 = &PTR_LAB_01159860;
  local_d8 = &PTR_LAB_01158940;
  ppuStack_d0 = &PTR_LAB_01158940;
  local_e8 = &PTR_LAB_01159890;
  ppuStack_e0 = &PTR_LAB_01158940;
  local_f8 = &PTR_LAB_011598a8;
  local_108 = &PTR_LAB_011598c0;
  local_118 = &PTR_LAB_011598d8;
  local_128 = &PTR_LAB_011598f0;
  local_138 = &PTR_LAB_01158940;
  local_140 = &PTR_LAB_01159910;
  local_158 = &PTR_LAB_01159930;
  local_150 = &PTR_LAB_01158940;
  local_168 = &PTR_LAB_01159948;
  local_178 = &PTR_LAB_01158940;
  local_180 = &PTR_LAB_01158940;
  local_188 = &PTR_LAB_01158940;
  local_190 = &PTR_LAB_01158940;
  local_198 = &PTR_LAB_01159980;
  local_1a8 = &PTR_LAB_01159998;
  local_1b8 = &PTR_LAB_011599b0;
  local_1c8 = &PTR_LAB_01158940;
  local_1d0 = &PTR_LAB_01158940;
  local_1d8 = &PTR_LAB_011599d8;
  local_1e8 = &PTR_LAB_011599f0;
  local_1f8 = &PTR_LAB_01158940;
  local_200 = &PTR_LAB_01159a10;
  local_218 = &PTR_LAB_01158940;
  ppuStack_210 = &PTR_LAB_01158940;
  local_228 = &PTR_LAB_01158940;
  ppuStack_220 = &PTR_LAB_01158940;
  local_238 = &PTR_LAB_01159a50;
  ppuStack_230 = &PTR_LAB_01158940;
  local_248 = &PTR_LAB_01159a68;
  local_258 = &PTR_LAB_01159a80;
  local_270 = &PTR_LAB_01158940;
  ppuStack_268 = &PTR_LAB_01158940;
  local_280 = &PTR_LAB_01159ab0;
  ppuStack_278 = &PTR_LAB_01158940;
  local_298 = &PTR_LAB_01158940;
  ppuStack_290 = &PTR_LAB_01158940;
  local_2a8 = &PTR_LAB_01159ae0;
  ppuStack_2a0 = &PTR_LAB_01158940;
  local_2b8 = &PTR_LAB_01159af8;
  local_2d0 = &PTR_LAB_01158940;
  ppuStack_2c8 = &PTR_LAB_01158940;
  local_2e0 = &PTR_LAB_01159b28;
  ppuStack_2d8 = &PTR_LAB_01158940;
  local_2f0 = &PTR_LAB_01159b40;
  local_300 = &PTR_LAB_01159b58;
  local_310 = &PTR_LAB_01159b70;
  local_320 = &PTR_LAB_01159b88;
  local_330 = &PTR_LAB_01159ba0;
  local_340 = &PTR_LAB_01159bb8;
  local_358 = &PTR_LAB_01158940;
  ppuStack_350 = &PTR_LAB_01158940;
  local_368 = &PTR_LAB_01158940;
  ppuStack_360 = &PTR_LAB_01158940;
  DAT_01225e18 = 1;
  puStack_378 = auStack_430;
  puStack_370 = auStack_450;
  puStack_380 = auStack_4f0;
  thunk_FUN_000236c0();
  lVar1 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000287c0();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00027078(&PTR____CFConstantStringClassReference_01157d10,uVar2);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  uStack_b4 = (uint)(lVar1 != 0 && lVar3 != 0);
  if (lVar1 != 0 && lVar3 != 0) {
    uStack_ec = (uint)DAT_01225d20;
                    /* WARNING: Could not recover jumptable at 0x0002aa0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_e8[DAT_01225d20] + (int)-(uRam00000000011598a0 ^ 0x17b466c1)))();
    return;
  }
  uStack_c4 = (uint)(DAT_01225d70 == -1);
  if (DAT_01225d70 != -1) {
    _dispatch_once(local_c0[uStack_c4] + (int)-(uRam0000000001159870 ^ 0xb55619df),&DAT_01225d70,
                   &PTR___NSConcreteGlobalBlock_01061640);
  }
  uVar2 = DAT_01225d68;
  _objc_retain(DAT_01225d68);
  _objc_sync_enter();
  DAT_01225d58 = 0;
  _objc_sync_exit(uVar2);
  _objc_release(uVar2);
  _objc_release(lVar3);
  _objc_release(lVar1);
  CallSupervisor(0xde1a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_90) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


