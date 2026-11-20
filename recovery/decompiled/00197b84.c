/* Decompiled from supplied 5.2.2 arm package. VA 0x197b84. FUN_00197b84 */

undefined1  [16] FUN_00197b84(long param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  uVar1 = _objc_loadWeakRetained(*(long *)(param_1 + 0x20) + 8);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),uVar1,PTR_s_seekToTime__0114ad18);
  _objc_release(uVar1);
  CallSupervisor(0x8321);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


