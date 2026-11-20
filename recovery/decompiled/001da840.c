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
  _objc_msgSend(param_3,PTR_s_dequeueReusableCellWithIdentifie_0114b8d0,
                &PTR____CFConstantStringClassReference_011b8920);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  if (lVar6 == 0) {
    uVar7 = _objc_alloc((&PTR_LAB_011b9230)[lVar6 == 0] + (int)-(uRam00000000011b9240 ^ 0x414818a8),
                        PTR_YTPTableViewCell_0114ee38);
    lVar6 = _objc_msgSend(uVar7,PTR_s_initWithStyle_reuseIdentifier__0114b8d8,3,
                          &PTR____CFConstantStringClassReference_011b8920);
  }
  puVar1 = PTR_s_section_0114af60;
  lVar13 = (long)_sections;
  uVar12 = *(undefined8 *)(param_1 + lVar13);
  uVar7 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  puVar2 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  _objc_msgSend(uVar12,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar7);
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
  uVar12 = _objc_msgSend(param_4,PTR_s_row_0114af70);
  _objc_msgSend(uVar7,puVar2,uVar12);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  uVar7 = _objc_alloc(PTR_YTPTableViewCell_0114ee38);
  puVar2 = PTR_s_objectForKeyedSubscript__0114ae80;
  _objc_msgSend(uVar12,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011b8860);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  lVar8 = _objc_msgSend(uVar7,PTR_s_initWithStyle_reuseIdentifier__0114b8d8,3,uVar9);
  _objc_release(lVar6);
  _objc_release(uVar9);
  _objc_msgSend(uVar12,puVar2,&PTR____CFConstantStringClassReference_011b88e0);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar6 != 0) {
    _objc_msgSend((&PTR_LAB_011b9268)[lVar6 == 0] + (int)-(uRam00000000011b9278 ^ 0xb4b122db),uVar12
                  ,puVar2,&PTR____CFConstantStringClassReference_011b88e0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_textLabel_0114b8e0;
    _objc_msgSend(lVar8,PTR_s_textLabel_0114b8e0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_setText__0114b388,uVar7);
    _objc_release(uVar9);
    _objc_release(uVar7);
    _objc_msgSend(lVar8,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_setNumberOfLines__0114b5f0,0);
    _objc_release(uVar7);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar8,puVar1);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_setTextColor__0114b5d8,uVar7);
    _objc_release(uVar9);
    _objc_release(uVar7);
  }
  _objc_msgSend(uVar12,puVar2,&PTR____CFConstantStringClassReference_011b88a0);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar6 != 0) {
    _objc_msgSend((&PTR_LAB_011b9288)[lVar6 == 0] + (int)-(uRam00000000011b9298 ^ 0x7846a9ac),uVar12
                  ,puVar2,&PTR____CFConstantStringClassReference_011b88a0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_class_0114ae88;
    uVar9 = _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_class_0114ae88);
    puVar1 = PTR_s_isKindOfClass__0114ad70;
    iVar4 = FUN_001ddc7c(uVar7,PTR_s_isKindOfClass__0114ad70,uVar9);
    _objc_release(uVar7);
    _objc_msgSend(uVar12,puVar2,&PTR____CFConstantStringClassReference_011b88a0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    if (iVar4 == 0) {
      uVar9 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar3);
      uVar5 = FUN_001ddb74(uVar7,puVar1,uVar9);
      _objc_release(uVar7);
      if (uVar5 == 0) goto LAB_001dafc0;
      _objc_msgSend((&PTR_LAB_011b92c0)[uVar5] + (int)-(uRam00000000011b92d0 ^ 0x1df1a98e),uVar12,
                    puVar2,&PTR____CFConstantStringClassReference_011b88a0);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,PTR_s_channelImage__0114e098,uVar7);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar8,PTR_s_imageView_0114b720);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,PTR_s_setImage__0114b8f8,uVar9);
    }
    else {
      _objc_msgSend(param_1,PTR_s_ytlImageWithName__0114e078,uVar7);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar8,PTR_s_imageView_0114b720);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar10,PTR_s_setImage__0114b8f8,uVar9);
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


