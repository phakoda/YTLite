// Decompiled hook evidence for YTColdConfig. This is not compilable Logos source.

// -[YTColdConfig mainAppCoreClientIosEnableStartupAnimation], original IMP slot 0x01225fd8
/* Decompiled from supplied 5.2.2 arm package. VA 0x520e4. FUN_000520e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000520e4(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01226a54 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,@selector(integerForKey:),
                        @"startupAnimation");
  _objc_release(uVar1);
  if (lVar2 < 2) {
    if (lVar2 == 1) {
      return 1;
    }
  }
  else if (lVar2 < 4) {
    if (lVar2 == 2) {
      return 0;
    }
  }
  else if (lVar2 == 4) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000523e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*_DAT_01225fd8)(param_1,param_2);
  return uVar1;
}



// -[YTColdConfig removeNextPaddleForSingletonVideos], original IMP slot 0x01226350
/* Decompiled from supplied 5.2.2 arm package. VA 0x8659c. FUN_0008659c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008659c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c6c = 1;
  iVar1 = FUN_000df0ec(@"hidePrevNext");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086748. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226350)(param_1,param_2);
    return uVar2;
  }
  return 1;
}



// -[YTColdConfig removePreviousPaddleForSingletonVideos], original IMP slot 0x01226358
/* Decompiled from supplied 5.2.2 arm package. VA 0x86760. FUN_00086760 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086760(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c70 = 1;
  iVar1 = FUN_000df110(@"hidePrevNext");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226358)(param_1,param_2);
    return uVar2;
  }
  return 1;
}



// -[YTColdConfig replaceNextPaddleWithFastForwardButtonForSingletonVods], original IMP slot 0x01226360
/* Decompiled from supplied 5.2.2 arm package. VA 0x86928. FUN_00086928 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086928(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c74 = 1;
  iVar1 = FUN_000df134(@"replacePrevNext");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086b0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226360)(param_1,param_2);
    return uVar2;
  }
  return 1;
}



// -[YTColdConfig replacePreviousPaddleWithRewindButtonForSingletonVods], original IMP slot 0x01226368
/* Decompiled from supplied 5.2.2 arm package. VA 0x86b24. FUN_00086b24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086b24(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c78 = 1;
  iVar1 = FUN_000df158(@"replacePrevNext");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226368)(param_1,param_2);
    return uVar2;
  }
  return 1;
}



// -[YTColdConfig enableHideChipsInTheCommentsHeaderOnScrollIos], original IMP slot 0x01226370
/* Decompiled from supplied 5.2.2 arm package. VA 0x86d08. FUN_00086d08 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086d08(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c7c = 1;
  iVar1 = FUN_000df17c(@"stickSortComments");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00086f04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226370)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig enableChipsInTheCommentsHeaderIos], original IMP slot 0x01226378
/* Decompiled from supplied 5.2.2 arm package. VA 0x86f1c. FUN_00086f1c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00086f1c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c80 = 1;
  iVar1 = FUN_000df1a0(@"hideSortComments");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226378)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig shouldUseAppThemeSetting], original IMP slot 0x01226380
/* Decompiled from supplied 5.2.2 arm package. VA 0x87120. FUN_00087120 */

undefined8 FUN_00087120(void)

{
  return 1;
}



// -[YTColdConfig isLandscapeEngagementPanelSwipeRightToDismissEnabled], original IMP slot 0x01226388
/* Decompiled from supplied 5.2.2 arm package. VA 0x87128. FUN_00087128 */

undefined8 FUN_00087128(void)

{
  return 1;
}



// -[YTColdConfig enableSwipeToRemoveInPlaylistWatchEp], original IMP slot 0x01226390
/* Decompiled from supplied 5.2.2 arm package. VA 0x87130. FUN_00087130 */

undefined8 FUN_00087130(void)

{
  return 1;
}



// -[YTColdConfig enableLightThemeAmbientMode], original IMP slot 0x01226398
/* Decompiled from supplied 5.2.2 arm package. VA 0x87138. FUN_00087138 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087138(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c90 = 1;
  iVar1 = FUN_000df1c4(@"disableAmbientMode");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008733c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226398)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig iosAmbientModeExtendWidthInLandscape], original IMP slot 0x012263a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x87354. FUN_00087354 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087354(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c94 = 1;
  iVar1 = FUN_000df1e8(@"disableAmbientMode");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008755c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263a0)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig iosEnableFullScreenAmbientMode], original IMP slot 0x012263a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x87574. FUN_00087574 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087574(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c98 = 1;
  iVar1 = FUN_000df20c(@"disableAmbientMode");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008776c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263a8)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig enableTurnOffCinematicForFrameWithBlackBars], original IMP slot 0x012263b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x87784. FUN_00087784 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087784(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226c9c = 1;
  iVar1 = FUN_000df230(@"disableAmbientMode");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263b0)(param_1,param_2);
    return uVar2;
  }
  return 1;
}



// -[YTColdConfig queueClientGlobalConfigEnableFloatingPlaylistMinibar], original IMP slot 0x012263b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x8798c. FUN_0008798c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0008798c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ca0 = 1;
  iVar1 = FUN_000df254(@"playlistOldMinibar");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087b90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263b8)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig disablePlaybackLockScreenController], original IMP slot 0x012263c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x87ba8. FUN_00087ba8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00087ba8(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ca4 = 1;
  iVar1 = FUN_000df278(@"ytlLockButton");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00087d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012263c0)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTColdConfig iosEnableVideoPlayerScrubber], original IMP slot 0x012263c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x87d74. FUN_00087d74 */

void FUN_00087d74(void)

{
  DAT_01226ca8 = 1;
  FUN_000df29c(@"shortsProgress");
  return;
}



// -[YTColdConfig mobileShortsTabInlined], original IMP slot 0x012263d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x87ec8. FUN_00087ec8 */

uint FUN_00087ec8(void)

{
  uint uVar1;
  
  DAT_01226cac = 1;
  uVar1 = _ytpBool(@"shortsProgress");
  return uVar1 & 1;
}



// -[YTColdConfig iosUseSystemVolumeControlInFullscreen], original IMP slot 0x012263d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x88028. FUN_00088028 */

void FUN_00088028(void)

{
  DAT_01226cb0 = 1;
  FUN_000df2e4(@"stockVolumeHUD");
  return;
}



// -[YTColdConfig enableYouthereCommandsOnIos], original IMP slot 0x012263e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8818c. FUN_0008818c */

undefined8 FUN_0008818c(void)

{
  return 0;
}



// -[YTColdConfig cxClientEnableIosLocalNetworkPermissionWifiFixes], original IMP slot 0x012263e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x88194. FUN_00088194 */

undefined8 FUN_00088194(void)

{
  return 1;
}



// -[YTColdConfig cxClientEnableIosLocalNetworkPermissionUsingSockets], original IMP slot 0x012263f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8819c. FUN_0008819c */

undefined8 FUN_0008819c(void)

{
  return 0;
}



// -[YTColdConfig cxClientEnableIosLocalNetworkPermissionReliabilityFixes], original IMP slot 0x012263f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x881a4. FUN_000881a4 */

undefined8 FUN_000881a4(void)

{
  return 1;
}



// -[YTColdConfig iosPlayerClientSharedConfigPopulateSwAv1MediaCapabilities], original IMP slot 0x01226400
/* Decompiled from supplied 5.2.2 arm package. VA 0x881ac. FUN_000881ac */

undefined8 FUN_000881ac(void)

{
  return 0;
}



// -[YTColdConfig mediaEngineClientForceSoftwareDecoderOnDecoderRetry], original IMP slot 0x01226408
/* Decompiled from supplied 5.2.2 arm package. VA 0x881b4. FUN_000881b4 */

undefined8 FUN_000881b4(void)

{
  return 0;
}


