/* Decompiled from supplied 5.2.2 arm package. VA 0x1fe508. FUN_001fe508 */

undefined1  [16] FUN_001fe508(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x28);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_parserError_0114e310);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  (**(code **)(lVar1 + 0x10))(lVar1,0,uVar2);
  _objc_release(uVar2);
  CallSupervisor(0xb34c);
  return ZEXT816(0x1f);
}


