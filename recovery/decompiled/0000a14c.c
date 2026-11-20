/* Decompiled from supplied 5.2.2 arm package. VA 0xa14c. FUN_0000a14c */

void FUN_0000a14c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_012258b4 = 1;
  (*pcRam0000000001225868)(param_1,param_2);
  _objc_msgSend(param_2,PTR_s_parentViewController_0114ad68);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_01150e20);
  uVar3 = FUN_0000c000(uVar1,PTR_s_isKindOfClass__0114ad70,uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0000a748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151408)[uVar3 & 0xffffffff] + (int)-(uRam0000000001151418 ^ 0x7d3ed7eb)))()
  ;
  return;
}


