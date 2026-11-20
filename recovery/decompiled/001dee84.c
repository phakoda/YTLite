/* Decompiled from supplied 5.2.2 arm package. VA 0x1dee84. FUN_001dee84 */

undefined1  [16] FUN_001dee84(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(*(long *)(*(long *)(param_1 + 0x30) + 8) + 0x28) == 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_componentsJoinedByString__0114ded0,&cf___);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(*(long *)(param_1 + 0x28) + 0x10))(*(long *)(param_1 + 0x28),uVar1,0);
    _objc_release(uVar1);
  }
  else {
    (**(code **)(*(long *)(param_1 + 0x28) + 0x10))(*(long *)(param_1 + 0x28),0);
  }
  CallSupervisor(0x5f69);
  return ZEXT816(0x1f);
}


