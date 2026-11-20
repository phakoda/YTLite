/* Decompiled from supplied 5.2.2 arm package. VA 0x42d44. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID WelcomeVC::tableView_cellForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ID IVar12;
  undefined8 uVar13;
  
  DAT_01225ef0 = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,PTR_s_dequeueReusableCellWithIdentifie_0114b8d0,
                &PTR____CFConstantStringClassReference_0115c7d0);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  if (lVar7 == 0) {
    uVar9 = _objc_alloc(PTR__OBJC_CLASS___UITableViewCell_0114ec80);
    lVar7 = _objc_msgSend(uVar9,PTR_s_initWithStyle_reuseIdentifier__0114b8d8,3,
                          &PTR____CFConstantStringClassReference_0115c7d0);
  }
  lVar8 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  if (lVar8 == 0) {
    uVar13 = *(undefined8 *)(param_1 + (long)_settingsData);
    uVar9 = _objc_msgSend(param_4,PTR_s_row_0114af70);
    _objc_msgSend(uVar13,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar9);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
    _objc_msgSend(uVar9,PTR_s_objectForKeyedSubscript__0114ae80,
                  &PTR____CFConstantStringClassReference_0115c790);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    puVar4 = PTR_s_textLabel_0114b8e0;
    _objc_msgSend(lVar7,PTR_s_textLabel_0114b8e0);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_setText__0114b388;
    _objc_msgSend(uVar10,PTR_s_setText__0114b388,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(0x4030000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                  PTR_s_boldSystemFontOfSize__0114b5e0);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar4);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar5 = PTR_s_setFont__0114b5e8;
    _objc_msgSend(uVar10,PTR_s_setFont__0114b5e8,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(lVar7,puVar4);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,PTR_s_setAdjustsFontSizeToFitWidth__0114b740,1);
    _objc_release(uVar13);
    puVar2 = PTR_s_whiteColor_0114b080;
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar4);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar4 = PTR_s_setTextColor__0114b5d8;
    _objc_msgSend(uVar10,PTR_s_setTextColor__0114b5d8,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(uVar9,puVar1,&PTR____CFConstantStringClassReference_0115c750);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    puVar6 = PTR_s_detailTextLabel_0114b8e8;
    _objc_msgSend(lVar7,PTR_s_detailTextLabel_0114b8e8);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar10,puVar3,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(lVar7,puVar6);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,PTR_s_setNumberOfLines__0114b5f0,0);
    _objc_release(uVar13);
    _objc_msgSend(0x402c000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                  PTR_s_systemFontOfSize__0114b660);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar6);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar10,puVar5,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar2);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_00c4c250,uVar13,PTR_s_colorWithAlphaComponent__0114b548);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar6);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,puVar4,uVar10);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(uVar9,puVar1,&PTR____CFConstantStringClassReference_0115c710);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_cellImageWithName__0114b8f0,uVar13);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,PTR_s_imageView_0114b720);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,PTR_s_setImage__0114b8f8,uVar10);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,PTR_s_setBackgroundColor__0114b550,uVar13);
    _objc_release(uVar13);
    _objc_msgSend(lVar7,PTR_s_setUserInteractionEnabled__0114b820,0);
    _objc_release(uVar9);
  }
  _objc_release(param_4);
  IVar12 = _objc_autoreleaseReturnValue(lVar7);
  return IVar12;
}


