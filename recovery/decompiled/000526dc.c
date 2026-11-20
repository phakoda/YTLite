/* Decompiled from supplied 5.2.2 arm package. VA 0x526dc. FUN_000526dc */

void FUN_000526dc(void)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226a5c = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,PTR_s_integerForKey__0114b3a8,
                        &PTR____CFConstantStringClassReference_0115f1c0);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00052b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a7d8)[lVar2 == 3] + (int)-(uRam000000000117a7e8 ^ 0x40debe98)))();
  return;
}


