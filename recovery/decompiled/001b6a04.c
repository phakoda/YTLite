/* Decompiled from supplied 5.2.2 arm package. VA 0x1b6a04. setCairo: */

/* Function Stack Size: 0x14 bytes */

void YTPMedia::setCairo_(ID param_1,SEL param_2,bool param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  DAT_01227ab0 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_objectForInfoDictionaryKey__0114ae00,
                &PTR____CFConstantStringClassReference_011b1fb0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  lVar4 = _objc_msgSend(uVar3,PTR_s_compare_options__0114ae08,
                        &PTR____CFConstantStringClassReference_011b1f70,0x40);
  uVar1 = 0;
  if (lVar4 != -1) {
    uVar1 = (char)param_3;
  }
  *(undefined1 *)(param_1 + 8) = uVar1;
  _objc_release(uVar3);
  CallSupervisor(0xfc79);
  return;
}


