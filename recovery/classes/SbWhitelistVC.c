// Decompiled implementation evidence for SbWhitelistVC. Not compilable source.

// -[SbWhitelistVC init], 0x1d662c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d662c. init */

/* Function Stack Size: 0x10 bytes */

ID SbWhitelistVC::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ID local_50;
  undefined *puStack_48;
  uint local_3c;
  undefined **local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_01060708;
  local_38 = &PTR_LAB_011b8ef0;
  puStack_48 = PTR_SbWhitelistVC_0114f118;
  local_50 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_50,@selector(initWithStyle:),1);
  local_3c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    uVar2 = _objc_msgSend(*(undefined8 *)PTR____NSArray0___01060670,@selector(mutableCopy));
    lVar4 = (long)_channels;
    uVar3 = *(undefined8 *)(IVar1 + lVar4);
    *(undefined8 *)(IVar1 + lVar4) = uVar2;
    _objc_release(uVar3);
    uStack_30 = *(undefined8 *)(IVar1 + lVar4);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_30,1);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + (long)_sections);
    *(undefined8 *)(IVar1 + (long)_sections) = uVar2;
    _objc_release(uVar3);
    _objc_msgSend(IVar1,@selector(setupWhitelist));
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_28) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar1;
}



// -[SbWhitelistVC setupWhitelist], 0x1d6770
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d6770. setupWhitelist */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::setupWhitelist(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined ***pppuVar5;
  undefined1 *puVar6;
  undefined **ppuVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint extraout_var;
  undefined1 auStack_430 [48];
  undefined1 auStack_400 [144];
  undefined1 auStack_370 [128];
  undefined1 auStack_2f0 [64];
  undefined1 auStack_2b0 [16];
  undefined1 auStack_2a0 [16];
  undefined1 auStack_290 [16];
  undefined1 auStack_280 [16];
  undefined1 auStack_270 [16];
  undefined **ppuStack_260;
  undefined **ppuStack_258;
  undefined **ppuStack_250;
  undefined8 uStack_248;
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined **ppuStack_230;
  undefined8 uStack_228;
  undefined1 auStack_220 [32];
  undefined1 *puStack_200;
  undefined1 *puStack_1f8;
  undefined1 *puStack_1f0;
  undefined8 uStack_1e8;
  undefined1 *puStack_1e0;
  undefined ***pppuStack_1d8;
  undefined ***pppuStack_1d0;
  undefined ***pppuStack_1c8;
  undefined ***pppuStack_1c0;
  undefined8 uStack_1b8;
  undefined1 *puStack_1b0;
  undefined1 *puStack_1a8;
  undefined1 *puStack_1a0;
  undefined1 *puStack_198;
  undefined1 *puStack_190;
  undefined1 *puStack_188;
  undefined1 *puStack_180;
  long lStack_178;
  undefined1 *puStack_170;
  ID local_168;
  undefined1 *puStack_160;
  undefined1 *puStack_158;
  undefined **local_150;
  undefined **local_140;
  undefined **local_130;
  undefined **local_120;
  undefined **local_118;
  undefined **local_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_e8;
  undefined **local_e0;
  undefined **ppuStack_d8;
  undefined **local_c8;
  undefined **local_c0;
  undefined **ppuStack_b8;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  puStack_1e0 = (undefined1 *)&puStack_200;
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__objc_msgSend_011b8f10;
  local_7c = (uint)(DAT_01227d98 == 0);
  local_90 = &PTR_LAB_011b8f30;
  local_88 = &PTR_LAB_011b8c20;
  local_a8 = &PTR_LAB_011b8f50;
  ppuStack_a0 = &PTR_LAB_011b8c20;
  local_c0 = &PTR_LAB_011b8c20;
  ppuStack_b8 = &PTR_LAB_011b8c20;
  local_c8 = &PTR_LAB_011b8f78;
  local_e0 = &PTR_LAB_011b8c20;
  ppuStack_d8 = &PTR_LAB_011b8c20;
  local_e8 = &PTR_LAB_011b8fa0;
  local_100 = &PTR_LAB_011b8fc0;
  ppuStack_f8 = &PTR_LAB_011b8c20;
  local_110 = &PTR_LAB_011b8c20;
  local_120 = &PTR_LAB_011b8fe8;
  local_118 = &PTR_LAB_011b8c20;
  local_130 = &PTR_LAB_011b9000;
  local_140 = &PTR_LAB_011b9018;
  local_150 = &PTR_LAB_011b8c20;
  DAT_01227d98 = 1;
  puStack_188 = auStack_220;
  pppuStack_1d8 = &ppuStack_230;
  pppuStack_1c0 = &ppuStack_250;
  pppuStack_1d0 = &ppuStack_260;
  puStack_1f0 = auStack_270;
  puStack_1a0 = auStack_280;
  puStack_1b0 = auStack_290;
  puStack_190 = auStack_2a0;
  puStack_158 = auStack_2b0;
  puStack_180 = auStack_2f0;
  puStack_1a8 = auStack_370;
  puStack_1f8 = auStack_400;
  puStack_200 = auStack_430;
  lStack_178 = (long)_channels;
  pppuStack_1c8 = pppuStack_1d0;
  puStack_198 = puStack_1a0;
  puStack_170 = puStack_1f0;
  local_168 = param_1;
  puStack_160 = puStack_1b0;
  _objc_msgSend(*(undefined8 *)(param_1 + lStack_178),@selector(removeAllObjects));
  puVar1 = @selector(numberWithBool:);
  ppuStack_230 = @"date";
  ppuStack_240 = @"key";
  ppuStack_238 = @"ascending";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithBool:),0);
  uStack_228 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(dictionaryWithObjects:forKeys:count:);
  uStack_1b8 = uStack_228;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),pppuStack_1d8,&ppuStack_240,2);
  pppuStack_1d8 = (undefined ***)_objc_retainAutoreleasedReturnValue();
  puVar4 = puStack_1e0;
  *(undefined ****)(puStack_1e0 + -0x20) = pppuStack_1d8;
  ppuStack_250 = @"date";
  ppuStack_260 = @"key";
  ppuStack_258 = @"ascending";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,1);
  uStack_248 = _objc_retainAutoreleasedReturnValue();
  uStack_1e8 = uStack_248;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar2,pppuStack_1c0,pppuStack_1d0,2);
  pppuStack_1c0 = (undefined ***)_objc_retainAutoreleasedReturnValue();
  *(undefined ****)(puVar4 + -0x18) = pppuStack_1c0;
  pppuVar5 = pppuStack_1c8;
  pppuStack_1c8[-2] = @"name";
  puVar3 = puStack_1f0;
  *(undefined ***)(puStack_1f0 + -0x10) = @"key";
  *(undefined ***)(puVar3 + -8) = @"ascending";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,1);
  ppuVar7 = (undefined **)_objc_retainAutoreleasedReturnValue();
  pppuVar5[-1] = ppuVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar2,puStack_170,puStack_1a0,2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar4 + -0x10) = uVar8;
  puVar6 = puStack_198;
  *(undefined ***)(puStack_198 + -0x10) = @"name";
  puVar3 = puStack_1b0;
  *(undefined ***)(puStack_1b0 + -0x10) = @"key";
  *(undefined ***)(puVar3 + -8) = @"ascending";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar6 + -8) = uVar9;
  puStack_170 = puVar2;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar2,puStack_160,puStack_190,2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar4 + -8) = uVar10;
  puStack_160 = @selector(arrayWithObjects:count:);
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                puStack_188,4);
  _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(ppuVar7);
  _objc_release(pppuStack_1c0);
  _objc_release(uStack_1e8);
  _objc_release(pppuStack_1d8);
  _objc_release(uStack_1b8);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(integerForKey:),@"sbWhitelistSortType")
  ;
  _objc_release(uVar8);
  uStack_94 = extraout_var >> 0x1f ^ 1;
                    /* WARNING: Could not recover jumptable at 0x001d7660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_90[uStack_94] + (int)-(DAT_011b8f40 ^ 0xe844f7cb)))();
  return;
}



// -[SbWhitelistVC loadView], 0x1d7eb0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d7eb0. loadView */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::loadView(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  ID IStack_80;
  undefined *puStack_78;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011b9038;
  local_5c = (uint)(DAT_01227d9c == 0);
  local_68 = &PTR_LAB_011b8c20;
  DAT_01227d9c = 1;
  puStack_78 = PTR_SbWhitelistVC_0114f118;
  IStack_80 = param_1;
  _objc_msgSendSuper2(&IStack_80,@selector(loadView));
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(localizedStringForKey:value:table:),
                @"Sb.Whitelist",0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setTitle:),uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = @selector(tableView);
  _objc_msgSend(param_1,@selector(tableView));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  dVar4 = (double)_objc_msgSend(uVar2,@selector(contentInset));
  _objc_release(uVar2);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(dVar4 + 15.0,in_d1,in_d2,in_d3,uVar2,@selector(setContentInset:));
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(colorWithDynamicProvider:),
                &PTR___NSConcreteGlobalBlock_01062d20);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setBackgroundColor:),uVar2);
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
  CallSupervisor(0x9764);
  return;
}



// -[SbWhitelistVC closeButtonTapped], 0x1d838c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d838c. closeButtonTapped */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::closeButtonTapped(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(dismissViewControllerAnimated:completion:),1,0);
  CallSupervisor(0x3443);
  return;
}



// -[SbWhitelistVC tableView:titleForHeaderInSection:], 0x1d83c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d83c8. tableView:titleForHeaderInSection: */

/* Function Stack Size: 0x20 bytes */

ID SbWhitelistVC::tableView_titleForHeaderInSection_
             (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long_long lVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined8 uVar4;
  
  DAT_01227da8 = 1;
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_channels));
  if (lVar1 == param_4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(localizedStringForKey:value:table:),
                  @"Sb.Channels",0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
  }
  else {
    uVar4 = 0;
  }
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar3;
}



// -[SbWhitelistVC tableView:willDisplayHeaderView:forSection:], 0x1d85d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d85d0. tableView:willDisplayHeaderView:forSection: */

/* Function Stack Size: 0x28 bytes */

void SbWhitelistVC::tableView_willDisplayHeaderView_forSection_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long_long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  DAT_01227dac = 1;
  _objc_retain(param_4);
  _objc_retain();
  puVar2 = PTR__OBJC_CLASS___UIFont_0114ec08;
  puVar1 = @selector(systemFontOfSize:weight:);
  uVar6 = *(undefined8 *)PTR__UIFontWeightLight_01060568;
  _objc_retain(param_3);
  _objc_msgSend(0x402c000000000000,uVar6,puVar2,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(textLabel);
  _objc_msgSend(param_4,@selector(textLabel));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setFont:),uVar6);
  _objc_release(uVar3);
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTextColor:),uVar6);
  _objc_release(uVar3);
  _objc_release(uVar6);
  _objc_msgSend(param_1,@selector(tableView:titleForHeaderInSection:),param_3,param_5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setText:),uVar6);
  _objc_release(uVar3);
  _objc_release(uVar6);
  _objc_msgSend(param_4,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setTextAlignment:),4);
  _objc_release(uVar6);
  _objc_msgSend(param_4,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setNumberOfLines:),0);
  _objc_release(uVar6);
  lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(indexOfObject:),
                        *(undefined8 *)(param_1 + (long)_channels));
  if (lVar4 == param_5) {
    _objc_msgSend(param_4,@selector(viewWithTag:),1000);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x001d8a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR__objc_msgSend_011b9118)[lVar5 == 0] + (int)-(uRam00000000011b9128 ^ 0x144915c0)
              ))();
    return;
  }
  _objc_release((&PTR__objc_msgSend_011b9100)[lVar4 == param_5] + (int)-(DAT_011b9110 ^ 0x9e615779),
                param_4);
  _objc_release(param_4);
  CallSupervisor(0x8e68);
  if (*(long *)PTR____stack_chk_guard_01060708 == lVar5) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// -[SbWhitelistVC getSortActions], 0x1d8efc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d8efc. getSortActions */

/* Function Stack Size: 0x10 bytes */

ID SbWhitelistVC::getSortActions(ID param_1,SEL param_2)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  undefined ***pppuVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  ID IVar20;
  long lVar21;
  undefined *puStack_3c0;
  undefined8 uStack_3b8;
  code *pcStack_3b0;
  undefined *puStack_3a8;
  undefined8 uStack_3a0;
  ID IStack_398;
  undefined1 auStack_390 [128];
  undefined1 auStack_310 [64];
  undefined auStack_2d0 [32];
  undefined auStack_2b0 [32];
  undefined1 auStack_290 [32];
  undefined1 auStack_270 [32];
  undefined **ppuStack_250;
  undefined **ppuStack_248;
  undefined **ppuStack_240;
  undefined8 uStack_230;
  undefined **ppuStack_228;
  undefined8 uStack_220;
  undefined **ppuStack_210;
  undefined **ppuStack_208;
  undefined **ppuStack_200;
  undefined *puStack_1f0;
  undefined **ppuStack_1e8;
  undefined *puStack_1e0;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined **ppuStack_1b0;
  undefined **ppuStack_1a8;
  undefined ***pppuStack_1a0;
  undefined ***pppuStack_198;
  undefined8 uStack_190;
  undefined8 *puStack_188;
  undefined8 uStack_180;
  undefined *puStack_178;
  undefined8 uStack_170;
  undefined1 *puStack_168;
  undefined1 *puStack_160;
  undefined1 *puStack_158;
  undefined1 *puStack_150;
  undefined8 uStack_148;
  undefined1 *puStack_140;
  ID local_138;
  undefined8 uStack_130;
  undefined *puStack_128;
  undefined *puStack_120;
  undefined *puStack_118;
  undefined *puStack_110;
  undefined *puStack_108;
  undefined8 *puStack_100;
  undefined *puStack_f8;
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
  local_88 = &PTR_LAB_011b9138;
  local_8c = (uint)(DAT_01227db0 == 0);
  local_a0 = &PTR_LAB_011b9158;
  local_98 = &PTR_LAB_011b8c20;
  local_b8 = &PTR_LAB_011b8c20;
  ppuStack_b0 = &PTR_LAB_011b8c20;
  local_c0 = &PTR_LAB_011b9180;
  local_d8 = &PTR_FUN_011b91a0;
  ppuStack_d0 = &PTR_LAB_011b8c20;
  local_e8 = &PTR_LAB_011b91b8;
  DAT_01227db0 = 1;
  puStack_100 = &uStack_1d0;
  puStack_188 = &uStack_230;
  pppuStack_1a0 = &ppuStack_250;
  ppuStack_1a8 = (undefined **)auStack_270;
  puStack_168 = auStack_290;
  puStack_178 = auStack_2b0;
  puStack_120 = auStack_2d0;
  puStack_160 = auStack_310;
  puStack_150 = auStack_390;
  pppuStack_198 = pppuStack_1a0;
  puStack_158 = (undefined1 *)ppuStack_1a8;
  puStack_140 = puStack_168;
  local_138 = param_1;
  puStack_118 = puStack_178;
  puStack_f8 = puStack_120;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  uStack_130 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(ytl_defaultBundle);
  ppuStack_210 = @"title";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  puStack_108 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(puStack_108,@selector(localizedStringForKey:value:table:),
                @"Sb.Newest",0,0);
  puStack_1f0 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(numberWithInt:);
  ppuStack_1e8 = @"clock";
  ppuStack_208 = @"icon";
  ppuStack_200 = @"sortType";
  puStack_110 = puStack_1f0;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithInt:),0);
  puStack_1e0 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(dictionaryWithObjects:forKeys:count:);
  puStack_128 = puStack_1e0;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),&puStack_1f0,&ppuStack_210,3);
  uStack_1d0 = _objc_retainAutoreleasedReturnValue();
  ppuStack_250 = @"title";
  uStack_148 = uStack_1d0;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uStack_170 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_170,puVar4,@"Sb.Oldest",0,0);
  uStack_230 = _objc_retainAutoreleasedReturnValue();
  ppuStack_228 = @"clock.arrow.circlepath";
  ppuStack_248 = @"icon";
  ppuStack_240 = @"sortType";
  uStack_180 = uStack_230;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3,1);
  uStack_220 = _objc_retainAutoreleasedReturnValue();
  uStack_190 = uStack_220;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar5,puStack_188,pppuStack_1a0,3);
  uStack_1c8 = _objc_retainAutoreleasedReturnValue();
  ppuVar6 = ppuStack_1a8;
  puStack_188 = (undefined8 *)uStack_1c8;
  *(undefined ***)((long)ppuStack_1a8 + -0x20) = @"title";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  pppuStack_1a0 = (undefined ***)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(pppuStack_1a0,puVar4,@"Sb.Alphabetical",0,0);
  ppuStack_1b0 = (undefined **)_objc_retainAutoreleasedReturnValue();
  pppuVar7 = pppuStack_198;
  pppuStack_198[-4] = ppuStack_1b0;
  pppuVar7[-3] = @"textformat";
  *(undefined ***)((long)ppuVar6 + -0x18) = @"icon";
  *(undefined ***)((long)ppuVar6 + -0x10) = @"sortType";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3,2);
  ppuStack_1a8 = (undefined **)_objc_retainAutoreleasedReturnValue();
  pppuVar7[-2] = ppuStack_1a8;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar5,puStack_158,puStack_168,3);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar8 = puStack_178;
  uStack_1c0 = uVar11;
  *(undefined ***)(puStack_178 + -0x20) = @"title";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar4,@"Sb.AlphabeticalRev",0,0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar9 = puStack_140;
  *(undefined8 *)(puStack_140 + -0x20) = uVar13;
  *(undefined ***)(puVar9 + -0x18) = @"textformat.size";
  *(undefined ***)(puVar8 + -0x18) = @"icon";
  *(undefined ***)(puVar8 + -0x10) = @"sortType";
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3,3);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar9 + -0x10) = uVar14;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar5,puStack_118,puStack_120,3);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  uStack_1b8 = uVar15;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                puStack_100,4);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(ppuStack_1a8);
  puVar9 = puStack_160;
  _objc_release(ppuStack_1b0);
  _objc_release(pppuStack_1a0);
  _objc_release(puStack_188);
  _objc_release(uStack_190);
  _objc_release(uStack_180);
  _objc_release(uStack_170);
  _objc_release(uStack_148);
  _objc_release(puStack_128);
  _objc_release(puStack_110);
  _objc_release(puStack_108);
  puVar2 = puStack_f8;
  puVar1 = (undefined8 *)(puStack_f8 + -0x20);
  *(undefined8 *)(puStack_f8 + -0x18) = 0;
  *puVar1 = 0;
  *(undefined8 *)(puVar2 + -8) = 0;
  *(undefined8 *)(puVar2 + -0x10) = 0;
  *(undefined8 *)(puVar2 + -0x38) = 0;
  *(undefined8 *)(puVar2 + -0x40) = 0;
  *(undefined8 *)(puVar2 + -0x28) = 0;
  *(undefined8 *)(puVar2 + -0x30) = 0;
  uVar11 = _objc_retain(uVar16);
  puStack_158 = @selector(countByEnumeratingWithState:objects:count:);
  uStack_148 = uVar16;
  lVar17 = _objc_msgSend(uVar11,@selector(countByEnumeratingWithState:objects:count:),puVar9,puStack_150,
                         0x10);
  uVar11 = DAT_00c4c228;
  uStack_a4 = (uint)(lVar17 == 0);
  if (lVar17 == 0) {
LAB_001da1e0:
    uVar11 = uStack_148;
    _objc_release(uStack_148);
    _objc_release(uVar11);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar20 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uStack_130);
    return IVar20;
  }
  puStack_140 = (undefined1 *)**(undefined8 **)(puVar9 + 0x10);
LAB_001d9ec8:
  puVar2 = @selector(objectForKeyedSubscript:);
  lVar21 = 0;
  puStack_100 = (undefined8 *)@selector(actionWithTitle:image:identifier:handler:);
  puStack_f8 = @selector(systemImageNamed:);
  puStack_110 = @selector(integerForKey:);
  puStack_108 = @selector(standardUserDefaults);
  puStack_118 = @selector(integerValue);
  puStack_120 = @selector(setState:);
  puStack_128 = @selector(addObject:);
  uStack_c4 = (uint)((undefined1 *)**(undefined8 **)(puVar9 + 0x10) == puStack_140);
  if ((undefined1 *)**(undefined8 **)(puVar9 + 0x10) == puStack_140) goto LAB_001d9fdc;
  do {
    _objc_enumerationMutation(uStack_148);
LAB_001d9fdc:
    do {
      puVar4 = PTR__OBJC_CLASS___UIAction_0114ec40;
      uVar16 = *(undefined8 *)(*(long *)(puVar9 + 8) + lVar21 * 8);
      _objc_msgSend(uVar16,puVar2,@"title");
      uVar12 = _objc_retainAutoreleasedReturnValue();
      puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
      _objc_msgSend(uVar16,puVar2,@"icon");
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar3,puStack_f8,uVar13);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puStack_3c0 = PTR___NSConcreteStackBlock_01060660;
      uStack_3b8 = uVar11;
      pcStack_3b0 = FUN_001da240;
      puStack_3a8 = &UNK_01062d40;
      IStack_398 = local_138;
      uStack_3a0 = uVar16;
      _objc_msgSend(puVar4,puStack_100,uVar12,uVar14,0,&puStack_3c0);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar12);
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puStack_108);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      lVar18 = _objc_msgSend(uVar12,puStack_110,@"sbWhitelistSortType");
      _objc_release(uVar12);
      _objc_msgSend(uVar16,puVar2,@"sortType");
      uVar12 = _objc_retainAutoreleasedReturnValue();
      lVar19 = _objc_msgSend(uVar12,puStack_118);
      _objc_msgSend(uVar15,puStack_120,lVar18 == lVar19);
      _objc_release(uVar12);
      _objc_msgSend(uStack_130,puStack_128,uVar15);
      _objc_release(uVar15);
      bVar10 = lVar17 + -1 == lVar21;
      uStack_dc = (uint)bVar10;
      if (bVar10) {
        lVar17 = _objc_msgSend(uStack_148,puStack_158,puVar9,puStack_150,0x10);
        uStack_ec = (uint)(lVar17 == 0);
        if (lVar17 != 0) goto LAB_001d9ec8;
        uStack_ec = 1;
        goto LAB_001da1e0;
      }
      lVar21 = lVar21 + 1;
      uStack_c4 = (uint)((undefined1 *)**(undefined8 **)(puVar9 + 0x10) == puStack_140);
    } while ((undefined1 *)**(undefined8 **)(puVar9 + 0x10) == puStack_140);
  } while( true );
}



// -[SbWhitelistVC updateSortMenu], 0x1da52c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1da52c. updateSortMenu */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::updateSortMenu(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  puVar1 = PTR__OBJC_CLASS___UIMenu_0114ed00;
  DAT_01227dc0 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(localizedStringForKey:value:table:),
                @"SortType",0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(getSortActions));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(menuWithTitle:image:identifier:options:children:),uVar3,0,
                @"sb_menu",1,uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_sortButton),@selector(setMenu:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xc97);
  return;
}



// -[SbWhitelistVC numberOfSectionsInTableView:], 0x1da7cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1da7cc. numberOfSectionsInTableView: */

/* Function Stack Size: 0x18 bytes */

long_long SbWhitelistVC::numberOfSectionsInTableView_(ID param_1,SEL param_2,ID param_3)

{
  long_long lVar1;
  
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),@selector(count));
  return lVar1;
}



// -[SbWhitelistVC tableView:numberOfRowsInSection:], 0x1da7e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1da7e4. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long SbWhitelistVC::tableView_numberOfRowsInSection_
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



// -[SbWhitelistVC tableView:cellForRowAtIndexPath:], 0x1da840
/* Decompiled from supplied 5.2.2 arm package. VA 0x1da840. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID SbWhitelistVC::tableView_cellForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ID IVar11;
  undefined8 uVar12;
  long lVar13;
  
  DAT_01227dcc = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,@selector(dequeueReusableCellWithIdentifier:),
                @"cell");
  lVar6 = _objc_retainAutoreleasedReturnValue();
  if (lVar6 == 0) {
    uVar7 = _objc_alloc((&PTR_LAB_011b9230)[lVar6 == 0] + (int)-(uRam00000000011b9240 ^ 0x414818a8),
                        PTR_YTPTableViewCell_0114ee38);
    lVar6 = _objc_msgSend(uVar7,@selector(initWithStyle:reuseIdentifier:),3,
                          @"cell");
  }
  puVar1 = @selector(section);
  lVar13 = (long)_sections;
  uVar12 = *(undefined8 *)(param_1 + lVar13);
  uVar7 = _objc_msgSend(param_4,@selector(section));
  puVar2 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar12,@selector(objectAtIndexedSubscript:),uVar7);
  lVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar8 == 0) {
    _objc_retain((&PTR_LAB_011b9250)[lVar8 == 0] + (int)-(uRam00000000011b9260 ^ 0xc89da52e),lVar6);
    goto LAB_001dafd0;
  }
  uVar12 = *(undefined8 *)(param_1 + lVar13);
  uVar7 = _objc_msgSend(param_4,puVar1);
  _objc_msgSend(uVar12,puVar2,uVar7);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar12 = _objc_msgSend(param_4,@selector(row));
  _objc_msgSend(uVar7,puVar2,uVar12);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  uVar7 = _objc_alloc(PTR_YTPTableViewCell_0114ee38);
  puVar2 = @selector(objectForKeyedSubscript:);
  _objc_msgSend(uVar12,@selector(objectForKeyedSubscript:),
                @"id");
  uVar9 = _objc_retainAutoreleasedReturnValue();
  lVar8 = _objc_msgSend(uVar7,@selector(initWithStyle:reuseIdentifier:),3,uVar9);
  _objc_release(lVar6);
  _objc_release(uVar9);
  _objc_msgSend(uVar12,puVar2,@"title");
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar6 != 0) {
    _objc_msgSend((&PTR_LAB_011b9268)[lVar6 == 0] + (int)-(uRam00000000011b9278 ^ 0xb4b122db),uVar12
                  ,puVar2,@"title");
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(textLabel);
    _objc_msgSend(lVar8,@selector(textLabel));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(setText:),uVar7);
    _objc_release(uVar9);
    _objc_release(uVar7);
    _objc_msgSend(lVar8,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setNumberOfLines:),0);
    _objc_release(uVar7);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar8,puVar1);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(setTextColor:),uVar7);
    _objc_release(uVar9);
    _objc_release(uVar7);
  }
  _objc_msgSend(uVar12,puVar2,@"image");
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar6 != 0) {
    _objc_msgSend((&PTR_LAB_011b9288)[lVar6 == 0] + (int)-(uRam00000000011b9298 ^ 0x7846a9ac),uVar12
                  ,puVar2,@"image");
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(class);
    uVar9 = _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,@selector(class));
    puVar1 = @selector(isKindOfClass:);
    iVar4 = FUN_001ddc7c(uVar7,@selector(isKindOfClass:),uVar9);
    _objc_release(uVar7);
    _objc_msgSend(uVar12,puVar2,@"image");
    uVar7 = _objc_retainAutoreleasedReturnValue();
    if (iVar4 == 0) {
      uVar9 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar3);
      uVar5 = FUN_001ddb74(uVar7,puVar1,uVar9);
      _objc_release(uVar7);
      if (uVar5 == 0) goto LAB_001dafc0;
      _objc_msgSend((&PTR_LAB_011b92c0)[uVar5] + (int)-(uRam00000000011b92d0 ^ 0x1df1a98e),uVar12,
                    puVar2,@"image");
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,@selector(channelImage:),uVar7);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar8,@selector(imageView));
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,@selector(setImage:),uVar9);
    }
    else {
      _objc_msgSend(param_1,@selector(ytlImageWithName:),uVar7);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar8,@selector(imageView));
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,@selector(setImage:),uVar9);
    }
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar7);
  }
LAB_001dafc0:
  _objc_retain(lVar8);
  _objc_release(uVar12);
  lVar6 = lVar8;
LAB_001dafd0:
  _objc_release(lVar6);
  _objc_release(param_4);
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(lVar6);
  return IVar11;
}



// -[SbWhitelistVC tableView:shouldHighlightRowAtIndexPath:], 0x1db004
/* Decompiled from supplied 5.2.2 arm package. VA 0x1db004. tableView:shouldHighlightRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool SbWhitelistVC::tableView_shouldHighlightRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  return 1;
}



// -[SbWhitelistVC tableView:didSelectRowAtIndexPath:], 0x1db00c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1db00c. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void SbWhitelistVC::tableView_didSelectRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_01227dd4 = 1;
  _objc_retain(param_3);
  uVar3 = _objc_retain(param_4);
  uVar6 = *(undefined8 *)(param_1 + (long)_sections);
  uVar3 = _objc_msgSend(uVar3,@selector(section));
  puVar1 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar6,@selector(objectAtIndexedSubscript:),uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_msgSend(param_4,@selector(row));
  _objc_msgSend(uVar3,puVar1,uVar6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  puVar1 = @selector(objectForKeyedSubscript:);
  _objc_msgSend(uVar6,@selector(objectForKeyedSubscript:),
                @"type");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001ddda4(uVar3,@selector(isEqualToString:),
                       @"channel");
  _objc_release(uVar3);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_slimBarVisibilityChange__011b9318)[uVar2] +
                  (int)-(DAT_011b9328 ^ 0x940769df),uVar6,puVar1,
                  @"key");
    lVar4 = _objc_retainAutoreleasedReturnValue();
    if (lVar4 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(URLWithString:),lVar4);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,@selector(openURL:options:completionHandler:),uVar5,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
      _objc_release(uVar5);
      _objc_release(uVar3);
    }
    _objc_release(lVar4);
  }
  _objc_msgSend(param_3,@selector(deselectRowAtIndexPath:animated:),param_4,1);
  _objc_release(uVar6);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xb12a);
  return;
}



// -[SbWhitelistVC tableView:trailingSwipeActionsConfigurationForRowAtIndexPath:], 0x1db400
/* Decompiled from supplied 5.2.2 arm package. VA 0x1db400. tableView:trailingSwipeActionsConfigurationForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID SbWhitelistVC::tableView_trailingSwipeActionsConfigurationForRowAtIndexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 auStack_d0 [2];
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  ID IStack_a0;
  undefined8 uStack_98;
  undefined **local_88;
  int iStack_7c;
  undefined **local_78;
  undefined **ppuStack_70;
  uint local_64;
  undefined **local_60;
  long local_58;
  
  puVar1 = @selector(section);
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_60 = &PTR_LAB_011b9358;
  local_64 = (uint)(DAT_01227dd8 == 0);
  local_78 = &PTR_LAB_011b9378;
  ppuStack_70 = &PTR_LAB_011b8c20;
  local_88 = &PTR_LAB_011b8c20;
  DAT_01227dd8 = 1;
  uVar7 = *(undefined8 *)(param_1 + (long)_sections);
  uVar3 = _objc_retain(param_4);
  uVar3 = _objc_msgSend(uVar3,puVar1);
  puVar1 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar7,@selector(objectAtIndexedSubscript:),uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(param_4,@selector(row));
  _objc_release(param_4);
  _objc_msgSend(uVar3,puVar1,uVar7);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar7,@selector(objectForKeyedSubscript:),
                @"type");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001ddeec(uVar3,@selector(isEqualToString:),
                       @"channel");
  _objc_release(uVar3);
  puVar1 = PTR__OBJC_CLASS___UIContextualAction_0114efb0;
  iStack_7c = iVar2;
  if (iVar2 == 0) {
    uVar6 = 0;
  }
  else {
    puStack_c0 = PTR___NSConcreteStackBlock_01060660;
    uStack_b8 = DAT_00c4c228;
    pcStack_b0 = FUN_001db870;
    puStack_a8 = &UNK_01062d70;
    IStack_a0 = param_1;
    _objc_retain(uVar7);
    uStack_98 = uVar7;
    _objc_msgSend(puVar1,@selector(contextualActionWithStyle:title:handler:),1,&cf___,&puStack_c0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),
                  @"trash");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setImage:),uVar4);
    _objc_release(uVar4);
    puVar1 = PTR__OBJC_CLASS___UISwipeActionsConfiguration_0114efb8;
    auStack_d0[0] = uVar3;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  auStack_d0,1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,@selector(configurationWithActions:),uVar4);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(uVar6,@selector(setPerformsFirstActionWithFullSwipe:),1);
    _objc_release(uVar3);
    _objc_release(uStack_98);
  }
  _objc_release(uVar7);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_58) {
    IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
    return IVar5;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[SbWhitelistVC removeChannelWithLink:], 0x1db9c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1db9c8. removeChannelWithLink: */

/* Function Stack Size: 0x18 bytes */

void SbWhitelistVC::removeChannelWithLink_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  long lVar12;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined *puStack_140;
  undefined1 *puStack_138;
  undefined *puStack_130;
  ID IStack_128;
  long lStack_120;
  ID local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
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
  local_78 = &PTR_LAB_011b93b8;
  local_7c = (uint)(DAT_01227de0 == 0);
  local_a0 = &PTR_LAB_011b93f0;
  local_90 = &PTR_LAB_011b93d8;
  ppuStack_88 = &PTR_LAB_011b8c20;
  local_b8 = &PTR_LAB_011b8c20;
  ppuStack_b0 = &PTR_LAB_011b8c20;
  local_c0 = &PTR_LAB_011b9418;
  local_d8 = &PTR_LAB_011b9438;
  ppuStack_d0 = &PTR_LAB_011b8c20;
  local_f0 = &PTR_LAB_011b9458;
  ppuStack_e8 = &PTR_LAB_011b8c20;
  local_100 = &PTR_LAB_011b9470;
  local_110 = &PTR_LAB_011b8c20;
  DAT_01227de0 = 1;
  local_118 = param_3;
  _objc_retain(param_3);
  puVar9 = @selector(standardUserDefaults);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(objectForKey:),@"sbWhitelist");
  uVar6 = _objc_retainAutoreleasedReturnValue();
  lVar7 = _objc_msgSend(uVar6,@selector(mutableCopy));
  _objc_release(uVar6);
  _objc_release(uVar5);
  uStack_94 = (uint)(lVar7 == 0);
  if (lVar7 != 0) {
    uStack_158 = 0;
    uStack_160 = 0;
    uStack_148 = 0;
    uStack_150 = 0;
    lStack_178 = 0;
    uStack_180 = 0;
    uStack_168 = 0;
    plStack_170 = (long *)0x0;
    uVar5 = _objc_retain(local_90[uStack_94] + (int)-(DAT_011b93e8 ^ 0xeb9e3bd2),lVar7);
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar8 = _objc_msgSend(uVar5,@selector(countByEnumeratingWithState:objects:count:),&uStack_180,
                          auStack_200,0x10);
    uStack_a4 = (uint)(lVar8 == 0);
    puVar10 = local_a0[uStack_a4] + (int)-(uRam00000000011b9400 ^ 0x3b4445c8);
    if (lVar8 != 0) {
      puStack_140 = puVar1;
      puStack_130 = puVar9;
      lStack_120 = *plStack_170;
      puStack_138 = auStack_200;
      IStack_128 = param_1;
LAB_001dbd2c:
      puVar2 = @selector(objectForKeyedSubscript:);
      puVar1 = @selector(isEqualToString:);
      lVar12 = 0;
      uStack_c4 = (uint)(*plStack_170 == lStack_120);
      puVar9 = local_c0[uStack_c4] + (int)-(uRam00000000011b9428 ^ 0x71e7450d);
      if (*plStack_170 == lStack_120) goto LAB_001dbd6c;
      do {
        _objc_enumerationMutation(puVar9,lVar7);
LAB_001dbd6c:
        do {
          uVar11 = *(undefined8 *)(lStack_178 + lVar12 * 8);
          _objc_msgSend(lVar7,puVar2,uVar11);
          uVar5 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar5,puVar2,@"link");
          uVar6 = _objc_retainAutoreleasedReturnValue();
          uVar4 = FUN_001de19c(uVar6,puVar1,local_118);
          _objc_release(uVar6);
          uStack_dc = uVar4;
          if (uVar4 != 0) {
            _objc_msgSend(lVar7,@selector(removeObjectForKey:),uVar11);
            _objc_release(uVar5);
            puVar10 = &stack0xffffffffffffffd0;
            param_1 = IStack_128;
            puVar9 = puStack_130;
            goto LAB_001dbf4c;
          }
          _objc_release(local_d8[uVar4] + (int)-(uRam00000000011b9448 ^ 0x69d4ae7e),uVar5);
          bVar3 = lVar8 + -1 == lVar12;
          uStack_f4 = (uint)bVar3;
          if (bVar3) {
            lVar8 = _objc_msgSend(lVar7,puStack_140,&uStack_180,puStack_138,0x10);
            uStack_104 = (uint)(lVar8 == 0);
            puVar10 = local_100[uStack_104] + (int)-(uRam00000000011b9480 ^ 0xd3f4b1ab);
            param_1 = IStack_128;
            puVar9 = puStack_130;
            if (lVar8 == 0) goto LAB_001dbf4c;
            goto LAB_001dbd2c;
          }
          lVar12 = lVar12 + 1;
          uStack_c4 = (uint)(*plStack_170 == lStack_120);
          puVar9 = local_c0[uStack_c4] + (int)-(uRam00000000011b9428 ^ 0x71e7450d);
        } while (*plStack_170 == lStack_120);
      } while( true );
    }
LAB_001dbf4c:
    _objc_release(puVar10,lVar7);
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar9);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setObject:forKey:),lVar7,
                  @"sbWhitelist");
    _objc_release(uVar5);
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar9);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    FUN_001de114(uVar5,@selector(synchronize));
    _objc_release(uVar5);
    _objc_msgSend(param_1,@selector(setupWhitelist));
  }
  _objc_release(lVar7);
  _objc_release(local_118);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}



// -[SbWhitelistVC ytlImageWithName:], 0x1dc018
/* Decompiled from supplied 5.2.2 arm package. VA 0x1dc018. ytlImageWithName: */

/* Function Stack Size: 0x18 bytes */

ID SbWhitelistVC::ytlImageWithName_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  puVar2 = PTR__OBJC_CLASS___NSBundle_0114eae8;
  puVar1 = @selector(ytl_defaultBundle);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,@selector(imageNamed:inBundle:compatibleWithTraitCollection:),param_3,uVar4,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar5,@selector(imageWithRenderingMode:),2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  IVar7 = _objc_autoreleaseReturnValue(uVar6);
  return IVar7;
}



// -[SbWhitelistVC channelImage:], 0x1dc0d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1dc0d8. channelImage: */

/* Function Stack Size: 0x18 bytes */

ID SbWhitelistVC::channelImage_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
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
  local_48 = FUN_001dc1a8;
  puStack_40 = &DAT_010619a0;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_58);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(local_38);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}



// -[SbWhitelistVC .cxx_destruct], 0x1dc400
/* Decompiled from supplied 5.2.2 arm package. VA 0x1dc400. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_channels,0);
  _objc_storeStrong(param_1 + (long)_sections,0);
  _objc_storeStrong(param_1 + (long)_sortButton,0);
  CallSupervisor(0x6c41);
  return;
}


