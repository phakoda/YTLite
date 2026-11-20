/* Decompiled from supplied 5.2.2 arm package. VA 0x211308. FUN_00211308 */

undefined8 FUN_00211308(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_localizedStringForKey_value_tabl_0114b278,param_1,0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  lVar3 = _objc_msgSend(uVar2,PTR_s_length_0114b438);
  if (lVar3 != 0) {
    param_1 = uVar2;
  }
  _objc_retainAutoreleaseReturnValue(param_1);
  _objc_release(uVar2);
  return param_1;
}


