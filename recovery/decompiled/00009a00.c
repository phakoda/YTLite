/* Decompiled from supplied 5.2.2 arm package. VA 0x9a00. recovered_hook_00009a00 */

void recovered_hook_00009a00(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  uRam00000000012258b0 = 1;
  (*pcRam0000000001225860)(param_1,param_2);
  _objc_msgSend(param_2,PTR_s_parentViewController_0114ad68);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_01150ca0);
  uVar3 = FUN_0000be88(uVar1,PTR_s_isKindOfClass__0114ad70,uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00009ff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151398)[uVar3 & 0xffffffff] + (int)-(DAT_011513a8 ^ 0xad76b9e9)))();
  return;
}


