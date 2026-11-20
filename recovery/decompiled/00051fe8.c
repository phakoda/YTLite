/* Decompiled from supplied 5.2.2 arm package. VA 0x51fe8. FUN_00051fe8 */

void FUN_00051fe8(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  (*DAT_01225fd0)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIContextMenuInteraction_0114ecd8);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithDelegate__0114bd78,param_1);
  _objc_msgSend(uVar1,PTR_s_setUserInteractionEnabled__0114b820,1);
  _objc_msgSend(uVar1,PTR_s_addInteraction__0114c380,uVar2);
  _objc_release(uVar2);
  _objc_autoreleaseReturnValue(uVar1);
  return;
}


