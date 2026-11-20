/* Decompiled from supplied 5.2.2 arm package. VA 0x2139d4. FUN_002139d4 */

undefined1  [16] FUN_002139d4(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (*(long *)(lVar2 + 8) != 0) {
    _objc_msgSend((long)*(double *)(param_1 + 0x28),lVar2,PTR_s_formattedTime__0114e400);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar2,PTR_s_updateSlimBarTitle_style__0114e418,uVar1,
                  *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x28));
    _objc_release(uVar1);
  }
  CallSupervisor(0x44b9);
  return ZEXT816(0x1f);
}


