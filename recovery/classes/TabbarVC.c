// Decompiled implementation evidence for TabbarVC. Not compilable source.

// -[TabbarVC init], 0x12ea7c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12ea7c. init */

/* Function Stack Size: 0x10 bytes */

ID TabbarVC::init(ID param_1,SEL param_2)

{
  ID IVar1;
  
  IVar1 = _objc_msgSend(param_1,@selector(initForSettings:),1);
  return IVar1;
}



// -[TabbarVC initForSettings:], 0x12ea8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12ea8c. initForSettings: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x14 bytes */

ID TabbarVC::initForSettings_(ID param_1,SEL param_2,bool param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ID IVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined8 auStack_560 [4];
  undefined8 auStack_540 [4];
  undefined8 auStack_520 [4];
  undefined8 auStack_500 [4];
  undefined8 auStack_4e0 [4];
  undefined8 auStack_4c0 [4];
  undefined8 auStack_4a0 [4];
  undefined8 auStack_480 [4];
  undefined8 auStack_460 [4];
  undefined8 auStack_440 [4];
  undefined8 auStack_420 [2];
  undefined8 auStack_410 [2];
  undefined8 auStack_400 [2];
  undefined8 auStack_3f0 [2];
  undefined8 auStack_3e0 [2];
  undefined8 auStack_3d0 [2];
  undefined8 auStack_3c0 [2];
  undefined8 auStack_3b0 [2];
  undefined8 auStack_3a0 [2];
  undefined8 auStack_390 [2];
  undefined8 auStack_380 [2];
  undefined8 auStack_370 [2];
  undefined8 auStack_360 [2];
  undefined8 auStack_350 [2];
  undefined8 auStack_340 [2];
  undefined8 auStack_330 [2];
  undefined8 auStack_320 [2];
  undefined8 auStack_310 [2];
  undefined8 auStack_300 [2];
  undefined8 auStack_2f0 [2];
  undefined8 auStack_2e0 [2];
  undefined8 auStack_2d0 [2];
  undefined8 auStack_2c0 [2];
  undefined8 auStack_2b0 [2];
  undefined8 auStack_2a0 [2];
  undefined **ppuStack_290;
  undefined **ppuStack_288;
  undefined8 auStack_280 [2];
  undefined **ppuStack_270;
  undefined **ppuStack_268;
  undefined **ppuStack_260;
  undefined **ppuStack_258;
  undefined8 uStack_250;
  undefined8 *puStack_248;
  undefined8 *puStack_240;
  undefined8 *puStack_238;
  undefined8 *puStack_230;
  undefined8 *puStack_228;
  undefined8 *puStack_220;
  undefined8 *puStack_218;
  undefined8 *puStack_210;
  undefined8 *puStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  ID IStack_1e0;
  undefined *puStack_1d8;
  undefined8 *puStack_1c8;
  undefined8 *puStack_1c0;
  undefined8 *puStack_1b8;
  undefined8 uStack_1b0;
  undefined8 *puStack_1a8;
  undefined8 *puStack_1a0;
  undefined8 *puStack_198;
  undefined8 *puStack_190;
  undefined8 *puStack_188;
  undefined8 *puStack_180;
  undefined8 *puStack_178;
  undefined8 *puStack_170;
  undefined8 *puStack_168;
  undefined8 *puStack_160;
  undefined8 *puStack_158;
  undefined8 *puStack_150;
  undefined8 *puStack_148;
  undefined8 *puStack_140;
  undefined8 *puStack_138;
  undefined8 *puStack_130;
  undefined8 *puStack_128;
  undefined8 *puStack_120;
  undefined8 *puStack_118;
  undefined8 *puStack_110;
  undefined8 *puStack_108;
  undefined8 *puStack_100;
  undefined8 *puStack_f8;
  undefined8 *puStack_f0;
  undefined8 *puStack_e8;
  undefined8 *puStack_e0;
  undefined8 *puStack_d8;
  undefined8 *puStack_d0;
  undefined8 *puStack_c8;
  undefined8 *puStack_c0;
  undefined8 *puStack_b8;
  undefined8 *puStack_b0;
  undefined8 *puStack_a8;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118fe40;
  local_7c = (uint)(DAT_012273cc == 0);
  local_90 = &PTR_LAB_0118fe60;
  ppuStack_88 = &PTR_LAB_0118faf0;
  local_a0 = &PTR_LAB_0118faf0;
  DAT_012273cc = 1;
  puStack_1a0 = auStack_280;
  puStack_190 = auStack_2a0;
  puStack_198 = auStack_2b0;
  puStack_180 = auStack_2c0;
  puStack_188 = auStack_2d0;
  puStack_170 = auStack_2e0;
  puStack_178 = auStack_2f0;
  puStack_160 = auStack_300;
  puStack_168 = auStack_310;
  puStack_150 = auStack_320;
  puStack_158 = auStack_330;
  puStack_140 = auStack_340;
  puStack_148 = auStack_350;
  puStack_130 = auStack_360;
  puStack_138 = auStack_370;
  puStack_120 = auStack_380;
  puStack_128 = auStack_390;
  puStack_110 = auStack_3a0;
  puStack_118 = auStack_3b0;
  puStack_100 = auStack_3c0;
  puStack_108 = auStack_3d0;
  puStack_f8 = auStack_3f0;
  puStack_e0 = auStack_420;
  puStack_e8 = auStack_440;
  puStack_f0 = auStack_460;
  puStack_a8 = auStack_480;
  puStack_d0 = auStack_4a0;
  puStack_d8 = auStack_4c0;
  puStack_c0 = auStack_4e0;
  puStack_c8 = auStack_500;
  puStack_b0 = auStack_520;
  puStack_b8 = auStack_540;
  puStack_1d8 = PTR_TabbarVC_0114f0b0;
  IStack_1e0 = param_1;
  IVar6 = _objc_msgSendSuper2(&IStack_1e0,@selector(initWithStyle:),1);
  uStack_94 = (uint)(IVar6 == 0);
  if (IVar6 != 0) {
    *(char *)(IVar6 + (long)__isSettings) = (char)param_3;
    puVar1 = @selector(dictionaryWithObjects:forKeys:count:);
    ppuStack_270 = @"type";
    ppuStack_268 = @"key";
    ppuStack_260 = @"tab";
    ppuStack_258 = @"FEwhat_to_watch";
    puStack_1c8 = auStack_3e0;
    puStack_1c0 = auStack_400;
    puStack_1b8 = auStack_410;
    puStack_1a8 = auStack_560;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  @selector(dictionaryWithObjects:forKeys:count:),&ppuStack_260,&ppuStack_270,2);
    uStack_250 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_1a0;
    ppuStack_290 = @"type";
    ppuStack_288 = @"key";
    uStack_1b0 = uStack_250;
    *puStack_1a0 = @"tab";
    puVar3[1] = @"FEshorts";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar3,&ppuStack_290,2);
    puStack_248 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_198;
    puStack_1a0 = puStack_248;
    *puStack_198 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_190;
    *puStack_190 = @"tab";
    puVar4[1] = @"FEsubscriptions";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_240 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_188;
    puStack_190 = puStack_240;
    *puStack_188 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_180;
    *puStack_180 = @"tab";
    puVar4[1] = @"FElibrary";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_238 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_178;
    puStack_180 = puStack_238;
    *puStack_178 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_170;
    *puStack_170 = @"tab";
    puVar4[1] = @"FEhistory";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_230 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_168;
    puStack_170 = puStack_230;
    *puStack_168 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_160;
    *puStack_160 = @"tab";
    puVar4[1] = @"FEpost_home";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_228 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_158;
    puStack_160 = puStack_228;
    *puStack_158 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_150;
    *puStack_150 = @"tab";
    puVar4[1] = @"VLWL";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_220 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_148;
    puStack_150 = puStack_220;
    *puStack_148 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_140;
    *puStack_140 = @"tab";
    puVar4[1] = @"FEhype_leaderboard";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_218 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_138;
    puStack_140 = puStack_218;
    *puStack_138 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_130;
    *puStack_130 = @"tab";
    puVar4[1] = @"UC-9-kyTW8ZkZNDHQJ6FgpwQ";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_210 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_128;
    puStack_130 = puStack_210;
    *puStack_128 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_120;
    *puStack_120 = @"tab";
    puVar4[1] = @"UC4R8DWoMoI7CAwX8_LjQHig";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    puStack_208 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_118;
    puStack_120 = puStack_208;
    *puStack_118 = @"type";
    puVar3[1] = @"key";
    puVar4 = puStack_110;
    *puStack_110 = @"tab";
    puVar4[1] = @"UCOpNcN46UbXVtpKMrmU4Abg";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar4 = puStack_100;
    puVar3 = puStack_108;
    uStack_200 = uVar7;
    *puStack_108 = @"type";
    puVar3[1] = @"key";
    *puVar4 = @"tab";
    puVar4[1] = @"UCEgdi0XIXXZ-qJOFPf4JSKw";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,2);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar4 = puStack_f8;
    uStack_1f8 = uVar8;
    *puStack_f8 = @"type";
    puVar4[1] = @"key";
    puVar3 = puStack_1c8;
    *puStack_1c8 = @"tab";
    puVar3[1] = @"FEnotifications_inbox";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar3,puVar4,2);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar4 = puStack_1b8;
    uStack_1f0 = uVar9;
    *puStack_1b8 = @"type";
    puVar4[1] = @"key";
    puVar3 = puStack_1c0;
    *puStack_1c0 = @"tab";
    puVar3[1] = @"FEuploads";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar3,puVar4,2);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(arrayWithObjects:count:);
    puStack_f8 = (undefined8 *)@selector(arrayWithObjects:count:);
    uStack_1e8 = uVar10;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_250,0xe);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    uVar12 = *(undefined8 *)(IVar6 + (long)_tabs);
    *(undefined8 *)(IVar6 + (long)_tabs) = uVar11;
    _objc_release(uVar12);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(puStack_120);
    _objc_release(puStack_130);
    _objc_release(puStack_140);
    _objc_release(puStack_150);
    _objc_release(puStack_160);
    _objc_release(puStack_170);
    _objc_release(puStack_180);
    _objc_release(puStack_190);
    _objc_release(puStack_1a0);
    _objc_release(uStack_1b0);
    puVar4 = puStack_e8;
    puVar3 = puStack_f0;
    *puStack_f0 = @"type";
    puVar3[1] = @"key";
    *puVar4 = @"int";
    puVar4[1] = @"startupTab";
    puVar3[2] = @"id";
    puVar4[2] = @"startupCell";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar3 = puStack_e0;
    *puStack_e0 = uVar7;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar2,puVar3,1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puStack_e0 = (undefined8 *)(long)_startup;
    uVar9 = *(undefined8 *)(IVar6 + (long)puStack_e0);
    *(undefined8 *)(IVar6 + (long)puStack_e0) = uVar8;
    _objc_release(uVar9);
    _objc_release(uVar7);
    puVar4 = puStack_d0;
    puVar3 = puStack_d8;
    *puStack_d8 = @"title";
    puVar3[1] = @"type";
    *puVar4 = @"TranslucentBar";
    puVar4[1] = @"bool";
    puVar3[2] = @"key";
    puVar3[3] = @"id";
    puVar4[2] = @"frostedPivot";
    puVar4[3] = @"tabbarCell";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar5 = puStack_a8;
    *puStack_a8 = uVar7;
    puVar4 = puStack_c0;
    puVar3 = puStack_c8;
    *puStack_c8 = @"title";
    puVar3[1] = @"type";
    *puVar4 = @"RemoveLabels";
    puVar4[1] = @"bool";
    puVar3[2] = @"key";
    puVar3[3] = @"id";
    puVar4[2] = @"removeLabels";
    puVar4[3] = @"tabbarCell";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,4);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar5[1] = uVar8;
    puVar4 = puStack_b0;
    puVar3 = puStack_b8;
    *puStack_b8 = @"title";
    puVar3[1] = @"type";
    *puVar4 = @"RemoveIndicators";
    puVar4[1] = @"bool";
    puVar3[2] = @"key";
    puVar3[3] = @"id";
    puVar4[2] = @"removeIndicators";
    puVar4[3] = @"tabbarCell";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar4,puVar3,4);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar5[2] = uVar9;
    puVar4 = puStack_f8;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_f8,puVar5,3);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    lVar15 = (long)_tabbar;
    uVar11 = *(undefined8 *)(IVar6 + lVar15);
    *(undefined8 *)(IVar6 + lVar15) = uVar10;
    _objc_release(uVar11);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    puVar1 = @selector(mutableCopy);
    uVar9 = *(undefined8 *)PTR____NSArray0___01060670;
    uVar7 = _objc_msgSend(uVar9,@selector(mutableCopy));
    lVar14 = (long)_activeTabs;
    uVar8 = *(undefined8 *)(IVar6 + lVar14);
    *(undefined8 *)(IVar6 + lVar14) = uVar7;
    _objc_release(uVar8);
    uVar7 = _objc_msgSend(uVar9,puVar1);
    lVar13 = (long)_inactiveTabs;
    uVar8 = *(undefined8 *)(IVar6 + lVar13);
    *(undefined8 *)(IVar6 + lVar13) = uVar7;
    _objc_release(uVar8);
    puVar3 = puStack_1a8;
    *puStack_1a8 = *(undefined8 *)(IVar6 + lVar15);
    puVar3[1] = *(undefined8 *)(IVar6 + (long)puStack_e0);
    puVar3[2] = *(undefined8 *)(IVar6 + lVar14);
    puVar3[3] = *(undefined8 *)(IVar6 + lVar13);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar4,puVar3,4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = *(undefined8 *)(IVar6 + (long)_sections);
    *(undefined8 *)(IVar6 + (long)_sections) = uVar7;
    _objc_release(uVar8);
    puVar1 = @selector(tableView);
    _objc_msgSend(IVar6,@selector(tableView));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setEditing:animated:),1,0);
    _objc_release(uVar7);
    _objc_msgSend(IVar6,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setAllowsSelectionDuringEditing:),1);
    _objc_release(uVar7);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar6;
}



// -[TabbarVC loadView], 0x130ce0
/* Decompiled from supplied 5.2.2 arm package. VA 0x130ce0. loadView */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

void TabbarVC::loadView(ID param_1,SEL param_2)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IStack_70;
  undefined *puStack_68;
  undefined **local_60;
  uint uStack_54;
  undefined **local_50;
  undefined **ppuStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR__objc_msgSend_0118fe80;
  local_3c = (uint)(DAT_012273d0 == 0);
  local_50 = &PTR_LAB_0118fea0;
  ppuStack_48 = &PTR_LAB_0118faf0;
  local_60 = &PTR_LAB_0118faf0;
  DAT_012273d0 = 1;
  puStack_68 = PTR_TabbarVC_0114f0b0;
  IStack_70 = param_1;
  _objc_msgSendSuper2(&IStack_70,@selector(loadView));
  _objc_msgSend(param_1,@selector(initTabs));
  bVar1 = *(char *)(param_1 + (long)__isSettings) == '\0';
  uStack_54 = (uint)bVar1;
  if (bVar1) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(localizedStringForKey:value:table:),
                  @"Tabbar",0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(setTitle:),uVar3);
    _objc_release(uVar3);
    _objc_release(uVar2);
    uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
    uVar2 = _objc_msgSend(uVar2,@selector(initWithBarButtonSystemItem:target:action:),0x18,param_1,
                          @selector(closeButtonTapped));
    _objc_msgSend(param_1,@selector(navigationItem));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setRightBarButtonItem:),uVar2);
    _objc_release(uVar3);
    _objc_release(uVar2);
  }
  CallSupervisor(0x938a);
  return;
}



// -[TabbarVC closeButtonTapped], 0x130f4c
/* Decompiled from supplied 5.2.2 arm package. VA 0x130f4c. closeButtonTapped */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::closeButtonTapped(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(dismissViewControllerAnimated:completion:),1,0);
  CallSupervisor(0xa175);
  return;
}



// -[TabbarVC initTabs], 0x130f88
/* Decompiled from supplied 5.2.2 arm package. VA 0x130f88. initTabs */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::initTabs(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  long lStack_180;
  long lStack_178;
  ID IStack_170;
  undefined1 *puStack_168;
  undefined *puStack_160;
  undefined8 uStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined *puStack_140;
  long lStack_138;
  undefined *puStack_130;
  undefined *puStack_128;
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
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  puVar1 = @selector(removeAllObjects);
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118fec0;
  local_7c = (uint)(DAT_012273d8 == 0);
  local_90 = &PTR_LAB_0118fee0;
  local_a0 = &PTR_LAB_0118fef8;
  local_88 = &PTR_LAB_0118faf0;
  local_b8 = &PTR_LAB_0118faf0;
  ppuStack_b0 = &PTR_LAB_0118faf0;
  local_c0 = &PTR_LAB_0118ff20;
  local_d8 = &PTR_LAB_0118ff40;
  ppuStack_d0 = &PTR_LAB_0118faf0;
  local_f0 = &PTR_LAB_0118ff60;
  ppuStack_e8 = &PTR_LAB_0118faf0;
  local_100 = &PTR_LAB_0118ff78;
  local_110 = &PTR_LAB_0118faf0;
  DAT_012273d8 = 1;
  lVar5 = (long)_activeTabs;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),@selector(removeAllObjects));
  lVar6 = (long)_inactiveTabs;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(objectForKey:),@"activeTabs");
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  uStack_158 = _objc_retainAutoreleasedReturnValue();
  uStack_118 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_tabs),@selector(mutableCopy));
  uStack_94 = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    uStack_198 = 0;
    uStack_1a0 = 0;
    uStack_188 = 0;
    uStack_190 = 0;
    puStack_1b8 = (undefined8 *)0x0;
    uStack_1c0 = 0;
    uStack_1a8 = 0;
    plStack_1b0 = (long *)0x0;
    lStack_180 = lVar6;
    lStack_178 = lVar5;
    IStack_170 = param_1;
    uVar3 = _objc_retain(lVar4);
    puStack_160 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar3,@selector(countByEnumeratingWithState:objects:count:),&uStack_1c0,
                          auStack_240,0x10);
    uStack_a4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      lStack_138 = *plStack_1b0;
      puStack_120 = @selector(predicateWithFormat:);
      puStack_128 = @selector(filteredArrayUsingPredicate:);
      puStack_130 = @selector(count);
      puStack_140 = @selector(firstObject);
      puStack_148 = @selector(addObject:);
      puStack_150 = @selector(removeObject:);
      uStack_c4 = (uint)(*plStack_1b0 == lStack_138);
      puStack_168 = auStack_240;
      if (*plStack_1b0 != lStack_138) {
        _objc_enumerationMutation
                  (local_c0[uStack_c4] + (int)-(uRam000000000118ff30 ^ 0x47682186),lVar4);
      }
      thunk_FUN_00136ad4(PTR__OBJC_CLASS___NSPredicate_0114ed68,puStack_120,
                         @"key == %@",*puStack_1b8);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_118,puStack_128,uVar3);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      lVar5 = _objc_msgSend(uVar3,puStack_130);
      uStack_dc = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x00131490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d8[uStack_dc] + (int)-(uRam000000000118ff50 ^ 0xbd74a23e)))();
      return;
    }
    _objc_release(local_a0[uStack_a4] + (int)-(uRam000000000118ff08 ^ 0x5389751f),lVar4);
    param_1 = IStack_170;
    lVar5 = lStack_178;
    lVar6 = lStack_180;
  }
  uVar3 = uStack_158;
  puVar1 = @selector(addObjectsFromArray:);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),@selector(addObjectsFromArray:),uStack_158);
  uVar2 = uStack_118;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,uStack_118);
  _objc_release(uVar2);
  _objc_release(uVar3);
  _objc_release(lVar4);
  CallSupervisor(0xea61);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[TabbarVC saveTabsOrder], 0x1316d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1316d0. saveTabsOrder */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::saveTabsOrder(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_012273dc = 1;
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_activeTabs),@selector(valueForKey:),
                @"key");
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setObject:forKey:),uVar4,
                @"activeTabs");
  _objc_release(uVar5);
  _objc_msgSend(param_1,@selector(tableView));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSIndexSet_0114ee80;
  uVar6 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_startup));
  _objc_msgSend(puVar1,@selector(indexSetWithIndex:),uVar6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(reloadSections:withRowAnimation:),uVar6,100);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _NSClassFromString(@"YTHeaderContentComboViewController");
  uVar5 = _objc_alloc_init();
  _objc_msgSend(uVar5,@selector(refreshPivotBar));
  _objc_release(uVar5);
  puVar1 = @selector(parentViewController);
  _objc_msgSend(param_1,@selector(parentViewController));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_getClass(s_YTHeaderContentComboViewControll_0118ed90);
  uVar2 = FUN_00136e94(uVar5,@selector(isKindOfClass:),uVar6);
  _objc_release(uVar5);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_0118ffb8)[uVar2] + (int)-(DAT_0118ffc8 ^ 0x9041c40f),param_1,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(headerViewController));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(hideRightNavigationButtons);
    iVar3 = FUN_00136f1c(uVar6,@selector(respondsToSelector:),
                         @selector(hideRightNavigationButtons));
    if (iVar3 != 0) {
      _objc_msgSend(uVar6,@selector(performSelector:),puVar1);
    }
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  _objc_release(uVar4);
  CallSupervisor(0x5a46);
  return;
}



// -[TabbarVC tableView:titleForHeaderInSection:], 0x131ee4
/* Decompiled from supplied 5.2.2 arm package. VA 0x131ee4. tableView:titleForHeaderInSection: */

/* Function Stack Size: 0x20 bytes */

ID TabbarVC::tableView_titleForHeaderInSection_(ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined *puVar1;
  long_long lVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined8 uVar5;
  long lVar6;
  
  puVar1 = @selector(indexOfObject:);
  DAT_012273e0 = 1;
  lVar6 = (long)_sections;
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_startup));
  if (lVar2 == param_4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(localizedStringForKey:value:table:),
                  @"Startup",0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,
                          *(undefined8 *)(param_1 + (long)_tabbar));
    if (lVar2 == param_4) {
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,@selector(localizedStringForKey:value:table:),
                    @"Main",0,0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,
                            *(undefined8 *)(param_1 + (long)_activeTabs));
      if (lVar2 == param_4) {
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar3,@selector(localizedStringForKey:value:table:),
                      @"ActiveTabs",0,0);
        uVar5 = _objc_retainAutoreleasedReturnValue();
      }
      else {
        lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,
                              *(undefined8 *)(param_1 + (long)_inactiveTabs));
        if (lVar2 != param_4) {
          uVar5 = 0;
          goto LAB_00132474;
        }
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar3,@selector(localizedStringForKey:value:table:),
                      @"InactiveTabs",0,0);
        uVar5 = _objc_retainAutoreleasedReturnValue();
      }
    }
  }
  _objc_release(uVar3);
LAB_00132474:
  IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar4;
}



// -[TabbarVC tableView:titleForFooterInSection:], 0x13248c
/* Decompiled from supplied 5.2.2 arm package. VA 0x13248c. tableView:titleForFooterInSection: */

/* Function Stack Size: 0x20 bytes */

ID TabbarVC::tableView_titleForFooterInSection_(ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long lVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined8 uVar4;
  
  DAT_012273e4 = 1;
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(count));
  if (lVar1 - 1U == param_4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(localizedStringForKey:value:table:),
                  @"HideLibraryFooter",0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
  }
  else {
    uVar4 = 0;
  }
  IVar3 = _objc_autoreleaseReturnValue(uVar4);
  return IVar3;
}



// -[TabbarVC numberOfSectionsInTableView:], 0x1326e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1326e8. numberOfSectionsInTableView: */

/* Function Stack Size: 0x18 bytes */

long_long TabbarVC::numberOfSectionsInTableView_(ID param_1,SEL param_2,ID param_3)

{
  long_long lVar1;
  
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(count));
  return lVar1;
}



// -[TabbarVC tableView:numberOfRowsInSection:], 0x132700
/* Decompiled from supplied 5.2.2 arm package. VA 0x132700. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long TabbarVC::tableView_numberOfRowsInSection_
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



// -[TabbarVC tableView:cellForRowAtIndexPath:], 0x13275c
/* Decompiled from supplied 5.2.2 arm package. VA 0x13275c. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID TabbarVC::tableView_cellForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  ID IVar18;
  undefined8 uVar19;
  long lVar20;
  
  DAT_012273f0 = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,@selector(dequeueReusableCellWithIdentifier:),
                @"cell");
  lVar8 = _objc_retainAutoreleasedReturnValue();
  if (lVar8 == 0) {
    uVar9 = _objc_alloc((&PTR__objc_msgSend_01190100)[lVar8 == 0] +
                        (int)-(DAT_01190110 ^ 0x653b6e73),PTR_YTPTableViewCell_0114ee38);
    lVar8 = _objc_msgSend(uVar9,@selector(initWithStyle:reuseIdentifier:),3,
                          @"cell");
  }
  puVar3 = @selector(section);
  lVar20 = (long)_sections;
  uVar19 = *(undefined8 *)(param_1 + lVar20);
  uVar9 = _objc_msgSend(param_4,@selector(section));
  puVar1 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar19,@selector(objectAtIndexedSubscript:),uVar9);
  lVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar10 == 0) {
    _objc_retain((&PTR__objc_msgSend_01190120)[lVar10 == 0] + (int)-(DAT_01190130 ^ 0x82aeea18),
                 lVar8);
  }
  else {
    uVar19 = *(undefined8 *)(param_1 + lVar20);
    uVar9 = _objc_msgSend(param_4,puVar3);
    _objc_msgSend(uVar19,puVar1,uVar9);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar4 = @selector(row);
    uVar19 = _objc_msgSend(param_4,@selector(row));
    _objc_msgSend(uVar9,puVar1,uVar19);
    uVar19 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar9);
    uVar9 = _objc_alloc(PTR_YTPTableViewCell_0114ee38);
    puVar2 = @selector(objectForKeyedSubscript:);
    _objc_msgSend(uVar19,@selector(objectForKeyedSubscript:),
                  @"id");
    uVar11 = _objc_retainAutoreleasedReturnValue();
    lVar10 = _objc_msgSend(uVar9,@selector(initWithStyle:reuseIdentifier:),3,uVar11);
    _objc_release(lVar8);
    _objc_release(uVar11);
    _objc_msgSend(uVar19,puVar2,@"type");
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(isEqualToString:);
    iVar7 = FUN_001372c4(uVar9,@selector(isEqualToString:),
                         @"bool");
    _objc_release(uVar9);
    if (iVar7 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar19,puVar2,@"title");
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,@selector(localizedStringForKey:value:table:),uVar11,0,0);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,@selector(textLabel));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,@selector(setText:),uVar16);
      _objc_release(uVar17);
      _objc_release(uVar16);
      _objc_release(uVar11);
      _objc_release(uVar9);
      _objc_msgSend(uVar19,puVar2,@"key");
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,@selector(switchForKey:),uVar9);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
      lVar8 = _objc_msgSend(param_4,puVar3);
      uVar12 = _objc_msgSend(param_4,puVar4);
      _objc_msgSend(uVar11,@selector(setTag:),uVar12 & 0xffff | lVar8 << 0x10);
      _objc_msgSend(lVar10,@selector(setAccessoryView:),uVar11);
      _objc_release(uVar11);
    }
    _objc_msgSend(uVar19,puVar2,@"type");
    uVar9 = _objc_retainAutoreleasedReturnValue();
    iVar7 = FUN_00137afc(uVar9,puVar1,@"int");
    _objc_release(uVar9);
    puVar3 = @selector(standardUserDefaults);
    if (iVar7 != 0) {
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      puVar4 = @selector(objectForKey:);
      _objc_msgSend(uVar9,@selector(objectForKey:),
                    @"startupTab");
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar3);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,puVar4,@"activeTabs");
      uVar16 = _objc_retainAutoreleasedReturnValue();
      uVar17 = _objc_msgSend(uVar16,@selector(mutableCopy));
      _objc_release(uVar16);
      _objc_release(uVar9);
      iVar7 = FUN_0013738c(uVar17,@selector(containsObject:),
                           @"FEuploads");
      if (iVar7 != 0) {
        _objc_msgSend(uVar17,@selector(removeObject:),
                      @"FEuploads");
      }
      _objc_msgSend(param_1,@selector(segmentForItems:),uVar17);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar16 = _objc_msgSend(uVar17,@selector(indexOfObject:),uVar11);
      _objc_msgSend(uVar9,@selector(setSelectedSegmentIndex:),uVar16);
      _objc_msgSend(uVar9,@selector(addTarget:action:forControlEvents:),param_1,
                    @selector(setSegment:),0x1000);
      puVar6 = @selector(contentView);
      _objc_msgSend(lVar10,@selector(contentView));
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar16,@selector(addSubview:),uVar9);
      _objc_release(uVar16);
      puVar3 = @selector(centerYAnchor);
      _objc_msgSend(uVar9,@selector(centerYAnchor));
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puVar3 = @selector(constraintEqualToAnchor:);
      _objc_msgSend(uVar16,@selector(constraintEqualToAnchor:),uVar14);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      puVar4 = @selector(setActive:);
      _objc_msgSend(uVar15,@selector(setActive:),1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      puVar5 = @selector(centerXAnchor);
      _objc_msgSend(uVar9,@selector(centerXAnchor));
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar5);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar16,puVar3,uVar14);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      puVar3 = @selector(leadingAnchor);
      _objc_msgSend(uVar9,@selector(leadingAnchor));
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puVar5 = @selector(constraintEqualToAnchor:constant:);
      _objc_msgSend(0x4034000000000000,uVar16,@selector(constraintEqualToAnchor:constant:),uVar14
                   );
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      puVar3 = @selector(trailingAnchor);
      _objc_msgSend(uVar9,@selector(trailingAnchor));
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0xc034000000000000,uVar16,puVar5,uVar14);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      _objc_release(uVar9);
      _objc_release(uVar17);
      _objc_release(uVar11);
    }
    _objc_msgSend(uVar19,puVar2,@"type");
    uVar9 = _objc_retainAutoreleasedReturnValue();
    iVar7 = FUN_00137534(uVar9,puVar1,@"tab");
    _objc_release(uVar9);
    if (iVar7 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar19,puVar2,@"key");
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,@selector(localizedStringForKey:value:table:),uVar11,0,0);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(textLabel);
      _objc_msgSend(lVar10,@selector(textLabel));
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,@selector(setText:),uVar16);
      _objc_release(uVar17);
      _objc_release(uVar16);
      _objc_release(uVar11);
      _objc_release(uVar9);
      _objc_msgSend(lVar10,puVar1);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,@selector(setAdjustsFontSizeToFitWidth:),1);
      _objc_release(uVar9);
      _objc_msgSend(uVar19,puVar2,@"key");
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,@selector(iconImageNamed:),uVar9);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(imageView);
      _objc_msgSend(lVar10,@selector(imageView));
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar16,@selector(setImage:),uVar11);
      _objc_release(uVar16);
      _objc_release(uVar11);
      _objc_release(uVar9);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar1);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,@selector(setTintColor:),uVar9);
      _objc_release(uVar11);
      _objc_release(uVar9);
    }
    _objc_retain(lVar10);
    _objc_release(uVar19);
    lVar8 = lVar10;
  }
  _objc_release(lVar8);
  _objc_release(param_4);
  IVar18 = _objc_autoreleaseReturnValue(lVar8);
  return IVar18;
}



// -[TabbarVC iconImageNamed:], 0x13379c
/* Decompiled from supplied 5.2.2 arm package. VA 0x13379c. iconImageNamed: */

/* Function Stack Size: 0x18 bytes */

ID TabbarVC::iconImageNamed_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  ID local_38;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(0x4038000000000000,0x4038000000000000,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_58 = PTR___NSConcreteGlobalBlock_01060658;
  local_50 = DAT_00c4c2a8;
  local_48 = FUN_00133890;
  puStack_40 = &DAT_010619a0;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_58);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(imageWithRenderingMode:),2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(local_38);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// -[TabbarVC tableView:didSelectRowAtIndexPath:], 0x133a1c
/* Decompiled from supplied 5.2.2 arm package. VA 0x133a1c. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void TabbarVC::tableView_didSelectRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_012273fc = 1;
  _objc_retain(param_3);
  uVar4 = _objc_retain(param_4);
  uVar7 = *(undefined8 *)(param_1 + (long)_sections);
  uVar4 = _objc_msgSend(uVar4,@selector(section));
  puVar1 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar7,@selector(objectAtIndexedSubscript:),uVar4);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(param_4,@selector(row));
  _objc_msgSend(uVar4,puVar1,uVar7);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(uVar7,@selector(objectForKeyedSubscript:),
                @"type");
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00137de4(uVar4,@selector(isEqualToString:),
                       @"bool");
  _objc_release(uVar4);
  if (iVar2 != 0) {
    _objc_msgSend(param_3,@selector(cellForRowAtIndexPath:),param_4);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(accessoryView));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = _NSClassFromString(@"ABCSwitch");
    iVar2 = FUN_00137f94(uVar5,@selector(isKindOfClass:),uVar6);
    if (iVar2 != 0) {
      _objc_msgSend(uVar5,@selector(prepareHapticFeedback));
      uVar3 = FUN_00137e4c(uVar5,@selector(isOn));
      _objc_msgSend(uVar5,@selector(setOn:animated:userGenerated:),uVar3 ^ 1,1,1);
      _objc_msgSend(uVar5,@selector(releaseHapticFeedback));
      _objc_msgSend(uVar5,@selector(fireHapticFeedback));
      _NSClassFromString(@"YTHeaderContentComboViewController");
      uVar6 = _objc_alloc_init();
      _objc_msgSend(uVar6,@selector(refreshPivotBar));
      _objc_release(uVar6);
    }
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_msgSend(param_3,@selector(deselectRowAtIndexPath:animated:),param_4,1);
  _objc_release(uVar7);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x31a8);
  return;
}



// -[TabbarVC switchForKey:], 0x134094
/* Decompiled from supplied 5.2.2 arm package. VA 0x134094. switchForKey: */

/* Function Stack Size: 0x18 bytes */

ID TabbarVC::switchForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  DAT_01227400 = 1;
  _objc_retain(param_3);
  _NSClassFromString(@"ABCSwitch");
  uVar1 = _objc_alloc_init();
  _objc_msgSend(param_1,@selector(view));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(tintColor));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setOnTintColor:),uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(grayColor));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3fe0000000000000,uVar2,@selector(colorWithAlphaComponent:));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setOffTrackColor:),uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_001380dc(uVar2,@selector(boolForKey:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar1,@selector(setOn:),uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(toggleSwitch:),0x1000);
  IVar4 = _objc_autoreleaseReturnValue(uVar1);
  return IVar4;
}



// -[TabbarVC toggleSwitch:], 0x13432c
/* Decompiled from supplied 5.2.2 arm package. VA 0x13432c. toggleSwitch: */

/* Function Stack Size: 0x18 bytes */

void TabbarVC::toggleSwitch_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_01227404 = 1;
  uVar2 = _objc_retain(param_3);
  uVar3 = _objc_msgSend(uVar2,@selector(tag));
  puVar1 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(objectAtIndexedSubscript:),
                (long)uVar3 >> 0x10);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,puVar1,uVar3 & 0xffff);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  if (lVar4 != 0) {
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar5 = FUN_00138224(param_3,@selector(isOn));
    _objc_msgSend(lVar4,@selector(objectForKeyedSubscript:),
                  @"key");
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(setBool:forKey:),uVar5,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar2);
  }
  _NSClassFromString(@"YTHeaderContentComboViewController");
  uVar2 = _objc_alloc_init();
  _objc_msgSend(uVar2,@selector(refreshPivotBar));
  _objc_release(uVar2);
  _objc_release(lVar4);
  _objc_release(param_3);
  CallSupervisor(0x30f6);
  return;
}



// -[TabbarVC segmentForItems:], 0x134788
/* Decompiled from supplied 5.2.2 arm package. VA 0x134788. segmentForItems: */

/* Function Stack Size: 0x18 bytes */

ID TabbarVC::segmentForItems_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ID IVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  ID IVar11;
  undefined8 uVar12;
  undefined1 auStack_280 [128];
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 auStack_1c0 [2];
  undefined1 auStack_1b0 [16];
  undefined8 auStack_1a0 [2];
  undefined8 auStack_190 [3];
  undefined *puStack_178;
  undefined1 *puStack_170;
  undefined8 *puStack_168;
  undefined8 uStack_160;
  ID IStack_158;
  ID local_150;
  undefined *puStack_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined *puStack_130;
  undefined *puStack_128;
  long lStack_120;
  long lStack_118;
  undefined8 *puStack_110;
  undefined8 *puStack_108;
  undefined1 *puStack_100;
  undefined **local_f0;
  undefined **local_e0;
  undefined **ppuStack_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01190288;
  local_7c = (uint)(DAT_01227408 == 0);
  local_90 = &PTR_LAB_011902a8;
  local_88 = &PTR_LAB_0118faf0;
  local_a8 = &PTR_LAB_0118faf0;
  ppuStack_a0 = &PTR_LAB_0118faf0;
  local_b0 = &PTR_LAB_011902d0;
  local_c8 = &PTR_LAB_011902f0;
  ppuStack_c0 = &PTR_LAB_0118faf0;
  local_e0 = &PTR_LAB_01190310;
  ppuStack_d8 = &PTR_LAB_0118faf0;
  local_f0 = &PTR_LAB_01190328;
  DAT_01227408 = 1;
  puStack_100 = auStack_1b0;
  puStack_110 = auStack_1c0;
  puStack_168 = &uStack_200;
  puStack_170 = auStack_280;
  local_150 = param_3;
  puStack_108 = auStack_1a0;
  _objc_retain(param_3);
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UISegmentedControl_0114ee48);
  uVar6 = _objc_msgSend(uVar6,@selector(initWithItems:),
                        *(undefined8 *)PTR____NSArray0___01060670);
  _objc_msgSend(uVar6,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  uVar12 = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
  auStack_1a0[0] = uVar12;
  _objc_msgSend(param_1,@selector(view));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(tintColor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(dictionaryWithObjects:forKeys:count:);
  auStack_190[0] = uVar8;
  IStack_158 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),auStack_190,auStack_1a0,1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(setTitleTextAttributes:forState:);
  _objc_msgSend(uVar6,@selector(setTitleTextAttributes:forState:),uVar9,4);
  _objc_release(uVar9);
  IVar11 = IStack_158;
  _objc_release(uVar8);
  _objc_release(uVar7);
  auStack_1c0[0] = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_100;
  puStack_108[-2] = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar5,puStack_110,1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  uStack_160 = uVar6;
  _objc_msgSend(uVar6,puVar2,uVar8,0);
  puVar3 = puStack_168;
  _objc_release(uVar8);
  _objc_release(uVar7);
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1f8 = 0;
  uStack_200 = 0;
  uStack_1e8 = 0;
  uStack_1f0 = 0;
  uVar6 = _objc_retain(param_3);
  puStack_178 = @selector(countByEnumeratingWithState:objects:count:);
  lStack_118 = _objc_msgSend(uVar6,@selector(countByEnumeratingWithState:objects:count:),puVar3,
                             puStack_170,0x10);
  IVar4 = local_150;
  uStack_94 = (uint)(lStack_118 == 0);
  if (lStack_118 != 0) {
    lStack_120 = *(long *)puVar3[2];
    puStack_108 = (undefined8 *)@selector(filteredArrayUsingPredicate:);
    puStack_100 = @selector(predicateWithFormat:);
    puStack_110 = (undefined8 *)@selector(count);
    puStack_128 = @selector(firstObject);
    puStack_130 = @selector(objectForKeyedSubscript:);
    puStack_138 = @selector(iconImageNamed:);
    puStack_140 = @selector(numberOfSegments);
    puStack_148 = @selector(insertSegmentWithImage:atIndex:animated:);
    lStack_118 = lStack_118 + -1;
    uStack_b4 = (uint)(*(long *)puVar3[2] == lStack_120);
    if (*(long *)puVar3[2] != lStack_120) {
      _objc_enumerationMutation(local_150);
    }
    thunk_FUN_001383f8(PTR__OBJC_CLASS___NSPredicate_0114ed68,puStack_100,
                       @"key == %@",*(undefined8 *)puVar3[1]);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(IVar11 + (long)_tabs),puStack_108,uVar6);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    lVar10 = _objc_msgSend(uVar6,puStack_110);
    uStack_cc = (uint)(lVar10 == 0);
                    /* WARNING: Could not recover jumptable at 0x00134d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar11 = (*(code *)(local_c8[uStack_cc] + (int)-(uRam0000000001190300 ^ 0x97ebfdf3)))();
    return IVar11;
  }
  _objc_release(local_150);
  _objc_release(IVar4);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uStack_160);
  return IVar11;
}



// -[TabbarVC setSegment:], 0x134f50
/* Decompiled from supplied 5.2.2 arm package. VA 0x134f50. setSegment: */

/* Function Stack Size: 0x18 bytes */

void TabbarVC::setSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_0122740c = 1;
  _objc_retain(param_3);
  puVar1 = @selector(standardUserDefaults);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(objectForKey:),@"activeTabs");
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(uVar4,@selector(mutableCopy));
  _objc_release(uVar4);
  _objc_release(uVar3);
  iVar2 = FUN_00138598(uVar5,@selector(containsObject:),
                       @"FEuploads");
  if (iVar2 != 0) {
    _objc_msgSend(uVar5,@selector(removeObject:),@"FEuploads"
                 );
  }
  uVar3 = _objc_msgSend(param_3,@selector(selectedSegmentIndex));
  _objc_msgSend(uVar5,@selector(objectAtIndexedSubscript:),uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setObject:forKey:),uVar3,
                @"startupTab");
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_release(param_3);
  CallSupervisor(0x3043);
  return;
}



// -[TabbarVC tableView:canEditRowAtIndexPath:], 0x135354
/* Decompiled from supplied 5.2.2 arm package. VA 0x135354. tableView:canEditRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool TabbarVC::tableView_canEditRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  long lVar6;
  
  _objc_retain(param_4);
  puVar1 = @selector(section);
  lVar3 = _objc_msgSend(param_4,@selector(section));
  puVar2 = @selector(indexOfObject:);
  lVar6 = (long)_sections;
  lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_activeTabs));
  if (lVar3 == lVar4) {
    bVar5 = 1;
  }
  else {
    lVar3 = _objc_msgSend((&PTR_LAB_01190380)[lVar3 == lVar4] + (int)-(DAT_01190390 ^ 0xa61ca204),
                          param_4,puVar1);
    lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar2,
                          *(undefined8 *)(param_1 + (long)_inactiveTabs));
    bVar5 = (bool)(lVar3 == lVar4);
  }
  _objc_release(param_4);
  return bVar5;
}



// -[TabbarVC tableView:canMoveRowAtIndexPath:], 0x135464
/* Decompiled from supplied 5.2.2 arm package. VA 0x135464. tableView:canMoveRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool TabbarVC::tableView_canMoveRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  long lVar1;
  long lVar2;
  
  lVar1 = _objc_msgSend(param_4,@selector(section));
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_activeTabs));
  return (bool)(lVar1 == lVar2);
}



// -[TabbarVC tableView:targetIndexPathForMoveFromRowAtIndexPath:toProposedIndexPath:], 0x1354c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1354c0. tableView:targetIndexPathForMoveFromRowAtIndexPath:toProposedIndexPath: */

/* Function Stack Size: 0x28 bytes */

ID TabbarVC::tableView_targetIndexPathForMoveFromRowAtIndexPath_toProposedIndexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  ID IVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar2 = @selector(section);
  lVar3 = _objc_msgSend(param_4,@selector(section));
  lVar4 = _objc_msgSend(param_5,puVar2);
  IVar1 = param_5;
  if (lVar3 != lVar4) {
    IVar1 = param_4;
  }
  _objc_retainAutoreleaseReturnValue(IVar1);
  _objc_release(param_5);
  _objc_release(param_4);
  return IVar1;
}



// -[TabbarVC tableView:moveRowAtIndexPath:toIndexPath:], 0x135540
/* Decompiled from supplied 5.2.2 arm package. VA 0x135540. tableView:moveRowAtIndexPath:toIndexPath: */

/* Function Stack Size: 0x28 bytes */

void TabbarVC::tableView_moveRowAtIndexPath_toIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  
  _objc_retain(param_5);
  puVar1 = @selector(row);
  lVar7 = (long)_activeTabs;
  uVar5 = *(undefined8 *)(param_1 + lVar7);
  uVar2 = _objc_retain(param_4);
  uVar2 = _objc_msgSend(uVar2,puVar1);
  _objc_msgSend(uVar5,@selector(objectAtIndexedSubscript:),uVar2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + lVar7);
  uVar5 = _objc_msgSend(param_4,puVar1);
  _objc_release(param_4);
  _objc_msgSend(uVar6,@selector(removeObjectAtIndex:),uVar5);
  uVar3 = _objc_msgSend(param_5,puVar1);
  uVar4 = _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(count));
  uVar5 = *(undefined8 *)(param_1 + lVar7);
  if (uVar3 < uVar4) {
    uVar6 = _objc_msgSend((&PTR_LAB_011903a0)[uVar3 < uVar4] + (int)-(DAT_011903b0 ^ 0xc8af6962),
                          param_5,puVar1);
    _objc_msgSend(uVar5,@selector(insertObject:atIndex:),uVar2,uVar6);
  }
  else {
    _objc_msgSend(uVar5,@selector(addObject:),uVar2);
  }
  _objc_msgSend(param_1,@selector(saveTabsOrder));
  _objc_release(uVar2);
  _objc_release(param_5);
  CallSupervisor(0x3ad8);
  return;
}



// -[TabbarVC tableView:editingStyleForRowAtIndexPath:], 0x1356e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1356e4. tableView:editingStyleForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

long_long TabbarVC::tableView_editingStyleForRowAtIndexPath_
                    (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  long_long lVar4;
  long lVar5;
  
  lVar2 = _objc_msgSend(param_4,@selector(section));
  puVar1 = @selector(indexOfObject:);
  lVar5 = (long)_sections;
  lVar3 = _objc_msgSend(*(undefined8 *)(param_1 + lVar5),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_activeTabs));
  if (lVar2 == lVar3) {
    lVar4 = 1;
  }
  else {
    lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar5),puVar1,
                          *(undefined8 *)(param_1 + (long)_inactiveTabs));
    lVar4 = (ulong)(lVar2 != 0) << 1;
  }
  return lVar4;
}



// -[TabbarVC tableView:commitEditingStyle:forRowAtIndexPath:], 0x1357c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1357c4. tableView:commitEditingStyle:forRowAtIndexPath: */

/* Function Stack Size: 0x28 bytes */

void TabbarVC::tableView_commitEditingStyle_forRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,long_long param_4,ID param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  
  DAT_01227424 = 1;
  _objc_retain(param_3);
  _objc_retain(param_5);
  puVar1 = @selector(standardUserDefaults);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(objectForKey:);
  _objc_msgSend(uVar6,@selector(objectForKey:),@"activeTabs");
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar4,@"startupTab");
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  puVar4 = @selector(count);
  if ((long)param_4 < 2) {
    if (param_4 != 1) goto LAB_001364d0;
    lVar9 = _objc_msgSend(uVar7,@selector(count));
    puVar2 = @selector(row);
    if (lVar9 == 1) {
      uVar6 = _NSClassFromString((&PTR_LAB_01190458)[lVar9 == 1] +
                                 (int)-(uRam0000000001190468 ^ 0xe6bfd783),
                                 @"YTAlertView");
      _objc_msgSend(uVar6,@selector(infoDialog));
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(ytl_defaultBundle);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar4 = @selector(localizedStringForKey:value:table:);
      _objc_msgSend(uVar11,@selector(localizedStringForKey:value:table:),
                    @"Warning",0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setTitle:),uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar4,@"AtLeastOneTab",0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setSubtitle:),uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(uVar6,@selector(show));
    }
    else {
      lVar9 = (long)_activeTabs;
      uVar11 = *(undefined8 *)(param_1 + lVar9);
      uVar6 = _objc_msgSend(param_5,@selector(row));
      puVar3 = @selector(objectAtIndexedSubscript:);
      _objc_msgSend(uVar11,@selector(objectAtIndexedSubscript:),uVar6);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar12 = *(undefined8 *)(param_1 + lVar9);
      uVar11 = _objc_msgSend(param_5,puVar2);
      _objc_msgSend(uVar12,@selector(removeObjectAtIndex:),uVar11);
      lVar13 = (long)_inactiveTabs;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(addObject:),uVar6);
      puVar2 = @selector(objectForKeyedSubscript:);
      _objc_msgSend(uVar6,@selector(objectForKeyedSubscript:),
                    @"key");
      uVar11 = _objc_retainAutoreleasedReturnValue();
      uVar5 = FUN_00138b80(uVar11,@selector(isEqualToString:),uVar8);
      _objc_release(uVar11);
      if (uVar5 != 0) {
        _objc_msgSend((&PTR_LAB_01190478)[uVar5] + (int)-(DAT_01190488 ^ 0x9d0c36fd),
                      PTR_YTLUserDefaults_0114ead8,puVar1);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(param_1 + lVar9),puVar3,0);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,puVar2,@"key");
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,@selector(setObject:forKey:),uVar10,
                      @"startupTab");
        _objc_release(uVar10);
        _objc_release(uVar12);
        _objc_release(uVar11);
      }
      puVar1 = PTR__OBJC_CLASS___NSIndexPath_0114ee10;
      lVar9 = _objc_msgSend(*(undefined8 *)(param_1 + lVar13),puVar4);
      uVar11 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),
                             @selector(indexOfObject:),*(undefined8 *)(param_1 + lVar13));
      _objc_msgSend(puVar1,@selector(indexPathForRow:inSection:),lVar9 + -1,uVar11);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,@selector(moveRowAtIndexPath:toIndexPath:),param_5,uVar11);
      _objc_release(uVar11);
      _objc_msgSend(param_1,@selector(saveTabsOrder));
    }
  }
  else {
    if (param_4 != 2) goto LAB_001364d0;
    lVar13 = (long)_activeTabs;
    lVar9 = _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(count));
    puVar1 = @selector(row);
    if (lVar9 == 6) {
      uVar6 = _NSClassFromString((&PTR_LAB_011904a0)[lVar9 == 6] +
                                 (int)-(uRam00000000011904b0 ^ 0xceed9c55),
                                 @"YTAlertView");
      _objc_msgSend(uVar6,@selector(infoDialog));
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(ytl_defaultBundle);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar4 = @selector(localizedStringForKey:value:table:);
      _objc_msgSend(uVar11,@selector(localizedStringForKey:value:table:),
                    @"Warning",0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setTitle:),uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar4,@"TabsCountRestricted",0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setSubtitle:),uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(uVar6,@selector(show));
    }
    else {
      lVar9 = (long)_inactiveTabs;
      uVar11 = *(undefined8 *)(param_1 + lVar9);
      uVar6 = _objc_msgSend(param_5,@selector(row));
      _objc_msgSend(uVar11,@selector(objectAtIndexedSubscript:),uVar6);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar12 = *(undefined8 *)(param_1 + lVar9);
      uVar11 = _objc_msgSend(param_5,puVar1);
      _objc_msgSend(uVar12,@selector(removeObjectAtIndex:),uVar11);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(addObject:),uVar6);
      puVar1 = PTR__OBJC_CLASS___NSIndexPath_0114ee10;
      lVar9 = _objc_msgSend(*(undefined8 *)(param_1 + lVar13),puVar4);
      uVar11 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),
                             @selector(indexOfObject:),*(undefined8 *)(param_1 + lVar13));
      _objc_msgSend(puVar1,@selector(indexPathForRow:inSection:),lVar9 + -1,uVar11);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,@selector(moveRowAtIndexPath:toIndexPath:),param_5,uVar11);
      _objc_release(uVar11);
      _objc_msgSend(param_1,@selector(saveTabsOrder));
    }
  }
  _objc_release(uVar6);
LAB_001364d0:
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(param_5);
  _objc_release(param_3);
  CallSupervisor(0x6e21);
  return;
}



// -[TabbarVC .cxx_destruct], 0x136528
/* Decompiled from supplied 5.2.2 arm package. VA 0x136528. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_inactiveTabs,0);
  _objc_storeStrong(param_1 + (long)_activeTabs,0);
  _objc_storeStrong(param_1 + (long)_tabbar,0);
  _objc_storeStrong(param_1 + (long)_startup,0);
  _objc_storeStrong(param_1 + (long)_tabs,0);
  _objc_storeStrong(param_1 + (long)_sections,0);
  CallSupervisor(0x4a1c);
  return;
}


