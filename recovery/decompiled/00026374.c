/* Decompiled from supplied 5.2.2 arm package. VA 0x26374. FUN_00026374 */

undefined1  [16] FUN_00026374(void)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  if (DAT_01225d70 != -1) {
    _dispatch_once((&PTR_LAB_01159428)[DAT_01225d70 == -1] + (int)-(DAT_01159438 ^ 0x1e9c2165),
                   &DAT_01225d70,&PTR___NSConcreteGlobalBlock_01061640);
  }
  uVar1 = DAT_01225d68;
  _objc_retain(DAT_01225d68);
  _objc_sync_enter();
  if (DAT_01225d58 == '\0') {
    DAT_01225d58 = '\x01';
    _objc_sync_exit(uVar1);
    _objc_release(uVar1);
    _dispatch_get_global_queue(0,0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _dispatch_async(uVar1,&PTR___NSConcreteGlobalBlock_010615c0);
  }
  else {
    _objc_sync_exit(uVar1);
  }
  _objc_release(uVar1);
  CallSupervisor(0x1beb);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


