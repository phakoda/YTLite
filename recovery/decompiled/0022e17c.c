/* Decompiled from supplied 5.2.2 arm package. VA 0x22e17c. FUN_0022e17c */

undefined1  [16] FUN_0022e17c(long param_1)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR__OBJC_CLASS___PHAssetCreationRequest_0114ed60,
                PTR_s_creationRequestForAsset_0114e780);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_addResourceWithType_fileURL_opti_0114e788,2,
                *(undefined8 *)(param_1 + 0x20),0);
  _objc_release(uVar1);
  CallSupervisor(0xd3f1);
  return ZEXT816(0x1f);
}


