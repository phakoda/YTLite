/* Decompiled from supplied 5.2.2 arm package. VA 0x70f38. FUN_00070f38 */

void FUN_00070f38(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_01226b88 = 1;
  (*DAT_01226218)(param_1,param_2);
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_01163cf0);
  uVar3 = FUN_000d9190(uVar1,PTR_s_isKindOfClass__0114ad70,uVar2);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00071678. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ba88)[uVar3 & 0xffffffff] + (int)-(DAT_0117ba98 ^ 0xf6362c5a)))();
  return;
}


