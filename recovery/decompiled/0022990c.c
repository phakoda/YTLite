/* Decompiled from supplied 5.2.2 arm package. VA 0x22990c. getObservedIvarLongLong:name: */

/* Function Stack Size: 0x20 bytes */

long_long Dvbug::getObservedIvarLongLong_name_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  long_long lVar4;
  
  DAT_0122837c = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,PTR_s_UTF8String_0114b498);
  lVar3 = _class_getInstanceVariable(uVar1,uVar2);
  if (lVar3 == 0) {
    lVar4 = 0;
  }
  else {
    lVar3 = _ivar_getOffset((&PTR_LAB_011cfe88)[lVar3 == 0] +
                            (int)-(uRam00000000011cfe98 ^ 0xabcc69c4));
    lVar4 = *(long_long *)(param_3 + lVar3);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  return lVar4;
}


