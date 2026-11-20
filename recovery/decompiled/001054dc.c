/* Decompiled from supplied 5.2.2 arm package. VA 0x1054dc. getResoForQuality: */

/* Function Stack Size: 0x18 bytes */

long_long DownloadMenuHelper::getResoForQuality_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long_long lVar3;
  
  DAT_012271a0 = 1;
  _objc_msgSend(param_3,PTR_s_componentsSeparatedByString__0114b510,
                &PTR____CFConstantStringClassReference_011871e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_objectAtIndexedSubscript__0114aeb0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar2,PTR_s_integerValue_0114b4c8);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return lVar3;
}


