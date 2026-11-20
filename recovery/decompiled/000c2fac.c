/* Decompiled from supplied 5.2.2 arm package. VA 0xc2fac. FUN_000c2fac */

undefined1  [16] FUN_000c2fac(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR__OBJC_CLASS___PHAssetCreationRequest_0114ed60,
                PTR_s_creationRequestForAssetFromImage_0114c608,*(undefined8 *)(param_1 + 0x20));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setCreationDate__0114c610,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x20c4);
  return ZEXT816(0x1f);
}


