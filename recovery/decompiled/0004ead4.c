/* Decompiled from supplied 5.2.2 arm package. VA 0x4ead4. FUN_0004ead4 */

undefined1  [16] FUN_0004ead4(void)

{
  dispatch_time_t dVar1;
  
  (*DAT_01225f60)();
  dVar1 = _dispatch_time(0,300000000);
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061a20);
  CallSupervisor(0x7088);
  return ZEXT816(0x1f);
}


