/* Decompiled from supplied 5.2.2 arm package. VA 0x4fc10. FUN_0004fc10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0004fc10(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226a20 = 1;
  (*_DAT_01225f78)(param_1);
  uVar1 = _NSClassFromString(&PTR____CFConstantStringClassReference_0115e9f0);
  uVar2 = FUN_000d12ac(param_1,PTR_s_isKindOfClass__0114ad70,uVar1);
                    /* WARNING: Could not recover jumptable at 0x000504f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a3d0)[uVar2 & 0xffffffff] + (int)-(DAT_0117a3e0 ^ 0x250708f9)))();
  return;
}


