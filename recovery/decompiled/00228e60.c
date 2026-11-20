/* Decompiled from supplied 5.2.2 arm package. VA 0x228e60. setObservedIvar:name:value: */

/* Function Stack Size: 0x28 bytes */

void Dvbug::setObservedIvar_name_value_(ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01228374 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  uVar1 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,PTR_s_UTF8String_0114b498);
  lVar3 = _class_getInstanceVariable(uVar1,uVar2);
  if (lVar3 != 0) {
    _object_setIvar((&PTR_LAB_011cfdb0)[lVar3 == 0] + (int)-(DAT_011cfdc0 ^ 0x9205e587),param_3,
                    lVar3,param_5);
  }
  _objc_release(param_5);
  _objc_release(param_4);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


