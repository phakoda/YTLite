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
  puVar3 = PTR_s_tableView_titleForHeaderInSectio_0114d328;
  _objc_msgSend(param_1,PTR_s_tableView_titleForHeaderInSectio_0114d328,param_3,param_5);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_textLabel_0114b8e0;
  _objc_msgSend(param_4,PTR_s_textLabel_0114b8e0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setText__0114b388,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(0x402c000000000000,*(undefined8 *)PTR__UIFontWeightLight_01060568,
                PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_systemFontOfSize_weight__0114d330);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setFont__0114b5e8,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setTextColor__0114b5d8,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setTextAlignment__0114b5f8,4);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setNumberOfLines__0114b5f0,0);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),PTR_s_sections_0114d240);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_objectAtIndexedSubscript__0114aeb0,param_5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar1 = PTR_s_headerIcon_0114d338;
  _objc_msgSend(uVar5,PTR_s_headerIcon_0114d338);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar6 != 0) {
    _objc_msgSend((&PTR_LAB_0118d420)[lVar6 == 0] + (int)-(uRam000000000118d430 ^ 0x53e6afd6),uVar5,
                  puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_headerImage__0114d340,uVar4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uVar4 = _objc_alloc_init(PTR__OBJC_CLASS___NSTextAttachment_0114ee28);
    _objc_msgSend(uVar4,PTR_s_setImage__0114b8f8,uVar7);
    _objc_msgSend(0,0xc008000000000000,0x4030000000000000,0x4030000000000000,uVar4,
                  PTR_s_setBounds__0114d348);
    uVar8 = _objc_alloc_init(PTR__OBJC_CLASS___NSMutableAttributedString_0114ec28);
    _objc_msgSend(PTR__OBJC_CLASS___NSAttributedString_0114ee30,
                  PTR_s_attributedStringWithAttachment__0114d350,uVar4);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar10 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    puVar1 = PTR_s_initWithString__0114b658;
    uVar10 = _objc_msgSend(uVar10,PTR_s_initWithString__0114b658,
                           &PTR____CFConstantStringClassReference_0118bcc0);
    uVar11 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    _objc_msgSend(param_1,puVar3,param_3,param_5);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uVar11 = _objc_msgSend(uVar11,puVar1,uVar12);
    _objc_release(uVar12);
    puVar3 = PTR_s_appendAttributedString__0114d358;
    _objc_msgSend(uVar8,PTR_s_appendAttributedString__0114d358,uVar9);
    _objc_msgSend(uVar8,puVar3,uVar10);
    _objc_msgSend(uVar8,puVar3,uVar11);
    _objc_msgSend(param_4,puVar2);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,PTR_s_setAttributedText__0114b678,uVar8);
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


