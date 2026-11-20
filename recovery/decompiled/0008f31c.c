/* Decompiled from supplied 5.2.2 arm package. VA 0x8f31c. FUN_0008f31c */

void FUN_0008f31c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  DAT_01226d48 = 1;
  _objc_retain(param_3);
  (*DAT_012264e0)(param_1,param_2,param_3);
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_parentViewController_0114ad68);
  _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0008f644. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e3f8)[DAT_01226898 == 0] + (int)-(DAT_0117e408 ^ 0x1e9fc856)))();
  return;
}


