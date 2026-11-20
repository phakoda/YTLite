/* Decompiled from supplied 5.2.2 arm package. VA 0xbde0c. FUN_000bde0c */

void FUN_000bde0c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 auStack_210 [128];
  undefined8 uStack_190;
  undefined8 *puStack_188;
  long *plStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined *puStack_130;
  undefined1 *puStack_128;
  undefined *puStack_120;
  undefined8 uStack_118;
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
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01182618;
  local_7c = (uint)(DAT_01226f30 == 0);
  local_90 = &PTR_LAB_01182638;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_01182650;
  local_b8 = &PTR_LAB_01175340;
  ppuStack_b0 = &PTR_LAB_01175340;
  local_c0 = &PTR_LAB_01182678;
  local_d8 = &PTR_LAB_01182698;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_f0 = &PTR_LAB_011826b8;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_011826d0;
  local_110 = &PTR_LAB_01175340;
  DAT_01226f30 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_string_0114b508);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  puVar1 = PTR_s_length_0114b438;
  lVar5 = _objc_msgSend(uVar4,PTR_s_length_0114b438);
  uStack_94 = (uint)(lVar5 == 0);
  if (lVar5 != 0) {
    puStack_120 = puVar1;
    ppuStack_150 = &PTR____CFConstantStringClassReference_01171de0;
    ppuStack_148 = &PTR____CFConstantStringClassReference_01171ea0;
    ppuStack_140 = &PTR____CFConstantStringClassReference_01171e20;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &ppuStack_150,3);
    _objc_retainAutoreleasedReturnValue();
    puStack_188 = (undefined8 *)0x0;
    uStack_190 = 0;
    uStack_178 = 0;
    plStack_180 = (long *)0x0;
    uStack_168 = 0;
    uStack_170 = 0;
    uStack_158 = 0;
    uStack_160 = 0;
    uStack_118 = _objc_retain();
    puVar2 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar5 = _objc_msgSend(uStack_118,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_190,
                          auStack_210,0x10);
    uVar3 = uStack_118;
    puVar1 = PTR_s_containsString__0114af08;
    uStack_a4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      puStack_130 = puVar2;
      uStack_c4 = (uint)(*plStack_180 == *plStack_180);
      puStack_128 = auStack_210;
      if (*plStack_180 != *plStack_180) {
        _objc_enumerationMutation(uStack_118);
      }
      uStack_dc = FUN_000ec070(uVar4,puVar1,*puStack_188);
                    /* WARNING: Could not recover jumptable at 0x000be510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d8[uStack_dc] + (int)-(uRam00000000011826a8 ^ 0x9ea4ea5b)))();
      return;
    }
    _objc_release(uStack_118);
    _objc_release(uVar3);
  }
  _objc_release(uVar4);
  CallSupervisor(0xe33d);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


