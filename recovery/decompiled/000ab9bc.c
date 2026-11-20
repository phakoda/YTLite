/* Decompiled from supplied 5.2.2 arm package. VA 0xab9bc. FUN_000ab9bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000ab9bc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226e40 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e7b84(&PTR____CFConstantStringClassReference_0116e4e0);
  if (iVar1 == 0) {
    uVar2 = (*_DAT_01226688)(param_1,param_2,param_3);
    _objc_release(param_3);
    return uVar2;
  }
  _objc_msgSend(param_3,PTR_s_icon_0114cc30);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = _objc_msgSend(uVar2,PTR_s_iconType_0114ae10);
  _objc_release(uVar2);
                    /* WARNING: Could not recover jumptable at 0x000abbec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)((&PTR_LAB_011812e8)[iVar1 == 0xfb] + (int)-(uRam00000000011812f8 ^ 0x53e66d9e))
          )();
  return uVar2;
}


