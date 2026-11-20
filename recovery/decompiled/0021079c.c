/* Decompiled from supplied 5.2.2 arm package. VA 0x21079c. langCodeForIndex: */

/* Function Stack Size: 0x18 bytes */

ID YTPDB::langCodeForIndex_(ID param_1,SEL param_2,long_long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  ID IVar12;
  undefined *puVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  undefined8 local_150;
  long lStack_148;
  long *plStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  uint local_104;
  undefined **local_100;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_100 = &PTR_LAB_011cb158;
  _objc_msgSend(param_1,PTR_s_supportedLanguages_0114c2c8);
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_localizations_0114e350);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,PTR_s_dictionary_0114c7f8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  lStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  plStack_140 = (long *)0x0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uVar8 = _objc_retain(uVar7);
  puVar2 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lVar9 = _objc_msgSend(uVar8,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar9 == 0);
  puVar13 = local_100[local_104] + (int)-(DAT_011cb168 ^ 0x4c1482f2);
  if (lVar9 != 0) {
    lVar15 = *plStack_140;
    uVar8 = *(undefined8 *)PTR__NSLocaleIdentifier_01060378;
    do {
      puVar4 = PTR_s_displayNameForKey_value__0114e360;
      puVar3 = PTR_s_currentLocale_0114e358;
      puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
      lVar16 = 0;
      bVar5 = *plStack_140 == lVar15;
      puVar13 = (&PTR_LAB_011cb180)[bVar5] + (int)-(DAT_011cb190 ^ 0xe917b57);
      while( true ) {
        if (!bVar5) {
          _objc_enumerationMutation(puVar13,uVar7);
        }
        uVar14 = *(undefined8 *)(lStack_148 + lVar16 * 8);
        _objc_msgSend(PTR__OBJC_CLASS___NSLocale_0114ecb0,puVar3);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar10,puVar4,uVar8,uVar14);
        lVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar10);
        if (lVar11 != 0) {
          _objc_msgSend(uVar6,puVar1,lVar11);
          lVar9 = _objc_retainAutoreleasedReturnValue();
          _objc_release();
                    /* WARNING: Could not recover jumptable at 0x00210ab8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          IVar12 = (*(code *)((&PTR_LAB_011cb1b8)[lVar9 == 0] +
                             (int)-(uRam00000000011cb1c8 ^ 0x4b0ce127)))();
          return IVar12;
        }
        _objc_release((&PTR_LAB_011cb1a0)[lVar11 == 0] + (int)-(uRam00000000011cb1b0 ^ 0xe617a754),0
                     );
        bVar5 = lVar9 + -1 == lVar16;
        if (bVar5) break;
        lVar16 = lVar16 + 1;
        bVar5 = *plStack_140 == lVar15;
        puVar13 = (&PTR_LAB_011cb180)[bVar5] + (int)-(DAT_011cb190 ^ 0xe917b57);
      }
      lVar9 = _objc_msgSend((&PTR_caseD_1a_011cb1d8)[bVar5] +
                            (int)-(uRam00000000011cb1e8 ^ 0x6c157962),uVar7,puVar2,&local_150,
                            auStack_f8,0x10);
      puVar13 = (&PTR_LAB_011cb1f0)[lVar9 == 0] + (int)-(uRam00000000011cb200 ^ 0xdff2561e);
    } while (lVar9 != 0);
  }
  _objc_release(puVar13,uVar7);
                    /* WARNING: Could not recover jumptable at 0x00210b9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar12 = (*(code *)(*(long *)((long)&PTR_LAB_011cb208 + (param_3 >> 0x3c & 8)) +
                     (long)(int)-(uRam00000000011cb218 ^ 0xa6bb2bb8)))();
  return IVar12;
}


