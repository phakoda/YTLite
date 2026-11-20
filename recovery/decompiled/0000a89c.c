/* Decompiled from supplied 5.2.2 arm package. VA 0xa89c. FUN_0000a89c */

void FUN_0000a89c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_012258b8 = 1;
  _objc_retain(param_4);
  (*pcRam0000000001225870)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_0000c110(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_01150e80);
                    /* WARNING: Could not recover jumptable at 0x0000aa50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01151478)[uVar1 & 0xffffffff] + (int)-(DAT_01151488 ^ 0xe257a351)))();
  return;
}


