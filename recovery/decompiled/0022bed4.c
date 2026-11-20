/* Decompiled from supplied 5.2.2 arm package. VA 0x22bed4. FUN_0022bed4 */

undefined1  [16] FUN_0022bed4(long param_1)

{
  long lVar1;
  undefined1 auVar2 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x20) + 0x10);
  if (lVar1 != 0) {
    _objc_msgSend(lVar1,PTR_s_cancelDownload_0114e740);
  }
  CallSupervisor(0xa54b);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


