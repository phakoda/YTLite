/* Decompiled from supplied 5.2.2 arm package. VA 0x1253f8. dealloc */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::dealloc(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  ID local_30;
  undefined *puStack_28;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeObserver__0114c4b0,param_1);
  _objc_release(uVar1);
  puStack_28 = PTR_DVNTableViewController_0114f0a8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,PTR_s_dealloc_0114d678);
  return;
}


