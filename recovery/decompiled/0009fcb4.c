/* Decompiled from supplied 5.2.2 arm package. VA 0x9fcb4. FUN_0009fcb4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0009fcb4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  
  DAT_01226ddc = 1;
  uVar1 = FUN_000e5044(param_1,PTR_s_respondsToSelector__0114af58,PTR_s_maybeLoopPlayback_0114b9c0);
  if (uVar1 != 0) {
    (*_DAT_012265f8)(param_1,param_2,param_3);
    lVar2 = _ytpInt(&PTR____CFConstantStringClassReference_0116c440);
                    /* WARNING: Could not recover jumptable at 0x0009ff90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar3 = (*(code *)((&PTR_LAB_0117fdd0)[lVar2 == 2] + (int)-(uRam000000000117fde0 ^ 0x89ae18ff))
             )();
    return auVar3;
  }
  lVar2 = _ytpInt((&PTR_LAB_0117fdb8)[uVar1] + (int)-(DAT_0117fdc8 ^ 0x13846f42),
                  &PTR____CFConstantStringClassReference_0116c440);
  if (lVar2 != 2) {
    (*_DAT_012265f8)(param_1,param_2,param_3);
  }
  CallSupervisor(0x9c8e);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


