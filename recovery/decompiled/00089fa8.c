/* Decompiled from supplied 5.2.2 arm package. VA 0x89fa8. FUN_00089fa8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00089fa8(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  double dVar7;
  
  puVar1 = PTR_s_currentPlaybackRate_0114c6c0;
  DAT_01226d00 = 1;
  dVar7 = (double)_objc_msgSend(param_1,PTR_s_currentPlaybackRate_0114c6c0);
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar2 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  if (dVar7 == 1.0) {
    (*_DAT_01226470)(param_1,param_2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,puVar1);
    _objc_msgSend(puVar2,PTR_s_numberWithDouble__0114c310);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_stringValue_0114c958);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_000df6d8(puVar3,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_01168350,uVar6);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return;
}


