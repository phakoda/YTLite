// Decompiled hook evidence for YTInlineMutedPlaybackScrubbingSlider. This is not compilable Logos source.

// -[YTInlineMutedPlaybackScrubbingSlider currentMinimumTrackImage], original IMP slot 0x01226588
/* Decompiled from supplied 5.2.2 arm package. VA 0x95b20. FUN_00095b20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00095b20(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  DAT_01226da4 = 1;
  (*_DAT_01226588)();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(objectForKey:),@"progressMainColor");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(class));
  _objc_msgSend(puVar1,@selector(unarchivedObjectOfClass:fromData:error:),uVar2,uVar3,0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _ytpInt(@"progressBarIndex");
                    /* WARNING: Could not recover jumptable at 0x00095ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117ece8)[lVar5 != 0 && lVar4 != 0] +
            (int)-(uRam000000000117ecf8 ^ 0xd64b92e9)))();
  return;
}


