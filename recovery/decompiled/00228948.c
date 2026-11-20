/* Decompiled from supplied 5.2.2 arm package. VA 0x228948. getObservedIvar:name: */

/* Function Stack Size: 0x20 bytes */

ID Dvbug::getObservedIvar_name_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  ID IVar4;
  
  DAT_01228370 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,PTR_s_UTF8String_0114b498);
  lVar3 = _class_getInstanceVariable(uVar1,uVar2);
  uVar1 = 0;
  if (lVar3 != 0) {
    _object_getIvar((&PTR_LAB_011cfd38)[lVar3 == 0] + (int)-(DAT_011cfd48 ^ 0xf24d0249),param_3);
    uVar1 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(param_4);
  _objc_release(param_3);
  IVar4 = _objc_autoreleaseReturnValue(uVar1);
  return IVar4;
}


