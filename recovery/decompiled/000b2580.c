/* Decompiled from supplied 5.2.2 arm package. VA 0xb2580. FUN_000b2580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b2580(undefined8 param_1)

{
  undefined8 uVar1;
  
  DAT_01226e98 = 1;
  (*_DAT_01226738)(param_1);
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_parentViewController_0114ad68);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x000b2a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181708)[lRam0000000001226920 == 0] +
            (int)-(uRam0000000001181718 ^ 0x869031ee)))();
  return;
}


