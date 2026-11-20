/* Decompiled from supplied 5.2.2 arm package. VA 0xb9568. FUN_000b9568 */

void FUN_000b9568(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_01226ed8 = 1;
  (*DAT_012267a0)(param_1);
  _objc_msgSend(param_1,PTR_s_navigationButton_0114c240);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_000eacbc(&PTR____CFConstantStringClassReference_01171080);
  _objc_msgSend(uVar2,PTR_s_setSizeWithPaddingAndInsets__0114cd78,uVar1 ^ 1);
  _objc_release(uVar2);
  uVar3 = FUN_000ead00(&PTR____CFConstantStringClassReference_01171080);
                    /* WARNING: Could not recover jumptable at 0x000b9754. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181ff0)[uVar3 & 0xffffffff] + (int)-(DAT_01182000 ^ 0x83ede03)))();
  return;
}


