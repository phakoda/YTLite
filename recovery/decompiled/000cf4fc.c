/* Decompiled from supplied 5.2.2 arm package. VA 0xcf4fc. FUN_000cf4fc */

undefined1  [16] FUN_000cf4fc(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  DAT_01227050 = 1;
  uVar4 = *(undefined8 *)(param_1 + 0x20);
  uVar1 = _objc_msgSend(uVar4,PTR_s_length_0114b438);
  _objc_msgSend(uVar4,PTR_s_stringByReplacingOccurrencesOfSt_0114c3c8,
                &PTR____CFConstantStringClassReference_01175320,&cf___,0x400,0,uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000f0b80(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011752e0,uVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar4);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_openURL_options_completionHandle_0114b878,uVar3,
                *(undefined8 *)PTR____NSDictionary0___01060678,&PTR___NSConcreteGlobalBlock_010620d0
               );
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar4);
  _objc_release(uVar1);
  CallSupervisor(0x3b2a);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


