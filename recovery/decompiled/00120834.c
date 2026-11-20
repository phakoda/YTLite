/* Decompiled from supplied 5.2.2 arm package. VA 0x120834. pickerView:didSelectRow:inComponent: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::pickerView_didSelectRow_inComponent_
               (ID param_1,SEL param_2,ID param_3,long_long param_4,long_long param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  double dVar6;
  
  _objc_retain(param_3);
  uVar2 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_defaults_0114d278);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_minimumValue_0114d400;
  dVar5 = (double)_objc_msgSend(uVar2,PTR_s_minimumValue_0114d400);
  dVar6 = (double)(long)param_4;
  if (dVar5 <= dVar6) {
    dVar5 = dVar6;
  }
  _objc_msgSend(uVar2,PTR_s_key_0114c8f8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend((float)dVar5,uVar3,PTR_s_setFloat_forKey__0114d518,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  dVar5 = (double)_objc_msgSend(uVar2,puVar1);
  if (dVar6 < dVar5) {
    dVar5 = (double)_objc_msgSend((&PTR_LAB_0118dc90)[dVar6 < dVar5] +
                                  (int)-(DAT_0118dca0 ^ 0xb57972e8),uVar2,puVar1);
    _objc_msgSend(param_3,PTR_s_selectRow_inComponent_animated__0114d520,(long)dVar5,0,1);
    dVar5 = (double)_objc_msgSend(uVar2,puVar1);
    _objc_msgSend(param_1,PTR_s_pickerView_didSelectRow_inCompon_0114d528,param_3,(long)dVar5,0);
  }
  _objc_release(uVar2);
  _objc_release(param_3);
  CallSupervisor(0x9b5a);
  return;
}


