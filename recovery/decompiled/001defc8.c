/* Decompiled from supplied 5.2.2 arm package. VA 0x1defc8. translateSingleText:fromLanguage:toLanguage:completion: */

/* Function Stack Size: 0x30 bytes */

void YTPTranslator::translateSingleText_fromLanguage_toLanguage_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  code *pcStack_a0;
  undefined *puStack_98;
  ID IStack_90;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011b9a50;
  local_6c = (uint)(DAT_01227e14 == 0);
  local_78 = &PTR_LAB_011b97a0;
  DAT_01227e14 = 1;
  _objc_retain(param_6);
  puVar1 = PTR_s_stringByReplacingOccurrencesOfSt_0114b2c0;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011b9720,
                &PTR____CFConstantStringClassReference_011b9660);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,puVar1,&PTR____CFConstantStringClassReference_011b9620,
                &PTR____CFConstantStringClassReference_011b96e0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,PTR_s_URLQueryAllowedCharacterSet_0114b3c0
               );
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_stringByAddingPercentEncodingWit_0114b3c8,uVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  thunk_FUN_001e0408(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011b96a0,param_4,param_5,uVar4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dataTaskWithURL_completionHandle_0114d920;
  puStack_b0 = PTR___NSConcreteStackBlock_01060660;
  uStack_a8 = DAT_00c4c228;
  pcStack_a0 = FUN_001df82c;
  puStack_98 = &DAT_01062cf0;
  IStack_90 = param_6;
  _objc_retain(param_6);
  _objc_msgSend(uVar5,puVar1,uVar6,&puStack_b0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_msgSend(uVar7,PTR_s_resume_0114d928);
  _objc_release(uVar7);
  _objc_release(IStack_90);
  _objc_release(param_6);
  _objc_release(uVar5);
  _objc_release(uVar2);
  _objc_release(uVar4);
  _objc_release(uVar3);
  CallSupervisor(0xb90);
  return;
}


