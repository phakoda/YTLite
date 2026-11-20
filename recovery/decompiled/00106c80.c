/* Decompiled from supplied 5.2.2 arm package. VA 0x106c80. downloadVideoWithUrl:audioUrl:fileName:extension:videoID:videoSize:audioSize:duration:captions:playerVC: */

/* Function Stack Size: 0x60 bytes */

void DownloadMenuHelper::
     downloadVideoWithUrl_audioUrl_fileName_extension_videoID_videoSize_audioSize_duration_captions_playerVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               unsigned_long_long param_8,unsigned_long_long param_9,unsigned_long_long param_10,
               ID param_11,ID param_12)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_012271d8 = 1;
  _objc_retain(param_12);
  puVar2 = PTR__OBJC_CLASS___UIApplication_0114ebc8;
  puVar1 = PTR_s_sharedApplication_0114b528;
  _objc_retain(param_11);
  _objc_retain(param_7);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_delegate_0114b530);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_window_0114b3b0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar6,PTR_s_rootViewController_0114b968);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_alloc_init(PTR_YTLHelper_0114ed50);
  _objc_msgSend(uVar4,PTR_s_setHelper__0114ba98,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,PTR_s_helper_0114ba90);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  FUN_00113590(uVar5,PTR_s_downloadVideoWithUrl_audioUrl_fi_0114d038,param_3,param_4,param_5,param_6
               ,param_7,param_8,param_9,param_10,param_11);
  _objc_release(param_11);
  _objc_release(param_7);
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar5);
  if ((param_12 != 0) &&
     (iVar3 = FUN_00113454((&PTR_LAB_0118a998)[param_12 == 0] +
                           (int)-(uRam000000000118a9a8 ^ 0x4d38e521),
                           &PTR____CFConstantStringClassReference_011873d0), iVar3 != 0)) {
    _objc_msgSend(param_1,PTR_s_getThumbnail__0114d040,param_12);
  }
  _objc_release(uVar4);
  _objc_release(uVar6);
  _objc_release(param_12);
  return;
}


