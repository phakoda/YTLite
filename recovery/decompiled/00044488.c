/* Decompiled from supplied 5.2.2 arm package. VA 0x44488. FUN_00044488 */

undefined1  [16] FUN_00044488(void)

{
  dispatch_time_t dVar1;
  undefined1 auVar2 [16];
  
  dVar1 = _dispatch_time(0,2000000000);
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_010619c0);
  CallSupervisor(0x3e53);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


