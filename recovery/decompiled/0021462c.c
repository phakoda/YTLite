/* Decompiled from supplied 5.2.2 arm package. VA 0x21462c. formattedTime: */

/* Function Stack Size: 0x18 bytes */

ID YTPSleepTimer::formattedTime_(ID param_1,SEL param_2,double param_3)

{
  ID IVar1;
  
  if (DAT_012280f8 != -1) {
    _dispatch_once((&PTR_LAB_011cc830)[DAT_012280f8 == -1] + (int)-(DAT_011cc840 ^ 0xc5c08a4f),
                   &DAT_012280f8,&PTR___NSConcreteGlobalBlock_010630c0);
  }
  IVar1 = _objc_msgSend(param_3,DAT_012280f0,PTR_s_stringFromTimeInterval__0114d508);
  return IVar1;
}


