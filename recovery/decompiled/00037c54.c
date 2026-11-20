/* Decompiled from supplied 5.2.2 arm package. VA 0x37c54. FUN_00037c54 */

undefined1  [16] FUN_00037c54(long param_1)

{
  undefined **ppuVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01225e80 = 1;
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  ppuVar1 = &PTR____CFConstantStringClassReference_0115a680;
  if (bRam0000000001225e58 != 0) {
    ppuVar1 = &PTR____CFConstantStringClassReference_0115a640;
  }
  bRam0000000001225e58 = bRam0000000001225e58 ^ 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_systemImageNamed__0114b718,ppuVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setImage_forState__0114adf0,uVar2,0);
  _objc_release(uVar2);
  CallSupervisor(0xecaa);
  return ZEXT816(0x1f);
}


