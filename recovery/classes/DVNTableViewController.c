// Decompiled implementation evidence for DVNTableViewController. Not compilable source.

// -[DVNTableViewController initWithModel:defaults:], 0x1163f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1163f8. initWithModel:defaults: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::initWithModel_defaults_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  ID IVar2;
  long lVar3;
  undefined8 uVar4;
  ID IStack_a0;
  undefined *puStack_98;
  undefined **local_88;
  undefined **ppuStack_80;
  uint uStack_74;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118cbc8;
  local_4c = (uint)(DAT_0122724c == 0);
  local_60 = &PTR_LAB_0118cbe8;
  local_70 = &PTR_LAB_0118cc00;
  local_58 = &PTR__objc_msgSend_0118c130;
  local_88 = &PTR__objc_msgSend_0118c130;
  ppuStack_80 = &PTR__objc_msgSend_0118c130;
  DAT_0122724c = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puStack_98 = PTR_DVNTableViewController_0114f0a8;
  IStack_a0 = param_1;
  IVar2 = _objc_msgSendSuper2(&IStack_a0,@selector(initWithStyle:),1);
  uStack_64 = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    _objc_msgSend(IVar2,@selector(setModel:),param_3);
    _objc_msgSend(IVar2,@selector(setDefaults:),param_4);
    puVar1 = @selector(model);
    _objc_msgSend(IVar2,@selector(model));
    lVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    uStack_74 = (uint)(lVar3 == 0);
    if (lVar3 != 0) {
      _objc_msgSend(local_70[uStack_74] + (int)-(uRam000000000118cc10 ^ 0x8ed99e01),IVar2,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(setSelfViewController:),IVar2);
      _objc_release(uVar4);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(addObserver:selector:name:object:),IVar2,
                  @selector(_reloadSections),@"DVNAccStatusChanged",0);
    _objc_release(uVar4);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  return IVar2;
}



// -[DVNTableViewController loadView], 0x116764
/* Decompiled from supplied 5.2.2 arm package. VA 0x116764. loadView */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::loadView(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID local_60;
  undefined *puStack_58;
  int local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118cc28;
  puStack_58 = PTR_DVNTableViewController_0114f0a8;
  local_60 = param_1;
  _objc_msgSendSuper2(&local_60,@selector(loadView));
  puVar1 = @selector(model);
  _objc_msgSend(param_1,@selector(model));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(title));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setTitle:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  puVar2 = @selector(tableView);
  _objc_msgSend(param_1,@selector(tableView));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setSeparatorStyle:),0);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,0,0x4034000000000000,0,uVar4,@selector(setContentInset:));
  _objc_release(uVar4);
  _objc_msgSend(0x3fe8000000000000,0x3fe0000000000000,DAT_00c4c2f8,0x3ff0000000000000,
                PTR__OBJC_CLASS___UIColor_0114eb18,@selector(colorWithRed:green:blue:alpha:));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setTintColor:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(adaptiveBackgroundColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setBackgroundColor:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001258b8(uVar4,@selector(showsThanksHeart));
  _objc_release(uVar4);
  if (iVar3 != 0) {
    local_4c = iVar3;
    _objc_msgSend(param_1,@selector(setupThanksHeart));
  }
  CallSupervisor(0xeb82);
  return;
}



// -[DVNTableViewController viewDidLoad], 0x1169e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1169e4. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::viewDidLoad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  undefined1 in_q2 [16];
  undefined8 auStack_1b0 [4];
  ID IStack_190;
  undefined *puStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined *puStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined *puStack_130;
  undefined8 *puStack_128;
  undefined *puStack_120;
  undefined **local_118;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  int iStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  int iStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_0118cc48;
  local_8c = (uint)(DAT_01227254 == 0);
  local_a0 = &PTR_LAB_0118cc68;
  local_b0 = &PTR_LAB_0118cc80;
  local_98 = &PTR__objc_msgSend_0118c130;
  local_c8 = &PTR__objc_msgSend_0118c130;
  ppuStack_c0 = &PTR__objc_msgSend_0118c130;
  local_d0 = &PTR_LAB_0118cca8;
  local_e0 = &PTR_LAB_0118ccc0;
  local_f8 = &PTR_LAB_0118cce0;
  ppuStack_f0 = &PTR__objc_msgSend_0118c130;
  local_110 = &PTR__objc_msgSend_0118c130;
  ppuStack_108 = &PTR__objc_msgSend_0118c130;
  local_118 = &PTR__objc_msgSend_0118c130;
  DAT_01227254 = 1;
  puStack_188 = PTR_DVNTableViewController_0114f0a8;
  IStack_190 = param_1;
  _objc_msgSendSuper2(&IStack_190,@selector(viewDidLoad));
  puVar14 = @selector(parentViewController);
  _objc_msgSend(param_1,@selector(parentViewController));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_getClass(s_YTHeaderContentComboViewControll_0118b8d0);
  uVar3 = FUN_001259a0(uVar5,@selector(isKindOfClass:),uVar6);
  _objc_release(uVar5);
  uStack_a4 = uVar3;
  if (uVar3 != 0) {
    _objc_msgSend(local_a0[uVar3] + (int)-(DAT_0118cc78 ^ 0xffe20066),param_1,puVar14);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(headerViewController));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(hideRightNavigationButtons);
    iStack_b4 = FUN_00125a90(uVar6,@selector(respondsToSelector:),
                             @selector(hideRightNavigationButtons));
    if (iStack_b4 != 0) {
      _objc_msgSend(uVar6,@selector(performSelector:),puVar14);
    }
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  puVar14 = @selector(model);
  _objc_msgSend(param_1,@selector(model));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_00125a28(uVar5,@selector(supportsSearching));
  _objc_release(uVar5);
  iStack_d4 = iVar4;
  if (iVar4 != 0) {
    puStack_128 = auStack_1b0;
    _objc_msgSend(param_1,puVar14);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar13 = @selector(header);
    _objc_msgSend(uVar5,@selector(header));
    lVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    _objc_release(uVar5);
    uStack_e4 = (uint)(lVar7 == 0);
    if (lVar7 != 0) {
      uVar5 = _objc_alloc_init(PTR__OBJC_CLASS___UIView_0114ec30);
      puStack_120 = puVar14;
      uVar6 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
      _objc_msgSend(param_1,puStack_120);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,puVar13);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setText:),uVar9);
      _objc_release(uVar9);
      _objc_release(uVar8);
      _objc_msgSend(param_1,puStack_120);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,@selector(headerFont));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setFont:),uVar9);
      _objc_release(uVar9);
      _objc_release(uVar8);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setTextColor:),uVar8);
      _objc_release(uVar8);
      _objc_msgSend(param_1,puStack_120);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      uVar9 = _objc_msgSend(uVar8,@selector(headerAlignment));
      _objc_msgSend(uVar6,@selector(setTextAlignment:),uVar9);
      _objc_release(uVar8);
      _objc_msgSend(uVar6,@selector(setNumberOfLines:),0);
      _objc_msgSend(uVar6,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
      _objc_msgSend(uVar5,@selector(addSubview:),uVar6);
      puVar14 = @selector(topAnchor);
      _objc_msgSend(uVar6,@selector(topAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar14);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      puVar15 = @selector(constraintEqualToAnchor:constant:);
      _objc_msgSend(0x4020000000000000,uVar8,@selector(constraintEqualToAnchor:constant:),uVar9);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      puVar14 = @selector(setActive:);
      _objc_msgSend(uVar10,@selector(setActive:),1);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar13 = @selector(bottomAnchor);
      _objc_msgSend(uVar6,@selector(bottomAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar13);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0xc020000000000000,uVar8,puVar15,uVar9);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,puVar14,1);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar13 = @selector(leadingAnchor);
      _objc_msgSend(uVar6,@selector(leadingAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(safeAreaLayoutGuide);
      _objc_msgSend(uVar5,@selector(safeAreaLayoutGuide));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,puVar13);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x4039000000000000,uVar8,puVar15,uVar10);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar14,1);
      _objc_release(uVar11);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar13 = @selector(trailingAnchor);
      _objc_msgSend(uVar6,@selector(trailingAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar1);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,puVar13);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0xc039000000000000,uVar8,puVar15,uVar10);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar14,1);
      _objc_release(uVar11);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar15 = @selector(tableView);
      _objc_msgSend(param_1,@selector(tableView));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar14 = @selector(bounds);
      _objc_msgSend(uVar8,@selector(bounds));
      puVar13 = @selector(setFrame:);
      _objc_msgSend(0,0,in_q2,0,uVar5,@selector(setFrame:));
      _objc_release(uVar8);
      uVar9 = *(undefined8 *)(PTR__UILayoutFittingCompressedSize_010605c8 + 8);
      _objc_msgSend(*(undefined8 *)PTR__UILayoutFittingCompressedSize_010605c8,uVar9,uVar5,
                    @selector(systemLayoutSizeFittingSize:));
      _objc_msgSend(param_1,puVar15);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,puVar14);
      _objc_msgSend(0,0,in_q2,uVar9,uVar5,puVar13);
      _objc_release(uVar8);
      _objc_msgSend(param_1,puVar15);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,@selector(setTableHeaderView:),uVar5);
      _objc_release(uVar8);
      _objc_release(uVar6);
      puVar14 = puStack_120;
      _objc_release(uVar5);
    }
    _objc_msgSend(param_1,puVar14);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(footer);
    _objc_msgSend(uVar5,@selector(footer));
    lVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    _objc_release(uVar5);
    uStack_fc = (uint)(lVar7 == 0);
    puVar13 = @selector(bounds);
    puVar15 = @selector(tableView);
    puVar16 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
    if (lVar7 != 0) {
      uVar5 = _objc_alloc_init(PTR__OBJC_CLASS___UIView_0114ec30);
      uVar6 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
      _objc_msgSend(param_1,puVar14);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,puVar1);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setText:),uVar9);
      _objc_release(uVar9);
      _objc_release(uVar8);
      _objc_msgSend(param_1,puVar14);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,@selector(footerFont));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setFont:),uVar9);
      _objc_release(uVar9);
      _objc_release(uVar8);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setTextColor:),uVar8);
      _objc_release(uVar8);
      _objc_msgSend(param_1,puVar14);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      uVar9 = _objc_msgSend(uVar8,@selector(footerAlignment));
      _objc_msgSend(uVar6,@selector(setTextAlignment:),uVar9);
      _objc_release(uVar8);
      _objc_msgSend(uVar6,@selector(setNumberOfLines:),0);
      puStack_120 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
      _objc_msgSend(uVar6,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
      _objc_msgSend(uVar5,@selector(addSubview:),uVar6);
      puVar14 = @selector(topAnchor);
      _objc_msgSend(uVar6,@selector(topAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar14);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      puVar15 = @selector(constraintEqualToAnchor:constant:);
      _objc_msgSend(0x4020000000000000,uVar8,@selector(constraintEqualToAnchor:constant:),uVar9);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      puVar14 = @selector(setActive:);
      _objc_msgSend(uVar10,@selector(setActive:),1);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar13 = @selector(bottomAnchor);
      _objc_msgSend(uVar6,@selector(bottomAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar13);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0xc020000000000000,uVar8,puVar15,uVar9);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,puVar14,1);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar13 = @selector(leadingAnchor);
      _objc_msgSend(uVar6,@selector(leadingAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(safeAreaLayoutGuide);
      _objc_msgSend(uVar5,@selector(safeAreaLayoutGuide));
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,puVar13);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x4039000000000000,uVar8,puVar15,uVar10);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar14,1);
      _objc_release(uVar11);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar13 = @selector(trailingAnchor);
      _objc_msgSend(uVar6,@selector(trailingAnchor));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar16 = puStack_120;
      _objc_msgSend(uVar5,puVar1);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,puVar13);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0xc039000000000000,uVar8,puVar15,uVar10);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar14,1);
      _objc_release(uVar11);
      _objc_release(uVar10);
      _objc_release(uVar9);
      _objc_release(uVar8);
      puVar15 = @selector(tableView);
      _objc_msgSend(param_1,@selector(tableView));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar13 = @selector(bounds);
      _objc_msgSend(uVar8,@selector(bounds));
      puVar14 = @selector(setFrame:);
      _objc_msgSend(0,0,in_q2,0,uVar5,@selector(setFrame:));
      _objc_release(uVar8);
      uVar9 = *(undefined8 *)(PTR__UILayoutFittingCompressedSize_010605c8 + 8);
      _objc_msgSend(*(undefined8 *)PTR__UILayoutFittingCompressedSize_010605c8,uVar9,uVar5,
                    @selector(systemLayoutSizeFittingSize:));
      _objc_msgSend(param_1,puVar15);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,puVar13);
      _objc_msgSend(0,0,in_q2,uVar9,uVar5,puVar14);
      _objc_release(uVar8);
      _objc_msgSend(param_1,puVar15);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,@selector(setTableFooterView:),uVar5);
      _objc_release(uVar8);
      _objc_release(uVar6);
      _objc_release(uVar5);
    }
    puStack_130 = puVar15;
    _objc_storeStrong(param_1 + (long)_searchResults,*(undefined8 *)PTR____NSArray0___01060670);
    uVar5 = _objc_alloc(PTR__OBJC_CLASS___UISearchBar_0114ee08);
    _objc_msgSend(param_1,puVar15);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar13);
    uVar5 = _objc_msgSend(0,0,in_q2,DAT_00c4c358,uVar5,@selector(initWithFrame:));
    lVar7 = (long)_searchBar;
    uVar8 = *(undefined8 *)(param_1 + lVar7);
    *(undefined8 *)(param_1 + lVar7) = uVar5;
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(setDelegate:),param_1);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(setReturnKeyType:),9);
    _objc_msgSend(@"Search",@selector(ytl_localized));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(setPlaceholder:),uVar5);
    _objc_release(uVar5);
    uVar5 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(new));
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(setBackgroundImage:),uVar5);
    _objc_release(uVar5);
    _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(adaptiveBackgroundColor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(setBackgroundColor:),uVar5);
    _objc_release(uVar5);
    puVar1 = @selector(searchTextField);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(searchTextField));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setEnablesReturnKeyAutomatically:),0);
    _objc_release(uVar5);
    _objc_msgSend(param_1,puVar15);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(tintColor));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(setTintColor:),uVar6);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(layer);
    _objc_msgSend(uVar5,@selector(layer));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0,uVar6,@selector(setCornerRadius:));
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar14);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setMasksToBounds:),1);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar16,0);
    _objc_release(uVar5);
    _objc_msgSend(param_1,@selector(_removeSearchFieldCornerRadius:),
                  *(undefined8 *)(param_1 + lVar7));
    puStack_158 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    puStack_120 = (undefined *)_objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(leadingAnchor);
    _objc_msgSend(puStack_120,@selector(leadingAnchor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_138 = uVar5;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar14);
    uStack_140 = _objc_retainAutoreleasedReturnValue();
    puVar13 = @selector(constraintEqualToAnchor:);
    _objc_msgSend(uVar5,@selector(constraintEqualToAnchor:),uStack_140);
    uStack_148 = _objc_retainAutoreleasedReturnValue();
    puVar2 = puStack_128;
    *puStack_128 = uStack_148;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uStack_150 = _objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(trailingAnchor);
    _objc_msgSend(uStack_150,@selector(trailingAnchor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_160 = uVar5;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar14);
    uStack_168 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar13,uStack_168);
    uStack_170 = _objc_retainAutoreleasedReturnValue();
    puVar2[1] = uStack_170;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uStack_178 = _objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(topAnchor);
    _objc_msgSend(uStack_178,@selector(topAnchor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_180 = uVar5;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar14);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar13,uVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar2[2] = uVar5;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(bottomAnchor);
    _objc_msgSend(uVar8,@selector(bottomAnchor));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar14);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,puVar13,uVar10);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    puVar2[3] = uVar11;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puVar2,4
                 );
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puStack_158,@selector(activateConstraints:),uVar12);
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar5);
    _objc_release(uVar6);
    _objc_release(uStack_180);
    _objc_release(uStack_178);
    _objc_release(uStack_170);
    _objc_release(uStack_168);
    _objc_release(uStack_160);
    _objc_release(uStack_150);
    _objc_release(uStack_148);
    _objc_release(uStack_140);
    _objc_release(uStack_138);
    _objc_release(puStack_120);
    uVar6 = *(undefined8 *)(param_1 + lVar7);
    _objc_msgSend(param_1,puStack_130);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setTableHeaderView:),uVar6);
    _objc_release(uVar5);
  }
  CallSupervisor(0x4e4);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[DVNTableViewController viewWillAppear:], 0x118008
/* Decompiled from supplied 5.2.2 arm package. VA 0x118008. viewWillAppear: */

/* Function Stack Size: 0x14 bytes */

void DVNTableViewController::viewWillAppear_(ID param_1,SEL param_2,bool param_3)

{
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_DVNTableViewController_0114f0a8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,@selector(viewWillAppear:),param_3);
  _objc_msgSend(param_1,@selector(_removeSearchFieldCornerRadius:),
                *(undefined8 *)(param_1 + (long)_searchBar));
  return;
}



// -[DVNTableViewController traitCollectionDidChange:], 0x118064
/* Decompiled from supplied 5.2.2 arm package. VA 0x118064. traitCollectionDidChange: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::traitCollectionDidChange_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  ID local_50;
  undefined *puStack_48;
  int local_3c;
  undefined **local_38;
  
  puVar1 = @selector(traitCollectionDidChange:);
  local_38 = &PTR_LAB_0118cd10;
  puStack_48 = PTR_DVNTableViewController_0114f0a8;
  local_50 = param_1;
  _objc_retain(param_3);
  _objc_msgSendSuper2(&local_50,puVar1,param_3);
  _objc_msgSend(param_1,@selector(traitCollection));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00126bf8(uVar3,@selector(hasDifferentColorAppearanceComparedToTraitCollection:),param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  if (iVar2 != 0) {
    local_3c = iVar2;
    _objc_msgSend(param_1,@selector(_removeSearchFieldCornerRadius:),
                  *(undefined8 *)(param_1 + (long)_searchBar));
  }
  CallSupervisor(0x11d4);
  return;
}



// -[DVNTableViewController searchBarSearchButtonClicked:], 0x118178
/* Decompiled from supplied 5.2.2 arm package. VA 0x118178. searchBarSearchButtonClicked: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarSearchButtonClicked_(ID param_1,SEL param_2,ID param_3)

{
  FUN_00126c40(param_3,@selector(resignFirstResponder));
  CallSupervisor(0x4575);
  return;
}



// -[DVNTableViewController _removeSearchFieldCornerRadius:], 0x1181b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1181b0. _removeSearchFieldCornerRadius: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_removeSearchFieldCornerRadius_(ID param_1,SEL param_2,ID param_3)

{
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  
  _objc_retain(param_3);
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_0011824c;
  puStack_30 = &DAT_01061420;
  local_28 = param_3;
  _objc_retain(param_3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_48);
  _objc_release(local_28);
  _objc_release(param_3);
  CallSupervisor(5);
  return;
}



// -[DVNTableViewController _performSearch:], 0x118500
/* Decompiled from supplied 5.2.2 arm package. VA 0x118500. _performSearch: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_performSearch_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  bool bVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118cda8;
  _objc_retain(param_3);
  lVar3 = _objc_msgSend(param_3,@selector(length));
  bVar2 = lVar3 != 0;
  local_4c = (uint)bVar2;
  *(bool *)(param_1 + (long)_isSearching) = bVar2;
  if (bVar2) {
    _objc_msgSend(param_3,@selector(lowercaseString));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(model));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(cellsMatchingRecursive:);
    puStack_78 = PTR___NSConcreteStackBlock_01060660;
    uStack_70 = DAT_00c4c228;
    pcStack_68 = FUN_001186d8;
    puStack_60 = &UNK_010624c0;
    uStack_58 = uVar6;
    _objc_retain(uVar6);
    _objc_msgSend(uVar4,puVar1,&puStack_78);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar7 = *(undefined8 *)(param_1 + (long)_searchResults);
    *(undefined8 *)(param_1 + (long)_searchResults) = uVar5;
    _objc_release(uVar7);
    _objc_release(uVar4);
    _objc_release(uStack_58);
    _objc_release(uVar6);
  }
  else {
    _objc_storeStrong(param_1 + (long)_searchResults,*(undefined8 *)PTR____NSArray0___01060670);
  }
  _objc_msgSend(param_1,@selector(tableView));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(reloadData));
  _objc_release(uVar6);
  _objc_release(param_3);
  CallSupervisor(0x7ec9);
  return;
}



// -[DVNTableViewController searchBar:textDidChange:], 0x118ef0
/* Decompiled from supplied 5.2.2 arm package. VA 0x118ef0. searchBar:textDidChange: */

/* Function Stack Size: 0x20 bytes */

void DVNTableViewController::searchBar_textDidChange_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  
  puVar1 = @selector(_removeSearchFieldCornerRadius:);
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1,param_3);
  _objc_msgSend(param_1,@selector(_performSearch:),param_4);
  _objc_release(param_4);
  CallSupervisor(0x1bfc);
  return;
}



// -[DVNTableViewController searchBarCancelButtonClicked:], 0x118f70
/* Decompiled from supplied 5.2.2 arm package. VA 0x118f70. searchBarCancelButtonClicked: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarCancelButtonClicked_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  
  puVar1 = @selector(setText:);
  _objc_retain(param_3);
  _objc_msgSend(param_3,puVar1,&cf___);
  FUN_00127190(param_3,@selector(resignFirstResponder));
  _objc_release(param_3);
  _objc_msgSend(param_1,@selector(_performSearch:),&cf___);
  CallSupervisor(0x2901);
  return;
}



// -[DVNTableViewController searchBarTextDidBeginEditing:], 0x119004
/* Decompiled from supplied 5.2.2 arm package. VA 0x119004. searchBarTextDidBeginEditing: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarTextDidBeginEditing_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = @selector(searchTextField);
  DAT_01227284 = 1;
  uVar2 = _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setRightViewMode:),3);
  _objc_release(uVar2);
  uVar2 = _NSClassFromString(@"YTQTMButton");
  _objc_msgSend(uVar2,@selector(iconButton));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(enableNewTouchFeedback));
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),
                @"xmark.circle.fill");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setImage:forState:),uVar3,0);
  _objc_release(uVar3);
  _objc_msgSend(param_1,@selector(tableView));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(tintColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setTintColor:),uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(_searchClearTapped:),0x40);
  _objc_msgSend(param_3,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setRightView:),uVar2);
  _objc_release(uVar3);
  _objc_msgSend(param_1,@selector(_removeSearchFieldCornerRadius:),param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0x2cbe);
  return;
}



// -[DVNTableViewController searchBarTextDidEndEditing:], 0x11941c
/* Decompiled from supplied 5.2.2 arm package. VA 0x11941c. searchBarTextDidEndEditing: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarTextDidEndEditing_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = @selector(searchTextField);
  _objc_retain(param_3);
  _objc_msgSend(param_3,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setRightView:),0);
  _objc_release(uVar2);
  _objc_msgSend(param_3,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setRightViewMode:),0);
  _objc_release(uVar2);
  _objc_msgSend(param_1,@selector(_removeSearchFieldCornerRadius:),param_3);
  _objc_release(param_3);
  CallSupervisor(0xa87a);
  return;
}



// -[DVNTableViewController _searchClearTapped:], 0x1194e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1194e8. _searchClearTapped: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_searchClearTapped_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  lVar1 = (long)_searchBar;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar1),@selector(setText:),&cf___);
  FUN_00127458(*(undefined8 *)(param_1 + lVar1),@selector(resignFirstResponder));
  _objc_msgSend(param_1,@selector(_performSearch:),&cf___);
  _objc_msgSend(param_1,@selector(_removeSearchFieldCornerRadius:),
                *(undefined8 *)(param_1 + lVar1));
  CallSupervisor(0xb727);
  return;
}



// -[DVNTableViewController navigateToCell:], 0x119580
/* Decompiled from supplied 5.2.2 arm package. VA 0x119580. navigateToCell: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::navigateToCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  _objc_retain(param_3);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_model));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend();
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x001196d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118cf90)[lVar2 == 0] + (int)-(DAT_0118cfa0 ^ 0xcc2d0334)))();
  return;
}



// -[DVNTableViewController cellExistsInModel:target:], 0x119e58
/* Decompiled from supplied 5.2.2 arm package. VA 0x119e58. cellExistsInModel:target: */

/* Function Stack Size: 0x20 bytes */

bool DVNTableViewController::cellExistsInModel_target_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  bool bVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  uint local_184;
  undefined **local_180;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_180 = &PTR_LAB_0118d0e8;
  _objc_retain(param_4);
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  _objc_msgSend(param_3,@selector(sections));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar2,@selector(countByEnumeratingWithState:objects:count:),&local_1d0,auStack_f8,
                        0x10);
  local_184 = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x00119fac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (*(code *)(local_180[local_184] + (int)-(DAT_0118d0f8 ^ 0x2e843ed6)))();
  return bVar1;
}



// -[DVNTableViewController highlightRowAtIndexPath:], 0x11a490
/* Decompiled from supplied 5.2.2 arm package. VA 0x11a490. highlightRowAtIndexPath: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::highlightRowAtIndexPath_(ID param_1,SEL param_2,ID param_3)

{
  dispatch_time_t dVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID local_38;
  
  _objc_retain(param_3);
  dVar1 = _dispatch_time(0,350000000);
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_0011a538;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = param_3;
  _objc_retain(param_3);
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&local_60);
  _objc_release(local_38);
  _objc_release(param_3);
  return;
}



// -[DVNTableViewController viewDidAppear:], 0x11a718
/* Decompiled from supplied 5.2.2 arm package. VA 0x11a718. viewDidAppear: */

/* Function Stack Size: 0x14 bytes */

void DVNTableViewController::viewDidAppear_(ID param_1,SEL param_2,bool param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  ID local_50;
  undefined *puStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_0118d228;
  puStack_48 = PTR_DVNTableViewController_0114f0a8;
  local_50 = param_1;
  _objc_msgSendSuper2(&local_50,@selector(viewDidAppear:),param_3);
  puVar1 = @selector(pendingScrollCell);
  _objc_msgSend(param_1,@selector(pendingScrollCell));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  local_3c = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    _objc_msgSend(local_38[local_3c] + (int)-(DAT_0118d238 ^ 0x52c1e8fa),param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(navigateToCell:),uVar3);
    _objc_release(uVar3);
    _objc_msgSend(param_1,@selector(setPendingScrollCell:),0);
  }
  CallSupervisor(0xeb1e);
  return;
}



// -[DVNTableViewController pushController:withTitle:], 0x11a830
/* Decompiled from supplied 5.2.2 arm package. VA 0x11a830. pushController:withTitle: */

/* Function Stack Size: 0x20 bytes */

void DVNTableViewController::pushController_withTitle_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  
  DAT_012272b0 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar1 = @selector(parentViewController);
  _objc_msgSend(param_1,@selector(parentViewController));
  lVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(isKindOfClass:);
  if (lVar4 == 0) {
    uVar5 = _objc_getClass((&PTR_LAB_0118d268)[lVar4 == 0] + (int)-(DAT_0118d278 ^ 0x7802c308),
                           s_YTWrapperFlatViewController_0118ba30);
    uVar5 = _objc_msgSend(uVar5,@selector(alloc));
    _objc_msgSend(param_1,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar5 = _objc_msgSend(uVar5,@selector(initWithParentResponder:),uVar7);
    _objc_release(uVar7);
    _objc_msgSend(uVar5,@selector(setTitle:),param_4);
    _objc_msgSend(uVar5,@selector(setContent:),param_3);
    _objc_msgSend(uVar5,@selector(headerViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(updateHeaderWithButtonsToDisplay:),
                  *(undefined8 *)PTR____NSArray0___01060670);
    _objc_release(uVar7);
    _objc_msgSend(param_1,@selector(navigationController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(pushViewController:animated:),uVar5,1);
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(0);
    _objc_release(0);
    _objc_release(param_4);
    _objc_release(param_3);
    return;
  }
  uVar5 = _objc_getClass(s_YTWrapperSplitViewController_0118ba70);
  uVar3 = FUN_00127d10(lVar4,puVar2,uVar5);
  if (uVar3 == 0) {
    _objc_msgSend(lVar4,puVar1);
    lVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(lVar4);
                    /* WARNING: Could not recover jumptable at 0x0011ad68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_0118d2a0)[lVar6 == 0] + (int)-(uRam000000000118d2b0 ^ 0x460b5ae1)))();
    return;
  }
  uVar5 = _objc_retain((&PTR_LAB_0118d288)[uVar3] + (int)-(uRam000000000118d298 ^ 0x10c1ab32),lVar4)
  ;
  _objc_msgSend(uVar5,@selector(secondViewController));
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0011adc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118d2b8)[lVar4 == 0] + (int)-(DAT_0118d2c8 ^ 0x7572c77e)))();
  return;
}



// -[DVNTableViewController addDismissButton:], 0x11afa0
/* Decompiled from supplied 5.2.2 arm package. VA 0x11afa0. addDismissButton: */

/* Function Stack Size: 0x14 bytes */

void DVNTableViewController::addDismissButton_(ID param_1,SEL param_2,bool param_3)

{
  undefined **ppuVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithBarButtonSystemItem:target:action:),0x18,param_1,
                        @selector(closeButtonTapped));
  _objc_msgSend(param_1,@selector(navigationItem));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &@selector(setLeftBarButtonItem:);
  if (param_3 == 0) {
    ppuVar1 = &@selector(setRightBarButtonItem:);
  }
  _objc_msgSend(uVar3,*ppuVar1,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xcffc);
  return;
}



// -[DVNTableViewController closeButtonTapped], 0x11b05c
/* Decompiled from supplied 5.2.2 arm package. VA 0x11b05c. closeButtonTapped */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::closeButtonTapped(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(dismissViewControllerAnimated:completion:),1,0);
  CallSupervisor(0xa1ed);
  return;
}



// -[DVNTableViewController addLeftBarItem:image:handler:], 0x11b098
/* Decompiled from supplied 5.2.2 arm package. VA 0x11b098. addLeftBarItem:image:handler: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::addLeftBarItem_image_handler_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined **ppuVar4;
  
  ppuVar4 = &PTR__objc_msgSend_0118c130;
  DAT_012272bc = 1;
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar1 = PTR__OBJC_CLASS___UIBarButtonItem_0114ee18;
  _objc_retain(param_3);
  uVar2 = _objc_alloc(puVar1);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithTitle:style:target:action:),param_3,0,param_1,
                        @selector(_barButtonTriggered:),in_x6,in_x7,ppuVar4);
  _objc_release(param_3);
  if (param_4 != 0) {
    _objc_msgSend(uVar2,@selector(setImage:),param_4);
  }
  uVar3 = _objc_retainBlock(param_5);
  _objc_setAssociatedObject(uVar2,@"handler",uVar3,3);
  _objc_release(uVar3);
  _objc_msgSend(param_1,@selector(navigationItem));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setLeftBarButtonItem:),uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(param_5);
  _objc_release(param_4);
  CallSupervisor(0x1a54);
  return;
}



// -[DVNTableViewController addRightBarItem:image:handler:], 0x11b2fc
/* Decompiled from supplied 5.2.2 arm package. VA 0x11b2fc. addRightBarItem:image:handler: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::addRightBarItem_image_handler_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined **ppuVar4;
  
  ppuVar4 = &PTR__objc_msgSend_0118c130;
  DAT_012272c0 = 1;
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar1 = PTR__OBJC_CLASS___UIBarButtonItem_0114ee18;
  _objc_retain(param_3);
  uVar2 = _objc_alloc(puVar1);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithTitle:style:target:action:),param_3,0,param_1,
                        @selector(_barButtonTriggered:),in_x6,in_x7,ppuVar4);
  _objc_release(param_3);
  if (param_4 != 0) {
    _objc_msgSend(uVar2,@selector(setImage:),param_4);
  }
  uVar3 = _objc_retainBlock(param_5);
  _objc_setAssociatedObject(uVar2,@"handler",uVar3,3);
  _objc_release(uVar3);
  _objc_msgSend(param_1,@selector(navigationItem));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setRightBarButtonItem:),uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(param_5);
  _objc_release(param_4);
  CallSupervisor(0xc848);
  return;
}



// -[DVNTableViewController _barButtonTriggered:], 0x11b560
/* Decompiled from supplied 5.2.2 arm package. VA 0x11b560. _barButtonTriggered: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_barButtonTriggered_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  DAT_012272c4 = 1;
  _objc_getAssociatedObject(param_3,@"handler");
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    (**(code **)(lVar1 + 0x10))(lVar1);
  }
  _objc_release(lVar1);
  return;
}



// -[DVNTableViewController setupThanksHeart], 0x11b6d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x11b6d0. setupThanksHeart */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::setupThanksHeart(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 auStack_b0 [16];
  undefined *puStack_a0;
  undefined8 uStack_98;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  puStack_90 = (undefined1 *)&puStack_a0;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_0118d3a0;
  local_74 = (uint)(DAT_012272c8 == 0);
  local_80 = &PTR__objc_msgSend_0118c130;
  DAT_012272c8 = 1;
  puStack_88 = auStack_b0;
  uVar4 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  _objc_msgSend(uVar4,@selector(setTextAlignment:),1);
  _objc_msgSend(uVar4,@selector(setText:),&PTR____CFConstantStringClassReference_0118bc70);
  _objc_msgSend(DAT_00c4c360,PTR__OBJC_CLASS___UIFont_0114ec08,@selector(systemFontOfSize:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setFont:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(uVar4,@selector(sizeToFit));
  puVar2 = @selector(tableView);
  _objc_msgSend(param_1,@selector(tableView));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(addSubview:),uVar4);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,@selector(animationWithKeyPath:),
                @"transform.scale");
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(numberWithDouble:);
  _objc_msgSend(DAT_00c4c368,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setFromValue:),uVar6);
  _objc_release(uVar6);
  _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setToValue:),uVar6);
  _objc_release(uVar6);
  _objc_msgSend(uVar5,@selector(setAutoreverses:),1);
  _objc_msgSend(0x7f800000,uVar5,@selector(setRepeatCount:));
  _objc_msgSend(0x3fe0000000000000,uVar5,@selector(setDuration:));
  _objc_msgSend(uVar4,@selector(layer));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(addAnimation:forKey:),uVar5,
                @"scaleAnimation");
  _objc_release(uVar6);
  puVar1 = @selector(centerXAnchor);
  puStack_a0 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar4,@selector(centerXAnchor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_98 = uVar6;
  _objc_msgSend(param_1,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(constraintEqualToAnchor:),uVar8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_90;
  *(undefined8 *)(puStack_90 + -0x10) = uVar6;
  _objc_msgSend(uVar4,@selector(bottomAnchor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,@selector(topAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc02e000000000000,uVar9,@selector(constraintEqualToAnchor:constant:),uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar3 + -8) = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puStack_88
                ,2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_a0,@selector(activateConstraints:),uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar6);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uStack_98);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0xaa45);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[DVNTableViewController tableView:heightForRowAtIndexPath:], 0x11bd8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x11bd8c. tableView:heightForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

double DVNTableViewController::tableView_heightForRowAtIndexPath_
                 (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  return *(double *)PTR__UITableViewAutomaticDimension_010605d8;
}



// -[DVNTableViewController tableView:titleForHeaderInSection:], 0x11bd9c
/* Decompiled from supplied 5.2.2 arm package. VA 0x11bd9c. tableView:titleForHeaderInSection: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::tableView_titleForHeaderInSection_
             (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  SEL extraout_x1;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),@selector(sections));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(objectAtIndexedSubscript:),param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(header));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
    _objc_release(uVar1);
    param_2 = extraout_x1;
  }
  else {
    uVar4 = 0;
  }
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4,param_2);
  return IVar3;
}



// -[DVNTableViewController tableView:titleForFooterInSection:], 0x11be90
/* Decompiled from supplied 5.2.2 arm package. VA 0x11be90. tableView:titleForFooterInSection: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::tableView_titleForFooterInSection_
             (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  SEL extraout_x1;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),@selector(sections));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(objectAtIndexedSubscript:),param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(footer));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
    _objc_release(uVar1);
    param_2 = extraout_x1;
  }
  else {
    uVar4 = 0;
  }
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4,param_2);
  return IVar3;
}



// -[DVNTableViewController tableView:willDisplayHeaderView:forSection:], 0x11bf84
/* Decompiled from supplied 5.2.2 arm package. VA 0x11bf84. tableView:willDisplayHeaderView:forSection: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::tableView_willDisplayHeaderView_forSection_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  
  DAT_012272d8 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar3 = @selector(tableView:titleForHeaderInSection:);
  _objc_msgSend(param_1,@selector(tableView:titleForHeaderInSection:),param_3,param_5);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(textLabel);
  _objc_msgSend(param_4,@selector(textLabel));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setText:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(0x402c000000000000,*(undefined8 *)PTR__UIFontWeightLight_01060568,
                PTR__OBJC_CLASS___UIFont_0114ec08,@selector(systemFontOfSize:weight:));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setFont:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setTextColor:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setTextAlignment:),4);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setNumberOfLines:),0);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),@selector(sections));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(objectAtIndexedSubscript:),param_5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar1 = @selector(headerIcon);
  _objc_msgSend(uVar5,@selector(headerIcon));
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar6 != 0) {
    _objc_msgSend((&PTR_LAB_0118d420)[lVar6 == 0] + (int)-(uRam000000000118d430 ^ 0x53e6afd6),uVar5,
                  puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(headerImage:),uVar4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uVar4 = _objc_alloc_init(PTR__OBJC_CLASS___NSTextAttachment_0114ee28);
    _objc_msgSend(uVar4,@selector(setImage:),uVar7);
    _objc_msgSend(0,0xc008000000000000,0x4030000000000000,0x4030000000000000,uVar4,
                  @selector(setBounds:));
    uVar8 = _objc_alloc_init(PTR__OBJC_CLASS___NSMutableAttributedString_0114ec28);
    _objc_msgSend(PTR__OBJC_CLASS___NSAttributedString_0114ee30,
                  @selector(attributedStringWithAttachment:),uVar4);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar10 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    puVar1 = @selector(initWithString:);
    uVar10 = _objc_msgSend(uVar10,@selector(initWithString:),
                           @" ");
    uVar11 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    _objc_msgSend(param_1,puVar3,param_3,param_5);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uVar11 = _objc_msgSend(uVar11,puVar1,uVar12);
    _objc_release(uVar12);
    puVar3 = @selector(appendAttributedString:);
    _objc_msgSend(uVar8,@selector(appendAttributedString:),uVar9);
    _objc_msgSend(uVar8,puVar3,uVar10);
    _objc_msgSend(uVar8,puVar3,uVar11);
    _objc_msgSend(param_4,puVar2);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,@selector(setAttributedText:),uVar8);
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar4);
    _objc_release(uVar7);
  }
  _objc_release(uVar5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xcda3);
  return;
}



// -[DVNTableViewController tableView:willDisplayFooterView:forSection:], 0x11c4a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x11c4a4. tableView:willDisplayFooterView:forSection: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::tableView_willDisplayFooterView_forSection_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_4);
  puVar2 = PTR__OBJC_CLASS___UIFont_0114ec08;
  puVar1 = @selector(systemFontOfSize:weight:);
  uVar4 = *(undefined8 *)PTR__UIFontWeightLight_01060568;
  _objc_retain(param_3);
  _objc_msgSend(0x402a000000000000,uVar4,puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(textLabel);
  _objc_msgSend(param_4,@selector(textLabel));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setFont:),uVar4);
  _objc_release(uVar3);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTextColor:),uVar4);
  _objc_release(uVar3);
  _objc_release(uVar4);
  _objc_msgSend(param_1,@selector(tableView:titleForFooterInSection:),param_3,param_5);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setText:),uVar4);
  _objc_release(uVar3);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setTextAlignment:),4);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setNumberOfLines:),0);
  _objc_release(uVar4);
  _objc_release(param_4);
  return;
}



// -[DVNTableViewController tableView:heightForFooterInSection:], 0x11c698
/* Decompiled from supplied 5.2.2 arm package. VA 0x11c698. tableView:heightForFooterInSection: */

/* Function Stack Size: 0x20 bytes */

double DVNTableViewController::tableView_heightForFooterInSection_
                 (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double in_d2;
  double in_d3;
  double dVar4;
  undefined8 uStack_58;
  undefined8 uStack_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  _objc_retain(param_3);
  _objc_msgSend(param_1,@selector(tableView:titleForFooterInSection:),param_3,param_4);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 == 0) {
    dVar4 = 0.0;
  }
  else {
    _objc_msgSend(param_3,@selector(frame));
    uStack_58 = *(undefined8 *)PTR__NSFontAttributeName_01060368;
    _objc_msgSend(0x402a000000000000,*(undefined8 *)PTR__UIFontWeightLight_01060568,
                  PTR__OBJC_CLASS___UIFont_0114ec08,@selector(systemFontOfSize:weight:));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uStack_50 = uVar2;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  @selector(dictionaryWithObjects:forKeys:count:),&uStack_50,&uStack_58,1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 + -40.0,0x7fefffffffffffff,lVar1,
                  @selector(boundingRectWithSize:options:attributes:context:),1,uVar3,0);
    _objc_release(uVar3);
    _objc_release(uVar2);
    dVar4 = (double)(long)in_d3 + 10.0;
  }
  _objc_release(lVar1);
  _objc_release(param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return dVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[DVNTableViewController numberOfSectionsInTableView:], 0x11c868
/* Decompiled from supplied 5.2.2 arm package. VA 0x11c868. numberOfSectionsInTableView: */

/* Function Stack Size: 0x18 bytes */

long_long DVNTableViewController::numberOfSectionsInTableView_(ID param_1,SEL param_2,ID param_3)

{
  long_long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),@selector(sections));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    lVar1 = _objc_msgSend(uVar2,@selector(count));
    _objc_release(uVar2);
  }
  else {
    lVar1 = 1;
  }
  return lVar1;
}



// -[DVNTableViewController tableView:numberOfRowsInSection:], 0x11c924
/* Decompiled from supplied 5.2.2 arm package. VA 0x11c924. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long DVNTableViewController::tableView_numberOfRowsInSection_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long_long lVar4;
  
  if (*(char *)(param_1 + (long)_isSearching) != '\0') {
    lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_searchResults),@selector(count));
    return lVar4;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),@selector(sections));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(objectAtIndexedSubscript:),param_4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(_cellsForSection:),uVar2);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  lVar4 = _objc_msgSend(uVar3,@selector(count));
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return lVar4;
}



// -[DVNTableViewController _cellForIndexPath:], 0x11ca5c
/* Decompiled from supplied 5.2.2 arm package. VA 0x11ca5c. _cellForIndexPath: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::_cellForIndexPath_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  undefined8 uVar7;
  
  puVar2 = @selector(sections);
  puVar1 = @selector(row);
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    uVar3 = *(undefined8 *)(param_1 + (long)_model);
    _objc_retain(param_3);
    _objc_msgSend(uVar3,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(param_3,@selector(section));
    puVar1 = @selector(objectAtIndexedSubscript:);
    _objc_msgSend(uVar7,@selector(objectAtIndexedSubscript:),uVar3);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(_cellsForSection:),uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(param_3,@selector(row));
    _objc_release(param_3);
    _objc_msgSend(uVar5,puVar1,uVar3);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar7);
  }
  else {
    uVar7 = *(undefined8 *)(param_1 + (long)_searchResults);
    uVar3 = _objc_retain(param_3);
    uVar3 = _objc_msgSend(uVar3,puVar1);
    _objc_release(param_3);
    _objc_msgSend(uVar7,@selector(objectAtIndexedSubscript:),uVar3);
    uVar3 = _objc_retainAutoreleasedReturnValue();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar6;
}



// -[DVNTableViewController tableView:cellForRowAtIndexPath:], 0x11cc18
/* Decompiled from supplied 5.2.2 arm package. VA 0x11cc18. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::tableView_cellForRowAtIndexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  ID IVar7;
  long lVar8;
  undefined8 uVar9;
  
  DAT_012272f0 = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_1,@selector(_cellForIndexPath:),param_4);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_alloc(PTR_YTPTableViewCell_0114ee38);
  puVar1 = @selector(type);
  lVar5 = _objc_msgSend(uVar3,@selector(type));
  if (lVar5 != 0xc) {
    lVar5 = _objc_msgSend((&PTR_LAB_0118d4f0)[lVar5 == 0xc] +
                          (int)-(uRam000000000118d500 ^ 0x9588c42a),uVar3,puVar1);
    if ((lVar5 != 6) &&
       (lVar5 = _objc_msgSend((&PTR_LAB_0118d508)[lVar5 == 6] +
                              (int)-(uRam000000000118d518 ^ 0x45b80716),uVar3,puVar1), lVar5 != 0xb)
       ) {
      uVar9 = 3;
      goto LAB_0011d0cc;
    }
  }
  uVar9 = 1;
LAB_0011d0cc:
  _objc_msgSend(uVar3,@selector(reuseIdentifier));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar4,@selector(initWithStyle:reuseIdentifier:),uVar9,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(uVar3,@selector(setSourceView:),uVar4);
  puVar2 = @selector(title);
  _objc_msgSend(uVar3,@selector(title));
  lVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar5 != 0) {
    _objc_msgSend(uVar3,puVar2);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(textLabel));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(setText:),uVar9);
    _objc_release(uVar4);
    _objc_release(uVar9);
    _objc_msgSend(uVar3,@selector(subtitle));
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0011d228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar7 = (*(code *)((&PTR_LAB_0118d560)[lVar5 == 0] + (int)-(uRam000000000118d570 ^ 0x5e65afda)))
                      ();
    return IVar7;
  }
  _objc_msgSend((&PTR_LAB_0118d540)[lVar5 == 0] + (int)-(uRam000000000118d550 ^ 0x41243c52),uVar3,
                @selector(subtitle));
  lVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(subtitleProvider);
  if (lVar5 == 0) {
    _objc_msgSend(uVar3,@selector(subtitleProvider));
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    if (lVar5 != 0) {
      _objc_msgSend((&PTR_LAB_0118d5d8)[lVar5 == 0] + (int)-(uRam000000000118d5e8 ^ 0x61fa3116),
                    uVar3,puVar2);
      lVar5 = _objc_retainAutoreleasedReturnValue();
      (**(code **)(lVar5 + 0x10))();
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(detailTextLabel));
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(setText:),uVar9);
      _objc_release(uVar4);
      _objc_release(uVar9);
      _objc_release(lVar5);
    }
    _objc_msgSend(uVar3,@selector(icon));
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0011d528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar7 = (*(code *)((&PTR_LAB_0118d5f8)[lVar5 == 0] + (int)-(uRam000000000118d608 ^ 0xcf807cc0)))
                      ();
    return IVar7;
  }
  lVar8 = _objc_msgSend((&PTR_LAB_0118d5a0)[lVar5 == 0] + (int)-(uRam000000000118d5b0 ^ 0xb8262d79),
                        uVar3,puVar1);
  _objc_release(lVar5);
                    /* WARNING: Could not recover jumptable at 0x0011d3ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar7 = (*(code *)((&PTR_LAB_0118d5b8)[lVar8 == 3] + (int)-(uRam000000000118d5c8 ^ 0xd3040ec9)))()
  ;
  return IVar7;
}



// -[DVNTableViewController tableView:didSelectRowAtIndexPath:], 0x11f264
/* Decompiled from supplied 5.2.2 arm package. VA 0x11f264. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void DVNTableViewController::tableView_didSelectRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auStack_2a0 [64];
  undefined1 auStack_260 [48];
  undefined1 *puStack_230;
  undefined1 *puStack_228;
  ID IStack_220;
  undefined **local_218;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **ppuStack_1f0;
  undefined **local_1e0;
  undefined **ppuStack_1d8;
  undefined **local_1c8;
  undefined **local_1c0;
  undefined **ppuStack_1b8;
  undefined **local_1a8;
  undefined **local_198;
  undefined **ppuStack_190;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **local_148;
  undefined **ppuStack_140;
  uint uStack_134;
  undefined **local_130;
  undefined **ppuStack_128;
  undefined **local_120;
  undefined **ppuStack_118;
  uint uStack_10c;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  int iStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_0118d970;
  local_74 = (uint)(DAT_012272f4 == 0);
  local_88 = &PTR_LAB_0118d990;
  local_a0 = &PTR_LAB_0118d9b0;
  local_b0 = &PTR_LAB_0118d9c8;
  local_80 = &PTR__objc_msgSend_0118c130;
  local_98 = &PTR__objc_msgSend_0118c130;
  local_c8 = &PTR__objc_msgSend_0118c130;
  ppuStack_c0 = &PTR__objc_msgSend_0118c130;
  local_d0 = &PTR_LAB_0118d9f0;
  local_e0 = &PTR_LAB_0118da08;
  local_f8 = &PTR_LAB_0118da28;
  ppuStack_f0 = &PTR__objc_msgSend_0118c130;
  local_108 = &PTR_LAB_0118da40;
  local_120 = &PTR__objc_msgSend_0118c130;
  ppuStack_118 = &PTR__objc_msgSend_0118c130;
  local_130 = &PTR_LAB_0118da70;
  ppuStack_128 = &PTR__objc_msgSend_0118c130;
  local_148 = &PTR_LAB_0118da90;
  ppuStack_140 = &PTR__objc_msgSend_0118c130;
  local_158 = &PTR_LAB_0118daa8;
  local_170 = &PTR__objc_msgSend_0118c130;
  ppuStack_168 = &PTR__objc_msgSend_0118c130;
  local_180 = &PTR_LAB_0118dad8;
  ppuStack_178 = &PTR__objc_msgSend_0118c130;
  local_198 = &PTR_LAB_0118daf8;
  ppuStack_190 = &PTR__objc_msgSend_0118c130;
  local_1a8 = &PTR_LAB_0118db10;
  local_1c0 = &PTR__objc_msgSend_0118c130;
  ppuStack_1b8 = &PTR__objc_msgSend_0118c130;
  local_1c8 = &PTR_LAB_0118db38;
  local_1e0 = &PTR_LAB_0118db58;
  ppuStack_1d8 = &PTR__objc_msgSend_0118c130;
  local_1f8 = &PTR_LAB_0118db78;
  ppuStack_1f0 = &PTR__objc_msgSend_0118c130;
  local_210 = &PTR__objc_msgSend_0118c130;
  ppuStack_208 = &PTR__objc_msgSend_0118c130;
  local_218 = &PTR__objc_msgSend_0118c130;
  DAT_012272f4 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_msgSend(param_1,@selector(_cellForIndexPath:),param_4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(type);
  bVar3 = *(char *)(param_1 + (long)_isSearching) == '\0';
  uStack_8c = (uint)bVar3;
  if (!bVar3) {
    FUN_0012b348(*(undefined8 *)(param_1 + (long)_searchBar),@selector(resignFirstResponder));
    _objc_msgSend(param_3,@selector(deselectRowAtIndexPath:animated:),param_4,1);
    _objc_msgSend(param_1,@selector(navigateToCell:),uVar5);
    _objc_release(uVar5);
    _objc_release(param_4);
    _objc_release(param_3);
    CallSupervisor(0x2b24);
    return;
  }
  puStack_230 = auStack_2a0;
  puStack_228 = auStack_260;
  lVar6 = _objc_msgSend(uVar5,@selector(type));
  uStack_a4 = (uint)(lVar6 == 0);
  if (lVar6 == 0) {
    _objc_msgSend(param_3,@selector(cellForRowAtIndexPath:),param_4);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(accessoryView));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_getClass(s_ABCSwitch_0118bdb2);
    iStack_b4 = FUN_0012af98(uVar9,@selector(isKindOfClass:),uVar7);
    if (iStack_b4 != 0) {
      _objc_msgSend(uVar9,@selector(prepareHapticFeedback));
      uVar4 = FUN_0012adc8(uVar9,@selector(isOn));
      _objc_msgSend(uVar9,@selector(setOn:animated:userGenerated:),uVar4 ^ 1,1,1);
      _objc_msgSend(uVar9,@selector(releaseHapticFeedback));
      _objc_msgSend(uVar9,@selector(fireHapticFeedback));
    }
    _objc_release(uVar9);
    _objc_release(uVar8);
  }
  lVar6 = _objc_msgSend(uVar5,puVar1);
  uStack_d4 = (uint)(lVar6 == 3);
  IStack_220 = param_3;
  if (lVar6 == 3) {
    _objc_msgSend(uVar5,@selector(subtitle));
    lVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    uStack_e4 = (uint)(lVar6 == 0);
                    /* WARNING: Could not recover jumptable at 0x0011f7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_e0[uStack_e4] + (int)-(uRam000000000118da18 ^ 0xa25f9202)))();
    return;
  }
  lVar6 = _objc_msgSend(local_d0[uStack_d4] + (int)-(uRam000000000118da00 ^ 0x526baf00),uVar5,puVar1
                       );
  uStack_fc = (uint)(lVar6 == 8);
  if (lVar6 == 8) {
    _objc_msgSend(param_3,@selector(cellForRowAtIndexPath:),param_4);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(accessoryView));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(styleRequestedColorPickerPresentation);
    uStack_10c = FUN_0012b320(uVar9,@selector(respondsToSelector:),
                              @selector(styleRequestedColorPickerPresentation));
    if (uStack_10c == 0) {
      _objc_msgSend(uVar9,@selector(performSelector:),@selector(invokeColorPicker:));
    }
    else {
      _objc_msgSend(local_108[uStack_10c] + (int)-(uRam000000000118da50 ^ 0x684dc1b5),uVar9,puVar2);
    }
    _objc_release(uVar9);
    _objc_release(uVar8);
  }
  lVar6 = _objc_msgSend(uVar5,puVar1);
  uStack_134 = (uint)(lVar6 == 0xb);
                    /* WARNING: Could not recover jumptable at 0x0011f9ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_130[uStack_134] + (int)-(uRam000000000118da80 ^ 0x5928dc12)))();
  return;
}



// -[DVNTableViewController formatSliderValue:format:], 0x1202f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1202f4. formatSliderValue:format: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::formatSliderValue_format_
             (ID param_1,SEL param_2,double param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_0122730c = 1;
  if ((long)param_4 < 2) {
    if (param_4 == 1) {
      thunk_FUN_0012b4ec(param_3,PTR__OBJC_CLASS___NSString_0114eb38,
                         @selector(stringWithFormat:),
                         @"%.2fx");
      uVar2 = _objc_retainAutoreleasedReturnValue();
      goto LAB_00120594;
    }
  }
  else if (param_4 == 2) {
    uVar1 = _objc_alloc_init(PTR__OBJC_CLASS___NSDateComponentsFormatter_0114ee40);
    _objc_msgSend(uVar1,@selector(setUnitsStyle:),2);
    _objc_msgSend(param_3,uVar1,@selector(stringFromTimeInterval:));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar1);
    goto LAB_00120594;
  }
  thunk_FUN_0012b518(param_3,PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%.1f");
  uVar2 = _objc_retainAutoreleasedReturnValue();
LAB_00120594:
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// -[DVNTableViewController pickerView:viewForRow:forComponent:reusingView:], 0x1205ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1205ac. pickerView:viewForRow:forComponent:reusingView: */

/* Function Stack Size: 0x30 bytes */

ID DVNTableViewController::pickerView_viewForRow_forComponent_reusingView_
             (ID param_1,SEL param_2,ID param_3,long_long param_4,long_long param_5,ID param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  _objc_retain(param_6);
  uVar1 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_retain(param_6);
  IVar4 = param_6;
  if (param_6 == 0) {
    IVar4 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
    _objc_msgSend(IVar4,@selector(setTextAlignment:),1);
    _objc_msgSend(0x402a000000000000,*(undefined8 *)PTR__UIFontWeightRegular_01060578,
                  PTR__OBJC_CLASS___UIFont_0114ec08,@selector(systemFontOfSize:weight:));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,@selector(setFont:),uVar3);
    _objc_release(uVar3);
    _objc_msgSend(param_1,@selector(view));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(tintColor));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,@selector(setTextColor:),uVar2);
    _objc_release(uVar2);
    _objc_release(uVar3);
  }
  uVar3 = _objc_msgSend(uVar1,@selector(sliderFormat));
  _objc_msgSend((double)(long)param_4,param_1,@selector(formatSliderValue:format:),uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar4,@selector(setText:),uVar3);
  _objc_release(uVar3);
  _objc_release(uVar1);
  _objc_release(param_6);
  IVar4 = _objc_autoreleaseReturnValue(IVar4);
  return IVar4;
}



// -[DVNTableViewController numberOfComponentsInPickerView:], 0x1207bc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1207bc. numberOfComponentsInPickerView: */

/* Function Stack Size: 0x18 bytes */

long_long DVNTableViewController::numberOfComponentsInPickerView_(ID param_1,SEL param_2,ID param_3)

{
  return 1;
}



// -[DVNTableViewController pickerView:numberOfRowsInComponent:], 0x1207c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1207c4. pickerView:numberOfRowsInComponent: */

/* Function Stack Size: 0x20 bytes */

long_long DVNTableViewController::pickerView_numberOfRowsInComponent_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  double dVar2;
  
  uVar1 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  dVar2 = (double)_objc_msgSend(uVar1,@selector(maximumValue));
  _objc_release(uVar1);
  return (long)(dVar2 + 1.0);
}



// -[DVNTableViewController pickerView:didSelectRow:inComponent:], 0x120834
/* Decompiled from supplied 5.2.2 arm package. VA 0x120834. pickerView:didSelectRow:inComponent: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::pickerView_didSelectRow_inComponent_
               (ID param_1,SEL param_2,ID param_3,long_long param_4,long_long param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  double dVar6;
  
  _objc_retain(param_3);
  uVar2 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(defaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(minimumValue);
  dVar5 = (double)_objc_msgSend(uVar2,@selector(minimumValue));
  dVar6 = (double)(long)param_4;
  if (dVar5 <= dVar6) {
    dVar5 = dVar6;
  }
  _objc_msgSend(uVar2,@selector(key));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend((float)dVar5,uVar3,@selector(setFloat:forKey:),uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  dVar5 = (double)_objc_msgSend(uVar2,puVar1);
  if (dVar6 < dVar5) {
    dVar5 = (double)_objc_msgSend((&PTR_LAB_0118dc90)[dVar6 < dVar5] +
                                  (int)-(DAT_0118dca0 ^ 0xb57972e8),uVar2,puVar1);
    _objc_msgSend(param_3,@selector(selectRow:inComponent:animated:),(long)dVar5,0,1);
    dVar5 = (double)_objc_msgSend(uVar2,puVar1);
    _objc_msgSend(param_1,@selector(pickerView:didSelectRow:inComponent:),param_3,(long)dVar5,0);
  }
  _objc_release(uVar2);
  _objc_release(param_3);
  CallSupervisor(0x9b5a);
  return;
}



// -[DVNTableViewController headerImage:], 0x120a04
/* Decompiled from supplied 5.2.2 arm package. VA 0x120a04. headerImage: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::headerImage_(ID param_1,SEL param_2,ID param_3)

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
  uVar2 = _objc_msgSend(0x4030000000000000,0x4030000000000000,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_58 = PTR___NSConcreteGlobalBlock_01060658;
  local_50 = DAT_00c4c2a8;
  local_48 = FUN_00120afc;
  puStack_40 = &DAT_010619a0;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_58);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,@selector(imageWithRenderingMode:),2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(local_38);
  _objc_release(param_3);
  IVar4 = _objc_autoreleaseReturnValue(uVar2);
  return IVar4;
}



// -[DVNTableViewController iconImage:mode:size:], 0x120c58
/* Decompiled from supplied 5.2.2 arm package. VA 0x120c58. iconImage:mode:size: */

/* Function Stack Size: 0x28 bytes */

ID DVNTableViewController::iconImage_mode_size_
             (ID param_1,SEL param_2,ID param_3,long_long param_4,double param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  double local_48;
  
  _objc_retain(param_3);
  local_48 = 24.0;
  if (param_5 != 0.0) {
    local_48 = param_5;
  }
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(local_48,local_48,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_70 = PTR___NSConcreteGlobalBlock_01060658;
  local_68 = DAT_00c4c2a8;
  local_60 = FUN_00120d6c;
  puStack_58 = &DAT_010624f0;
  local_50 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(imageWithRenderingMode:),param_4);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(local_50);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// -[DVNTableViewController accessoryImage:], 0x120ec8
/* Decompiled from supplied 5.2.2 arm package. VA 0x120ec8. accessoryImage: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::accessoryImage_(ID param_1,SEL param_2,ID param_3)

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
  uVar2 = _objc_msgSend(0x4034000000000000,0x4034000000000000,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_58 = PTR___NSConcreteGlobalBlock_01060658;
  local_50 = DAT_00c4c2a8;
  local_48 = FUN_00120fbc;
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



// -[DVNTableViewController _cellForTag:], 0x121118
/* Decompiled from supplied 5.2.2 arm package. VA 0x121118. _cellForTag: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::_cellForTag_(ID param_1,SEL param_2,long_long param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),@selector(sections));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(objectAtIndexedSubscript:);
    _objc_msgSend(uVar3,@selector(objectAtIndexedSubscript:),(long)param_3 >> 0x10);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(_cellsForSection:),uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar1,param_3 & 0xffff);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  else {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_searchResults),
                  @selector(objectAtIndexedSubscript:),param_3 & 0xffff);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar6;
}



// -[DVNTableViewController _cellsForSection:], 0x12126c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12126c. _cellsForSection: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::_cellsForSection_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  ID IVar3;
  undefined8 uVar4;
  
  puVar1 = @selector(cellsProvider);
  _objc_retain(param_3);
  _objc_msgSend(param_3,puVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) {
    _objc_msgSend(param_3,@selector(cells));
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend((&PTR_LAB_0118dcd8)[lVar2 == 0] + (int)-(DAT_0118dce8 ^ 0xedf822d5),param_3,puVar1
                 );
    IVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    (**(code **)(IVar3 + 0x10))(IVar3);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    param_3 = IVar3;
  }
  _objc_release(param_3);
  _objc_release(lVar2);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar3;
}



// -[DVNTableViewController switchForKey:], 0x12137c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12137c. switchForKey: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::switchForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  DAT_01227340 = 1;
  _objc_retain(param_3);
  _NSClassFromString(@"ABCSwitch");
  uVar1 = _objc_alloc_init();
  _objc_msgSend(param_1,@selector(tableView));
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
  _objc_msgSend(param_1,@selector(defaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_0012c118(uVar2,@selector(boolForKey:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar1,@selector(setOn:),uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(toggleSwitch:),0x1000);
  IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar1);
  return IVar4;
}



// -[DVNTableViewController toggleSwitch:], 0x1215f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1215f4. toggleSwitch: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::toggleSwitch_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_3);
  uVar1 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend(param_1,@selector(defaults));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    uVar3 = FUN_0012c1e0(param_3,@selector(isOn));
    _objc_msgSend(lVar2,@selector(key));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(setBool:forKey:),uVar3,uVar4);
    _objc_release(uVar4);
    _objc_release(uVar1);
  }
  _objc_release(lVar2);
  _objc_release(param_3);
  CallSupervisor(0x7bf4);
  return;
}



// -[DVNTableViewController setSegment:], 0x12174c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12174c. setSegment: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::setSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_3);
  uVar1 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend(param_1,@selector(defaults));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(param_3,@selector(selectedSegmentIndex));
    _objc_msgSend(lVar2,@selector(key));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(setInteger:forKey:),uVar3,uVar4);
    _objc_release(uVar4);
    _objc_release(uVar1);
  }
  _objc_release(lVar2);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[DVNTableViewController sliderValueChanged:], 0x121888
/* Decompiled from supplied 5.2.2 arm package. VA 0x121888. sliderValueChanged: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::sliderValueChanged_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  
  _objc_retain(param_3);
  puVar1 = @selector(tag);
  uVar5 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar5);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(dividerValue);
  if (lVar6 != 0) {
    dVar13 = (double)_objc_msgSend(lVar6,@selector(dividerValue));
    puVar2 = @selector(value);
    if (0.0 < dVar13) {
      fVar12 = (float)_objc_msgSend((&PTR_LAB_0118dd78)[0.0 < dVar13] +
                                    (int)-(uRam000000000118dd88 ^ 0x503aa305),param_3,
                                    @selector(value));
      dVar13 = (double)_objc_msgSend(lVar6,puVar3);
      dVar14 = (double)_objc_msgSend(lVar6,puVar3);
      _objc_msgSend((float)(dVar14 * (double)(long)((double)fVar12 / dVar13)),param_3,
                    @selector(setValue:));
    }
    _objc_msgSend(param_1,@selector(defaults));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar11 = _objc_msgSend(param_3,puVar2);
    _objc_msgSend(lVar6,@selector(key));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,uVar5,@selector(setFloat:forKey:),uVar7);
    _objc_release(uVar7);
    _objc_release(uVar5);
    lVar8 = _objc_msgSend(param_3,puVar1);
    uVar4 = _objc_msgSend(param_3,puVar1);
    _objc_msgSend(PTR__OBJC_CLASS___NSIndexPath_0114ee10,@selector(indexPathForRow:inSection:),
                  uVar4,lVar8 >> 0x10);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(tableView));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(cellForRowAtIndexPath:),uVar5);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    fVar12 = (float)_objc_msgSend(param_3,puVar2);
    uVar7 = _objc_msgSend(lVar6,@selector(sliderFormat));
    _objc_msgSend((double)fVar12,param_1,@selector(formatSliderValue:format:),uVar7);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(detailTextLabel));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar10,@selector(setText:),uVar7);
    _objc_release(uVar10);
    _objc_release(uVar7);
    _objc_release(uVar9);
    _objc_release(uVar5);
  }
  _objc_release(lVar6);
  _objc_release(param_3);
  CallSupervisor(0x256c);
  return;
}



// -[DVNTableViewController stepperValueChanged:], 0x121bac
/* Decompiled from supplied 5.2.2 arm package. VA 0x121bac. stepperValueChanged: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::stepperValueChanged_(ID param_1,SEL param_2,ID param_3)

{
  double dVar1;
  undefined *puVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  
  _objc_retain(param_3);
  puVar2 = @selector(tag);
  uVar4 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar4);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  if (lVar5 != 0) {
    _objc_msgSend(param_1,@selector(defaults));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    dVar1 = (double)_objc_msgSend(param_3,@selector(value));
    _objc_msgSend(lVar5,@selector(key));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend((float)dVar1,uVar4,@selector(setFloat:forKey:),uVar6);
    _objc_release(uVar6);
    _objc_release(uVar4);
    lVar7 = _objc_msgSend(param_3,puVar2);
    uVar3 = _objc_msgSend(param_3,puVar2);
    _objc_msgSend(param_1,@selector(tableView));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSIndexPath_0114ee10,@selector(indexPathForRow:inSection:),
                  uVar3,lVar7 >> 0x10);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(cellForRowAtIndexPath:),uVar6);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(param_1,@selector(stepperLabelForCell:),lVar5);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(textLabel));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setAttributedText:),uVar4);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uVar8);
  }
  _objc_release(lVar5);
  _objc_release(param_3);
  CallSupervisor(0xade3);
  return;
}



// -[DVNTableViewController colorWellTap:], 0x121e08
/* Decompiled from supplied 5.2.2 arm package. VA 0x121e08. colorWellTap: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::colorWellTap_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  _objc_retain(param_3);
  uVar2 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar2);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSKeyedArchiver_0114ec48;
  if (lVar3 != 0) {
    _objc_msgSend(param_3,@selector(selectedColor));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,@selector(archivedDataWithRootObject:requiringSecureCoding:error:),uVar2,0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
    _objc_msgSend(param_1,@selector(defaults));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar3,@selector(key));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(setObject:forKey:),uVar4,uVar5);
    _objc_release(uVar5);
    _objc_release(uVar2);
    _objc_release(uVar4);
  }
  _objc_release(lVar3);
  _objc_release(param_3);
  CallSupervisor(0x3c2a);
  return;
}



// -[DVNTableViewController textFieldShouldReturn:], 0x121fa8
/* Decompiled from supplied 5.2.2 arm package. VA 0x121fa8. textFieldShouldReturn: */

/* Function Stack Size: 0x18 bytes */

bool DVNTableViewController::textFieldShouldReturn_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  
  FUN_0012c848(param_3,@selector(resignFirstResponder));
  _objc_msgSend(param_1,@selector(tableView));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(reloadData));
  _objc_release(uVar1);
  return 1;
}



// -[DVNTableViewController titleValue:], 0x122008
/* Decompiled from supplied 5.2.2 arm package. VA 0x122008. titleValue: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::titleValue_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  
  _objc_retain(param_3);
  uVar3 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend(param_1,@selector(_cellForTag:),uVar3);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(text);
  if (lVar4 != 0) {
    _objc_msgSend(param_3,@selector(text));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(length);
    lVar4 = _objc_msgSend(uVar3,@selector(length));
    if (lVar4 == 0) {
      uVar8 = 0;
    }
    else {
      _objc_msgSend((&PTR_LAB_0118ddf8)[lVar4 == 0] + (int)-(uRam000000000118de08 ^ 0x1479c3ea),
                    param_3,puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,@selector(whitespaceCharacterSet))
      ;
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(invertedSet));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      lVar4 = _objc_msgSend(uVar5,@selector(rangeOfCharacterFromSet:),uVar7);
      uVar8 = (uint)(lVar4 == 0x7fffffffffffffff);
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar5);
    }
    _objc_release(uVar3);
    _objc_msgSend(param_3,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    lVar4 = _objc_msgSend(uVar3,puVar2);
    if (lVar4 == 0) {
      uVar8 = 1;
    }
    _objc_release(uVar3);
    _objc_msgSend(param_1,@selector(defaults));
    _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0012223c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_0118de18)[uVar8] + (int)-(uRam000000000118de28 ^ 0x759810ad)))();
    return;
  }
  _objc_release((&PTR__objc_msgSend_0118dde0)[lVar4 == 0] + (int)-(DAT_0118ddf0 ^ 0xeaf9694e),0);
  _objc_release(param_3);
  CallSupervisor(0xb47b);
  return;
}



// -[DVNTableViewController segmentForItems:isCompact:], 0x122380
/* Decompiled from supplied 5.2.2 arm package. VA 0x122380. segmentForItems:isCompact: */

/* Function Stack Size: 0x1c bytes */

ID DVNTableViewController::segmentForItems_isCompact_
             (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  long lVar2;
  ID IVar3;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  uint local_184;
  undefined **local_180;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_180 = &PTR_LAB_0118de40;
  _objc_retain(param_3);
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UISegmentedControl_0114ee48);
  uVar1 = _objc_msgSend(uVar1,@selector(initWithItems:),param_3);
  _objc_msgSend(uVar1,@selector(setTranslatesAutoresizingMaskIntoConstraints:),param_4);
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  _objc_msgSend(uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,@selector(countByEnumeratingWithState:objects:count:),&local_1d0,auStack_f8,
                        0x10);
  local_184 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x001224f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_180[local_184] + (int)-(DAT_0118de50 ^ 0x6fb13ebe)))();
  return IVar3;
}



// -[DVNTableViewController sliderWithKey:min:max:], 0x122900
/* Decompiled from supplied 5.2.2 arm package. VA 0x122900. sliderWithKey:min:max: */

/* Function Stack Size: 0x28 bytes */

ID DVNTableViewController::sliderWithKey_min_max_
             (ID param_1,SEL param_2,ID param_3,double param_4,double param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  undefined4 uVar8;
  
  puVar1 = PTR__OBJC_CLASS___UISlider_0114ee50;
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(param_1,@selector(tableView));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(tintColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setTintColor:),uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend((float)param_4,uVar2,@selector(setMinimumValue:));
  _objc_msgSend((float)param_5,uVar2,@selector(setMaximumValue:));
  _objc_msgSend(param_1,@selector(defaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(uVar3,@selector(floatForKey:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar8,uVar2,@selector(setValue:));
  _objc_release(uVar3);
  _objc_msgSend(uVar2,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar3 = _objc_msgSend(0x4028000000000000,0x402e000000000000,uVar3,@selector(initWithSize:));
  _objc_msgSend(uVar3,@selector(imageWithActions:),&PTR___NSConcreteGlobalBlock_01062530);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setThumbImage:forState:),uVar4,0);
  _objc_msgSend(uVar2,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(sliderValueChanged:),0x1000);
  _objc_msgSend(uVar2,@selector(heightAnchor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x403e000000000000,uVar5,@selector(constraintEqualToConstant:));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setActive:),1);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  IVar7 = _objc_autoreleaseReturnValue(uVar2);
  return IVar7;
}



// -[DVNTableViewController timePickerForCell:indexPath:], 0x122c48
/* Decompiled from supplied 5.2.2 arm package. VA 0x122c48. timePickerForCell:indexPath: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::timePickerForCell_indexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  float fVar8;
  double dVar9;
  
  _objc_retain(param_3);
  puVar1 = PTR_DVNPickerView_0114ee58;
  _objc_retain(param_4);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setDelegate:),param_1);
  _objc_msgSend(uVar2,@selector(setDataSource:),param_1);
  _objc_msgSend(0,0,0x4054000000000000,0x404e000000000000,uVar2,@selector(setFrame:));
  lVar3 = _objc_msgSend(param_4,@selector(section));
  uVar4 = _objc_msgSend(param_4,@selector(row));
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setTag:),uVar4 & 0xffff | lVar3 << 0x10);
  _objc_msgSend(param_1,@selector(defaults));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(key));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  fVar8 = (float)_objc_msgSend(uVar5,@selector(floatForKey:),uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  puVar1 = @selector(minimumValue);
  dVar9 = (double)_objc_msgSend(param_3,@selector(minimumValue));
  if ((double)fVar8 < dVar9) {
    dVar9 = (double)_objc_msgSend((&PTR_LAB_0118df50)[(double)fVar8 < dVar9] +
                                  (int)-(DAT_0118df60 ^ 0xcd2f9a53),param_3,puVar1);
    fVar8 = (float)dVar9;
  }
  _objc_msgSend(uVar2,@selector(selectRow:inComponent:animated:),(long)fVar8,0,0);
  _objc_release(param_3);
  IVar7 = _objc_autoreleaseReturnValue(uVar2);
  return IVar7;
}



// -[DVNTableViewController stepperForCell:indexPath:], 0x122e44
/* Decompiled from supplied 5.2.2 arm package. VA 0x122e44. stepperForCell:indexPath: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::stepperForCell_indexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ID IVar7;
  float fVar8;
  
  puVar1 = PTR__OBJC_CLASS___UIStepper_0114ee60;
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(param_3,@selector(minimumValue));
  _objc_msgSend(uVar2,@selector(setMinimumValue:));
  _objc_msgSend(param_3,@selector(maximumValue));
  _objc_msgSend(uVar2,@selector(setMaximumValue:));
  _objc_msgSend(param_3,@selector(dividerValue));
  _objc_msgSend(uVar2,@selector(setStepValue:));
  _objc_msgSend(param_1,@selector(defaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(key));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  fVar8 = (float)_objc_msgSend(uVar3,@selector(floatForKey:),uVar4);
  _objc_msgSend((double)fVar8,uVar2,@selector(setValue:));
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(param_1,@selector(tableView));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(tintColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setTintColor:),uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  lVar5 = _objc_msgSend(param_4,@selector(section));
  uVar6 = _objc_msgSend(param_4,@selector(row));
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setTag:),uVar6 & 0xffff | lVar5 << 0x10);
  _objc_msgSend(uVar2,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(stepperValueChanged:),0x1000);
  IVar7 = _objc_autoreleaseReturnValue(uVar2);
  return IVar7;
}



// -[DVNTableViewController stepperLabelForCell:], 0x123038
/* Decompiled from supplied 5.2.2 arm package. VA 0x123038. stepperLabelForCell: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::stepperLabelForCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  float fVar8;
  undefined8 auStack_c0 [2];
  undefined8 auStack_b0 [3];
  undefined8 *puStack_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  puVar1 = PTR__OBJC_CLASS___NSMutableAttributedString_0114ec28;
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_0118df70;
  local_84 = (uint)(DAT_01227374 == 0);
  local_90 = &PTR__objc_msgSend_0118c130;
  DAT_01227374 = 1;
  puStack_98 = auStack_b0;
  _objc_retain(param_3);
  uVar2 = _objc_alloc(puVar1);
  _objc_msgSend(param_3,@selector(title));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar2,@selector(initWithString:),uVar3);
  _objc_release(uVar3);
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  _objc_msgSend(param_1,@selector(defaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(key));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  fVar8 = (float)_objc_msgSend(uVar3,@selector(floatForKey:),uVar4);
  uVar5 = _objc_msgSend(param_3,@selector(sliderFormat));
  _objc_release(param_3);
  _objc_msgSend((double)fVar8,param_1,@selector(formatSliderValue:format:),uVar5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_0012d504(puVar1,@selector(stringWithFormat:),
                     &PTR____CFConstantStringClassReference_0118bf00,uVar5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
  auStack_c0[0] = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  auStack_b0[0] = uVar4;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),puStack_98,auStack_c0,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar3,@selector(initWithString:attributes:),uVar6,uVar5);
  _objc_msgSend(uVar2,@selector(appendAttributedString:),uVar3);
  _objc_release(uVar3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar6);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    IVar7 = _objc_autoreleaseReturnValue(uVar2);
    return IVar7;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[DVNTableViewController colorWellForKey:title:], 0x123394
/* Decompiled from supplied 5.2.2 arm package. VA 0x123394. colorWellForKey:title: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::colorWellForKey_title_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  puVar1 = @selector(defaults);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(objectForKey:),param_3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(class));
  _objc_msgSend(puVar1,@selector(unarchivedObjectOfClass:fromData:error:),uVar2,uVar3,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIColorWell_0114ee68);
  uVar4 = _objc_msgSend(0,0,0x403e000000000000,0x403e000000000000,uVar4,
                        @selector(initWithFrame:));
  _objc_msgSend(uVar4,@selector(setTitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar4,@selector(setSupportsAlpha:),1);
  _objc_msgSend(uVar4,@selector(setSelectedColor:),uVar2);
  _objc_msgSend(uVar4,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(colorWellTap:),0x1000);
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// -[DVNTableViewController textFieldForCell:], 0x123508
/* Decompiled from supplied 5.2.2 arm package. VA 0x123508. textFieldForCell: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::textFieldForCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ID IVar5;
  
  _objc_retain(param_3);
  uVar1 = _objc_alloc_init(PTR__OBJC_CLASS___UITextField_0114ee70);
  _objc_msgSend(0x402c000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                @selector(systemFontOfSize:));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setFont:),uVar2);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,@selector(setKeyboardType:),0);
  _objc_msgSend(uVar1,@selector(setReturnKeyType:),9);
  _objc_msgSend(uVar1,@selector(setDelegate:),param_1);
  _objc_msgSend(uVar1,@selector(setBorderStyle:),0);
  _objc_msgSend(uVar1,@selector(setTextAlignment:),2);
  _objc_msgSend(uVar1,@selector(setClearButtonMode:),1);
  _objc_msgSend(uVar1,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(param_1,@selector(defaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(key));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(stringForKey:),uVar3);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  if (lVar4 == 0) {
    _objc_msgSend(param_3,@selector(placeholder));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(setPlaceholder:),uVar2);
  }
  else {
    _objc_msgSend(uVar1,@selector(setText:),lVar4);
    _objc_msgSend(param_1,@selector(view));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(tintColor));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(setTextColor:),uVar3);
    _objc_release(uVar3);
  }
  _objc_release(uVar2);
  _objc_msgSend(uVar1,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(titleValue:),0x20000);
  _objc_release(lVar4);
  _objc_release(param_3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar1);
  return IVar5;
}



// -[DVNTableViewController editorForIndexPath:], 0x1237ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1237ac. editorForIndexPath: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::editorForIndexPath_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  ID IVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  double in_d2;
  undefined *puStack_120;
  undefined8 uStack_118;
  code *pcStack_110;
  undefined *puStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  ID IStack_f0;
  undefined1 auStack_e0 [48];
  undefined *puStack_b0;
  ID IStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined **ppuStack_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  
  puVar1 = @selector(sections);
  puStack_a0 = (undefined1 *)&puStack_b0;
  local_78 = &PTR_LAB_0118dfb8;
  local_7c = (uint)(DAT_01227380 == 0);
  local_88 = &PTR__objc_msgSend_0118c130;
  DAT_01227380 = 1;
  puStack_98 = auStack_e0;
  ppuStack_90 = &puStack_120;
  uVar12 = *(undefined8 *)(param_1 + (long)_model);
  IStack_a8 = param_1;
  _objc_retain(param_3);
  _objc_msgSend(uVar12,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_msgSend(param_3,@selector(section));
  puVar1 = @selector(objectAtIndexedSubscript:);
  _objc_msgSend(uVar12,@selector(objectAtIndexedSubscript:),uVar6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(cells));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(param_3,@selector(row));
  _objc_release(param_3);
  _objc_msgSend(uVar7,puVar1,uVar8);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar12);
  uVar6 = _objc_alloc_init(PTR__OBJC_CLASS___UITextView_0114ee78);
  puVar2 = @selector(labelColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(colorWithAlphaComponent:);
  uVar12 = DAT_00c4c258;
  _objc_msgSend(DAT_00c4c258,uVar7,@selector(colorWithAlphaComponent:));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puStack_b0 = @selector(setBackgroundColor:);
  _objc_msgSend(uVar6,@selector(setBackgroundColor:),uVar9);
  _objc_release(uVar9);
  _objc_release(uVar7);
  puVar1 = @selector(layer);
  _objc_msgSend(uVar6,@selector(layer));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4008000000000000,uVar7,@selector(setCornerRadius:));
  _objc_release(uVar7);
  _objc_msgSend(uVar6,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3ff0000000000000,uVar7,@selector(setBorderWidth:));
  _objc_release(uVar7);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(grayColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3fe0000000000000,uVar7,puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uVar10 = _objc_retainAutorelease();
  uVar10 = _objc_msgSend(uVar10,@selector(CGColor));
  _objc_msgSend(uVar6,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,@selector(setBorderColor:),uVar10);
  _objc_release(uVar11);
  _objc_release(uVar9);
  _objc_release(uVar7);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setTextColor:),uVar7);
  _objc_release(uVar7);
  IVar4 = IStack_a8;
  _objc_msgSend(IStack_a8,@selector(defaults));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(key));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(valueForKey:),uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setText:),uVar10);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar7);
  _objc_msgSend(uVar6,@selector(setEditable:),1);
  _objc_msgSend(uVar6,@selector(setScrollEnabled:),1);
  _objc_msgSend(uVar6,@selector(setTextAlignment:),4);
  _objc_msgSend(0x402c000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                @selector(systemFontOfSize:));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setFont:),uVar7);
  _objc_release(uVar7);
  uVar7 = _objc_getClass(s_YTAlertView_0118bf4e);
  _objc_msgSend(uVar7,@selector(dialog));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(title));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setTitle:),uVar9);
  _objc_release(uVar9);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,uVar9,puVar3);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puStack_b0,uVar12);
  _objc_release(uVar12);
  _objc_release(uVar9);
  puVar3 = @selector(ytl_localized);
  _objc_msgSend(@"Copy",@selector(ytl_localized));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_a0;
  puVar1 = PTR___NSConcreteStackBlock_01060660;
  *(undefined **)(puStack_a0 + -0x30) = PTR___NSConcreteStackBlock_01060660;
  uVar12 = DAT_00c4c228;
  *(undefined8 *)(puVar5 + -0x28) = DAT_00c4c228;
  *(code **)(puVar5 + -0x20) = FUN_0012409c;
  *(undefined **)(puVar5 + -0x18) = &DAT_01061420;
  _objc_retain(uVar6);
  *(undefined8 *)(puVar5 + -0x10) = uVar6;
  puVar2 = @selector(addTitle:withAction:);
  _objc_msgSend(uVar7,@selector(addTitle:withAction:),uVar9,puStack_98);
  _objc_release(uVar9);
  _objc_msgSend(@"Save",puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puStack_120 = puVar1;
  uStack_118 = uVar12;
  pcStack_110 = FUN_00124254;
  puStack_108 = &DAT_01061910;
  IStack_f0 = IVar4;
  uStack_100 = uVar8;
  uStack_f8 = uVar6;
  _objc_retain(uVar6);
  _objc_retain(uVar8);
  _objc_msgSend(uVar7,puVar2,uVar9,ppuStack_90);
  _objc_release(uVar9);
  _objc_msgSend(@"Cancel",puVar3);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2,uVar12,0);
  _objc_release(uVar12);
  uVar12 = _objc_alloc(PTR__OBJC_CLASS___UIView_0114ec30);
  _objc_msgSend(uVar7,@selector(frameForDialog));
  uVar12 = _objc_msgSend(0,0,in_d2 + -50.0,DAT_00c4c378,uVar12,@selector(initWithFrame:));
  _objc_msgSend(uVar12,@selector(frame));
  _objc_msgSend(uVar6,@selector(setFrame:));
  _objc_msgSend(uVar12,@selector(addSubview:),uVar6);
  _objc_msgSend(uVar7,@selector(setCustomContentView:),uVar12);
  _objc_msgSend(uVar7,@selector(show));
  _objc_release(uVar12);
  _objc_release(uStack_f8);
  _objc_release(uStack_100);
  _objc_release(*(undefined8 *)(puVar5 + -0x10));
  _objc_release(uVar6);
  _objc_release(uVar8);
  _objc_release(uVar7);
  CallSupervisor(0x85bd);
  return;
}



// -[DVNTableViewController menuButtonWithTitle:array:key:], 0x1245bc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1245bc. menuButtonWithTitle:array:key: */

/* Function Stack Size: 0x28 bytes */

ID DVNTableViewController::menuButtonWithTitle_array_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  ID IVar1;
  
                    /* WARNING: Could not recover jumptable at 0x001246ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_0118e060)[DAT_01227390 == 0] + (int)-(DAT_0118e070 ^ 0xfd176edd)))();
  return IVar1;
}



// -[DVNTableViewController systemImage:withSize:], 0x1250e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1250e4. systemImage:withSize: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::systemImage_withSize_(ID param_1,SEL param_2,ID param_3,double param_4)

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
  local_60 = FUN_001251c4;
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



// -[DVNTableViewController isRTL], 0x12534c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12534c. isRTL */

/* Function Stack Size: 0x10 bytes */

bool DVNTableViewController::isRTL(ID param_1,SEL param_2)

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



// -[DVNTableViewController _reloadSections], 0x1253b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1253b8. _reloadSections */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::_reloadSections(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,@selector(tableView));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(reloadData));
  _objc_release(uVar1);
  return;
}



// -[DVNTableViewController dealloc], 0x1253f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1253f8. dealloc */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::dealloc(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  ID local_30;
  undefined *puStack_28;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(removeObserver:),param_1);
  _objc_release(uVar1);
  puStack_28 = PTR_DVNTableViewController_0114f0a8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,@selector(dealloc));
  return;
}



// -[DVNTableViewController model], 0x125470
/* Decompiled from supplied 5.2.2 arm package. VA 0x125470. model */

/* Function Stack Size: 0x10 bytes */

ID DVNTableViewController::model(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_model);
}



// -[DVNTableViewController setModel:], 0x125480
/* Decompiled from supplied 5.2.2 arm package. VA 0x125480. setModel: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::setModel_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_model,param_3);
  CallSupervisor(0x8c13);
  return;
}



// -[DVNTableViewController defaults], 0x1254bc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1254bc. defaults */

/* Function Stack Size: 0x10 bytes */

ID DVNTableViewController::defaults(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_defaults);
}



// -[DVNTableViewController setDefaults:], 0x1254cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1254cc. setDefaults: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::setDefaults_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_defaults,param_3);
  CallSupervisor(0xde17);
  return;
}



// -[DVNTableViewController pendingScrollCell], 0x125508
/* Decompiled from supplied 5.2.2 arm package. VA 0x125508. pendingScrollCell */

/* Function Stack Size: 0x10 bytes */

ID DVNTableViewController::pendingScrollCell(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_pendingScrollCell);
}



// -[DVNTableViewController setPendingScrollCell:], 0x125518
/* Decompiled from supplied 5.2.2 arm package. VA 0x125518. setPendingScrollCell: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::setPendingScrollCell_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_pendingScrollCell,param_3);
  return;
}



// -[DVNTableViewController .cxx_destruct], 0x12552c
/* Decompiled from supplied 5.2.2 arm package. VA 0x12552c. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_pendingScrollCell,0);
  _objc_storeStrong(param_1 + (long)_defaults,0);
  _objc_storeStrong(param_1 + (long)_model,0);
  _objc_storeStrong(param_1 + (long)_searchBar,0);
  _objc_storeStrong(param_1 + (long)_searchResults,0);
  CallSupervisor(0xb9a3);
  return;
}


