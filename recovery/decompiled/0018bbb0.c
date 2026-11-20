/* Decompiled from supplied 5.2.2 arm package. VA 0x18bbb0. addSection: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::addSection_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x48),PTR_s_arrayByAddingObject__0114d978);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0x48) = uVar1;
  _objc_release(uVar2);
  CallSupervisor(0x6bbf);
  return;
}


