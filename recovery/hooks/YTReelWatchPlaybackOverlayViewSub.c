// Decompiled hook evidence for YTReelWatchPlaybackOverlayViewSub. This is not compilable Logos source.

// -[YTReelWatchPlaybackOverlayViewSub layoutSubviews], original IMP slot 0x01226318
/* Decompiled from supplied 5.2.2 arm package. VA 0x8210c. FUN_0008210c */

void FUN_0008210c(undefined8 param_1)

{
  ulong uVar1;
  
  if (DAT_01226c44 == 0) {
    s_downloadManager_01166d03[0] = DAT_01166cf3 ^ 0x4b;
    s_downloadManager_01166d03[1] = bRam0000000001166cf4 ^ 0x1c;
    s_downloadManager_01166d03[2] = bRam0000000001166cf5 ^ 0x10;
    s_downloadManager_01166d03[3] = bRam0000000001166cf6 ^ 0xbd;
    s_downloadManager_01166d03[4] = bRam0000000001166cf7 ^ 0xa0;
    s_downloadManager_01166d03[5] = bRam0000000001166cf8 ^ 0x43;
    s_downloadManager_01166d03[6] = bRam0000000001166cf9 ^ 0x2a;
    s_downloadManager_01166d03[7] = bRam0000000001166cfa ^ 0xb5;
    s_downloadManager_01166d03[8] = bRam0000000001166cfb ^ 0x68;
    s_downloadManager_01166d03[9] = bRam0000000001166cfc ^ 0xf7;
    s_downloadManager_01166d03[10] = bRam0000000001166cfd ^ 0x3b;
    s_downloadManager_01166d03[0xb] = bRam0000000001166cfe ^ 0x45;
    s_downloadManager_01166d03[0xc] = bRam0000000001166cff ^ 0x18;
    s_downloadManager_01166d03[0xd] = bRam0000000001166d00 ^ 0x5e;
    s_downloadManager_01166d03[0xe] = bRam0000000001166d01 ^ 0x26;
    s_downloadManager_01166d03[0xf] = bRam0000000001166d02 ^ 0xb3;
    s__playerOverlayView_01166ce0[0] = bRam0000000001166cc0 ^ 0xb8;
    s__playerOverlayView_01166ce0[1] = bRam0000000001166cc1 ^ 0x99;
    s__playerOverlayView_01166ce0[2] = bRam0000000001166cc2 ^ 0x50;
    s__playerOverlayView_01166ce0[3] = bRam0000000001166cc3 ^ 2;
    s__playerOverlayView_01166ce0[4] = bRam0000000001166cc4 ^ 0x91;
    s__playerOverlayView_01166ce0[5] = bRam0000000001166cc5 ^ 0xc9;
    s__playerOverlayView_01166ce0[6] = bRam0000000001166cc6 ^ 0xb8;
    s__playerOverlayView_01166ce0[7] = bRam0000000001166cc7 ^ 200;
    s__playerOverlayView_01166ce0[8] = bRam0000000001166cc8 ^ 0x6a;
    s__playerOverlayView_01166ce0[9] = bRam0000000001166cc9 ^ 0xb3;
    s__playerOverlayView_01166ce0[10] = bRam0000000001166cca ^ 0xe6;
    s__playerOverlayView_01166ce0[0xb] = bRam0000000001166ccb ^ 0xd9;
    s__playerOverlayView_01166ce0[0xc] = bRam0000000001166ccc ^ 0x28;
    s__playerOverlayView_01166ce0[0xd] = bRam0000000001166ccd ^ 0xfc;
    s__playerOverlayView_01166ce0[0xe] = bRam0000000001166cce ^ 0xd4;
    s__playerOverlayView_01166ce0[0xf] = bRam0000000001166ccf ^ 0xcf;
    s__playerOverlayView_01166ce0[0x10] = bRam0000000001166cd0 ^ 0xa7;
    s__playerOverlayView_01166ce0[0x11] = bRam0000000001166cd1 ^ 0x87;
    s__playerOverlayView_01166ce0[0x12] = bRam0000000001166cd2 ^ 0x61;
    s__playerOverlayView_01166ca0[0] = DAT_01166c80 ^ 0x96;
    s__playerOverlayView_01166ca0[1] = bRam0000000001166c81 ^ 0xc4;
    s__playerOverlayView_01166ca0[2] = bRam0000000001166c82 ^ 0x6a;
    s__playerOverlayView_01166ca0[3] = bRam0000000001166c83 ^ 0xa6;
    s__playerOverlayView_01166ca0[4] = bRam0000000001166c84 ^ 0x7e;
    s__playerOverlayView_01166ca0[5] = bRam0000000001166c85 ^ 0x1c;
    s__playerOverlayView_01166ca0[6] = bRam0000000001166c86 ^ 0x56;
    s__playerOverlayView_01166ca0[7] = bRam0000000001166c87 ^ 0x2d;
    s__playerOverlayView_01166ca0[8] = bRam0000000001166c88 ^ 10;
    s__playerOverlayView_01166ca0[9] = bRam0000000001166c89 ^ 0x86;
    s__playerOverlayView_01166ca0[10] = bRam0000000001166c8a ^ 0xcf;
    s__playerOverlayView_01166ca0[0xb] = bRam0000000001166c8b ^ 0x58;
    s__playerOverlayView_01166ca0[0xc] = ~bRam0000000001166c8c;
    s__playerOverlayView_01166ca0[0xd] = bRam0000000001166c8d ^ 0x7b;
    s__playerOverlayView_01166ca0[0xe] = bRam0000000001166c8e ^ 200;
    s__playerOverlayView_01166ca0[0xf] = bRam0000000001166c8f ^ 0xa5;
    s__playerOverlayView_01166ca0[0x10] = bRam0000000001166c90 ^ 0xdc;
    s__playerOverlayView_01166ca0[0x11] = bRam0000000001166c91 ^ 0xce;
    s__playerOverlayView_01166ca0[0x12] = bRam0000000001166c92 ^ 0x78;
    s__elementView_01166c53[0] = DAT_01166c46 ^ 0x3b;
    s__elementView_01166c53[1] = DAT_01166c47 ^ 0x2c;
    s__elementView_01166c53[2] = DAT_01166c48 ^ 200;
    s__elementView_01166c53[3] = DAT_01166c49 ^ 0xc1;
    s__elementView_01166c53[4] = DAT_01166c4a ^ 0xe2;
    s__elementView_01166c53[5] = DAT_01166c4b ^ 0xf2;
    s__elementView_01166c53[6] = DAT_01166c4c ^ 0xcd;
    s__elementView_01166c53[7] = DAT_01166c4d ^ 0xdc;
    s__elementView_01166c53[8] = DAT_01166c4e ^ 0xd2;
    s__elementView_01166c53[9] = DAT_01166c4f ^ 0xd5;
    s__elementView_01166c53[10] = DAT_01166c50 ^ 0xac;
    s__elementView_01166c53[0xb] = DAT_01166c51 ^ 0x45;
    s__elementView_01166c53[0xc] = DAT_01166c52 ^ 0xda;
    s__rootNode_01166c6a[0] = DAT_01166c60 ^ 0xbe;
    s__rootNode_01166c6a[1] = DAT_01166c61 ^ 0x4e;
    s__rootNode_01166c6a[2] = DAT_01166c62 ^ 0x89;
    s__rootNode_01166c6a[3] = DAT_01166c63 ^ 0x25;
    s__rootNode_01166c6a[4] = DAT_01166c64 ^ 0xaf;
    s__rootNode_01166c6a[5] = DAT_01166c65 ^ 0xa6;
    s__rootNode_01166c6a[6] = DAT_01166c66 ^ 0x36;
    s__rootNode_01166c6a[7] = DAT_01166c67 ^ 0x3a;
    s__rootNode_01166c6a[8] = DAT_01166c68 ^ 0x61;
    s__rootNode_01166c6a[9] = DAT_01166c69 ^ 0x4f;
    s__elementView_01166c39[0] = DAT_01166c2c ^ 0xbd;
    s__elementView_01166c39[1] = DAT_01166c2d ^ 0x40;
    s__elementView_01166c39[2] = DAT_01166c2e ^ 3;
    s__elementView_01166c39[3] = DAT_01166c2f ^ 0x15;
    s__elementView_01166c39[4] = DAT_01166c30 ^ 0x96;
    s__elementView_01166c39[5] = DAT_01166c31 ^ 0xdc;
    s__elementView_01166c39[6] = DAT_01166c32 ^ 0x5f;
    s__elementView_01166c39[7] = DAT_01166c33 ^ 0x37;
    s__elementView_01166c39[8] = DAT_01166c34 ^ 0x71;
    s__elementView_01166c39[9] = DAT_01166c35 ^ 0xc2;
    s__elementView_01166c39[10] = DAT_01166c36 ^ 0x3f;
    s__elementView_01166c39[0xb] = DAT_01166c37 ^ 0x89;
    s__elementView_01166c39[0xc] = DAT_01166c38 ^ 0x49;
    s__rootNode_01166c22[0] = DAT_01166c18 ^ 0x38;
    s__rootNode_01166c22[1] = DAT_01166c19 ^ 0x24;
    s__rootNode_01166c22[2] = DAT_01166c1a ^ 0x2f;
    s__rootNode_01166c22[3] = DAT_01166c1b ^ 0x86;
    s__rootNode_01166c22[4] = DAT_01166c1c ^ 0xf;
    s__rootNode_01166c22[5] = DAT_01166c1d ^ 0xfb;
    s__rootNode_01166c22[6] = DAT_01166c1e ^ 0x2c;
    s__rootNode_01166c22[7] = DAT_01166c1f ^ 0x83;
    s__rootNode_01166c22[8] = DAT_01166c20 ^ 0x60;
    s__rootNode_01166c22[9] = DAT_01166c21 ^ 0x8c;
    s_reel_player_overlay_reel_action__01166bf0[0] = DAT_01166bc0 ^ 0xf5;
    s_reel_player_overlay_reel_action__01166bf0[1] = DAT_01166bc1 ^ 0xb2;
    s_reel_player_overlay_reel_action__01166bf0[2] = DAT_01166bc2 ^ 0x90;
    s_reel_player_overlay_reel_action__01166bf0[3] = DAT_01166bc3 ^ 0xc;
    s_reel_player_overlay_reel_action__01166bf0[4] = DAT_01166bc4 ^ 0x99;
    s_reel_player_overlay_reel_action__01166bf0[5] = DAT_01166bc5 ^ 0x7e;
    s_reel_player_overlay_reel_action__01166bf0[6] = DAT_01166bc6 ^ 100;
    s_reel_player_overlay_reel_action__01166bf0[7] = DAT_01166bc7 ^ 0xd6;
    s_reel_player_overlay_reel_action__01166bf0[8] = DAT_01166bc8 ^ 0x3b;
    s_reel_player_overlay_reel_action__01166bf0[9] = DAT_01166bc9 ^ 0x6b;
    s_reel_player_overlay_reel_action__01166bf0[10] = DAT_01166bca ^ 0x46;
    s_reel_player_overlay_reel_action__01166bf0[0xb] = DAT_01166bcb ^ 0xea;
    s_reel_player_overlay_reel_action__01166bf0[0xc] = DAT_01166bcc ^ 0x6c;
    s_reel_player_overlay_reel_action__01166bf0[0xd] = DAT_01166bcd ^ 0x3c;
    s_reel_player_overlay_reel_action__01166bf0[0xe] = DAT_01166bce ^ 0xe5;
    s_reel_player_overlay_reel_action__01166bf0[0xf] = DAT_01166bcf ^ 0xac;
    s_reel_player_overlay_reel_action__01166bf0[0x10] = DAT_01166bd0 ^ 0x7c;
    s_reel_player_overlay_reel_action__01166bf0[0x11] = DAT_01166bd1 ^ 0xea;
    s_reel_player_overlay_reel_action__01166bf0[0x12] = DAT_01166bd2 ^ 0xe9;
    s_reel_player_overlay_reel_action__01166bf0[0x13] = DAT_01166bd3 ^ 0x7c;
    s_reel_player_overlay_reel_action__01166bf0[0x14] = DAT_01166bd4 ^ 0x34;
    s_reel_player_overlay_reel_action__01166bf0[0x15] = DAT_01166bd5 ^ 0xa8;
    s_reel_player_overlay_reel_action__01166bf0[0x16] = DAT_01166bd6 ^ 0xd8;
    s_reel_player_overlay_reel_action__01166bf0[0x17] = DAT_01166bd7 ^ 0x53;
    s_reel_player_overlay_reel_action__01166bf0[0x18] = DAT_01166bd8 ^ 0x9c;
    s_reel_player_overlay_reel_action__01166bf0[0x19] = DAT_01166bd9 ^ 0x98;
    s_reel_player_overlay_reel_action__01166bf0[0x1a] = DAT_01166bda ^ 0x1d;
    s_reel_player_overlay_reel_action__01166bf0[0x1b] = DAT_01166bdb ^ 0x71;
    s_reel_player_overlay_reel_action__01166bf0[0x1c] = DAT_01166bdc ^ 0x4a;
    s_reel_player_overlay_reel_action__01166bf0[0x1d] = DAT_01166bdd ^ 0x42;
    s_reel_player_overlay_reel_action__01166bf0[0x1e] = DAT_01166bde ^ 0x31;
    s_reel_player_overlay_reel_action__01166bf0[0x1f] = DAT_01166bdf ^ 0xaf;
    s_reel_player_overlay_reel_action__01166bf0[0x20] = DAT_01166be0 ^ 0xeb;
    s_reel_player_overlay_reel_action__01166bf0[0x21] = DAT_01166be1 ^ 0xd9;
    s_reel_player_overlay_reel_action__01166bf0[0x22] = DAT_01166be2 ^ 0x55;
    s_reel_player_overlay_reel_action__01166bf0[0x23] = DAT_01166be3 ^ 0xe5;
    s_reel_player_overlay_reel_action__01166bf0[0x24] = DAT_01166be4 ^ 0x8d;
    s_reel_player_overlay_reel_action__01166bf0[0x25] = DAT_01166be5 ^ 0x5f;
    s_reel_player_overlay_reel_action__01166bf0[0x26] = DAT_01166be6 ^ 0x6d;
    s_reel_player_overlay_reel_action__01166bf0[0x27] = DAT_01166be7 ^ 0x61;
  }
  DAT_01226c44 = 1;
  (*DAT_01226318)(param_1);
  uVar1 = FUN_000de414(@"downloadManager");
                    /* WARNING: Could not recover jumptable at 0x00082adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117d020)[uVar1 & 0xffffffff] + (int)-(DAT_0117d030 ^ 0xc15cfa0f)))();
  return;
}



// -[YTReelWatchPlaybackOverlayViewSub didTapYtlButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x82fb0. FUN_00082fb0 */

undefined1  [16] FUN_00082fb0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01226c48 = 1;
  _objc_retain(param_3);
  puVar1 = @selector(parentResponder);
  _objc_msgSend(param_1,@selector(parentResponder));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_012268c8 == 0) {
    DAT_012268c8 = _objc_getClass((&PTR_LAB_0117d170)[DAT_012268c8 == 0] +
                                  (int)-(DAT_0117d180 ^ 0xef714abd),
                                  s_YTReelPlayerViewController_01166e80);
  }
  lVar2 = DAT_012268c8;
  _objc_retainAutorelease(DAT_012268c8);
  uVar3 = FUN_000de4dc(uVar4,@selector(isKindOfClass:),lVar2);
  _objc_release(uVar4);
  if (uVar3 != 0) {
    _objc_msgSend((&PTR_LAB_0117d190)[uVar3] + (int)-(uRam000000000117d1a0 ^ 0xa1225cb7),param_1,
                  puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(player));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,@selector(showDownloadSheetShorts:withSender:),
                  uVar5,param_3);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(param_3);
  CallSupervisor(0x4994);
  return ZEXT816(0x1f);
}


