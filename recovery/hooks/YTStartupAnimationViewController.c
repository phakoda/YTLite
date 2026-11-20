// Decompiled hook evidence for YTStartupAnimationViewController. This is not compilable Logos source.

// -[YTStartupAnimationViewController viewDidLoad], original IMP slot 0x01225fe0
/* Decompiled from supplied 5.2.2 arm package. VA 0x52438. FUN_00052438 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00052438(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226a58 = 1;
  (*_DAT_01225fe0)(param_1);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000d18d0(uVar1,@selector(boolForKey:),
                       @"oledTheme");
                    /* WARNING: Could not recover jumptable at 0x000525e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a778)[uVar2 & 0xffffffff] + (int)-(uRam000000000117a788 ^ 0x4d951762)))()
  ;
  return;
}



// -[YTStartupAnimationViewController playLottieAnimation], original IMP slot 0x01225fe8
/* Decompiled from supplied 5.2.2 arm package. VA 0x526dc. FUN_000526dc */

void FUN_000526dc(void)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226a5c = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,@selector(integerForKey:),
                        @"startupAnimation");
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00052b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a7d8)[lVar2 == 3] + (int)-(uRam000000000117a7e8 ^ 0x40debe98)))();
  return;
}



// -[YTStartupAnimationViewController dealloc], original IMP slot 0x01225ff0
/* Decompiled from supplied 5.2.2 arm package. VA 0x53748. FUN_00053748 */

void FUN_00053748(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  uint local_104;
  undefined **local_100;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_100 = &PTR_LAB_0117a8c0;
  _objc_getAssociatedObject(param_1,@selector(playLottieAnimation));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  lVar2 = _objc_msgSend(uVar1,@selector(countByEnumeratingWithState:objects:count:),&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x0005382c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_100[local_104] + (int)-(DAT_0117a8d0 ^ 0x8c086bf7)))();
  return;
}


