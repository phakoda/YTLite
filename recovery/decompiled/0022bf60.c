/* Decompiled from supplied 5.2.2 arm package. VA 0x22bf60. downloadProgress: */

/* Function Stack Size: 0x14 bytes */

void YTLHelper::downloadProgress_(ID param_1,SEL param_2,float param_3)

{
  undefined **ppuVar1;
  char cVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  DAT_012283a4 = 1;
  uVar7 = *(undefined8 *)(param_1 + 0x18);
  cVar2 = *(char *)(param_1 + 0x40);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR____CFConstantStringClassReference_011d0380;
  if (cVar2 != '\0') {
    ppuVar1 = &PTR____CFConstantStringClassReference_011d0340;
  }
  _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,ppuVar1,0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00232170((double)(param_3 * 100.0),puVar3,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d0300,uVar5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,uVar7,PTR_s_updateText_progress__0114e2f0,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x4748);
  return;
}


