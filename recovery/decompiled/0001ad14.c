/* Decompiled from supplied 5.2.2 arm package. VA 0x1ad14. FUN_0001ad14 */

void FUN_0001ad14(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01225bb8 = 1;
  (*DAT_01225a68)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar1,PTR_s_mutableCopy_0114b010);
  _objc_release(uVar1);
  _objc_msgSend(uVar2,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011548f0);
  lVar3 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0001b094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_DAT_01155458)[lVar3 == 0] + (int)-(DAT_01155468 ^ 0xc6ddfa8d)))();
  return;
}


