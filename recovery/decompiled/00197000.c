/* Decompiled from supplied 5.2.2 arm package. VA 0x197000. FUN_00197000 */

undefined1  [16] FUN_00197000(long param_1)

{
  long lVar1;
  undefined1 auVar2 [16];
  
  DAT_0122784c = 1;
  lVar1 = _objc_loadWeakRetained(param_1 + 0x30);
  if (lVar1 != 0) {
    lVar1 = _objc_loadWeakRetained(*(long *)(param_1 + 0x20) + 8);
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x00197214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar2 = (*(code *)((&PTR_LAB_011aaea0)[lVar1 == 0] + (int)-(uRam00000000011aaeb0 ^ 0x3327c308))
             )();
    return auVar2;
  }
  _objc_release((&PTR_LAB_011aae88)[lVar1 == 0] + (int)-(uRam00000000011aae98 ^ 0x69759e50),0);
  CallSupervisor(0xa300);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


