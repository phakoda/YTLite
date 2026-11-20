/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1e4c. FUN_001c1e4c */

undefined1  [16] FUN_001c1e4c(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long lVar2;
  double dVar3;
  
  _objc_retain(param_2);
  lVar2 = *(long *)(*(long *)(param_1 + 0x28) + 8);
  *(double *)(lVar2 + 0x18) = *(double *)(lVar2 + 0x18) - *(double *)(param_1 + 0x30);
  dVar3 = *(double *)(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x18);
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_toastProgress);
  if (0.0 < dVar3) {
    _objc_msgSend((float)dVar3,uVar1,PTR_s_setProgress_animated__0114dd28,1);
  }
  else {
    _objc_msgSend(0,uVar1,PTR_s_setProgress_animated__0114dd28,1);
    _objc_msgSend(param_2,PTR_s_invalidate_0114de10);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_hide_0114d0a0);
  }
  _objc_release(param_2);
  CallSupervisor(0x3771);
  return ZEXT816(0x1f);
}


