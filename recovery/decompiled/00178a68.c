/* Decompiled from supplied 5.2.2 arm package. VA 0x178a68. patreonButtonCellWithType:model: */

/* Function Stack Size: 0x20 bytes */

ID YTPSettingsBuilder::patreonButtonCellWithType_model_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  ID IVar8;
  undefined1 auStack_120 [16];
  undefined1 auStack_110 [64];
  undefined1 *puStack_d0;
  undefined1 *puStack_c8;
  ID IStack_b8;
  undefined **local_b0;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  undefined8 local_68;
  
  local_68 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011a8638;
  local_74 = (uint)(DAT_01227518 == 0);
  local_88 = &PTR_LAB_011a8658;
  ppuStack_80 = &PTR_LAB_011a7950;
  local_a0 = &PTR_LAB_011a8678;
  ppuStack_98 = &PTR_LAB_011a7950;
  local_b0 = &PTR_LAB_011a7950;
  DAT_01227518 = 1;
  puStack_c8 = auStack_110;
  puStack_d0 = auStack_120;
  IStack_b8 = param_4;
  _objc_retain(param_4);
  puVar4 = PTR_s_isEqualToString__0114ae48;
  uVar7 = _objc_retain(param_3);
  iVar5 = FUN_00189f94(uVar7,puVar4,&PTR____CFConstantStringClassReference_011a5780);
  uVar6 = FUN_00189fbc(param_3,puVar4,&PTR____CFConstantStringClassReference_011a5740);
  FUN_00189fe4(param_3,puVar4,&PTR____CFConstantStringClassReference_011a5700);
  _objc_release(param_3);
  uStack_8c = FUN_0018a008();
  ppuVar3 = &PTR____CFConstantStringClassReference_011a5640;
  if (uVar6 == 0) {
    ppuVar3 = &PTR____CFConstantStringClassReference_011a5680;
  }
  ppuVar1 = &PTR____CFConstantStringClassReference_011a56c0;
  if (uVar6 == 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_011a5600;
  }
  ppuVar2 = &PTR____CFConstantStringClassReference_011a5540;
  if (iVar5 == 0) {
    ppuVar2 = ppuVar3;
  }
  ppuVar3 = &PTR____CFConstantStringClassReference_011a55c0;
  if (iVar5 == 0) {
    ppuVar3 = ppuVar1;
  }
  _objc_retain(ppuVar2);
  _objc_retain(ppuVar3);
  uStack_8c = uVar6 & uStack_8c;
                    /* WARNING: Could not recover jumptable at 0x00179340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar8 = (*(code *)(local_88[uStack_8c] + (int)-(DAT_011a8668 ^ 0x1cd615da)))();
  return IVar8;
}


