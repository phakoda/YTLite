/* Decompiled from supplied 5.2.2 arm package. VA 0x1186d8. FUN_001186d8 */

undefined8 FUN_001186d8(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 *puStack_1c8;
  long *plStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  uint local_184;
  undefined **local_180;
  undefined1 auStack_178 [128];
  undefined1 auStack_f8 [128];
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_180 = &PTR__objc_msgSend_0118cdd0;
  _objc_retain(param_2);
  lVar6 = _objc_msgSend(param_2,PTR_s_type_0114b050);
  uVar11 = 0;
  local_184 = (uint)(lVar6 == 4);
  if (lVar6 != 4) {
    _objc_msgSend(param_2,PTR_s_title_0114c7f0);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_lowercaseString_0114cf58;
    _objc_msgSend(uVar11,PTR_s_lowercaseString_0114cf58);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_containsString__0114af08;
    iVar4 = FUN_00126ed0(uVar7,PTR_s_containsString__0114af08,*(undefined8 *)(param_1 + 0x20));
    _objc_release(uVar7);
    _objc_release(uVar11);
    uVar11 = 1;
    if (iVar4 == 0) {
      _objc_msgSend(param_2,PTR_s_subtitle_0114d1e8);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar3);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      iVar4 = FUN_00127068(uVar8,puVar1,*(undefined8 *)(param_1 + 0x20));
      _objc_release(uVar8);
      _objc_release(uVar7);
      if (iVar4 == 0) {
        _objc_msgSend(param_2,PTR_s_identifier_0114c500);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        iVar4 = FUN_00126f38(uVar8,puVar1,*(undefined8 *)(param_1 + 0x20));
        _objc_release(uVar8);
        _objc_release(uVar7);
        if (iVar4 == 0) {
          uStack_1a8 = 0;
          uStack_1b0 = 0;
          uStack_198 = 0;
          uStack_1a0 = 0;
          puStack_1c8 = (undefined8 *)0x0;
          uStack_1d0 = 0;
          uStack_1b8 = 0;
          plStack_1c0 = (long *)0x0;
          _objc_msgSend(param_2,PTR_s_titleIndexes_0114d1f0);
          uVar7 = _objc_retainAutoreleasedReturnValue();
          puVar2 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
          lVar6 = _objc_msgSend(uVar7,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1d0,
                                auStack_f8,0x10);
          puVar9 = (&PTR_LAB_0118ce30)[lVar6 == 0] + (int)-(uRam000000000118ce40 ^ 0x5751a0e1);
          if (lVar6 != 0) {
            lVar10 = *plStack_1c0;
            if (*plStack_1c0 != lVar10) {
              _objc_enumerationMutation
                        ((&PTR_LAB_0118ce58)[*plStack_1c0 == lVar10] +
                         (int)-(uRam000000000118ce68 ^ 0x70603edf),uVar7);
            }
            _objc_msgSend(*puStack_1c8,puVar3);
            uVar11 = _objc_retainAutoreleasedReturnValue();
            uVar5 = FUN_00126e68(uVar11,puVar1,*(undefined8 *)(param_1 + 0x20));
            _objc_release(uVar11);
            uVar11 = 1;
            if (uVar5 != 0) {
              _objc_release((&PTR_LAB_0118ce78)[uVar5] + (int)-(uRam000000000118ce88 ^ 0x92462b46),
                            uVar7);
              goto LAB_00118d3c;
            }
            if (lVar6 != 1) {
                    /* WARNING: Could not recover jumptable at 0x00118b9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar11 = (*(code *)((&PTR_LAB_0118ce58)[*plStack_1c0 == lVar10] +
                                 (int)-(uRam000000000118ce68 ^ 0x70603edf)))();
              return uVar11;
            }
            lVar6 = _objc_msgSend((&PTR_LAB_0118ce90)[lVar6 == 1] +
                                  (int)-(uRam000000000118cea0 ^ 0xceb953ff),uVar7,puVar2,&uStack_1d0
                                  ,auStack_f8,0x10);
            puVar9 = (&PTR_FUN_0118cea8)[lVar6 == 0] + (int)-(DAT_0118ceb8 ^ 0xbadbe5b3);
            if (lVar6 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00118c28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar11 = (*(code *)((&PTR_LAB_0118ce58)[*plStack_1c0 == lVar10] +
                                 (int)-(uRam000000000118ce68 ^ 0x70603edf)))();
              return uVar11;
            }
          }
          _objc_release(puVar9,uVar7);
          puVar1 = PTR_s_titleIndexesProvider_0114d1f8;
          _objc_msgSend(param_2,PTR_s_titleIndexesProvider_0114d1f8);
          lVar6 = _objc_retainAutoreleasedReturnValue();
          _objc_release();
          uVar11 = 0;
          if (lVar6 != 0) {
            uStack_1e8 = 0;
            uStack_1f0 = 0;
            uStack_1d8 = 0;
            uStack_1e0 = 0;
            uStack_208 = 0;
            uStack_210 = 0;
            uStack_1f8 = 0;
            uStack_200 = 0;
            _objc_msgSend(param_2,puVar1);
            lVar6 = _objc_retainAutoreleasedReturnValue();
            (**(code **)(lVar6 + 0x10))();
            uVar11 = _objc_retainAutoreleasedReturnValue();
            _objc_release(lVar6);
            lVar6 = _objc_msgSend(uVar11,puVar2,&uStack_210,auStack_178,0x10);
                    /* WARNING: Could not recover jumptable at 0x00118d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar11 = (*(code *)((&PTR_LAB_0118ced8)[lVar6 == 0] +
                               (int)-(uRam000000000118cee8 ^ 0x188a0d53)))();
            return uVar11;
          }
        }
      }
    }
  }
LAB_00118d3c:
  _objc_release(param_2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar11;
}


