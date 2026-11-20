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
  puVar1 = PTR_s_class_0114ae88;
  uVar2 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
  uVar3 = _objc_retainAutorelease(param_4);
  uVar3 = _objc_msgSend(uVar3,PTR_s_UTF8String_0114b498);
  lVar4 = _class_getInstanceVariable(uVar2,uVar3);
  if (lVar4 == 0) {
    _objc_msgSend((&PTR_LAB_011cfca0)[lVar4 == 0] + (int)-(uRam00000000011cfcb0 ^ 0x64cbebb6),
                  param_3,puVar1);
    _NSStringFromClass();
    lVar4 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_0022a94c(&PTR____CFConstantStringClassReference_011cf370,param_4,lVar4);
  }
  else {
    _object_getIvar(param_3);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    if (lVar4 == 0) {
      thunk_FUN_0022a978((&PTR_LAB_011cfcb8)[lVar4 == 0] + (int)-(uRam00000000011cfcc8 ^ 0x2b31a024)
                         ,&PTR____CFConstantStringClassReference_011cf3b0,param_4);
    }
    else {
      thunk_FUN_0022a900(&PTR____CFConstantStringClassReference_011cf3f0,param_4,lVar4);
    }
  }
  _objc_release(lVar4);
  _objc_release(param_4);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


