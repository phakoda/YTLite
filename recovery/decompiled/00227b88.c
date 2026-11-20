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
    thunk_FUN_0022a7f4(puVar5,&PTR____CFConstantStringClassReference_011cf1d0,param_3,param_4);
  }
  else {
    lVar1 = _objc_msgSend(param_4,PTR_s_length_0114b438);
    puVar5 = (&PTR_LAB_011cfc40)[lVar1 == 0] + (int)-(uRam00000000011cfc50 ^ 0xdc5b2fe7);
    if (lVar1 == 0) goto LAB_00227ff8;
    uVar2 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
    uVar3 = _objc_retainAutorelease(param_4);
    uVar3 = _objc_msgSend(uVar3,PTR_s_UTF8String_0114b498);
    lVar1 = _class_getInstanceVariable(uVar2,uVar3);
    if (lVar1 != 0) {
      _objc_msgSend(param_3,PTR_s_valueForKey__0114ae90,param_4);
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


