/* Decompiled from supplied 5.2.2 arm package. VA 0x10d600. FUN_0010d600 */

undefined1  [16] FUN_0010d600(long param_1,long param_2,long param_3)

{
  undefined1 auVar1 [16];
  
  DAT_01227224 = 1;
  _objc_retain(param_2);
  _objc_retain(param_3);
  if (param_2 != 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_hide_0114d0a0);
    (**(code **)(*(long *)(param_1 + 0x28) + 0x10))(*(long *)(param_1 + 0x28),param_2);
    _objc_release(param_3);
    _objc_release(param_2);
    CallSupervisor(0x2928);
    auVar1._8_8_ = 0x1f;
    auVar1._0_8_ = 0x1a;
    return auVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0010d998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar1 = (*(code *)((&PTR_LAB_0118b3f0)[param_3 == 0] + (int)-(uRam000000000118b400 ^ 0x509c5f3a))
           )();
  return auVar1;
}


