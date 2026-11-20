/* Decompiled from supplied 5.2.2 arm package. VA 0xb9cbc. FUN_000b9cbc */

undefined1  [16]
FUN_000b9cbc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  thunk_FUN_000cd138();
  (*DAT_012267d0)(param_1,param_2,param_3,param_4,param_5);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x7270);
  return ZEXT816(0x1f);
}


