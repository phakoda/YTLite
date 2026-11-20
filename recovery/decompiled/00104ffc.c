/* Decompiled from supplied 5.2.2 arm package. VA 0x104ffc. detailForMimeType: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::detailForMimeType_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  ID IVar7;
  long lVar8;
  undefined1 auVar9 [16];
  
  DAT_0122719c = 1;
  uVar3 = _objc_retain(param_3);
  puVar1 = PTR_s_rangeOfString__0114b670;
  auVar9 = _objc_msgSend(uVar3,PTR_s_rangeOfString__0114b670,
                         &PTR____CFConstantStringClassReference_01187090);
  if (auVar9._0_8_ == 0x7fffffffffffffff) {
    lVar5 = 0;
  }
  else {
    _objc_msgSend(param_3,PTR_s_substringFromIndex__0114c5f0,auVar9._0_8_ + auVar9._8_8_);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_componentsSeparatedByString__0114b510,
                  &PTR____CFConstantStringClassReference_01187190);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_firstObject_0114b748);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  auVar9 = _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_01187110);
  uVar3 = 0;
  lVar8 = 0;
  if (auVar9._0_8_ != 0x7fffffffffffffff) {
    _objc_msgSend(param_3,PTR_s_substringFromIndex__0114c5f0,auVar9._0_8_ + auVar9._8_8_);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_componentsSeparatedByString__0114b510;
    _objc_msgSend(uVar3,PTR_s_componentsSeparatedByString__0114b510,
                  &PTR____CFConstantStringClassReference_01187150);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_firstObject_0114b748;
    _objc_msgSend(uVar4,PTR_s_firstObject_0114b748);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(uVar6,puVar1,&PTR____CFConstantStringClassReference_011870d0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2);
    lVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar6);
    _objc_release(uVar3);
    uVar3 = 0;
    if (lVar5 != 0 && lVar8 != 0) {
      thunk_FUN_00112b90(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_01187050,lVar5,lVar8);
      uVar3 = _objc_retainAutoreleasedReturnValue();
    }
  }
  _objc_release(lVar8);
  _objc_release(lVar5);
  _objc_release(param_3);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar7;
}


