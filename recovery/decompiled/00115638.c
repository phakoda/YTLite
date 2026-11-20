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
  IVar4 = _objc_msgSendSuper2(&IStack_a0,PTR_s_initWithStyle_reuseIdentifier__0114b8d8);
  uStack_84 = (uint)(IVar4 == 0);
  if (IVar4 != 0) {
    _objc_msgSend(DAT_00c4c2e0,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310)
    ;
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,PTR_s_setValue_forKey__0114b208,uVar5,
                  &PTR____CFConstantStringClassReference_0118b4c0);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_setBackgroundColor__0114b550;
    _objc_msgSend(IVar4,PTR_s_setBackgroundColor__0114b550,uVar5);
    _objc_release(uVar5);
    uVar5 = _objc_msgSend(PTR__OBJC_CLASS___UIView_0114ec30,PTR_s_new_0114b030);
    _objc_msgSend(IVar4,PTR_s_setSelectedBackgroundView__0114d0d8,uVar5);
    _objc_release(uVar5);
    _objc_msgSend(0x3fe8000000000000,0x3fe0000000000000,DAT_00c4c2f8,DAT_00c4c258,
                  PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithRed_green_blue_alpha__0114c5f8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,PTR_s_selectedBackgroundView_0114d0e0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar1,uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    dVar7 = (double)_objc_msgSend(uVar5,PTR_s_scale_0114cc78);
    _objc_release(uVar5);
    puVar1 = PTR_s_systemFontOfSize__0114b660;
    uVar5 = 0x4030000000000000;
    if (dVar7 != 3.0) {
      uVar5 = 0x402c000000000000;
    }
    _objc_msgSend(uVar5,PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_systemFontOfSize__0114b660);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_textLabel_0114b8e0;
    _objc_msgSend(IVar4,PTR_s_textLabel_0114b8e0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_setFont__0114b5e8;
    _objc_msgSend(uVar6,PTR_s_setFont__0114b5e8,uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(IVar4,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setAdjustsFontSizeToFitWidth__0114b740,1);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_secondaryLabelColor_0114d0e8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_detailTextLabel_0114b8e8;
    _objc_msgSend(IVar4,PTR_s_detailTextLabel_0114b8e8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setTextColor__0114b5d8,uVar5);
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
    _objc_msgSend(uVar5,PTR_s_setNumberOfLines__0114b5f0,0);
    _objc_release(uVar5);
  }
  return IVar4;
}


