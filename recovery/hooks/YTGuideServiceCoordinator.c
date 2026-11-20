// Decompiled hook evidence for YTGuideServiceCoordinator. This is not compilable Logos source.

// -[YTGuideServiceCoordinator handleResponse:withCompletion:], original IMP slot 0x012267b0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb9a58. FUN_000b9a58 */

void FUN_000b9a58(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  _objc_retain(param_4);
  _objc_retain(param_3);
  thunk_FUN_000cd138();
  (*DAT_012267b0)(param_1,param_2,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  return;
}



// -[YTGuideServiceCoordinator handleResponse:error:completion:], original IMP slot 0x012267b8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb9ac4. FUN_000b9ac4 */

undefined1  [16]
FUN_000b9ac4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  thunk_FUN_000cd138();
  (*DAT_012267b8)(param_1,param_2,param_3,param_4,param_5);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x655);
  return ZEXT816(0x1f);
}


