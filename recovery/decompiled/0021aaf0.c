/* Decompiled from supplied 5.2.2 arm package. VA 0x21aaf0. mediaWithPlayer: */

/* Function Stack Size: 0x18 bytes */

ID RPCMedia::mediaWithPlayer_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ID IVar11;
  undefined *puVar12;
  undefined8 uVar13;
  undefined *puVar14;
  
  _objc_retain(param_3);
  puVar14 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uVar3 = FUN_0021b09c(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0);
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar12 = (&PTR_LAB_011cce50)[uVar3] + (int)-(DAT_011cce60 ^ 0x9f09908);
  if (uVar3 == 0) {
    uVar3 = FUN_0021b404(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    uVar13 = 0;
    puVar12 = (&PTR_LAB_011cce68)[uVar3] + (int)-(uRam00000000011cce78 ^ 0xd18c5f8a);
    puVar14 = puVar2;
    if (uVar3 == 0) goto LAB_0021aee4;
  }
  _objc_msgSend(puVar12,param_3,puVar14);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  uVar13 = 0;
  if (lVar4 != 0) {
    uVar13 = _objc_alloc_init(PTR_RPCMedia_0114ead0);
    _objc_msgSend(param_3,PTR_s_currentVideoID_0114e558);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,PTR_s_setVideoID__0114e560,uVar5);
    _objc_release(uVar5);
    puVar1 = PTR_s_playerData_0114c7d0;
    _objc_msgSend(lVar4,PTR_s_playerData_0114c7d0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar14 = PTR_s_videoDetails_0114c7d8;
    _objc_msgSend(uVar5,PTR_s_videoDetails_0114c7d8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_title_0114c7f0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,PTR_s_setTitle__0114afc0,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(lVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar14);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_author_0114c7e8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,PTR_s_setAuthor__0114e568,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar12 = PTR_s_activeVideo_0114c788;
    _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_totalMediaTime_0114b978);
    _objc_msgSend(uVar13,PTR_s_setTotalTime__0114e570);
    _objc_release(uVar5);
    _objc_msgSend(param_3,puVar12);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_currentVideoTime_0114e578);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_time_0114adc0);
    _objc_msgSend(uVar13,PTR_s_setCurrentTime__0114adb0);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(lVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar14);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_thumbnail_0114cf88);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_thumbnailsArray_0114cf90);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_objectAtIndexedSubscript__0114aeb0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_URL_0114c578);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,PTR_s_setThumbnailURL__0114e580,uVar10);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(lVar4);
  }
LAB_0021aee4:
  _objc_release(param_3);
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar13);
  return IVar11;
}


