/* Decompiled from supplied 5.2.2 arm package. VA 0x11b560. _barButtonTriggered: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_barButtonTriggered_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  DAT_012272c4 = 1;
  _objc_getAssociatedObject(param_3,&PTR____CFConstantStringClassReference_0118bb60);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    (**(code **)(lVar1 + 0x10))(lVar1);
  }
  _objc_release(lVar1);
  return;
}


