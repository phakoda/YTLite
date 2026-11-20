/* Decompiled from supplied 5.2.2 arm package. VA 0x1b9e04. toastWindow */

/* Function Stack Size: 0x10 bytes */

ID ToastView::toastWindow(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  
  if (DAT_01227ad0 != -1) {
    _dispatch_once((&PTR_LAB_011b3e20)[DAT_01227ad0 == -1] + (int)-(DAT_011b3e30 ^ 0xdbe57c1c),
                   &DAT_01227ad0,&PTR___NSConcreteGlobalBlock_01062a00);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227ac8,param_2);
  return IVar1;
}


