/* Decompiled from supplied 5.2.2 arm package. VA 0x22df30. saveMedia: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::saveMedia_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  code *pcStack_e0;
  undefined *puStack_d8;
  ID IStack_d0;
  ID IStack_c8;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  ID IStack_a0;
  undefined **local_88;
  undefined **ppuStack_80;
  int iStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR__av_write_image_line2_011d1640;
  local_5c = (uint)(DAT_012283c0 == 0);
  local_70 = &PTR_LAB_011d1660;
  local_68 = &PTR__objc_msgSend_011d0fe0;
  local_88 = &PTR__objc_msgSend_011d0fe0;
  ppuStack_80 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283c0 = 1;
  uVar3 = _objc_retain(param_3);
  _objc_msgSend(uVar3,PTR_s_pathExtension_0114dc70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00232d44(uVar3,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_011d07f0);
  _objc_release(uVar3);
  iStack_74 = iVar2;
  if (iVar2 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___PHPhotoLibrary_0114ed58,PTR_s_sharedPhotoLibrary_0114c600);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR___NSConcreteStackBlock_01060660;
    uVar3 = DAT_00c4c228;
    puStack_c0 = PTR___NSConcreteStackBlock_01060660;
    uStack_b8 = DAT_00c4c228;
    pcStack_b0 = FUN_0022e17c;
    puStack_a8 = &DAT_01061420;
    _objc_retain(param_3);
    puStack_f0 = puVar1;
    uStack_e8 = uVar3;
    pcStack_e0 = FUN_0022e1f0;
    puStack_d8 = &UNK_010631d0;
    IStack_d0 = param_1;
    IStack_a0 = param_3;
    _objc_retain();
    IStack_c8 = param_3;
    _objc_msgSend(uVar4,PTR_s_performChanges_completionHandler_0114c620,&puStack_c0,&puStack_f0);
    _objc_release(uVar4);
    _objc_release(IStack_c8);
    _objc_release(IStack_a0);
  }
  else {
    _objc_msgSend(param_1,PTR_s_shareMedia__0114e758,param_3);
  }
  _objc_release(param_3);
  return;
}


