/* Decompiled from supplied 5.2.2 arm package. VA 0x1decd8. FUN_001decd8 */

void FUN_001decd8(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  _objc_retain(param_2);
  _objc_retain(param_3);
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  _objc_retain(uVar1);
  _objc_sync_enter();
  if (param_3 == 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_addObject__0114b3a0,param_2);
  }
  else {
    _objc_storeStrong(*(long *)(*(long *)(param_1 + 0x30) + 8) + 0x28,param_3);
  }
  _objc_sync_exit(uVar1);
  _objc_release(uVar1);
  _dispatch_group_leave(*(dispatch_group_t *)(param_1 + 0x28));
  _objc_release(param_3);
  (*(code *)PTR__objc_release_01061028)(param_2);
  return;
}


