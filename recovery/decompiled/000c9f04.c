/* Decompiled from supplied 5.2.2 arm package. VA 0xc9f04. FUN_000c9f04 */

void FUN_000c9f04(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  puVar3 = PTR_YTLHelper_0114ed50;
  puVar2 = PTR_YTPMedia_0114eae0;
  puVar1 = PTR_s_ytPlusShorts_0114c900;
  DAT_0122701c = 1;
  _objc_retain(param_2);
  _objc_retain(param_1);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar7 = 0x4040000000000000;
  if (param_3 == 0) {
    uVar7 = 0x4038000000000000;
  }
  _objc_msgSend(uVar7,puVar3,PTR_s_resizeImage_toSize__0114c8a8,uVar4);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar1 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011743c0,0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4050000000000000,0x404e000000000000,puVar1,
                PTR_s_createYTQTMButton_accessibilityL_0114c908,param_1,uVar5,0,uVar7,
                PTR_s_didTapYtlButton__0114be98);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_blackColor_0114c400);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_retainAutorelease();
  uVar5 = _objc_msgSend(uVar5,PTR_s_CGColor_0114c8c0);
  puVar1 = PTR_s_layer_0114ae60;
  _objc_msgSend(uVar7,PTR_s_layer_0114ae60);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setShadowColor__0114c8c8,uVar5);
  _objc_release(uVar6);
  _objc_release(uVar4);
  _objc_msgSend(uVar7,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3f000000,uVar4,PTR_s_setShadowOpacity__0114c8d0);
  _objc_release(uVar4);
  _objc_msgSend(uVar7,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,0,uVar4,PTR_s_setShadowOffset__0114c8d8);
  _objc_release(uVar4);
  _objc_msgSend(uVar7,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4010000000000000,uVar4,PTR_s_setShadowRadius__0114c8e0);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_touchFeedbackView_0114c910);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setCustomTouchFeedbackColor__0114c918,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar7,PTR_s_setTag__0114b858,999);
  _objc_msgSend(param_1,PTR_s_addSubview__0114b0a8,uVar7);
  _objc_release(param_1);
                    /* WARNING: Could not recover jumptable at 0x000ca378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_011835b8)[param_3] + (int)-(DAT_011835c8 ^ 0xacddb421)))();
  return;
}


