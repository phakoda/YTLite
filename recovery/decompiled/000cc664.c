/* Decompiled from supplied 5.2.2 arm package. VA 0xcc664. FUN_000cc664 */

undefined1  [16] FUN_000cc664(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  _objc_retain(param_2);
  iVar1 = FUN_000efe24(*(undefined8 *)(param_1 + 0x20),PTR_s_containsIndex__0114cae0,param_3);
  if (iVar1 == 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_addObject__0114b3a0,param_2);
  }
  _objc_release(param_2);
  CallSupervisor(0xd73f);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


