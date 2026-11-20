/* Decompiled from supplied 5.2.2 arm package. VA 0xb8a9c. FUN_000b8a9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b8a9c(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_01226ed4 = 1;
  (*_DAT_01226798)(param_1);
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_renderer_0114ccd0;
  _objc_msgSend(uVar3,PTR_s_renderer_0114ccd0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_description_0114af00);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = FUN_000ea5f8(uVar5,PTR_s_containsString__0114af08,
                       &PTR____CFConstantStringClassReference_01171020);
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sharedMedia_0114ccd8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_setCairo__0114cce0,uVar6);
  _objc_release(uVar7);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_icon_0114cc30);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar2 = _objc_msgSend(uVar4,PTR_s_iconType_0114ae10);
  _objc_release(uVar4);
  _objc_release(uVar3);
                    /* WARNING: Could not recover jumptable at 0x000b8d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181eb0)[iVar2 == 0x36c] + (int)-(DAT_01181ec0 ^ 0x1dcdb1c1)))();
  return;
}


