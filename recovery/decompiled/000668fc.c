/* Decompiled from supplied 5.2.2 arm package. VA 0x668fc. FUN_000668fc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000668fc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a80 = 1;
  iVar1 = FUN_000d6e2c(&PTR____CFConstantStringClassReference_01161c20);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00066a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226020)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


