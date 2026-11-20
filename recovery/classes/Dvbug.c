// Decompiled implementation evidence for Dvbug. Not compilable source.

// +[Dvbug instanceForObject:name:], 0x227b88
/* Decompiled from supplied 5.2.2 arm package. VA 0x227b88. instanceForObject:name: */

/* Function Stack Size: 0x20 bytes */

ID Dvbug::instanceForObject_name_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *puVar5;
  
  DAT_01228368 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar5 = (&PTR_LAB_011cfc28)[param_3 == 0] + (int)-(uRam00000000011cfc38 ^ 0x416b9f2);
  if (param_3 == 0) {
LAB_00227ff8:
    thunk_FUN_0022a7f4(puVar5,@"DVN --- senderObject (%@) or name (%@) is nil",param_3,param_4);
  }
  else {
    lVar1 = _objc_msgSend(param_4,@selector(length));
    puVar5 = (&PTR_LAB_011cfc40)[lVar1 == 0] + (int)-(uRam00000000011cfc50 ^ 0xdc5b2fe7);
    if (lVar1 == 0) goto LAB_00227ff8;
    uVar2 = _objc_msgSend(param_3,@selector(class));
    uVar3 = _objc_retainAutorelease(param_4);
    uVar3 = _objc_msgSend(uVar3,@selector(UTF8String));
    lVar1 = _class_getInstanceVariable(uVar2,uVar3);
    if (lVar1 != 0) {
      _objc_msgSend(param_3,@selector(valueForKey:),param_4);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      goto LAB_00228010;
    }
  }
  uVar2 = 0;
LAB_00228010:
  _objc_release(param_4);
  _objc_release(param_3);
  IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar4;
}



// +[Dvbug observeIvar:name:], 0x228038
/* Decompiled from supplied 5.2.2 arm package. VA 0x228038. observeIvar:name: */

/* Function Stack Size: 0x20 bytes */

void Dvbug::observeIvar_name_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  DAT_0122836c = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar1 = @selector(class);
  uVar2 = _objc_msgSend(param_3,@selector(class));
  uVar3 = _objc_retainAutorelease(param_4);
  uVar3 = _objc_msgSend(uVar3,@selector(UTF8String));
  lVar4 = _class_getInstanceVariable(uVar2,uVar3);
  if (lVar4 == 0) {
    _objc_msgSend((&PTR_LAB_011cfca0)[lVar4 == 0] + (int)-(uRam00000000011cfcb0 ^ 0x64cbebb6),
                  param_3,puVar1);
    _NSStringFromClass();
    lVar4 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_0022a94c(@"DVN --- ivar %@ not found in class %@",param_4,lVar4);
  }
  else {
    _object_getIvar(param_3);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    if (lVar4 == 0) {
      thunk_FUN_0022a978((&PTR_LAB_011cfcb8)[lVar4 == 0] + (int)-(uRam00000000011cfcc8 ^ 0x2b31a024)
                         ,@"DVN --- %@: (null)",param_4);
    }
    else {
      thunk_FUN_0022a900(@"DVN --- %@: %@",param_4,lVar4);
    }
  }
  _objc_release(lVar4);
  _objc_release(param_4);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// +[Dvbug getObservedIvar:name:], 0x228948
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
  uVar1 = _objc_msgSend(param_3,@selector(class));
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,@selector(UTF8String));
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



// +[Dvbug setObservedIvar:name:value:], 0x228e60
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
  uVar1 = _objc_msgSend(param_3,@selector(class));
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,@selector(UTF8String));
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



// +[Dvbug getObservedIntIvar:name:], 0x229350
/* Decompiled from supplied 5.2.2 arm package. VA 0x229350. getObservedIntIvar:name: */

/* Function Stack Size: 0x20 bytes */

long_long Dvbug::getObservedIntIvar_name_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  long_long lVar4;
  
  DAT_01228378 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_msgSend(param_3,@selector(class));
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,@selector(UTF8String));
  lVar3 = _class_getInstanceVariable(uVar1,uVar2);
  if (lVar3 == 0) {
    lVar4 = 0;
  }
  else {
    lVar3 = _ivar_getOffset((&PTR_LAB_011cfe10)[lVar3 == 0] +
                            (int)-(uRam00000000011cfe20 ^ 0x5405d5a2));
    lVar4 = *(long_long *)(param_3 + lVar3);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  return lVar4;
}



// +[Dvbug getObservedIvarLongLong:name:], 0x22990c
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
  uVar1 = _objc_msgSend(param_3,@selector(class));
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,@selector(UTF8String));
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



// +[Dvbug getObservedBoolIvar:name:], 0x229e2c
/* Decompiled from supplied 5.2.2 arm package. VA 0x229e2c. getObservedBoolIvar:name: */

/* Function Stack Size: 0x20 bytes */

bool Dvbug::getObservedBoolIvar_name_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  bool bVar4;
  
  DAT_01228380 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_msgSend(param_3,@selector(class));
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,@selector(UTF8String));
  lVar3 = _class_getInstanceVariable(uVar1,uVar2);
  if (lVar3 == 0) {
    bVar4 = 0;
  }
  else {
    lVar3 = _ivar_getOffset((&PTR_LAB_011cff00)[lVar3 == 0] +
                            (int)-(uRam00000000011cff10 ^ 0xe2e4b51b));
    bVar4 = (bool)(*(char *)(param_3 + lVar3) != '\0');
  }
  _objc_release(param_4);
  _objc_release(param_3);
  return bVar4;
}



// +[Dvbug setObservedBoolIvar:name:value:], 0x22a380
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
  uVar1 = _objc_msgSend(param_3,@selector(class));
  uVar2 = _objc_retainAutorelease(param_4);
  uVar2 = _objc_msgSend(uVar2,@selector(UTF8String));
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


