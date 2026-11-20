/* Decompiled from supplied 5.2.2 arm package. VA 0xca6ac. FUN_000ca6ac */

undefined8 FUN_000ca6ac(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined *puVar6;
  
  DAT_01227020 = 1;
  uVar5 = _objc_retain(param_2);
  puVar2 = PTR_s_videoType_0114ca60;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uVar3 = FUN_000ef764(uVar5,PTR_s_respondsToSelector__0114af58,PTR_s_videoType_0114ca60);
  if (uVar3 != 0) {
    uVar3 = FUN_000ef670((&PTR_LAB_01183600)[uVar3] + (int)-(DAT_01183610 ^ 0x21dca342),
                         &PTR____CFConstantStringClassReference_01174500);
    puVar6 = (&PTR_LAB_01183618)[uVar3] + (int)-(uRam0000000001183628 ^ 0x6bda0d6c);
    if (uVar3 != 0) {
      iVar4 = _objc_msgSend(puVar6,param_2,puVar2);
      puVar6 = (&PTR_LAB_01183630)[iVar4 == 3] + (int)-(uRam0000000001183640 ^ 0xcaef7bfc);
      uVar5 = 1;
      if (iVar4 == 3) goto LAB_000caef4;
    }
    uVar3 = FUN_000ef860(puVar6,&PTR____CFConstantStringClassReference_011744c0);
    if (uVar3 != 0) {
      iVar4 = _objc_msgSend((&PTR_LAB_01183648)[uVar3] + (int)-(uRam0000000001183658 ^ 0x655dfe68),
                            param_2,puVar2);
      puVar6 = (&PTR_LAB_01183660)[iVar4 == 10] + (int)-(uRam0000000001183670 ^ 0x76eb5a5e);
      uVar5 = 1;
      if (iVar4 == 10) goto LAB_000caef4;
    }
  }
  puVar2 = PTR_s_presentation_0114ca68;
  uVar3 = FUN_000ef8f0(param_2,puVar1,PTR_s_presentation_0114ca68);
  if (uVar3 != 0) {
    uVar3 = FUN_000ef71c((&PTR_LAB_01183678)[uVar3] + (int)-(uRam0000000001183688 ^ 0x18dc71f),
                         &PTR____CFConstantStringClassReference_01174500);
    if (uVar3 != 0) {
      _objc_msgSend((&PTR_LAB_01183690)[uVar3] + (int)-(uRam00000000011836a0 ^ 0x11413e8f),param_2,
                    puVar2);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      iVar4 = _objc_msgSend(uVar5,PTR_s_type_0114b050);
      _objc_release(uVar5);
                    /* WARNING: Could not recover jumptable at 0x000caca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)((&PTR_LAB_011836a8)[iVar4 == 4] + (int)-(uRam00000000011836b8 ^ 0x3144ec9f)
                        ))();
      return uVar5;
    }
    uVar3 = FUN_000ef64c(&PTR____CFConstantStringClassReference_011744c0);
    if (uVar3 != 0) {
      _objc_msgSend((&PTR_LAB_011836c0)[uVar3] + (int)-(uRam00000000011836d0 ^ 0xe150d1b6),param_2,
                    puVar2);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      iVar4 = _objc_msgSend(uVar5,PTR_s_type_0114b050);
      _objc_release(uVar5);
                    /* WARNING: Could not recover jumptable at 0x000cad44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)((&PTR_LAB_011836d8)[iVar4 == 5] + (int)-(uRam00000000011836e8 ^ 0x8be7612a)
                        ))();
      return uVar5;
    }
    uVar3 = FUN_000ef6f8(&PTR____CFConstantStringClassReference_01174480);
    if (uVar3 != 0) {
      _objc_msgSend((&PTR_LAB_011836f0)[uVar3] + (int)-(uRam0000000001183700 ^ 0x3cdcae02),param_2,
                    puVar2);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      iVar4 = _objc_msgSend(uVar5,PTR_s_type_0114b050);
                    /* WARNING: Could not recover jumptable at 0x000caf70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)((&PTR_LAB_01183708)[iVar4 == 3] + (int)-(uRam0000000001183718 ^ 0x33144757)
                        ))();
      return uVar5;
    }
  }
  uVar3 = FUN_000ef8c8(param_2,puVar1,PTR_s_livePreviewVideo_0114ca70);
  if ((uVar3 != 0) &&
     (iVar4 = FUN_000ef6d4((&PTR_LAB_01183740)[uVar3] + (int)-(uRam0000000001183750 ^ 0x60e2a882),
                           &PTR____CFConstantStringClassReference_01174480), iVar4 != 0)) {
    uVar3 = FUN_000ef814(param_2,PTR_s_isLivePreviewVideo_0114ca78);
    puVar6 = (&PTR_LAB_01183770)[uVar3] + (int)-(uRam0000000001183780 ^ 0x20ea427d);
    uVar5 = 1;
    if (uVar3 != 0) goto LAB_000caef4;
  }
  uVar3 = FUN_000ef83c(param_2,puVar1,PTR_s_liveVideo_0114ca80);
  puVar6 = (&PTR_LAB_01183788)[uVar3] + (int)-(uRam0000000001183798 ^ 0x53b730f);
  if (uVar3 != 0) {
    uVar3 = FUN_000ef5e8(puVar6,&PTR____CFConstantStringClassReference_01174480);
    puVar6 = (&PTR_LAB_011837a0)[uVar3] + (int)-(uRam00000000011837b0 ^ 0xb14e081a);
    if (uVar3 != 0) {
      uVar3 = FUN_000ef7cc(param_2,PTR_s_isLiveVideo_0114ca88);
      puVar6 = (&PTR_LAB_011837b8)[uVar3] + (int)-(uRam00000000011837c8 ^ 0x137ad77d);
      uVar5 = 1;
      if (uVar3 != 0) goto LAB_000caef4;
    }
  }
  uVar5 = 0;
LAB_000caef4:
  _objc_release(puVar6,param_2);
  return uVar5;
}


