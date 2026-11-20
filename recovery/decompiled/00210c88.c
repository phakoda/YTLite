/* Decompiled from supplied 5.2.2 arm package. VA 0x210c88. indexOfPreferredLanguage */

/* Function Stack Size: 0x10 bytes */

unsigned_long_long YTPDB::indexOfPreferredLanguage(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  unsigned_long_long uVar6;
  undefined *puVar7;
  unsigned_long_long uVar8;
  
  _objc_msgSend(param_1,PTR_s_supportedLanguages_0114c2c8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_preferredLocalizations_0114e388);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_firstObject_0114b748);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSLocale_0114ecb0,PTR_s_currentLocale_0114e358);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_displayNameForKey_value__0114e360,
                *(undefined8 *)PTR__NSLocaleIdentifier_01060378,uVar4);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar7 = (&PTR_LAB_011cb240)[lVar5 == 0] + (int)-(DAT_011cb250 ^ 0x1629ee0d);
  if (lVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar6 = _objc_msgSend(uVar1,PTR_s_indexOfObject__0114b020,lVar5);
    puVar7 = (undefined *)0x7fffffffffffffff;
    uVar8 = 0;
    if (uVar6 != 0x7fffffffffffffff) {
      uVar8 = uVar6;
    }
  }
  _objc_release(puVar7,lVar5);
  _objc_release(uVar4);
  _objc_release(uVar1);
  return uVar8;
}


