/* Decompiled from supplied 5.2.2 arm package. VA 0x1b16c. FUN_0001b16c */

void FUN_0001b16c(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01225bbc = 1;
  (*DAT_01225a70)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar1,PTR_s_mutableCopy_0114b010);
  _objc_release(uVar1);
  _objc_msgSend(uVar2,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011549c0);
  lVar3 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0001b48c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01155498)[lVar3 == 0] + (int)-(DAT_011554a8 ^ 0x63ee1669)))();
  return;
}


