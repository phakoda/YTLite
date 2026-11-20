/* Decompiled from supplied 5.2.2 arm package. VA 0x7dc00. FUN_0007dc00 */

void FUN_0007dc00(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226bfc = 1;
  iVar1 = FUN_000dcde4(&PTR____CFConstantStringClassReference_01165fe0);
  if (iVar1 == 0) {
    (*DAT_012262a8)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_autoreleaseReturnValue(uVar2);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0007dec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ca80)[lRam00000000012268b8 == 0] +
            (int)-(uRam000000000117ca90 ^ 0x590c97ff)))();
  return;
}


