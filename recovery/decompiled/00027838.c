/* Decompiled from supplied 5.2.2 arm package. VA 0x27838. FUN_00027838 */

void FUN_00027838(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  
  DAT_01225df0 = 1;
  bVar1 = lRam0000000001225d40 == -1;
  _objc_retain(param_2);
  _objc_retain(param_1);
                    /* WARNING: Could not recover jumptable at 0x0002798c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01159638)[bVar1] + (int)-(uRam0000000001159648 ^ 0x8db883df)))();
  return;
}


