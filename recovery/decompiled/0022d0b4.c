/* Decompiled from supplied 5.2.2 arm package. VA 0x22d0b4. FUN_0022d0b4 */

void FUN_0022d0b4(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  DAT_012283b8 = 1;
  _objc_retain(param_3);
  puVar2 = PTR__OBJC_CLASS___NSFileManager_0114eb48;
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_retain(param_2);
  _objc_msgSend(puVar2,puVar1);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0022d66c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d1558)[param_3 == 0] + (int)-(DAT_011d1568 ^ 0x24caafa4)))();
  return;
}


