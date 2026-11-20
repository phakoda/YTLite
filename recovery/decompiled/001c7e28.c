/* Decompiled from supplied 5.2.2 arm package. VA 0x1c7e28. hitTest:withEvent: */

/* Function Stack Size: 0x28 bytes */

ID ToastWindow::hitTest_withEvent_(ID param_1,SEL param_2,CGPoint param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IStack_1a0;
  undefined *puStack_198;
  ID IStack_190;
  undefined *puStack_188;
  ID IStack_180;
  undefined *puStack_178;
  undefined **local_168;
  undefined **local_158;
  uint uStack_14c;
  undefined **local_148;
  undefined **ppuStack_140;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_128;
  undefined **ppuStack_120;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f0;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_011b4b08;
  local_74 = (uint)(DAT_01227c54 == 0);
  local_88 = &PTR_LAB_011b4b28;
  local_a0 = &PTR__objc_msgSend_011b4b48;
  local_b0 = &PTR_LAB_011b4b60;
  local_c0 = &PTR_LAB_011b4b78;
  local_d0 = &PTR_LAB_011b4b90;
  local_e0 = &PTR_LAB_011b4ba8;
  local_f0 = &PTR_LAB_011b4bc0;
  local_100 = &PTR__objc_alloc_init_011b4bd8;
  local_110 = &PTR_LAB_011b4bf0;
  local_80 = &PTR_LAB_011b49f0;
  local_98 = &PTR_LAB_011b49f0;
  local_128 = &PTR_LAB_011b49f0;
  ppuStack_120 = &PTR_LAB_011b49f0;
  local_138 = &PTR_LAB_011b49f0;
  ppuStack_130 = &PTR_LAB_011b49f0;
  local_148 = &PTR__objc_msgSend_011b4c30;
  ppuStack_140 = &PTR_LAB_011b49f0;
  local_158 = &PTR__objc_alloc_init_011b4c48;
  local_168 = &PTR_LAB_011b49f0;
  DAT_01227c54 = 1;
  puStack_198 = PTR_ToastWindow_0114f0f0;
  IStack_1a0 = param_1;
  IStack_190 = param_1;
  _objc_msgSendSuper2(param_3.field0_0x0,param_3.field1_0x8,&IStack_1a0,
                      PTR_s_hitTest_withEvent__0114deb0);
  _objc_retainAutoreleasedReturnValue();
  IVar3 = _objc_retain();
  puVar2 = PTR_s__viewControllerForAncestor_0114ade0;
  puVar1 = PTR_s_isKindOfClass__0114ad70;
  uStack_8c = (uint)(IVar3 == 0);
  IStack_180 = IVar3;
  if (IVar3 != 0) {
    puStack_178 = PTR_s_class_0114ae88;
    puStack_188 = PTR_s_superview_0114c820;
    uVar4 = _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_class_0114ae88);
    uStack_a4 = FUN_001c971c(IVar3,puVar1,uVar4);
    if (uStack_a4 == 0) {
      _objc_msgSend(local_a0[uStack_a4] + (int)-(uRam00000000011b4b58 ^ 0x4906b865),IVar3,puVar2);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_011b4800);
      uStack_b4 = FUN_001c95e4(uVar4,puVar1,uVar5);
      if (uStack_b4 == 0) {
        _objc_msgSend(local_b0[uStack_b4] + (int)-(uRam00000000011b4b70 ^ 0x60a44e0),IVar3,puVar2);
        uVar5 = _objc_retainAutoreleasedReturnValue();
        uVar6 = _NSClassFromString(&PTR____CFConstantStringClassReference_011b4780);
        uStack_c4 = FUN_001c964c(uVar5,puVar1,uVar6);
        if (uStack_c4 == 0) {
          _objc_msgSend(IVar3,puVar2);
          uVar4 = _objc_retainAutoreleasedReturnValue();
          uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_011b4800);
          uStack_d4 = FUN_001c953c(uVar4,puVar1,uVar5);
                    /* WARNING: Could not recover jumptable at 0x001c87f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          IVar3 = (*(code *)(local_d0[uStack_d4] + (int)-(uRam00000000011b4ba0 ^ 0x87dab333)))();
          return IVar3;
        }
        _objc_release(local_c0[uStack_c4] + (int)-(uRam00000000011b4b88 ^ 0x46256e23),uVar5);
      }
      _objc_release(uVar4);
      uStack_14c = (uint)(IStack_180 == IStack_190);
                    /* WARNING: Could not recover jumptable at 0x001c8a5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar3 = (*(code *)(local_148[uStack_14c] + (int)-(uRam00000000011b4c40 ^ 0x2c33df6)))();
      return IVar3;
    }
  }
  uStack_14c = (uint)(IStack_180 == IStack_190);
                    /* WARNING: Could not recover jumptable at 0x001c89f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_148[uStack_14c] + (int)-(uRam00000000011b4c40 ^ 0x2c33df6)))();
  return IVar3;
}


