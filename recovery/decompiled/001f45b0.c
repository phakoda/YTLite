/* Decompiled from supplied 5.2.2 arm package. VA 0x1f45b0. FUN_001f45b0 */

undefined1  [16] FUN_001f45b0(long param_1)

{
  undefined1 auVar1 [16];
  
  _objc_storeStrong(*(long *)(param_1 + 0x20) + 0x10,*(undefined8 *)(param_1 + 0x28));
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_updateProgressDialog_0114e268);
  CallSupervisor(0xbda);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


