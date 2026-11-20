// Decompiled implementation evidence for YTPTableViewCell. Not compilable source.

// -[YTPTableViewCell setSelected:animated:], 0x1153f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1153f4. setSelected:animated: */

/* Function Stack Size: 0x18 bytes */

void YTPTableViewCell::setSelected_animated_(ID param_1,SEL param_2,bool param_3,bool param_4)

{
  ID local_50;
  undefined *puStack_48;
  bool local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_0118b518;
  puStack_48 = PTR_YTPTableViewCell_0114f098;
  local_50 = param_1;
  _objc_msgSendSuper2(&local_50,@selector(setSelected:animated:),param_3,param_4);
  local_3c = param_3;
                    /* WARNING: Could not recover jumptable at 0x0011546c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_38[param_3] + (int)-(DAT_0118b528 ^ 0x4df2eae4)))();
  return;
}



// -[YTPTableViewCell initWithStyle:reuseIdentifier:], 0x115638
/* Decompiled from supplied 5.2.2 arm package. VA 0x115638. initWithStyle:reuseIdentifier: */

/* Function Stack Size: 0x20 bytes */

ID YTPTableViewCell::initWithStyle_reuseIdentifier_
             (ID param_1,SEL param_2,long_long param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  ID IVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  double dVar7;
  ID IStack_a0;
  undefined *puStack_98;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  undefined **ppuStack_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_0118b540;
  local_6c = (uint)(DAT_01227244 == 0);
  local_80 = &PTR_LAB_0118b560;
  ppuStack_78 = &PTR_LAB_0118b4e0;
  local_90 = &PTR_LAB_0118b4e0;
  DAT_01227244 = 1;
  puStack_98 = PTR_YTPTableViewCell_0114f098;
  IStack_a0 = param_1;
  IVar4 = _objc_msgSendSuper2(&IStack_a0,@selector(initWithStyle:reuseIdentifier:));
  uStack_84 = (uint)(IVar4 == 0);
  if (IVar4 != 0) {
    _objc_msgSend(DAT_00c4c2e0,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:))
    ;
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,@selector(setValue:forKey:),uVar5,
                  @"_selectionFadeDuration");
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(setBackgroundColor:);
    _objc_msgSend(IVar4,@selector(setBackgroundColor:),uVar5);
    _objc_release(uVar5);
    uVar5 = _objc_msgSend(PTR__OBJC_CLASS___UIView_0114ec30,@selector(new));
    _objc_msgSend(IVar4,@selector(setSelectedBackgroundView:),uVar5);
    _objc_release(uVar5);
    _objc_msgSend(0x3fe8000000000000,0x3fe0000000000000,DAT_00c4c2f8,DAT_00c4c258,
                  PTR__OBJC_CLASS___UIColor_0114eb18,@selector(colorWithRed:green:blue:alpha:));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,@selector(selectedBackgroundView));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar1,uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    dVar7 = (double)_objc_msgSend(uVar5,@selector(scale));
    _objc_release(uVar5);
    puVar1 = @selector(systemFontOfSize:);
    uVar5 = 0x4030000000000000;
    if (dVar7 != 3.0) {
      uVar5 = 0x402c000000000000;
    }
    _objc_msgSend(uVar5,PTR__OBJC_CLASS___UIFont_0114ec08,@selector(systemFontOfSize:));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(textLabel);
    _objc_msgSend(IVar4,@selector(textLabel));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(setFont:);
    _objc_msgSend(uVar6,@selector(setFont:),uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(IVar4,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setAdjustsFontSizeToFitWidth:),1);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(detailTextLabel);
    _objc_msgSend(IVar4,@selector(detailTextLabel));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setTextColor:),uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(0x4028000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,puVar3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar2,uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(IVar4,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setNumberOfLines:),0);
    _objc_release(uVar5);
  }
  return IVar4;
}


