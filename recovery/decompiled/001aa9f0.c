/* Decompiled from supplied 5.2.2 arm package. VA 0x1aa9f0. adaptiveBackgroundColor */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::adaptiveBackgroundColor(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined *puStack_80;
  undefined8 uStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  ID IStack_60;
  undefined1 uStack_58;
  undefined **local_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b2608;
  local_3c = (uint)(DAT_012279ac == 0);
  local_48 = &PTR_LAB_011b20a0;
  DAT_012279ac = 1;
  uStack_58 = FUN_001b7304(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                           &PTR____CFConstantStringClassReference_011aecf0);
  puStack_80 = PTR___NSConcreteStackBlock_01060660;
  uStack_78 = DAT_00c4c230;
  pcStack_70 = FUN_001aaba4;
  puStack_68 = &UNK_010629c0;
  IStack_60 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithDynamicProvider__0114c558,
                &puStack_80);
  _objc_retainAutoreleasedReturnValue();
  IVar1 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return IVar1;
}


