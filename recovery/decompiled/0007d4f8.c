/* Decompiled from supplied 5.2.2 arm package. VA 0x7d4f8. FUN_0007d4f8 */

void FUN_0007d4f8(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(&DAT_00c4c330 + (ulong)(param_3 == 0) * 8),uVar1,
                PTR_s_colorWithAlphaComponent__0114b548);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _objc_autoreleaseReturnValue(uVar2);
  return;
}


