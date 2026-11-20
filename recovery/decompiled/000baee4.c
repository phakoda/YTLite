/* Decompiled from supplied 5.2.2 arm package. VA 0xbaee4. FUN_000baee4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000baee4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226f10 = 1;
  iVar1 = FUN_000eb084(&PTR____CFConstantStringClassReference_011714d0);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000bb0c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226810)(param_1,param_2);
    return uVar2;
  }
  return 1;
}


