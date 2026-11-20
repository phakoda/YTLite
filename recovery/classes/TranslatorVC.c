// Decompiled implementation evidence for TranslatorVC. Not compilable source.

// -[TranslatorVC initWithText:], 0x1e06b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e06b4. initWithText: */

/* Function Stack Size: 0x18 bytes */

ID TranslatorVC::initWithText_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ID IVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined8 auStack_1e0 [2];
  undefined **ppuStack_1d0;
  undefined **ppuStack_1c8;
  undefined **ppuStack_1c0;
  undefined **ppuStack_1b8;
  undefined8 uStack_1b0;
  undefined **ppuStack_1a8;
  undefined **ppuStack_1a0;
  undefined **ppuStack_198;
  undefined8 auStack_190 [2];
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined8 auStack_160 [2];
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined8 auStack_f0 [2];
  ID IStack_e0;
  undefined *puStack_d8;
  undefined *puStack_c8;
  undefined *puStack_c0;
  undefined8 *puStack_b8;
  undefined8 *puStack_b0;
  undefined8 *puStack_a8;
  ID IStack_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011ba738;
  local_74 = (uint)(DAT_01227e24 == 0);
  local_88 = &PTR_LAB_011ba758;
  ppuStack_80 = &PTR_LAB_011ba600;
  local_98 = &PTR_LAB_011ba600;
  DAT_01227e24 = 1;
  puStack_b8 = auStack_160;
  puStack_b0 = auStack_190;
  puStack_a8 = auStack_1e0;
  IStack_a0 = param_3;
  _objc_retain(param_3);
  puStack_d8 = PTR_TranslatorVC_0114f120;
  IStack_e0 = param_1;
  IVar4 = _objc_msgSendSuper2(&IStack_e0,@selector(initWithStyle:),2);
  uStack_8c = (uint)(IVar4 == 0);
  if (IVar4 != 0) {
    _objc_storeStrong(IVar4 + (long)_sourceText,IStack_a0);
    uVar5 = _objc_msgSend(PTR_YTPDB_0114ecc0,@selector(indexOfPreferredLanguage));
    *(undefined8 *)(IVar4 + (long)_langIndex) = uVar5;
    ppuStack_150 = @"title";
    puStack_c0 = @selector(ytl_localized);
    _objc_msgSend(@"Language");
    uVar5 = _objc_retainAutoreleasedReturnValue();
    ppuStack_148 = @"indexes";
    uStack_120 = uVar5;
    _objc_msgSend(PTR_YTPDB_0114ecc0,@selector(supportedLanguages));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    ppuStack_110 = @"menu";
    ppuStack_140 = @"type";
    ppuStack_138 = @"key";
    ppuStack_130 = @"id";
    ppuStack_108 = @"languageKey";
    ppuStack_100 = @"typeCell";
    puStack_c8 = @selector(dictionaryWithObjects:forKeys:count:);
    uStack_118 = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  @selector(dictionaryWithObjects:forKeys:count:),&uStack_120,&ppuStack_150,5);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(arrayWithObjects:count:);
    auStack_f0[0] = uVar7;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  auStack_f0,1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    lVar11 = (long)_type;
    uVar9 = *(undefined8 *)(IVar4 + lVar11);
    *(undefined8 *)(IVar4 + lVar11) = uVar8;
    _objc_release(uVar9);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar2 = puStack_c8;
    ppuStack_180 = @"type";
    ppuStack_178 = @"id";
    ppuStack_170 = @"textView";
    ppuStack_168 = @"translationCell";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puStack_c8,&ppuStack_170,&ppuStack_180,2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_b8;
    *puStack_b8 = uVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar3,1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    lVar10 = (long)_translation;
    uVar7 = *(undefined8 *)(IVar4 + lVar10);
    *(undefined8 *)(IVar4 + lVar10) = uVar6;
    _objc_release(uVar7);
    _objc_release(uVar5);
    ppuStack_1d0 = @"title";
    _objc_msgSend(@"Translate",puStack_c0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    ppuStack_1a8 = @"action";
    ppuStack_1c8 = @"type";
    ppuStack_1c0 = @"key";
    ppuStack_1b8 = @"id";
    ppuStack_1a0 = @"translateText";
    ppuStack_198 = @"translateCell";
    uStack_1b0 = uVar5;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar2,&uStack_1b0,&ppuStack_1d0,4);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_b0;
    *puStack_b0 = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar3,1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = *(undefined8 *)(IVar4 + (long)_translate);
    *(undefined8 *)(IVar4 + (long)_translate) = uVar7;
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar3 = puStack_a8;
    *puStack_a8 = *(undefined8 *)(IVar4 + lVar11);
    puVar3[1] = *(undefined8 *)(IVar4 + lVar10);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar3,2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = *(undefined8 *)(IVar4 + (long)_sections);
    *(undefined8 *)(IVar4 + (long)_sections) = uVar5;
    _objc_release(uVar6);
  }
  _objc_release(IStack_a0);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar4;
}



// -[TranslatorVC viewDidLoad], 0x1e13ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e13ac. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void TranslatorVC::viewDidLoad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IStack_80;
  undefined *puStack_78;
  undefined **local_70;
  int iStack_64;
  undefined **local_60;
  undefined **ppuStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011ba778;
  local_4c = (uint)(DAT_01227e28 == 0);
  local_60 = &PTR_LAB_011ba798;
  ppuStack_58 = &PTR_LAB_011ba600;
  local_70 = &PTR_LAB_011ba600;
  DAT_01227e28 = 1;
  puStack_78 = PTR_TranslatorVC_0114f120;
  IStack_80 = param_1;
  _objc_msgSendSuper2(&IStack_80,@selector(viewDidLoad));
  puVar2 = @selector(ytl_localized);
  _objc_msgSend(@"Translation",@selector(ytl_localized));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setTitle:),uVar4);
  _objc_release(uVar4);
  puVar1 = @selector(tableView);
  _objc_msgSend(param_1,@selector(tableView));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setSeparatorStyle:),0);
  _objc_release(uVar4);
  _objc_msgSend(0x3fe8000000000000,0x3fe0000000000000,DAT_00c4c2f8,0x3ff0000000000000,
                PTR__OBJC_CLASS___UIColor_0114eb18,@selector(colorWithRed:green:blue:alpha:));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setTintColor:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  uVar4 = _objc_msgSend(uVar4,@selector(initWithBarButtonSystemItem:target:action:),0x18,param_1,
                        @selector(closeButtonTapped));
  _objc_msgSend(param_1,@selector(navigationItem));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setRightBarButtonItem:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001e4b08(uVar4,@selector(boolForKey:),
                       @"oledTheme");
  _objc_release(uVar4);
  iStack_64 = iVar3;
  if (iVar3 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(colorWithDynamicProvider:),
                  &PTR___NSConcreteGlobalBlock_01062e00);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setBackgroundColor:),uVar4);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_msgSend(@"Translating",puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_textView),@selector(setText:),uVar4);
  _objc_release(uVar4);
  _objc_msgSend(param_1,@selector(translateText));
  CallSupervisor(0x31a9);
  return;
}



// -[TranslatorVC closeButtonTapped], 0x1e1964
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e1964. closeButtonTapped */

/* Function Stack Size: 0x10 bytes */

void TranslatorVC::closeButtonTapped(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(dismissViewControllerAnimated:completion:),1,0);
  CallSupervisor(0xcb8d);
  return;
}



// -[TranslatorVC tableView:willDisplayHeaderView:forSection:], 0x1e19a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e19a0. tableView:willDisplayHeaderView:forSection: */

/* Function Stack Size: 0x28 bytes */

void TranslatorVC::tableView_willDisplayHeaderView_forSection_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  _objc_retain(param_4);
  puVar2 = PTR__OBJC_CLASS___UIFont_0114ec08;
  puVar1 = @selector(systemFontOfSize:weight:);
  uVar5 = *(undefined8 *)PTR__UIFontWeightSemibold_01060580;
  _objc_retain(param_3);
  _objc_msgSend(0x402a000000000000,uVar5,puVar2,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(textLabel);
  _objc_msgSend(param_4,@selector(textLabel));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setFont:),uVar5);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTextColor:),uVar5);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_msgSend(param_1,@selector(tableView:titleForHeaderInSection:),param_3,param_5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar5,@selector(uppercaseString));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setText:),uVar3);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_msgSend(param_4,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setTextAlignment:),4);
  _objc_release(uVar5);
  _objc_msgSend(param_4,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setNumberOfLines:),0);
  _objc_release(uVar5);
  _objc_release(param_4);
  CallSupervisor(0xe276);
  return;
}



// -[TranslatorVC tableView:heightForRowAtIndexPath:], 0x1e1bd4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e1bd4. tableView:heightForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

double TranslatorVC::tableView_heightForRowAtIndexPath_
                 (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  long lVar1;
  long lVar2;
  double dVar3;
  
  lVar1 = _objc_msgSend(param_4,@selector(section));
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_translation));
  dVar3 = DAT_00c4c238;
  if (lVar1 != lVar2) {
    dVar3 = *(double *)PTR__UITableViewAutomaticDimension_010605d8;
  }
  return dVar3;
}



// -[TranslatorVC numberOfSectionsInTableView:], 0x1e1c44
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e1c44. numberOfSectionsInTableView: */

/* Function Stack Size: 0x18 bytes */

long_long TranslatorVC::numberOfSectionsInTableView_(ID param_1,SEL param_2,ID param_3)

{
  long_long lVar1;
  
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(count));
  return lVar1;
}



// -[TranslatorVC tableView:numberOfRowsInSection:], 0x1e1c5c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e1c5c. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long TranslatorVC::tableView_numberOfRowsInSection_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  long_long lVar2;
  
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(objectAtIndexedSubscript:),
                param_4);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,@selector(count));
  _objc_release(uVar1);
  return lVar2;
}



// -[TranslatorVC tableView:cellForRowAtIndexPath:], 0x1e1cb8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e1cb8. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID TranslatorVC::tableView_cellForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  ID IVar15;
  undefined *puVar16;
  undefined8 uVar17;
  undefined *puVar18;
  long lVar19;
  undefined8 auStack_210 [6];
  undefined8 auStack_1e0 [4];
  undefined8 auStack_1c0 [2];
  undefined8 auStack_1b0 [2];
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined *puStack_180;
  undefined *puStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined8 *puStack_140;
  undefined8 *puStack_138;
  undefined8 uStack_130;
  undefined8 *puStack_128;
  ID IStack_120;
  undefined **local_118;
  undefined **local_110;
  undefined **ppuStack_108;
  int iStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **ppuStack_d8;
  uint uStack_cc;
  undefined **local_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011ba7b8;
  local_8c = (uint)(DAT_01227e44 == 0);
  local_a0 = &PTR_LAB_011ba7d8;
  local_b8 = &PTR_LAB_011ba7f8;
  local_c8 = &PTR_LAB_011ba810;
  local_98 = &PTR_LAB_011ba600;
  local_b0 = &PTR_LAB_011ba600;
  local_e0 = &PTR_LAB_011ba830;
  ppuStack_d8 = &PTR_LAB_011ba600;
  local_f8 = &PTR_LAB_011ba850;
  ppuStack_f0 = &PTR_LAB_011ba600;
  local_110 = &PTR_LAB_011ba600;
  ppuStack_108 = &PTR_LAB_011ba600;
  local_118 = &PTR_LAB_011ba600;
  DAT_01227e44 = 1;
  puStack_140 = auStack_1b0;
  puStack_138 = auStack_1e0;
  puStack_128 = auStack_210;
  _objc_retain(param_4);
  _objc_msgSend(param_3,@selector(dequeueReusableCellWithIdentifier:),
                @"cell");
  lVar4 = _objc_retainAutoreleasedReturnValue();
  uStack_a4 = (uint)(lVar4 == 0);
  if (lVar4 == 0) {
    uVar5 = _objc_alloc(local_a0[uStack_a4] + (int)-(DAT_011ba7e8 ^ 0x64d0ba4c),
                        PTR__OBJC_CLASS___UITableViewCell_0114ec80);
    lVar4 = _objc_msgSend(uVar5,@selector(initWithStyle:reuseIdentifier:),3,
                          @"cell");
  }
  puVar18 = @selector(section);
  lVar19 = (long)_sections;
  uVar17 = *(undefined8 *)(param_1 + lVar19);
  uVar5 = _objc_msgSend(param_4,@selector(section));
  puVar16 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar17,@selector(objectAtIndexedSubscript:),uVar5);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_bc = (uint)(lVar6 == 0);
  IStack_120 = param_4;
  if (lVar6 == 0) {
    _objc_retain(local_b8[uStack_bc] + (int)-(uRam00000000011ba808 ^ 0xac027753),lVar4);
  }
  else {
    uVar17 = *(undefined8 *)(param_1 + lVar19);
    uVar5 = _objc_msgSend(param_4,puVar18);
    _objc_msgSend(uVar17,puVar16,uVar5);
    uVar17 = _objc_retainAutoreleasedReturnValue();
    uVar5 = _objc_msgSend(param_4,@selector(row));
    _objc_msgSend(uVar17,puVar16,uVar5);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar17);
    uVar17 = _objc_alloc(PTR__OBJC_CLASS___UITableViewCell_0114ec80);
    puVar18 = @selector(objectForKeyedSubscript:);
    _objc_msgSend(uVar5,@selector(objectForKeyedSubscript:),
                  @"id");
    uVar7 = _objc_retainAutoreleasedReturnValue();
    lVar6 = _objc_msgSend(uVar17,@selector(initWithStyle:reuseIdentifier:),3,uVar7);
    _objc_release(lVar4);
    _objc_release(uVar7);
    _objc_msgSend(uVar5,puVar18,@"type");
    uVar17 = _objc_retainAutoreleasedReturnValue();
    puVar16 = @selector(isEqualToString:);
    uVar2 = FUN_001e5e80(uVar17,@selector(isEqualToString:),
                         @"menu");
    _objc_release(uVar17);
    puStack_148 = puVar16;
    uStack_130 = uVar5;
    uStack_cc = uVar2;
    if (uVar2 != 0) {
      _objc_msgSend(local_c8[uVar2] + (int)-(uRam00000000011ba820 ^ 0xe1b2e358),uVar5,puVar18,
                    @"title");
      uVar17 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(ytl_localized);
      _objc_msgSend(uVar17,@selector(ytl_localized));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(textLabel);
      _objc_msgSend(lVar6,@selector(textLabel));
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,@selector(setText:),uVar7);
      uVar5 = uStack_130;
      _objc_release(uVar10);
      _objc_release(uVar7);
      _objc_release(uVar17);
      _objc_msgSend(lVar6,puVar16);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,@selector(setNumberOfLines:),0);
      _objc_release(uVar17);
      _objc_msgSend(uVar5,puVar18,@"title");
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar18,@"indexes");
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,@selector(menuButtonWithTitle:array:),uVar7,uVar10);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar6,@selector(setAccessoryView:),uVar11);
      _objc_release(uVar11);
      _objc_release(uVar10);
      _objc_release(uVar7);
      _objc_release(uVar17);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(systemBackgroundColor));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar6,@selector(setBackgroundColor:),uVar17);
      _objc_release(uVar17);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(systemGrayColor));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(DAT_00c4c2f0,uVar17,@selector(colorWithAlphaComponent:));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar10 = _objc_retainAutorelease();
      uVar10 = _objc_msgSend(uVar10,@selector(CGColor));
      puVar1 = @selector(layer);
      _objc_msgSend(lVar6,@selector(layer));
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar16 = puStack_148;
      _objc_msgSend(uVar11,@selector(setBorderColor:),uVar10);
      _objc_release(uVar11);
      _objc_release(uVar7);
      _objc_release(uVar17);
      _objc_msgSend(lVar6,puVar1);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x3ff0000000000000,uVar17,@selector(setBorderWidth:));
      _objc_release(uVar17);
    }
    _objc_msgSend(uVar5,puVar18,@"type");
    uVar17 = _objc_retainAutoreleasedReturnValue();
    uVar2 = FUN_001e5478(uVar17,puVar16,@"textView");
    _objc_release(uVar17);
    uStack_e4 = uVar2;
    if (uVar2 != 0) {
      _objc_msgSend(local_e0[uVar2] + (int)-(uRam00000000011ba840 ^ 0x49293ac6),
                    PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar6,@selector(setBackgroundColor:),uVar5);
      _objc_release(uVar5);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(systemGrayColor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(DAT_00c4c2f0,uVar5,@selector(colorWithAlphaComponent:));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      uVar7 = _objc_retainAutorelease();
      uVar7 = _objc_msgSend(uVar7,@selector(CGColor));
      puVar16 = @selector(layer);
      _objc_msgSend(lVar6,@selector(layer));
      uVar10 = _objc_retainAutoreleasedReturnValue();
      puStack_150 = puVar18;
      _objc_msgSend(uVar10,@selector(setBorderColor:),uVar7);
      _objc_release(uVar10);
      _objc_release(uVar17);
      _objc_release(uVar5);
      _objc_msgSend(lVar6,puVar16);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x3ff0000000000000,uVar5,@selector(setBorderWidth:));
      _objc_release(uVar5);
      uVar5 = _objc_alloc_init(PTR__OBJC_CLASS___UITextView_0114ee78);
      lVar4 = (long)_textView;
      uVar17 = *(undefined8 *)(param_1 + lVar4);
      *(undefined8 *)(param_1 + lVar4) = uVar5;
      _objc_release(uVar17);
      _objc_msgSend(PTR__OBJC_CLASS___UIFont_0114ec08,@selector(preferredFontForTextStyle:),
                    *(undefined8 *)PTR__UIFontTextStyleBody_01060558);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setFont:),uVar5);
      _objc_release(uVar5);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setEditable:),0);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setSelectable:),1);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setDataDetectorTypes:),2);
      auStack_1c0[0] = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
      _objc_msgSend(param_1,@selector(view));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(tintColor));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      puVar9 = puStack_140;
      *puStack_140 = uVar17;
      _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                    @selector(dictionaryWithObjects:forKeys:count:),puVar9,auStack_1c0,1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setLinkTextAttributes:),uVar7);
      _objc_release(uVar7);
      _objc_release(uVar17);
      _objc_release(uVar5);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setTranslatesAutoresizingMaskIntoConstraints:)
                    ,0);
      puVar1 = @selector(contentView);
      _objc_msgSend(lVar6,@selector(contentView));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(addSubview:),*(undefined8 *)(param_1 + lVar4));
      _objc_release(uVar5);
      puVar16 = @selector(leadingAnchor);
      puStack_180 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(leadingAnchor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uStack_158 = uVar5;
      _objc_msgSend(lVar6,puVar1);
      puStack_140 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puStack_140,puVar16);
      uStack_160 = _objc_retainAutoreleasedReturnValue();
      puVar18 = @selector(constraintEqualToAnchor:);
      _objc_msgSend(uVar5,@selector(constraintEqualToAnchor:),uStack_160);
      uStack_168 = _objc_retainAutoreleasedReturnValue();
      puVar9 = puStack_138;
      puVar16 = @selector(trailingAnchor);
      *puStack_138 = uStack_168;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(trailingAnchor));
      puVar8 = (undefined *)_objc_retainAutoreleasedReturnValue();
      puStack_178 = puVar8;
      _objc_msgSend(lVar6,puVar1);
      uStack_170 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_170,puVar16);
      uStack_188 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar8,puVar18,uStack_188);
      uStack_190 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(topAnchor);
      puVar9[1] = uStack_190;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(topAnchor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uStack_1a0 = uVar5;
      _objc_msgSend(lVar6,puVar1);
      uStack_198 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_198,puVar16);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar18,uVar17);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(bottomAnchor);
      puVar9[2] = uVar5;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(bottomAnchor));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar6,puVar1);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,puVar16);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar18,uVar11);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      puVar9[3] = uVar12;
      _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puVar9
                    ,4);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puStack_180,@selector(activateConstraints:),uVar13);
      _objc_release(uVar13);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_release(uVar10);
      puVar18 = puStack_150;
      _objc_release(uVar7);
      puVar16 = puStack_148;
      _objc_release(uVar5);
      uVar5 = uStack_130;
      _objc_release(uVar17);
      _objc_release(uStack_198);
      _objc_release(uStack_1a0);
      _objc_release(uStack_190);
      _objc_release(uStack_188);
      _objc_release(uStack_170);
      _objc_release(puStack_178);
      _objc_release(uStack_168);
      _objc_release(uStack_160);
      _objc_release(puStack_140);
      _objc_release(uStack_158);
    }
    _objc_msgSend(uVar5,puVar18,@"key");
    uVar17 = _objc_retainAutoreleasedReturnValue();
    iVar3 = FUN_001e53f0(uVar17,puVar16,@"translateText");
    _objc_release(uVar17);
    iStack_fc = iVar3;
    if (iVar3 != 0) {
      _objc_msgSend(lVar6,@selector(textLabel));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,@selector(setText:),0);
      _objc_release(uVar17);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(setBackgroundColor:);
      _objc_msgSend(lVar6,@selector(setBackgroundColor:),uVar17);
      _objc_release(uVar17);
      _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,@selector(buttonWithType:),1);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      lVar4 = (long)_translateButton;
      uVar7 = *(undefined8 *)(param_1 + lVar4);
      *(undefined8 *)(param_1 + lVar4) = uVar17;
      _objc_release(uVar7);
      uVar7 = *(undefined8 *)(param_1 + lVar4);
      _objc_msgSend(uVar5,puVar18,@"title");
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,@selector(setTitle:forState:),uVar17,0);
      _objc_release(uVar17);
      uVar7 = *(undefined8 *)(param_1 + lVar4);
      _objc_msgSend(uVar5,puVar18,@"key");
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uVar17 = _NSSelectorFromString();
      _objc_msgSend(uVar7,@selector(addTarget:action:forControlEvents:),param_1,uVar17,0x40);
      _objc_release(uVar5);
      _objc_msgSend(param_1,@selector(view));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(tintColor));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),puVar16,uVar17);
      _objc_release(uVar17);
      _objc_release(uVar5);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setTranslatesAutoresizingMaskIntoConstraints:)
                    ,0);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setTintColor:),uVar5);
      _objc_release(uVar5);
      puVar16 = @selector(titleLabel);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(titleLabel));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(setTextAlignment:),1);
      _objc_release(uVar5);
      _objc_msgSend(0x4031000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                    @selector(boldSystemFontOfSize:));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),puVar16);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,@selector(setFont:),uVar5);
      _objc_release(uVar17);
      _objc_release(uVar5);
      puVar16 = @selector(layer);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(layer));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x4024000000000000,uVar5,@selector(setCornerRadius:));
      _objc_release(uVar5);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),puVar16);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(setMasksToBounds:),1);
      _objc_release(uVar5);
      puVar1 = @selector(contentView);
      _objc_msgSend(lVar6,@selector(contentView));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(addSubview:),*(undefined8 *)(param_1 + lVar4));
      _objc_release(uVar5);
      puVar16 = @selector(leadingAnchor);
      puStack_178 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(leadingAnchor));
      puVar9 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
      puStack_140 = puVar9;
      _objc_msgSend(lVar6,puVar1);
      puStack_138 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puStack_138,puVar16);
      puStack_148 = (undefined *)_objc_retainAutoreleasedReturnValue();
      puVar18 = @selector(constraintEqualToAnchor:);
      _objc_msgSend(puVar9,@selector(constraintEqualToAnchor:),puStack_148);
      puStack_150 = (undefined *)_objc_retainAutoreleasedReturnValue();
      puVar9 = puStack_128;
      puVar16 = @selector(trailingAnchor);
      *puStack_128 = puStack_150;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(trailingAnchor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uStack_160 = uVar5;
      _objc_msgSend(lVar6,puVar1);
      uStack_158 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_158,puVar16);
      uStack_168 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar18,uStack_168);
      uStack_170 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(topAnchor);
      puVar9[1] = uStack_170;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(topAnchor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uStack_188 = uVar5;
      _objc_msgSend(lVar6,puVar1);
      puStack_180 = (undefined *)_objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puStack_180,puVar16);
      uStack_190 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar18,uStack_190);
      uStack_198 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(bottomAnchor);
      puVar9[2] = uStack_198;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(bottomAnchor));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uStack_1a0 = uVar5;
      _objc_msgSend(lVar6,puVar1);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,puVar16);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar18,uVar7);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      puVar9[3] = uVar10;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(heightAnchor));
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar16 = @selector(constraintEqualToConstant:);
      uVar5 = DAT_00c4c358;
      _objc_msgSend(DAT_00c4c358,uVar11,@selector(constraintEqualToConstant:));
      uVar12 = _objc_retainAutoreleasedReturnValue();
      puVar9[4] = uVar12;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(widthAnchor));
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,uVar13,puVar16);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puVar9[5] = uVar14;
      _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puVar9
                    ,6);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puStack_178,@selector(activateConstraints:),uVar5);
      _objc_release(uVar5);
      uVar5 = uStack_130;
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_release(uVar10);
      _objc_release(uVar7);
      _objc_release(uVar17);
      _objc_release(uStack_1a0);
      _objc_release(uStack_198);
      _objc_release(uStack_190);
      _objc_release(puStack_180);
      _objc_release(uStack_188);
      _objc_release(uStack_170);
      _objc_release(uStack_168);
      _objc_release(uStack_158);
      _objc_release(uStack_160);
      _objc_release(puStack_150);
      _objc_release(puStack_148);
      _objc_release(puStack_138);
      _objc_release(puStack_140);
    }
    _objc_retain(lVar6);
    _objc_release(uVar5);
    lVar4 = lVar6;
  }
  _objc_release(lVar4);
  _objc_release(IStack_120);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar15 = _objc_autoreleaseReturnValue(lVar4);
  return IVar15;
}



// -[TranslatorVC menuButtonWithTitle:array:], 0x1e3458
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e3458. menuButtonWithTitle:array: */

/* Function Stack Size: 0x20 bytes */

ID TranslatorVC::menuButtonWithTitle_array_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  ID IVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ID IVar12;
  undefined *puVar13;
  long lVar14;
  undefined *puStack_230;
  undefined8 uStack_228;
  code *pcStack_220;
  undefined *puStack_218;
  ID IStack_210;
  long lStack_208;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  ID IStack_138;
  undefined *puStack_130;
  undefined1 *puStack_128;
  long lStack_120;
  long lStack_118;
  undefined8 uStack_110;
  ID local_108;
  undefined *puStack_100;
  ID local_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011ba880;
  local_8c = (uint)(DAT_01227e48 == 0);
  local_a0 = &PTR_LAB_011ba8a0;
  local_98 = &PTR_LAB_011ba600;
  local_b8 = &PTR_LAB_011ba600;
  ppuStack_b0 = &PTR_LAB_011ba600;
  local_c0 = &PTR_LAB_011ba8c8;
  local_d8 = &PTR_LAB_011ba8e8;
  ppuStack_d0 = &PTR_LAB_011ba600;
  local_e8 = &PTR_LAB_011ba900;
  DAT_01227e48 = 1;
  IStack_138 = param_3;
  local_108 = param_1;
  local_f8 = param_4;
  _objc_retain(param_3);
  IVar4 = local_f8;
  _objc_retain(local_f8);
  _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,@selector(buttonWithType:),1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPDB_0114ecc0,@selector(supportedLanguages));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  IVar12 = local_108;
  lStack_118 = (long)_langIndex;
  _objc_msgSend(uVar8,@selector(objectAtIndexedSubscript:),
                *(undefined8 *)(local_108 + lStack_118));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setTitle:forState:),uVar9,0);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(0x402c000000000000,IVar12,@selector(systemImage:withSize:),
                @"chevron.up.chevron.down");
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setImage:forState:),uVar8,0);
  _objc_release(uVar8);
  iVar6 = FUN_001e6088(IVar12,@selector(isRTL));
  uVar8 = 3;
  if (iVar6 == 0) {
    uVar8 = 4;
  }
  _objc_msgSend(uVar7,@selector(setSemanticContentAttribute:),uVar8);
  _objc_msgSend(0x402a000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                @selector(systemFontOfSize:));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(titleLabel));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,@selector(setFont:),uVar8);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(IVar12,@selector(view));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(tintColor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setTitleColor:forState:),uVar9,0);
  _objc_release(uVar9);
  _objc_release(uVar8);
  uStack_140 = uVar7;
  _objc_msgSend(uVar7,@selector(sizeToFit));
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  uStack_110 = _objc_retainAutoreleasedReturnValue();
  lStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  plStack_170 = (long *)0x0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  uVar8 = _objc_retain(IVar4);
  puStack_130 = @selector(countByEnumeratingWithState:objects:count:);
  puStack_128 = auStack_200;
  lVar10 = _objc_msgSend(uVar8,@selector(countByEnumeratingWithState:objects:count:),&uStack_180,
                         auStack_200,0x10);
  IVar12 = local_108;
  uVar8 = DAT_00c4c228;
  uStack_a4 = (uint)(lVar10 == 0);
  puVar13 = local_a0[uStack_a4] + (int)-(DAT_011ba8b0 ^ 0xec9b3caa);
  if (lVar10 == 0) {
LAB_001e3b48:
    IVar4 = local_f8;
    _objc_release(puVar13,local_f8);
    uVar7 = uStack_110;
    IVar12 = IStack_138;
    _objc_msgSend(PTR__OBJC_CLASS___UIMenu_0114ed00,@selector(menuWithTitle:children:),
                  IStack_138,uStack_110);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar8 = uStack_140;
    _objc_msgSend(uStack_140,@selector(setMenu:),uVar9);
    _objc_release(uVar9);
    _objc_msgSend(uVar8,@selector(setShowsMenuAsPrimaryAction:),1);
    _objc_release(uVar7);
    _objc_release(IVar4);
    _objc_release(IVar12);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar12 = _objc_autoreleaseReturnValue(uVar8);
    return IVar12;
  }
  lStack_120 = *plStack_170;
LAB_001e3958:
  puVar3 = @selector(setState:);
  puVar2 = @selector(actionWithTitle:image:identifier:handler:);
  puVar1 = @selector(addObject:);
  lVar14 = 0;
  puStack_100 = @selector(indexOfObject:);
  uStack_c4 = (uint)(*plStack_170 == lStack_120);
  puVar13 = local_c0[uStack_c4] + (int)-(uRam00000000011ba8d8 ^ 0x2bb8da07);
  if (*plStack_170 == lStack_120) goto LAB_001e39c8;
  do {
    _objc_enumerationMutation(puVar13,local_f8);
LAB_001e39c8:
    do {
      uVar7 = *(undefined8 *)(lStack_178 + lVar14 * 8);
      lVar11 = _objc_msgSend(local_f8,puStack_100,uVar7);
      puStack_230 = PTR___NSConcreteStackBlock_01060660;
      uStack_228 = uVar8;
      pcStack_220 = FUN_001e3c1c;
      puStack_218 = &UNK_01062e20;
      IStack_210 = IVar12;
      lStack_208 = lVar11;
      _objc_msgSend(PTR__OBJC_CLASS___UIAction_0114ec40,puVar2,uVar7,0,0,&puStack_230);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar3,lVar11 == *(long *)(IVar12 + lStack_118));
      _objc_msgSend(uStack_110,puVar1,uVar7);
      _objc_release(uVar7);
      bVar5 = lVar10 + -1 == lVar14;
      uStack_dc = (uint)bVar5;
      if (bVar5) {
        lVar10 = _objc_msgSend(local_f8,puStack_130,&uStack_180,puStack_128,0x10);
        uStack_ec = (uint)(lVar10 == 0);
        puVar13 = local_e8[uStack_ec] + (int)-(uRam00000000011ba910 ^ 0x27262d9f);
        if (lVar10 != 0) goto LAB_001e3958;
        uStack_ec = 1;
        goto LAB_001e3b48;
      }
      lVar14 = lVar14 + 1;
      uStack_c4 = (uint)(*plStack_170 == lStack_120);
      puVar13 = local_c0[uStack_c4] + (int)-(uRam00000000011ba8d8 ^ 0x2bb8da07);
    } while (*plStack_170 == lStack_120);
  } while( true );
}



// -[TranslatorVC systemImage:withSize:], 0x1e3d38
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e3d38. systemImage:withSize: */

/* Function Stack Size: 0x20 bytes */

ID TranslatorVC::systemImage_withSize_(ID param_1,SEL param_2,ID param_3,double param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  double local_48;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(param_4,param_4,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_70 = PTR___NSConcreteGlobalBlock_01060658;
  local_68 = DAT_00c4c2a8;
  local_60 = FUN_001e3e18;
  puStack_58 = &DAT_010624f0;
  local_50 = param_3;
  local_48 = param_4;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(local_50);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}



// -[TranslatorVC isRTL], 0x1e3fa0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e3fa0. isRTL */

/* Function Stack Size: 0x10 bytes */

bool TranslatorVC::isRTL(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  puVar1 = PTR__OBJC_CLASS___UIView_0114ec30;
  _objc_msgSend(param_1,@selector(view));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar2,@selector(semanticContentAttribute));
  lVar4 = _objc_msgSend(puVar1,@selector(userInterfaceLayoutDirectionForSemanticContentAttribute:),uVar3);
  _objc_release(uVar2);
  return (bool)(lVar4 == 1);
}



// -[TranslatorVC translateText], 0x1e400c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e400c. translateText */

/* Function Stack Size: 0x10 bytes */

void TranslatorVC::translateText(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011ba938;
  local_4c = (uint)(DAT_01227e64 == 0);
  local_58 = &PTR_LAB_011ba600;
  DAT_01227e64 = 1;
  _objc_msgSend(@"Translating",@selector(ytl_localized));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar4 = (long)_textView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setText:),uVar2);
  _objc_release(uVar2);
  _objc_msgSend(param_1,@selector(tableView));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(tintColor));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar4),@selector(setTextColor:),uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = PTR_YTPTranslator_0114efc0;
  uVar3 = *(undefined8 *)(param_1 + (long)_sourceText);
  _objc_msgSend(PTR_YTPDB_0114ecc0,@selector(langCodeForIndex:),
                *(undefined8 *)(param_1 + (long)_langIndex));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_001e431c;
  puStack_78 = &DAT_010623d0;
  IStack_70 = param_1;
  _objc_msgSend(puVar1,@selector(translateText:fromLanguage:toLanguage:completion:),uVar3,
                @"auto",uVar2,&puStack_90);
  _objc_release(uVar2);
  CallSupervisor(0x6543);
  return;
}



// -[TranslatorVC tableView:shouldHighlightRowAtIndexPath:], 0x1e46fc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e46fc. tableView:shouldHighlightRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool TranslatorVC::tableView_shouldHighlightRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  return 0;
}



// -[TranslatorVC tableView:didSelectRowAtIndexPath:], 0x1e4704
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e4704. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void TranslatorVC::tableView_didSelectRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  _objc_msgSend(param_3,@selector(deselectRowAtIndexPath:animated:),param_4,1);
  return;
}



// -[TranslatorVC .cxx_destruct], 0x1e471c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1e471c. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void TranslatorVC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_translate,0);
  _objc_storeStrong(param_1 + (long)_translation,0);
  _objc_storeStrong(param_1 + (long)_type,0);
  _objc_storeStrong(param_1 + (long)_sections,0);
  _objc_storeStrong(param_1 + (long)_sourceText,0);
  _objc_storeStrong(param_1 + (long)_textView,0);
  _objc_storeStrong(param_1 + (long)_translateButton,0);
  _objc_storeStrong(param_1 + (long)_tableView,0);
  return;
}


