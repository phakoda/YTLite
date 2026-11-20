/* Decompiled from supplied 5.2.2 arm package. VA 0x287c0. FUN_000287c0 */

undefined ** FUN_000287c0(void)

{
  undefined **ppuVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  
  DAT_01225e04 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_identifierForVendor_0114b478);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_UUIDString_0114b480);
  ppuVar4 = (undefined **)_objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  ppuVar1 = &PTR____CFConstantStringClassReference_01157550;
  if (ppuVar4 != (undefined **)0x0) {
    ppuVar1 = ppuVar4;
  }
  _objc_retainAutoreleaseReturnValue(ppuVar1);
  _objc_release(ppuVar4);
  return ppuVar1;
}


