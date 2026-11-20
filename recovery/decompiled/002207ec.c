/* Decompiled from supplied 5.2.2 arm package. VA 0x2207ec. FUN_002207ec */

undefined1  [16] FUN_002207ec(long param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_hapticFeedback_0114e628);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_fullImage_0114e630);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _UIImageWriteToSavedPhotosAlbum(uVar1,0,0,0);
  _objc_release(uVar1);
  CallSupervisor(0xcdb);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


