/* Decompiled from supplied 5.2.2 arm package. VA 0x8eaac. FUN_0008eaac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0008eaac(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  DAT_01226d40 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_01169230);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_class_0114ae88);
  _objc_msgSend(puVar1,PTR_s_unarchivedObjectOfClass_fromData_0114b758,uVar2,uVar3,0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_011691f0);
  if (lVar5 != 0 && lVar4 != 0) {
    _objc_retain((&PTR_LAB_0117e340)[lVar5 != 0 && lVar4 != 0] +
                 (int)-(uRam000000000117e350 ^ 0xe9457ba3),lVar4);
    lVar5 = lVar4;
  }
  else {
    (*_DAT_012264d0)(param_1,param_2);
    lVar5 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(lVar4);
  _objc_release(uVar3);
  _objc_autoreleaseReturnValue(lVar5);
  return;
}


