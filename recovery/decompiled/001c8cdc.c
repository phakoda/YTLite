/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8cdc. appKeyWindow */

/* Function Stack Size: 0x10 bytes */

ID ToastWindow::appKeyWindow(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ID IVar6;
  undefined8 local_140;
  undefined8 *puStack_138;
  long *plStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  uint local_fc;
  undefined **local_f8;
  undefined1 auStack_f0 [128];
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_f8 = &PTR_LAB_011b4ca8;
  puStack_138 = (undefined8 *)0x0;
  local_140 = 0;
  uStack_128 = 0;
  plStack_130 = (long *)0x0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_windows_0114dec8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  lVar4 = _objc_msgSend(uVar3,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_140,auStack_f0,
                        0x10);
  puVar1 = PTR_s_isKeyWindow_0114deb8;
  local_fc = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    if (*plStack_130 != *plStack_130) {
      _objc_enumerationMutation
                ((&PTR_LAB_011b4cd0)[*plStack_130 == *plStack_130] +
                 (int)-(uRam00000000011b4ce0 ^ 0xc2542f69),uVar3);
    }
    uVar5 = FUN_001c9934(*puStack_138,puVar1);
                    /* WARNING: Could not recover jumptable at 0x001c8f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar6 = (*(code *)((&PTR_LAB_011b4cf0)[uVar5 & 0xffffffff] +
                      (int)-(uRam00000000011b4d00 ^ 0x7fb08900)))();
    return IVar6;
  }
  _objc_release(local_f8[local_fc] + (int)-(DAT_011b4cb8 ^ 0x291ef60f),uVar3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(0);
  return IVar6;
}


