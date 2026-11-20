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


