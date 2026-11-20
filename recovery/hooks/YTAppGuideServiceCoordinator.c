// Decompiled hook evidence for YTAppGuideServiceCoordinator. This is not compilable Logos source.

// -[YTAppGuideServiceCoordinator handleResponse:error:completion:], original IMP slot 0x012267c0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb9b6c. FUN_000b9b6c */

undefined1  [16]
FUN_000b9b6c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  thunk_FUN_000cd138();
  (*DAT_012267c0)(param_1,param_2,param_3,param_4,param_5);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xcb3a);
  return ZEXT816(0x1f);
}


