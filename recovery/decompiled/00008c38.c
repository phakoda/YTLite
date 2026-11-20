/* Decompiled from supplied 5.2.2 arm package. VA 0x8c38. FUN_00008c38 */

void FUN_00008c38(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_012258a8 = 1;
  (*pcRam0000000001225850)(param_1);
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_011509a0);
  uVar3 = FUN_0000bad8(uVar1,PTR_s_isKindOfClass__0114ad70,uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0000916c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011512d0)[uVar3 & 0xffffffff] + (int)-(DAT_011512e0 ^ 0x762bd33b)))();
  return;
}


