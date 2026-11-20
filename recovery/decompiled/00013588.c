/* Decompiled from supplied 5.2.2 arm package. VA 0x13588. FUN_00013588 */

void FUN_00013588(undefined8 param_1,undefined8 param_2,long param_3)

{
  DAT_012259a0 = 1;
  thunk_FUN_000146f4(&PTR____CFConstantStringClassReference_01153060,param_3);
  if (param_3 != 0x7fffffffffffffff) {
                    /* WARNING: Could not recover jumptable at 0x00013840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*pcRam0000000001225960)(param_1,param_2,param_3);
    return;
  }
  return;
}


