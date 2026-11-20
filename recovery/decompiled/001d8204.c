/* Decompiled from supplied 5.2.2 arm package. VA 0x1d8204. FUN_001d8204 */

void FUN_001d8204(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  DAT_01227da0 = 1;
  lVar1 = _objc_msgSend(param_2,PTR_s_userInterfaceStyle_0114c550);
  if (lVar1 == 2) {
    puVar2 = (undefined *)
             _NSClassFromString((&PTR_LAB_011b9078)[lVar1 == 2] + (int)-(DAT_011b9088 ^ 0x5bb293),
                                &PTR____CFConstantStringClassReference_011b80b0);
    ppuVar3 = &PTR_s_black2_0114be08;
  }
  else {
    ppuVar3 = &PTR_s_whiteColor_0114b080;
    puVar2 = PTR__OBJC_CLASS___UIColor_0114eb18;
  }
  _objc_msgSend(puVar2,*ppuVar3);
  _objc_retainAutoreleasedReturnValue();
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}


