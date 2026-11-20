/* Decompiled from supplied 5.2.2 arm package. VA 0xb97bc. FUN_000b97bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b97bc(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226edc = 1;
  (*_DAT_012267a8)(param_1);
  uVar1 = FUN_000ead64(&PTR____CFConstantStringClassReference_01171100);
                    /* WARNING: Could not recover jumptable at 0x000b99a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01182030)[uVar1 & 0xffffffff] + (int)-(uRam0000000001182040 ^ 0xe2fbf059)))()
  ;
  return;
}


