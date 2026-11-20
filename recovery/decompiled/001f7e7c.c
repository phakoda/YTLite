/* Decompiled from supplied 5.2.2 arm package. VA 0x1f7e7c. FUN_001f7e7c */

undefined1  [16] FUN_001f7e7c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01228018 = 1;
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011be790,0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_showToast__0114d088,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0xded9);
  return ZEXT816(0x1f);
}


