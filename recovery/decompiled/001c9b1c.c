/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9b1c. sharedManager */

/* Function Stack Size: 0x10 bytes */

ID ToastManager::sharedManager(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  
  if (DAT_01227c80 != -1) {
    _dispatch_once((&PTR_LAB_011b4e58)[DAT_01227c80 == -1] + (int)-(DAT_011b4e68 ^ 0xad99279f),
                   &DAT_01227c80,&PTR___NSConcreteGlobalBlock_01062ca0);
    param_2 = extraout_x1;
  }
  IVar1 = _objc_retainAutoreleaseReturnValue(DAT_01227c78,param_2);
  return IVar1;
}


