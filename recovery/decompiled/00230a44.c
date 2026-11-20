/* Decompiled from supplied 5.2.2 arm package. VA 0x230a44. downloadImageFromURL:download: */

/* Function Stack Size: 0x1c bytes */

void YTLHelper::downloadImageFromURL_download_(ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  long lVar2;
  ID IVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  undefined1 uStack_a0;
  undefined **local_88;
  undefined **ppuStack_80;
  uint uStack_74;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011d1820;
  local_4c = (uint)(DAT_01228410 == 0);
  local_60 = &PTR_LAB_011d1840;
  local_70 = &PTR_LAB_011d1858;
  local_58 = &PTR__objc_msgSend_011d0fe0;
  local_88 = &PTR__objc_msgSend_011d0fe0;
  ppuStack_80 = &PTR__objc_msgSend_011d0fe0;
  DAT_01228410 = 1;
  uVar1 = _objc_retain(param_3);
  _objc_msgSend(uVar1,PTR_s_absoluteString_0114c580);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uStack_64 = FUN_00234240(uVar1,PTR_s_containsString__0114af08,
                           &PTR____CFConstantStringClassReference_011d0de0);
  if (uStack_64 == 0) {
    _objc_retain(local_60[uStack_64] + (int)-(DAT_011d1850 ^ 0xe6f46a1b),param_3);
    IVar3 = param_3;
  }
  else {
    lVar2 = _objc_msgSend(uVar1,PTR_s_rangeOfString__0114b670,
                          &PTR____CFConstantStringClassReference_011d0de0);
    uStack_74 = (uint)(lVar2 == 0x7fffffffffffffff);
    if (lVar2 == 0x7fffffffffffffff) {
      IVar3 = 0;
    }
    else {
      _objc_msgSend(uVar1,PTR_s_substringFromIndex__0114c5f0,lVar2);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar1,PTR_s_stringByReplacingOccurrencesOfSt_0114b2c0,uVar4,
                    &PTR____CFConstantStringClassReference_011d0da0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar5);
      IVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
    }
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puStack_c0 = PTR___NSConcreteStackBlock_01060660;
  uStack_b8 = DAT_00c4c230;
  pcStack_b0 = FUN_00230ddc;
  puStack_a8 = &UNK_01063250;
  uStack_a0 = (undefined1)param_4;
  _objc_msgSend(uVar4,PTR_s_dataTaskWithURL_completionHandle_0114d920,IVar3,&puStack_c0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_resume_0114d928);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(IVar3);
  _objc_release(uVar1);
  _objc_release(param_3);
  return;
}


