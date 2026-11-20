/* Decompiled from supplied 5.2.2 arm package. VA 0x1e3fa0. isRTL */

/* Function Stack Size: 0x10 bytes */

bool TranslatorVC::isRTL(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  puVar1 = PTR__OBJC_CLASS___UIView_0114ec30;
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar2,PTR_s_semanticContentAttribute_0114d668);
  lVar4 = _objc_msgSend(puVar1,PTR_s_userInterfaceLayoutDirectionForS_0114d670,uVar3);
  _objc_release(uVar2);
  return (bool)(lVar4 == 1);
}


