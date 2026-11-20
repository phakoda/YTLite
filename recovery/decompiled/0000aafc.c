/* Decompiled from supplied 5.2.2 arm package. VA 0xaafc. FUN_0000aafc */

void FUN_0000aafc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  DAT_012258bc = 1;
  _objc_retain(param_4);
  (*pcRam0000000001225878)(param_1,param_2,param_3,param_4);
  uVar1 = FUN_0000c138(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_01150ee0);
                    /* WARNING: Could not recover jumptable at 0x0000aca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011514b8)[uVar1 & 0xffffffff] + (int)-(uRam00000000011514c8 ^ 0x1f343ba7)))()
  ;
  return;
}


