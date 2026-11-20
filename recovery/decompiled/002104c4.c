/* Decompiled from supplied 5.2.2 arm package. VA 0x2104c4. supportedLanguages */

/* Function Stack Size: 0x10 bytes */

ID YTPDB::supportedLanguages(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  ID IVar13;
  undefined *puVar14;
  ulong uVar15;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_localizations_0114e350);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_mutableCopy_0114b010;
  uVar9 = _objc_msgSend();
  _objc_release(uVar8);
  _objc_release(uVar7);
  puVar3 = PTR_s_count_0114b840;
  lVar10 = _objc_msgSend(uVar9,PTR_s_count_0114b840);
  puVar6 = PTR_s_setObject_atIndexedSubscript__0114e368;
  puVar5 = PTR_s_displayNameForKey_value__0114e360;
  puVar4 = PTR_s_currentLocale_0114e358;
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  if (lVar10 != 0) {
    uVar15 = 0;
    uVar7 = *(undefined8 *)PTR__NSLocaleIdentifier_01060378;
    puVar14 = PTR_s_setObject_atIndexedSubscript__0114e368;
    do {
      _objc_msgSend(puVar14,uVar9,puVar1,uVar15);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSLocale_0114ecb0,puVar4);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar5,uVar7,uVar8);
      lVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar11);
      if (lVar10 != 0) {
        _objc_msgSend((&PTR_LAB_011cb120)[lVar10 == 0] + (int)-(uRam00000000011cb130 ^ 0x40a774d5),
                      uVar9,puVar6,lVar10,uVar15);
      }
      _objc_release(lVar10);
      _objc_release(uVar8);
      uVar15 = uVar15 + 1;
      uVar12 = _objc_msgSend(uVar9,puVar3);
      puVar14 = (&PTR_LAB_011cb140)[uVar15 < uVar12] + (int)-(uRam00000000011cb150 ^ 0xf053d19a);
    } while (uVar15 < uVar12);
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSOrderedSet_0114f000,PTR_s_orderedSetWithArray__0114e370,uVar9);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_array_0114c388);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  uVar11 = _objc_msgSend(uVar8,puVar2);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_msgSend(uVar11,PTR_s_sortUsingSelector__0114e380,
                PTR_s_localizedCaseInsensitiveCompare__0114e378);
  uVar7 = _objc_msgSend(uVar11,PTR_s_copy_0114b058);
  _objc_release(uVar11);
  IVar13 = _objc_autoreleaseReturnValue(uVar7);
  return IVar13;
}


