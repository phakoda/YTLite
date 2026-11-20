/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff8b0. parser:didEndElement:namespaceURI:qualifiedName: */

/* Function Stack Size: 0x30 bytes */

void SRTParser::parser_didEndElement_namespaceURI_qualifiedName_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01228098 = 1;
  iVar2 = FUN_00201134(param_4,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_011c20a0);
  if (iVar2 == 0) {
    return;
  }
  _objc_msgSend(param_1,PTR_s_decodeHTML_hars__0114e320,*(undefined8 *)(param_1 + 0x10));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                PTR_s_whitespaceAndNewlineCharacterSet_0114e2d0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_stringByTrimmingCharactersInSet__0114e2d8,uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  ppuVar1 = &PTR_s_generateSRTWithText__0114e330;
  if (*(char *)(param_1 + 0x40) != '\0') {
    ppuVar1 = &PTR_s_generateTranscriptWithText__0114e328;
  }
  _objc_msgSend(param_1,*ppuVar1,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar3);
  return;
}


