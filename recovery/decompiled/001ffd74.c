/* Decompiled from supplied 5.2.2 arm package. VA 0x1ffd74. generateTranscriptWithText: */

/* Function Stack Size: 0x18 bytes */

void SRTParser::generateTranscriptWithText_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012280a0 = 1;
  _objc_msgSend(param_3,PTR_s_stringByReplacingOccurrencesOfSt_0114b2c0,
                &PTR____CFConstantStringClassReference_011c21d0,
                &PTR____CFConstantStringClassReference_011c2190);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                PTR_s_whitespaceAndNewlineCharacterSet_0114e2d0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_stringByTrimmingCharactersInSet__0114e2d8,uVar2);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_addObject__0114b3a0,uVar3);
  _objc_release(uVar3);
  CallSupervisor(0xe35a);
  return;
}


