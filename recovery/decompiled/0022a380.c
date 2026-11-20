/* Decompiled from supplied 5.2.2 arm package. VA 0x22a380. setObservedBoolIvar:name:value: */

/* Function Stack Size: 0x24 bytes */

void Dvbug::setObservedBoolIvar_name_value_
               (ID param_1,SEL param_2,ID param_3,ID param_4,bool param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01228384 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,PTR_s_UTF8String_0114b498);
  lVar3 = _class_getInstanceVariable(uVar1,uVar2);
  if (lVar3 != 0) {
    lVar3 = _ivar_getOffset((&PTR_LAB_011cff78)[lVar3 == 0] +
                            (int)-(uRam00000000011cff88 ^ 0xde09b3b));
    *(char *)(param_3 + lVar3) = (char)param_5;
  }
  _objc_release(param_4);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


