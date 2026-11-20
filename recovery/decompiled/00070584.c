/* Decompiled from supplied 5.2.2 arm package. VA 0x70584. FUN_00070584 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00070584(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_01226b84 = 1;
  _objc_retain(param_3);
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_01163b00);
  if (lVar5 == 1) {
    _objc_msgSend((&PTR_LAB_0117b960)[lVar5 == 1] + (int)-(DAT_0117b970 ^ 0xa5c4c45d),param_3,
                  PTR_s_description_0114af00);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    iVar4 = FUN_000d8e70(uVar6,PTR_s_containsString__0114af08,
                         &PTR____CFConstantStringClassReference_01163ac0);
    _objc_release(uVar6);
    if (iVar4 != 0) {
      if (lRam0000000001226888 == 0) {
        lRam0000000001226888 =
             _objc_getClass((&PTR_LAB_0117b990)[lRam0000000001226888 == 0] +
                            (int)-(uRam000000000117b9a0 ^ 0x5ef3ef64),s_YTUIResources_011639fe);
      }
      lVar5 = lRam0000000001226888;
      _objc_retainAutorelease(lRam0000000001226888);
      uVar6 = _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_pageStyle_0114c698);
      _objc_msgSend(lVar5,PTR_s_youtubePremiumLogoWithPageStyle__0114c6a0,uVar6);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(param_3);
      param_3 = uVar6;
    }
  }
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_01163b00);
  if (lVar5 == 2) {
    _objc_msgSend((&PTR_LAB_0117b9b8)[lVar5 == 2] + (int)-(DAT_0117b9c8 ^ 0x5014e651),param_3,
                  PTR_s_description_0114af00);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    iVar4 = FUN_000d9088(uVar6,PTR_s_containsString__0114af08,
                         &PTR____CFConstantStringClassReference_01163a80);
    _objc_release(uVar6);
    if (iVar4 != 0) {
      if (lRam0000000001226888 == 0) {
        lRam0000000001226888 =
             _objc_getClass((&PTR_LAB_0117b9e8)[lRam0000000001226888 == 0] +
                            (int)-(uRam000000000117b9f8 ^ 0x3edede6),s_YTUIResources_011639fe);
      }
      lVar5 = lRam0000000001226888;
      _objc_retainAutorelease(lRam0000000001226888);
      uVar6 = _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_pageStyle_0114c698);
      _objc_msgSend(lVar5,PTR_s_youtubeLogoWithPageStyle__0114c6a8,uVar6);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_release(param_3);
      param_3 = uVar6;
    }
  }
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_01163b00);
  puVar1 = PTR_s_description_0114af00;
  if (lVar5 == 3) {
    _objc_msgSend((&PTR_LAB_0117ba10)[lVar5 == 3] + (int)-(uRam000000000117ba20 ^ 0x5063b2b6),
                  param_3,PTR_s_description_0114af00);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_containsString__0114af08;
    uVar3 = FUN_000d8ed8(uVar6,PTR_s_containsString__0114af08,
                         &PTR____CFConstantStringClassReference_01163ac0);
    if (uVar3 == 0) {
      _objc_msgSend(param_3,puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      iVar4 = FUN_000d8f60(uVar7,puVar2,&PTR____CFConstantStringClassReference_01163a80);
      _objc_release(uVar7);
      _objc_release(uVar6);
      if (iVar4 == 0) goto LAB_00070ee4;
    }
    else {
      _objc_release((&PTR_LAB_0117ba28)[uVar3] + (int)-(uRam000000000117ba38 ^ 0xd054f328),uVar6);
    }
    _objc_msgSend(0,param_1,PTR_s_setAlpha__0114b698);
  }
LAB_00070ee4:
  (*_DAT_01226210)(param_1,param_2,param_3);
  _objc_release(param_3);
  CallSupervisor(0xe94d);
  return ZEXT816(0x1f);
}


