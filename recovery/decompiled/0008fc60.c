/* Decompiled from supplied 5.2.2 arm package. VA 0x8fc60. FUN_0008fc60 */

undefined8 FUN_0008fc60(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d58 = 1;
  iVar1 = FUN_000e0e14(&PTR____CFConstantStringClassReference_01169530);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008fe5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*DAT_01226500)(param_1,param_2);
    return uVar2;
  }
  return 0x1a;
}


