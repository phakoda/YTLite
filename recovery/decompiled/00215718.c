/* Decompiled from supplied 5.2.2 arm package. VA 0x215718. attributedTitle:image: */

/* Function Stack Size: 0x20 bytes */

ID YTPSleepTimer::attributedTitle_image_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  cfstringStruct *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  ID IVar6;
  undefined8 uVar7;
  
  DAT_012281b0 = 1;
  _objc_retain(param_4);
  puVar4 = PTR__OBJC_CLASS___NSAttributedString_0114ee30;
  puVar3 = PTR__OBJC_CLASS___NSMutableAttributedString_0114ec28;
  puVar2 = PTR_s_new_0114b030;
  if (param_4 == 0) {
    _objc_retain(param_3);
    uVar5 = _objc_alloc(puVar4);
    pcVar1 = &cf___;
    if (param_3 != 0) {
      pcVar1 = (cfstringStruct *)param_3;
    }
    uVar5 = _objc_msgSend(uVar5,PTR_s_initWithString__0114b658,pcVar1);
  }
  else {
    _objc_retain(param_3);
    uVar5 = _objc_msgSend(puVar3,puVar2);
    IVar6 = _objc_msgSend(PTR__OBJC_CLASS___NSTextAttachment_0114ee28,puVar2);
    _objc_msgSend(IVar6,PTR_s_setImage__0114b8f8,param_4);
    _objc_msgSend(0,0xc000000000000000,0x402c000000000000,0x402c000000000000,IVar6,
                  PTR_s_setBounds__0114d348);
    _objc_msgSend(PTR__OBJC_CLASS___NSAttributedString_0114ee30,
                  PTR_s_attributedStringWithAttachment__0114d350,IVar6);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_appendAttributedString__0114d358;
    _objc_msgSend(uVar5,PTR_s_appendAttributedString__0114d358,uVar7);
    _objc_release(uVar7);
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    puVar2 = PTR_s_initWithString__0114b658;
    uVar7 = _objc_msgSend(uVar7,PTR_s_initWithString__0114b658,
                          &PTR____CFConstantStringClassReference_011cb8b0);
    _objc_msgSend(uVar5,puVar3,uVar7);
    _objc_release(uVar7);
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    pcVar1 = &cf___;
    if (param_3 != 0) {
      pcVar1 = (cfstringStruct *)param_3;
    }
    uVar7 = _objc_msgSend(uVar7,puVar2,pcVar1);
    _objc_release(param_3);
    _objc_msgSend(uVar5,puVar3,uVar7);
    _objc_release(uVar7);
    param_3 = IVar6;
  }
  _objc_release(param_3);
  _objc_release(param_4);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar6;
}


