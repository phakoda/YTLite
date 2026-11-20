/* Decompiled from supplied 5.2.2 arm package. VA 0x8798c. FUN_0008798c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008798c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ca0 = 1;
  iVar1 = FUN_000df254(&PTR____CFConstantStringClassReference_01167b20);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087b90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263b8)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


