/* Decompiled from supplied 5.2.2 arm package. VA 0x3120c. FUN_0003120c */

undefined1  [16] FUN_0003120c(undefined8 param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = (param_2 & 6) == 2;
  if (bVar1) {
    thunk_FUN_00026374((&PTR_LAB_0115a080)[bVar1] + (int)-(DAT_0115a090 ^ 0x76343b50));
  }
  CallSupervisor(0xdfbf);
  return ZEXT816(0x1f);
}


