/* Decompiled from supplied 5.2.2 arm package. VA 0x19b714. addDurationWithoutSegments:videoController: */

/* Function Stack Size: 0x20 bytes */

void SBPlayerDecorator::addDurationWithoutSegments_videoController_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puVar5;
  double dVar6;
  undefined1 auStack_280 [136];
  undefined1 *puStack_1f8;
  undefined **local_1d0;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **ppuStack_198;
  undefined **local_188;
  undefined **local_178;
  undefined **local_168;
  undefined **local_158;
  undefined **ppuStack_150;
  undefined **local_140;
  undefined **ppuStack_138;
  undefined **local_128;
  undefined **ppuStack_120;
  undefined **local_110;
  undefined **local_108;
  undefined **ppuStack_100;
  undefined **local_f0;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  uint local_9c;
  undefined **local_98;
  long local_90;
  
  local_90 = *(long *)PTR____stack_chk_guard_01060708;
  local_98 = &PTR_LAB_011ac5c0;
  local_9c = (uint)(DAT_012278d0 == 0);
  local_b0 = &PTR_LAB_011ac5e0;
  local_c0 = &PTR_LAB_011ac5f8;
  local_d0 = &PTR_LAB_011ac610;
  local_e0 = &PTR_LAB_011ac628;
  local_f0 = &PTR_LAB_011ac640;
  local_a8 = &PTR_LAB_011ac130;
  local_108 = &PTR_LAB_011ac130;
  ppuStack_100 = &PTR_LAB_011ac130;
  local_110 = &PTR_LAB_011ac668;
  local_128 = &PTR_LAB_011ac688;
  ppuStack_120 = &PTR_LAB_011ac130;
  local_140 = &PTR_LAB_011ac6a8;
  ppuStack_138 = &PTR_LAB_011ac130;
  local_158 = &PTR_LAB_011ac6c8;
  ppuStack_150 = &PTR_LAB_011ac130;
  local_168 = &PTR__objc_msgSend_011ac6e0;
  local_178 = &PTR_LAB_011ac6f8;
  local_188 = &PTR_LAB_011ac710;
  local_1a0 = &PTR__objc_msgSend_011ac730;
  ppuStack_198 = &PTR_LAB_011ac130;
  local_1b8 = &PTR_LAB_011ac130;
  ppuStack_1b0 = &PTR_LAB_011ac130;
  local_1c8 = &PTR_LAB_011ac130;
  ppuStack_1c0 = &PTR_LAB_011ac130;
  local_1d0 = &PTR_LAB_011ac130;
  DAT_012278d0 = 1;
  puStack_1f8 = auStack_280;
  uVar2 = _objc_retain(param_3);
  _objc_msgSend(uVar2,PTR_s_parentViewController_0114ad68);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _NSClassFromString(&PTR____CFConstantStringClassReference_011ab970);
  uVar1 = FUN_001a12bc(uVar2,PTR_s_isKindOfClass__0114ad70,uVar3);
  _objc_release(uVar2);
  puVar5 = local_b0[uVar1] + (int)-(DAT_011ac5f0 ^ 0x48e096fa);
  uStack_b4 = uVar1;
  if (uVar1 != 0) {
    _objc_msgSend(param_3,PTR_s_contentVideoID_0114cef0);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lVar4 == 0);
    puVar5 = local_c0[uStack_c4] + (int)-(uRam00000000011ac608 ^ 0x1ff2f22d);
    if (lVar4 != 0) {
      dVar6 = (double)_objc_msgSend(param_3,PTR_s_currentVideoTotalMediaTime_0114c9f8);
      _objc_release(lVar4);
      uStack_d4 = (uint)(dVar6 == 0.0);
                    /* WARNING: Could not recover jumptable at 0x0019be60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d0[uStack_d4] + (int)-(uRam00000000011ac620 ^ 0x2745c139)))();
      return;
    }
    uStack_c4 = 1;
  }
  _objc_release(puVar5,param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_90) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


