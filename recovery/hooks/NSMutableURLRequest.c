// Decompiled hook evidence for NSMutableURLRequest. This is not compilable Logos source.

// +[NSMutableURLRequest ak_clientInfoHeader], original IMP slot 0x01225a68
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ad14. FUN_0001ad14 */

void FUN_0001ad14(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01225bb8 = 1;
  (*DAT_01225a68)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar1,@selector(mutableCopy));
  _objc_release(uVar1);
  _objc_msgSend(uVar2,@selector(objectForKeyedSubscript:),
                @"X-MMe-Client-Info");
  lVar3 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0001b094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_DAT_01155458)[lVar3 == 0] + (int)-(DAT_01155468 ^ 0xc6ddfa8d)))();
  return;
}



// -[NSMutableURLRequest allHTTPHeaderFields], original IMP slot 0x01225a70
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b16c. FUN_0001b16c */

void FUN_0001b16c(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_01225bbc = 1;
  (*DAT_01225a70)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar1,@selector(mutableCopy));
  _objc_release(uVar1);
  _objc_msgSend(uVar2,@selector(objectForKeyedSubscript:),
                @"User-Agent");
  lVar3 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0001b48c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01155498)[lVar3 == 0] + (int)-(DAT_011554a8 ^ 0x63ee1669)))();
  return;
}


