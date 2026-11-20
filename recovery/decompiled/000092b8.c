/* Decompiled from supplied 5.2.2 arm package. VA 0x92b8. FUN_000092b8 */

void FUN_000092b8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_012258ac = 1;
  (*pcRam0000000001225858)(param_1,param_2);
  _objc_msgSend(param_2,PTR_s_parentViewController_0114ad68);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_01150b20);
  uVar3 = FUN_0000bd10(uVar1,PTR_s_isKindOfClass__0114ad70,uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000098ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151328)[uVar3 & 0xffffffff] + (int)-(uRam0000000001151338 ^ 0x8e2cc8e0)))()
  ;
  return;
}


