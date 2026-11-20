/* Decompiled from supplied 5.2.2 arm package. VA 0x4ee9c. FUN_0004ee9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0004ee9c(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226a1c = 1;
  (*_DAT_01225f70)(param_1);
  uVar1 = _NSClassFromString(&PTR____CFConstantStringClassReference_0115e760);
  uVar2 = FUN_000d1084(param_1,PTR_s_isKindOfClass__0114ad70,uVar1);
                    /* WARNING: Could not recover jumptable at 0x0004f9e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a338)[uVar2 & 0xffffffff] + (int)-(uRam000000000117a348 ^ 0x935011e2)))()
  ;
  return;
}


