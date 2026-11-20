/* Decompiled from supplied 5.2.2 arm package. VA 0xc1fb4. FUN_000c1fb4 */

undefined1  [16] FUN_000c1fb4(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  _objc_msgSend(PTR__OBJC_CLASS___PHAssetCreationRequest_0114ed60,
                PTR_s_creationRequestForAssetFromImage_0114c608,*(undefined8 *)(param_1 + 0x20));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setCreationDate__0114c610,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x1cd9);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


