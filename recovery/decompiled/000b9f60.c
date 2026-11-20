/* Decompiled from supplied 5.2.2 arm package. VA 0xb9f60. FUN_000b9f60 */

void FUN_000b9f60(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226ef8 = 1;
  (*DAT_012267e0)(param_1);
  uVar1 = FUN_000eae6c(&PTR____CFConstantStringClassReference_011711c0);
                    /* WARNING: Could not recover jumptable at 0x000ba10c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011820c8)[uVar1 & 0xffffffff] + (int)-(DAT_011820d8 ^ 0xefe3e70d)))();
  return;
}


